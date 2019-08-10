/*
  (c) www.olliw.eu, OlliW, OlliW42
   
  License: GPL v3

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
   
  For the GNU General Public License see <http://www.gnu.org/licenses/>.
*/

#include "gopro/owGoProClass.h"


#define GOPRO_WOL_WAITTIME_MS  4000  //2500 isn't sufficient


typedef enum {
  GOPRO_RESULT_OK = true,             // 'o'
  GOPRO_RESULT_NOCONNECTION = false,  // 'n'
  GOPRO_RESULT_TIMEOUT = -1,          // 't'
  GOPRO_RESULT_UNKNOWN = -2,          // 'u'  //not used in this lib, is for higher level lib
  GOPRO_RESULT_ERROR = -4,            // 'e'  //not used in this lib, is for higher level lib
} GOPRORESULTENUM;


typedef enum {
  GOPRO_STARTUPTASK_IDLE = 0,
  GOPRO_STARTUPTASK_GETMAC = 0x0001,
  GOPRO_STARTUPTASK_SETTINGSLAST = 0x0002,
  GOPRO_STARTUPTASK_SETAUTOOFFNEVER = 0x0004,
  GOPRO_STARTUPTASK_EXECUTELIVESTREAMRESTART = 0x0008,
  GOPRO_STARTUPTASK_EXECUTELIVESTREAMSTOP = 0x0010,
  GOPRO_STARTUPTASK_CMDSUBMODEVIDEOVIDEO = 0x0020,
  GOPRO_STARTUPTASK_CMDSHUTTEROFF = 0x0040,
} GOPROSTARTUPTASKMASK;


class owGoPro: public owGoProClass  //if desired also the owGoProAdvancedClass can be inherited here
{
  public:
    owGoPro(const String ssid, const String password, bool debug = true);

    void begin(void);
    void end(void);
    bool isConnected(void);
    void printCredentials(void);
    bool getMac(void);
    void printMac(const uint8_t mac[]);
    void setMac(const uint8_t mac[]);
    bool macIsValid(void);

    void setStartupWoL(bool flag);
    void startupCmds(void);
    void loop(void);
    
    bool sendWoL(void);
    bool wakeUp(void);
    bool connectClient(void);
    bool isConnectedToClient(void);
    bool testConnectionToClient(void);
    int16_t sendKeepAlive(void);
    int16_t getMacfromInfo(void);

    int16_t sendCmdviaHttp(const String& request); //overwrite
    String getResponse(void){ return _response; }
    
    void extractSettingsFromResponse(String& settings_str);
    void extractCleanedSettingsFromResponse(String& settings_str);
    bool extractSettingValueFromResponse(const char* no, String& value);
    bool extractModifiedSettingsFromResponse(void);
    bool extractModifiedSettingsFromResponse(const char* no, String& modified_settings, String& settings_current);
    
    bool extractStatusValueFromResponse(const char* no, String& value);

    void debugOn(void){ _debug_previous = _debug; _debug = true; };
    void debugRestore(void){ _debug = _debug_previous; };
    void debugPort(HardwareSerial* debug_port){};

  private:
    WiFiClient _wifiClient;
    WiFiUDP _udpClient;
    String _ssid;
    String _password;
    
    uint8_t _mac[MAC_ADDRESS_LENGTH];
    bool _mac_isvalid;

    bool _debug_previous;

    unsigned long _heartbeat_next_ms;
    unsigned long _keepalive_rate_ms;
    unsigned long _keepalive_next_ms;

    bool _startup_wol; //flag to say if a WoL should be attempted at WiFi connection
    uint16_t _startup_task;
    unsigned long _startup_task_next_ms;
    bool _startup_ok;

    bool _is_connected_to_client; //this is updated by each call of connectClient()
    bool _is_connected_to_client_last;

    //this keeps the last HTTP request
    String _request; 
    String _response;
    uint16_t _response_code;
    
    String _settings_last;
};


