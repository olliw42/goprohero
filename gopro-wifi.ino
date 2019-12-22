
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

#define GOPRO_SSID "GP........"      // Wifi name (SSID)videoon;
#define GOPRO_PASS ".........."      // WiFi password

#define VERSION_STR "(c) olliw.eu, v2019-12-21"


//for debugging
#define MAIN_PRINT(x) 
#define MYHELPER_PRINT(x)   
#define GOPRO_DBG_ENABLED  false //false true


#include "my-helpers.h"
#include "my-gopro.h"


owGoPro gopro(GOPRO_SSID, GOPRO_PASS, GOPRO_DBG_ENABLED);


void setup()
{
  blink_init();
  cli_init();
  Serial.begin(115200);
#if defined(ARDUINO_ARCH_ESP32)
  //this is important: see https://forums.adafruit.com/viewtopic.php?f=57&t=153553
  pinMode(3, INPUT_PULLUP);
#endif  

  gopro.debugPort(&Serial);
  //this in combination with the begin() in loop() works very well !!  
  gopro.begin();
  //gopro.startupCmds();

  Serial.println();
  Serial.print("Hello, I'm gopro-wifi "); Serial.println(VERSION_STR);
  Serial.print("esp8266 started\r\n"); //this is to make use of the STorM32's ESP startup transmit block 
}


void serialPrintClose(int16_t res)
{
  if( res == true ) { 
    Serial.print('o'); //ok
  } else if( res == false ) { 
    Serial.print('n'); //not connected
  } else if( res == GOPRO_RESULT_TIMEOUT ) { 
    Serial.print('t'); //timeout
  } else if( res == GOPRO_RESULT_UNKNOWN ) { 
    Serial.print('u'); //unknown
  }else{ 
    Serial.print('e'); //error  //http error, or setting error, setting error reports actual setting xx/xxe
  }
}  


#if 1
//-----------------------------------------
// normal loop
//-----------------------------------------