owGoPro::owGoPro(const String ssid, const String password, bool debug)
{
    _ssid = ssid;
    _password = password;
    _debug = _debug_previous = debug;
    _mac_isvalid = false;
    _startup_task = 0xFFFF;
    
    _startup_wol = false;

    _keepalive_rate_ms = GOPRO_KEEPALIVE_MS;

    _is_connected_to_client = false;
    _is_connected_to_client_last = false;

    _request.reserve(512); //this is plenty
    _response.reserve(512); //response str can be large
    _settings_last.reserve(512); //settings str can be large
}


void owGoPro::begin(void)
{
    _heartbeat_next_ms = millis() + GOPRO_LOOP_MS;
    _keepalive_next_ms = millis() + _keepalive_rate_ms;

#if defined(ARDUINO_ARCH_ESP8266) // ESP8266
    WiFi.setOutputPower(0.0f); //0 dBm //not available with MKR1000
    WiFi.persistent(false);
    WiFi.mode(WIFI_STA); //this is needed for me
#endif    
#if defined(ARDUINO_ARCH_ESP32)
    WiFi.setTxPower(WIFI_POWER_MINUS_1dBm);
#endif    
    
    WiFi.begin(_ssid.c_str(), _password.c_str());
/*
    while (WiFi.status() != WL_CONNECTED) {
      delay(100);
      Serial.print(".");
    }*/

    //somehow, the MKR1000 won't connect without that line!!!
    if (WiFi.status() == WL_CONNECTED) {
        return;
    }
}


void owGoPro::end(void)
{
    _is_connected_to_client = false;
    _wifiClient.stop();
    _udpClient.stop();
    WiFi.disconnect();
}


bool owGoPro::isConnected(void)
{
    return (WiFi.status() == WL_CONNECTED);
}


void owGoPro::setStartupWoL(bool flag)
{
    _startup_wol = flag;
}


void owGoPro::startupCmds(void)
{
    if (!isConnected()) return;

    if( !_startup_task ) return;

    if( _startup_task == 0xFFFF ) {
        _startup_task_next_ms = 0;
        _startup_ok = true;
    }
    
    unsigned long curtime_ms = millis();
    if( curtime_ms < _startup_task_next_ms ) return;

    if (_startup_task & GOPRO_STARTUPTASK_GETMAC) {
        getMac();
        _startup_task &=~ GOPRO_STARTUPTASK_GETMAC;
        _startup_task_next_ms = curtime_ms + 500;
    }else
    if (_startup_task & GOPRO_STARTUPTASK_SETTINGSLAST) {
        int res = getStatus();
        if( (res == false) && _startup_wol ){ //false indicates _wifiClient.connect() failed, that's what empirically indicates sleeping gopro
            res = sendWoL();
            if( res == true ){
                delay(GOPRO_WOL_WAITTIME_MS);
                res = sendCmd(GOPRO_CMD_SUBMODE_VIDEO_VIDEO);
            }
        }
        if( res == true ){
            extractModifiedSettingsFromResponse();
            _startup_task &=~ GOPRO_STARTUPTASK_SETTINGSLAST;
            _startup_task_next_ms = curtime_ms + 500;
        }else{
            _startup_task = 0;   //TODO: why this ?????
            _startup_ok = false;
        }
    }else
    if (_startup_task & GOPRO_STARTUPTASK_SETAUTOOFFNEVER) {
        int res = sendSettingStr("59/0"); // Auto Off: Never
        if( res != true ) _startup_ok = false;
        _startup_task &=~ GOPRO_STARTUPTASK_SETAUTOOFFNEVER;
        _startup_task_next_ms = curtime_ms + 500;
    }else
    if (_startup_task & GOPRO_STARTUPTASK_EXECUTELIVESTREAMRESTART) {
        int res = executeLivestreamRestart();
        if( res != true ) _startup_ok = false;
        _startup_task &=~ GOPRO_STARTUPTASK_EXECUTELIVESTREAMRESTART;
        _startup_task_next_ms = curtime_ms + 20;
    }else
    if (_startup_task & GOPRO_STARTUPTASK_EXECUTELIVESTREAMSTOP) {
        //that's somehow sad: we must do it shortly after the restart, since otherwise all following
        // connections will fail with "client connection failed". Exeprimentally, then the stream was started, we 
        // always get "client connection failed". No idea why.
        int res = executeLivestreamStop();
        if( res != true ) _startup_ok = false;
        _startup_task &=~ GOPRO_STARTUPTASK_EXECUTELIVESTREAMSTOP;
        _startup_task_next_ms = curtime_ms + 500;

        if( !_startup_ok ) ESP.restart(); //that's brutal
    }else
    if (_startup_task & GOPRO_STARTUPTASK_CMDSUBMODEVIDEOVIDEO) {
        int res = sendCmd(GOPRO_CMD_SUBMODE_VIDEO_VIDEO); //sendCmd(GOPRO_CMD_MODE_VIDEO);
        if( res != true ) _startup_ok = false;
        _startup_task &=~ GOPRO_STARTUPTASK_CMDSUBMODEVIDEOVIDEO;
        _startup_task_next_ms = curtime_ms + 500;
    }else
    if (_startup_task & GOPRO_STARTUPTASK_CMDSHUTTEROFF) {
        sendCmd(GOPRO_CMD_SHUTTER_OFF); //can return 500 instead of true
        _startup_task &=~ GOPRO_STARTUPTASK_CMDSHUTTEROFF;
        _startup_task_next_ms = curtime_ms + 500;
        
        _keepalive_next_ms = curtime_ms + _keepalive_rate_ms; //bring keepalive into sync
        _startup_task = 0;
    }
}