void loop()
{
int16_t value1, value2;
char str[256];
int16_t mode_last = -1; //this is to handle shutter/videoon/videooff in a hopefully smart way
  
  unsigned long curtime_ms = millis();
  //blink_rate( (gopro.isConnected()) ? 1000 : 100 );
  blink_rate( (gopro.isConnectedToClient()) ? 1000 : 100 );
  blink_do(curtime_ms);
  cli_do(curtime_ms);

  gopro.loop();
  
  bool done = false; //this is to accept only one command per loop, we also could do it with a break, but it's nicer so
  
  while( Serial.available() && (done == false) ){
    char c = cli_getc();
    MAIN_PRINT(Serial.print(c);)

    if( cli_isenter(c) ){
      done = true;

      if( cli_bufiscmd("info") )            {gopro.debugOn();gopro.getInfo();gopro.debugRestore();}
      if( cli_bufiscmd("status") )          {gopro.debugOn();gopro.getStatus();gopro.debugRestore();}
      if( cli_bufiscmd("maci") )            {gopro.debugOn();gopro.getMacfromInfo();gopro.debugRestore();} //must come before getmac
      if( cli_bufiscmd("mac") )             {gopro.debugOn();gopro.getMac();gopro.debugRestore();}
      if( cli_bufiscmd("credentials") )     {gopro.debugOn();gopro.printCredentials();gopro.debugRestore();}
      if( cli_bufiscmd("wol") )             serialPrintClose(gopro.wakeUp());

      if( cli_bufiscmd("lsstart") )         gopro.executeLivestreamRestart();
      if( cli_bufiscmd("lsstop") )          gopro.executeLivestreamStop();

//      if( cli_bufissetcmds16("cmd",&value1) )       gopro.sendCmd(value1);
//      if( cli_bufissetcmds16("setting",&value1) )   gopro.setSetting(value1);

      if( cli_bufiscmd("shoot") )           gopro.cmdShutterOn();
      if( cli_bufiscmd("recon") )           gopro.cmdShutterOn();
      if( cli_bufiscmd("recoff") )          gopro.cmdShutterOff();

      //STorM32:
      
      if( cli_bufiscmd("ping") ) {
          int16_t res = gopro.testConnectionToClient();
          serialPrintClose(res);
      }
      
      //not currently used by STorM32
      if( cli_bufiscmd("reset") ) {
          serialPrintClose(true);
          delay(100); //give it 100ms to send the response
          ESP.restart();
      }
  
      // these try to get the mode correctly done
      // alternatively, one could accepts that one can't switch to photo when a video is recording
      // this could be captured by an additional flag
      // surely relies on a known starting condition, which appers to be however well given by the wifi connection handling
      if( cli_bufiscmd("shutter") ) {
          int16_t res = true;
          if( mode_last != GOPRO_CMD_SUBMODE_PHOTO_SINGLE ) { 
            res = gopro.cmdShutterOff();
            res = gopro.sendCmd(GOPRO_CMD_SUBMODE_PHOTO_SINGLE);
            delay(500); //it needs some time otherwise the shutter is missed
          }
          if( res == true ){ 
            mode_last = GOPRO_CMD_SUBMODE_PHOTO_SINGLE;
            res = gopro.cmdShutterOn();
          }  
          //doesn't respond  serialPrintClose(res);
      }
      if( cli_bufiscmd("videoon") ) {
          int16_t res = true;
          if( mode_last != GOPRO_CMD_SUBMODE_VIDEO_VIDEO ) res = gopro.sendCmd(GOPRO_CMD_SUBMODE_VIDEO_VIDEO);
          if( res == true ){ 
            mode_last = GOPRO_CMD_SUBMODE_VIDEO_VIDEO; 
            res = gopro.cmdShutterOn();
          }  
          //doesn't respond  serialPrintClose(res);
      }
      if( cli_bufiscmd("videooff") ) {
          int16_t res = true;
          if( mode_last != GOPRO_CMD_SUBMODE_VIDEO_VIDEO ) res = gopro.sendCmd(GOPRO_CMD_SUBMODE_VIDEO_VIDEO);
          if( res == true ){ 
            mode_last = GOPRO_CMD_SUBMODE_VIDEO_VIDEO; 
            res = gopro.cmdShutterOff();
          }  
          //doesn't respond  serialPrintClose(res);
      }

      //not currently used by STorM32
      if( cli_bufiscmd("video") ) {
          int16_t res = gopro.sendCmd(GOPRO_CMD_SUBMODE_VIDEO_VIDEO);
          serialPrintClose(res);
      }
      //not currently used by STorM32
      if( cli_bufiscmd("photo") ) {
          int16_t res = gopro.sendCmd(GOPRO_CMD_SUBMODE_PHOTO_SINGLE);
          serialPrintClose(res);
      }
      //not currently used by STorM32
      if( cli_bufiscmdstr("cmd",str) ) {
          int16_t res = gopro.sendCmdStr(String(str));
          serialPrintClose(res);
      }

      if( cli_bufissetcmds16("setzoom",&value1) ) {
          String cmd_str = GOPRO_CMD_STR[GOPRO_CMD_ZOOMRANGE]; //"digital_zoom?range_pcnt="
          cmd_str += String(value1);
          int16_t res = gopro.sendCmdStr(cmd_str);
          serialPrintClose(res);
      }

      //responses:
      // 'n','t'
      // 'e' : http error, initialization error
      // 'u' : unknown no
      // 'xx/xx,xx/xxe' : setting error, reports all actual settings, no/val is in first place, it was wrong an gave the 'e'
      // 'o' : seting ok
      // 'xx/xx,xx/xxo' : setting ok, reports all additionally modified settings, no/val is not in there
      if( cli_bufiscmdstr("setchk",str) ) {
          int16_t res = gopro.sendSettingStr(String(str)); //can return -500
          if( (res == true) || (res == -500) ) { //now check it
            res = gopro.getStatus();
            if( res == true ) { // disect status and check obtained value
                // split str into no
                char no[32];
                for(uint16_t i=0; i<strlen(str); i++) { no[i] = str[i]; if( no[i] == '/' ) { no[i] = '\0'; break; } }
                // get modified settings
                String modified_settings_str, settings_str;
                res = gopro.extractModifiedSettingsFromResponse(no, modified_settings_str, settings_str);
                if( res != true ) { 
                    res = GOPRO_RESULT_ERROR; //initialization error, should never happen
                }else
                if( modified_settings_str.length() == 0 ){ //if there is no change, modified_settings_str has zero length
                    //check if no exists
                    String search = no; search += "/";
                    int no_pos = settings_str.indexOf(search);
                    if( no_pos < 0 ){
                      res = GOPRO_RESULT_UNKNOWN;
                    }else{
                      //check if requested change had been accepted //this can happen when a no with wrong value was send
                      int value_end = settings_str.indexOf(",", no_pos);
                      String str_res = settings_str.substring(no_pos, value_end);
                      if( str_res != str ){
                        Serial.print(str_res);
                        res = GOPRO_RESULT_ERROR; //setting error, report actual setting
                      }
                    }
                }else{  
                    //check if no exists
                    String search = no; search += "/";
                    int no_pos = modified_settings_str.indexOf(search);
                    if( no_pos < 0 ){
                      res = GOPRO_RESULT_UNKNOWN;
                    }else{ 
                      //check if requested change had been accepted
                      int value_end = modified_settings_str.indexOf(",", no_pos);
                      String str_res = modified_settings_str.substring(no_pos, value_end);
                      modified_settings_str = modified_settings_str.substring(0,modified_settings_str.length()-1); //chop ','
                      if( str_res != str ){
                        Serial.print(modified_settings_str);
                        res = GOPRO_RESULT_ERROR; //setting error, report all actual settings
                      }else{
                        //the desired change is ok, chop it off
                        modified_settings_str = modified_settings_str.substring(value_end+1);
                        if( modified_settings_str.length() > 0 ) Serial.print(modified_settings_str);
                      }
                    }
                }
            } //end of if getStatus()==true
          }
          serialPrintClose(res);
      }

      if( cli_bufiscmdstr("set",str) ) {
          int16_t res = gopro.sendSettingStr(String(str));
          serialPrintClose(res);
      }
      
      //not currently used by STorM32
      if( cli_bufiscmdstr("getall",str) ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String settings_str;
            gopro.extractCleanedSettingsFromResponse(settings_str); 
            Serial.print(settings_str); 
          }
          serialPrintClose(res);
      }

      if( cli_bufiscmdstr("get",str) ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String value_str;
            if( !gopro.extractSettingValueFromResponse(str, value_str) ) {
              res = GOPRO_RESULT_UNKNOWN; //unknown setting no
            } else {
              Serial.print(value_str); 
            }
          }
          serialPrintClose(res);
      }

      //not currently used by STorM32
      if( cli_bufiscmdstr("stat",str) ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String value_str;
            if( !gopro.extractStatusValueFromResponse(str, value_str) ) {
              res = GOPRO_RESULT_UNKNOWN; //unknown setting no
            } else {
              Serial.print(value_str); 
            }
          }
          serialPrintClose(res);
      }

      if( cli_bufiscmd("capacity") ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String sdcard_inserted, memory_available;
            if( !gopro.extractStatusValueFromResponse("33", sdcard_inserted) || !gopro.extractStatusValueFromResponse("54", memory_available) ) {
              res = GOPRO_RESULT_UNKNOWN; //unknown setting no //should never happen
            } else {
              Serial.print(sdcard_inserted);
              Serial.print(',');
              Serial.print(memory_available);
            }
          }
          serialPrintClose(res);
      }

      if( cli_bufiscmd("battery2") ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String battery_available, battery_level, battery_percentage;
            if( !gopro.extractStatusValueFromResponse("1", battery_available) || 
                !gopro.extractStatusValueFromResponse("2", battery_level) || 
                !gopro.extractStatusValueFromResponse("70", battery_percentage)) {
              res = GOPRO_RESULT_UNKNOWN; //unknown setting no //should never happen
            } else {
              Serial.print(battery_available);
              Serial.print(',');
              Serial.print(battery_level);
              Serial.print(',');
              Serial.print(battery_percentage);
            }
          }
          serialPrintClose(res);
      }
      
      if( cli_bufiscmd("battery") ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String battery_available, battery_level;
            if( !gopro.extractStatusValueFromResponse("1", battery_available) || !gopro.extractStatusValueFromResponse("2", battery_level) ) {
              res = GOPRO_RESULT_UNKNOWN; //unknown setting no //should never happen
            } else {
              Serial.print(battery_available);
              Serial.print(',');
              Serial.print(battery_level);
            }
          }
          serialPrintClose(res);
      }
      
      //not currently used by STorM32
      if( cli_bufiscmd("mode") ) {
          int16_t res = gopro.getStatus();
          if( res == true ) {
            String mode_str, submode, recording;
            if( !gopro.extractStatusValueFromResponse("43", mode_str) || !gopro.extractStatusValueFromResponse("44", submode) || 
                !gopro.extractStatusValueFromResponse("8", recording) ) {
              res = GOPRO_RESULT_UNKNOWN; //unknown setting no //should never happen
            } else {
              Serial.print(mode_str);
              Serial.print(',');
              Serial.print(submode);
              Serial.print(',');
              Serial.print(recording);
            }
          }
          serialPrintClose(res);
      }

    } //end of if(cli_isenter(c))
  } //end of while()
}