void owGoPro::loop(void)
{
    if (!isConnected()) _is_connected_to_client = false; 

    if( isConnected() && _is_connected_to_client && (_is_connected_to_client_last != _is_connected_to_client) ){
        _startup_task = 0xFFFF;
    }
    _is_connected_to_client_last = _is_connected_to_client;

    startupCmds();

    unsigned long curtime_ms = millis();
  
    if( curtime_ms > _heartbeat_next_ms ){ 
        while (curtime_ms > _heartbeat_next_ms) _heartbeat_next_ms += GOPRO_LOOP_MS;
        if (WiFi.status() == WL_CONNECTED) { // isConnected()
            GOPRO_DBG("*");
        }else{
            GOPRO_DBG("!");
            _startup_task = 0xFFFF; //clear it so it's redone at each reconnect
#ifdef ARDUINO_SAMD_MKR1000
            //the MKR1000 wants Wifi.begin() to be called again and again
            // the ESP32 doesn't want this !!!
            begin(); //this also seems to work quite well! Somehow can't put this with the next into a method!?!?!
#endif      
        }
    }
  
    if( (_keepalive_rate_ms > 0) && (curtime_ms > _keepalive_next_ms) ){ 
        while (curtime_ms > _keepalive_next_ms) _keepalive_next_ms += _keepalive_rate_ms;
        if (isConnected() && !_startup_task) {
          sendKeepAlive();
        }
    }    
}


bool owGoPro::sendWoL(void)
{
    if (!_mac_isvalid) {
      GOPRO_DBG("gopro MAC is not valid");
      return false;
    }

    GOPRO_DBG("gopro send WoL");
  
    uint8_t preamble[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
    IPAddress addr(255, 255, 255, 255);

    _udpClient.begin(GOPRO_UDP_PORT);
    _udpClient.beginPacket(addr, GOPRO_UDP_PORT);
    _udpClient.write(preamble, 6);
    for (uint8_t i = 0; i < 16; i++) _udpClient.write(_mac, MAC_ADDRESS_LENGTH);
    _udpClient.endPacket();
    _udpClient.stop();

    return true;
}


//this should be called by users
bool owGoPro::wakeUp(void)
{
    bool res = sendWoL();
    if( res == true ){
        delay(GOPRO_WOL_WAITTIME_MS);
        _startup_task = 0xFFFF;
    }
    return res;
}


bool owGoPro::connectClient(void)
{
    if (!isConnected()) {
        _is_connected_to_client = false;
        return false;
    }

    if (_wifiClient.connect(GOPRO_HOST, GOPRO_WIFI_PORT, 100)) { //use WiFiClient internal timeout
        _is_connected_to_client = true;
        return true;
    }
    
    _is_connected_to_client = false;
    return false;
}


bool owGoPro::testConnectionToClient(void)
{
    if (!connectClient()) {
      return false;
    }
    _wifiClient.stop();
    return true;
}


bool owGoPro::isConnectedToClient(void)
{
    return _is_connected_to_client; 
}


int16_t owGoPro::sendKeepAlive(void)
{
    if (!connectClient()) {
      GOPRO_DBG("gopro send keep alive client connection failed");
      return GOPRO_RESULT_NOCONNECTION;
    }

    GOPRO_DBG("gopro send keep alive");

    _wifiClient.println("_GPHD_:0:0:2:0.000000\n");
    _wifiClient.stop();
    return GOPRO_RESULT_OK;
}


//responses
// true = 1: ok
// false = 0: no connection
// -1: timeout
// -value: http error
int16_t owGoPro::sendCmdviaHttp(const String& cmd)
{
//uint32_t t1 = millis();
  
    if (!connectClient()) {
      GOPRO_DBG("gopro client connection failed");
//Serial.println(millis()-t1); 
      return GOPRO_RESULT_NOCONNECTION;
    }

    GOPRO_DBG("gopro client connection successful");

    //send the request per GET
    _request = String("GET ") + cmd + " HTTP/1.1\r\n" +
               "Host: " + GOPRO_HOST + "\r\n" +
               "Connection: Keep-Alive\r\n\r\n";  //"Connection: close\r\n\r\n";
    _wifiClient.print(_request);
    
    //read the response
    _response = "";
  
    uint32_t curtime_ms = millis();
    while ((_wifiClient.available() <= 0) && (curtime_ms + GOPRO_RESPONSE_TIMEOUT_MS > millis())) {
        delay(5);
    }

    if (_wifiClient.available() <= 0) {
      GOPRO_DBG("gopro reading response failed");
      _wifiClient.stop();
      return GOPRO_RESULT_TIMEOUT;
    }
    
    while (_wifiClient.available() > 0) {
        char c = _wifiClient.read();
        _response += c;
    }

    GOPRO_DBG(_response);

    //extract the response code
    int blank_pos = _response.indexOf(" ");
    String str = _response.substring(blank_pos+1);
    _response_code = atoi(str.c_str());

    GOPRO_DBG(_response_code);

    _wifiClient.stop();

//Serial.println(millis()-t1); 

    if (_response_code == 200) return GOPRO_RESULT_OK;
    return -_response_code;
}


void owGoPro::printCredentials(void)
{
    if (!_debug) return;

    GOPRO_DBG("");
    GOPRO_DBG(String("SSID: ") + WiFi.SSID());
    GOPRO_DBG(String("Password: ") + _password);
    GOPRO_DBG(String("IP Address: ") + WiFi.localIP());
    GOPRO_DBG(String("RSSI: ") + WiFi.RSSI() + " dBm");
    uint8_t bmac[MAC_ADDRESS_LENGTH] = {};
    WiFi.macAddress(bmac);
    GOPRO_DBG("WifiBoard MAC:"); printMac(bmac);
    GOPRO_DBG("GoPro MAC:"); if(_mac_isvalid){ printMac(_mac); }else{ GOPRO_DBG("no valid mac"); }
}


bool owGoPro::getMac(void)
{
#if defined(ARDUINO_ARCH_ESP8266) // ESP8266
    return false;
#else
    GOPRO_DBG("gopro get MAC");
    
/*    if (_mac_isvalid) {
      printMac(_mac);
      return true;
    } */

    bool isreverted = false;
#if defined(ARDUINO_ARCH_ESP32)
    uint8_t* mptr = WiFi.BSSID();
    memcpy(_mac, mptr, MAC_ADDRESS_LENGTH);
#else
    WiFi.BSSID(_mac);
    isreverted = true;
#endif

    if (isreverted) {
        for (uint8_t i = 0; i < MAC_ADDRESS_LENGTH / 2; i++) {
            uint8_t m = _mac[i];
            _mac[i] = _mac[MAC_ADDRESS_LENGTH - i - 1];
            _mac[MAC_ADDRESS_LENGTH - i - 1] = m;
        }
    }

    printMac(_mac);
    _mac_isvalid = true;
    return true;
#endif
}


void owGoPro::setMac(const uint8_t mac[])
{
    for (uint8_t i = 0; i < MAC_ADDRESS_LENGTH; i++) _mac[i] = mac[i];
    printMac(_mac);
    _mac_isvalid = true;
}


bool owGoPro::macIsValid(void)
{
    return _mac_isvalid;
}


void owGoPro::printMac(const uint8_t mac[])
{
    if (!_debug) return;

    uint8_t c;
    char mac_str[20];
    uint8_t pos = 0;
    for (uint8_t i = 0; i < MAC_ADDRESS_LENGTH; i++) {
        c = (mac[i] & 0xF0) >> 4;
        mac_str[pos++] = ( c <= 9 ) ? '0'+c : 'a'+c-10;
        c = (mac[i] & 0x0F);
        mac_str[pos++] = ( c <= 9 ) ? '0'+c : 'a'+c-10;
        if (i < MAC_ADDRESS_LENGTH-1) mac_str[pos++] = ':';
    }
    mac_str[pos++] = '\0';
    GOPRO_DBG(mac_str);
}


int16_t owGoPro::getMacfromInfo(void)
{
    GOPRO_DBG("gopro get MAC from info");

/*    if (_mac_isvalid) {
      printMac(_mac);
      return true;
    } */

    int16_t res = sendCmdviaHttp("/gp/gpControl/info");
    if (res != GOPRO_RESULT_OK) return res;

    //find ap_mac entry in response
    int ap_mac_pos = _response.indexOf("ap_mac");
    int mac_start = _response.indexOf(":", ap_mac_pos+1);
    int mac_end = _response.indexOf(",", mac_start+1);
        
    String mac_string = _response.substring(mac_start+2, mac_end-1);
        
    if (mac_string.length() != 2*MAC_ADDRESS_LENGTH) {
        GOPRO_DBG("SHIT");
        return -4242; //return with something hopefully bad
    }
        
    uint8_t mac[MAC_ADDRESS_LENGTH];
    char c;
    for (uint8_t i = 0; i < MAC_ADDRESS_LENGTH; i++) {
        //we could do here some more checks like that each char is in [0..9a..f], or all are lower case, or length is ok, etc. pp
        c = mac_string.charAt(2*i);
        mac[i] = (( c <= '9' ) ? c - '0' : c - 'a' + 10) * 16;
        c = mac_string.charAt(2*i+1);
        mac[i] += ( c <= '9' ) ? c - '0' : c - 'a' + 10;
    }

    memcpy(_mac, mac, MAC_ADDRESS_LENGTH);
    _mac_isvalid = true;

    printMac(mac);
    
    return GOPRO_RESULT_OK;
}


void owGoPro::extractSettingsFromResponse(String& settings_str)
{
    //extract settings json
    int settings_pos = _response.indexOf("settings");
    int settings_start = _response.indexOf("{", settings_pos+1);
    int settings_end = _response.indexOf("}", settings_start+1);
    _response.setCharAt(settings_end, ','); //this is needed to get the last value right

    settings_str = _response.substring(settings_start, settings_end+2);
}


//like extractSettingsFromResponse(), but cleanes up the string to xx/xx,
void owGoPro::extractCleanedSettingsFromResponse(String& settings_str)
{
    //extract settings json
    int settings_pos = _response.indexOf("settings");
    int settings_start = _response.indexOf("{", settings_pos+1);
    int settings_end = _response.indexOf("}", settings_start+1);
    _response.setCharAt(settings_end, ','); //this is needed to get the last value right

    settings_str = _response.substring(settings_start, settings_end+2);

//Serial.println(settings_str);
    settings_str.replace("\"",""); //remove "
    settings_str.replace(":","/"); //remove :
    settings_str.replace("{",""); //remove {
    settings_str.replace("}",""); //remove }
}


bool owGoPro::extractSettingValueFromResponse(const char* no, String& value)
{
    //extract settings json
    int settings_pos = _response.indexOf("settings");
    int settings_start = _response.indexOf("{", settings_pos+1);
    int settings_end = _response.indexOf("}", settings_start+1);
    _response.setCharAt(settings_end, ','); //this is needed to get the last value right, no problem here in doing this

    //extract setting value
    String search = "\""; search += no; search += "\":";
    int no_pos = _response.indexOf(search, settings_start);
    if( (no_pos < 0) || (no_pos > settings_end) ){
        return false; //unknown
    }
    int value_start = _response.indexOf(":", no_pos);
    int value_end = _response.indexOf(",", value_start);
    value = _response.substring(value_start+1, value_end);
    return true;
}


// extracts all modified seetings
// returns xx/xx,yy/yy, etc., 
// puts the setting with no in first place if there is one
bool owGoPro::extractModifiedSettingsFromResponse(void)
{
    extractCleanedSettingsFromResponse(_settings_last); 
    return true;
}

bool owGoPro::extractModifiedSettingsFromResponse(const char* no, String& modified_settings, String& settings_current)
{
    modified_settings = "";
  
    extractCleanedSettingsFromResponse(settings_current); 

    if( _settings_last.length() == 0 ){ //no last yet set
      _settings_last = settings_current;
      return false;
    }

    if( _settings_last != settings_current ){
      String _str; _str.reserve(32);
      String _set; _set.reserve(512);
      
      int spos_last = 0;
      int s2pos_last = 0;
      int spos = settings_current.indexOf(",");
      int s2pos = _settings_last.indexOf(",");

      while( spos < settings_current.length() ){
        String s = settings_current.substring(spos_last, spos);
        String s2 = _settings_last.substring(s2pos_last, s2pos);

        if( s != s2 ){
          // get no in s
          char sno[32]; 
          for(uint16_t i=0; i<s.length(); i++) { sno[i] = s.charAt(i); if( sno[i] == '/' ){ sno[i] = '\0'; break; } }
          // compare with no
          if( !strcmp(no,sno) ) {
            _str = s; 
          }else{
            _set += s; _set += ","; 
          }
        }

        spos_last = spos+1;
        s2pos_last = s2pos+1;
        spos = settings_current.indexOf(",", spos_last);
        s2pos = _settings_last.indexOf(",", s2pos_last);
      }

      if( _str.length() != 0 ){ 
        modified_settings = _str;
        modified_settings += ",";
      }
      modified_settings += _set;
    }
    
    _settings_last = settings_current;
    return true;
}


bool owGoPro::extractStatusValueFromResponse(const char* no, String& value)
{
    //extract status json
    int status_pos = _response.indexOf("status");
    int status_start = _response.indexOf("{", status_pos+1);
    int status_end = _response.indexOf("}", status_start+1);
    _response.setCharAt(status_end, ','); //this is needed to get the last value right
    _response.setCharAt(status_end+1, '}'); //needed to avoid a bug then the function is called repeatedly
    //extract status value
    String search = "\""; search += no; search += "\":";
    int no_pos = _response.indexOf(search, status_start);
    if( (no_pos < 0) || (no_pos > status_end) ){
         return false;
    }
    int value_start = _response.indexOf(":", no_pos);
    int value_end = _response.indexOf(",", value_start);
    value = _response.substring(value_start+1, value_end);
    return true;
}