#else
//-----------------------------------------
// check changes in settings
// this helps to sort out the correct setting no-ers and value ranges
//-----------------------------------------

unsigned long next_ms = 0;
String settings_previous;

void loop()
{
  unsigned long curtime_ms = millis();

  blink_rate( (gopro.isConnected()) ? 500 : 100 );
  blink_do(curtime_ms);
  cli_do(curtime_ms);

  if( curtime_ms > next_ms ){ 
    next_ms += 1000;
    if( !gopro.isConnected() ) return;
    int16_t res = gopro.getStatus();
    //if( res != true ) return;

    String settings;
    gopro.extractSettingsFromResponse(settings);

    if( (settings_previous != settings) && (settings_previous.length() > 0) ){
      Serial.println("CHANGE!");
      
      int spos_last = 0;
      int s2pos_last = 0;
      int spos = settings.indexOf(",");
      int s2pos = settings_previous.indexOf(",");

      while( spos < settings.length() ){
        String s = settings.substring(spos_last, spos);
        String s2 = settings_previous.substring(s2pos_last, s2pos);

        if( s != s2 ){
          Serial.print(s); Serial.print(" (was "); Serial.print(s2); Serial.println(")");
        }
        
        spos_last = spos;
        s2pos_last = s2pos;
        spos = settings.indexOf(",", spos_last+1);
        s2pos = settings_previous.indexOf(",", s2pos_last+1);
      }
     
    }
    settings_previous = settings;
  }

  gopro.debugOn();
  char str[256];
  while( Serial.available() ){
    char c = cli_getc();
    Serial.print(c);
    if( cli_isenter(c) ){
      if( cli_bufiscmd("info") )            gopro.getInfo();
      if( cli_bufiscmd("status") )          gopro.getStatus();
      if( cli_bufiscmdstr("cmd",str) )      gopro.sendCmdStr(String(str));
      if( cli_bufiscmdstr("set",str) )      gopro.sendSettingStr(String(str));
      if( cli_bufiscmdstr("get",str) ) {
          if( gopro.getStatus() == true ) {
            String value_str;
            gopro.extractSettingValueFromResponse(str, value_str);
            Serial.print(value_str); 
          }
      }
    }  
  } //end of while()
  gopro.debugRestore();

}
#endif
