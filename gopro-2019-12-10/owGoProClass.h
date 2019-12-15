#ifndef OWGOPROCLASS_H
#define OWGOPROCLASS_H
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
   
  This program makes use of the tremendous work of KonradIT
  see <https://github.com/KonradIT/goprowifihack>.
*/
/*
  C++ class owGoProClass
  
  version 2019-07-21
*/


//--------------------------------------
// Defines
//--------------------------------------

#define GOPRO_CONTROL  "/gp/gpControl/"
#define GOPRO_COMMAND  "command/"
#define GOPRO_SETTING  "setting/"

#define GOPRO_CONTROLCOMMAND  GOPRO_CONTROL GOPRO_COMMAND
#define GOPRO_CONTROLSETTING  GOPRO_CONTROL GOPRO_SETTING


//--------------------------------------
// COMMANDS
//--------------------------------------

typedef enum {
  GOPRO_CMD_MODE_VIDEO = 0,               // 0
  GOPRO_CMD_MODE_PHOTO,                   // 1
  GOPRO_CMD_MODE_MULTISHOT,               // 2
  GOPRO_CMD_SUBMODE_VIDEO_VIDEO,          // 3   //0,0  VIDEO menu
  GOPRO_CMD_SUBMODE_VIDEO_TIMELAPSE,      // 4   //0,1  is in LAPSE menu!!!  "TIME LAPSE VIDEO"
  GOPRO_CMD_SUBMODE_VIDEO_VIDEOPLUSPHOTO, // 5   //0,2  VIDEO menu
  GOPRO_CMD_SUBMODE_VIDEO_LOOPING,        // 6   //0,3  VIDEO menu
  GOPRO_CMD_SUBMODE_PHOTO_SINGLE,         // 7   //1,1  PHOTO menu
  GOPRO_CMD_SUBMODE_PHOTO_NIGHT,          // 8   //1,2  PHOTO menu
  GOPRO_CMD_SUBMODE_MULTISHOT_BURST,      // 9   //2,0  is in PHOTO menu!!!  "BURST"
  GOPRO_CMD_SUBMODE_MULTISHOT_TIMELPAPSE, // 10  //2,1  is in LAPSE menu!!!  "TIME LAPSE PHOTO"
  GOPRO_CMD_SUBMODE_MULTISHOT_NIGHTLAPSE, // 11  //2,2  is in LAPSE menu!!!  "NIGHT LAPSE PHOTO"
  GOPRO_CMD_SHUTTER_OFF,                  // 12
  GOPRO_CMD_SHUTTER_ON,                   // 13
  GOPRO_CMD_LOCATE_OFF,                   // 14
  GOPRO_CMD_LOCATE_ON,                    // 15
  GOPRO_CMD_TAG,                          // 16
  GOPRO_CMD_SLEEP,                        // 17
  GOPRO_CMD_MAX
} GOPROCMDENUM;

const char* GOPRO_CMD_STR[GOPRO_CMD_MAX] = {
  "mode?p=0", "mode?p=1", "mode?p=2",
  "sub_mode?mode=0&sub_mode=0", "sub_mode?mode=0&sub_mode=1", "sub_mode?mode=0&sub_mode=2", "sub_mode?mode=0&sub_mode=3",
  "sub_mode?mode=1&sub_mode=1", "sub_mode?mode=1&sub_mode=2", 
  "sub_mode?mode=2&sub_mode=0", "sub_mode?mode=2&sub_mode=1", "sub_mode?mode=2&sub_mode=2",
  "shutter?p=0", "shutter?p=1",
  "system/locate?p=0", "system/locate?p=1",
  "storage/tag_moment", 
  "system/sleep", 
};


//--------------------------------------
// STATUS
//--------------------------------------

typedef enum {
  GOPRO_STATUS_BATTERY_AVAILABLE = 1,
  GOPRO_STATUS_BATTERY_LEVEL = 2,
  GOPRO_STATUS_RECORDING = 8,
  GOPRO_STATUS_STREAMING = 32,
  GOPRO_STATUS_SDCARD_INSERTED = 33,
  GOPRO_STATUS_PHOTOS_REMAINING = 34,
  GOPRO_STATUS_VIDEOTIME_REMAINING = 35,
  GOPRO_STATUS_MODE = 43,
  GOPRO_STATUS_SUBMODE = 44,
  GOPRO_STATUS_MEMORY_AVAILABLE = 54,
} GOPROSTATUSENUM;

typedef enum {
  GOPRO_STATUS_BATTERY_AVAILABLE_NO = 0,
  GOPRO_STATUS_BATTERY_AVAILABLE_YES = 1,
} GOPROSTATUSBATTERYAVAILABLEENUM;

typedef enum {
  GOPRO_STATUS_BATTERY_LEVEL_EMPTY = 0,
  GOPRO_STATUS_BATTERY_LEVEL_LOW = 2,
  GOPRO_STATUS_BATTERY_LEVEL_HALFWAY = 3,
  GOPRO_STATUS_BATTERY_LEVEL_FULL = 4,
  GOPRO_STATUS_BATTERY_LEVEL_CHARGING = 5,
} GOPROSTATUSBATTERYLEVELENUM;

typedef enum {
  GOPRO_STATUS_RECORDING_OFF = 0,
  GOPRO_STATUS_RECORDING_ON = 1,
} GOPROSTATUSRECORDINGENUM;

typedef enum {
  GOPRO_STATUS_STREAMING_OFF = 0,
  GOPRO_STATUS_STREAMING_ON = 1,
} GOPROSTATUSSTREAMINGENUM;

typedef enum {
  GOPRO_STATUS_SDCARD_INSERTED_YES = 0,
  GOPRO_STATUS_SDCARD_INSERTED_NO = 2,
} GOPROSTATUSSDCARDENUM;


//--------------------------------------
// owGoPro Class
//--------------------------------------

class owGoProClass
{
  public:
    owGoProClass(bool debug = false);
  
    virtual int16_t sendCmdviaHttp(const String& request) = 0;

    int16_t getInfo(void);
    int16_t getStatus(void);
    
    int16_t executeLivestreamStop(void);
    int16_t executeLivestreamRestart(void);

    int16_t sendCmdStr(const String& str);
    int16_t sendSettingStr(const String& str);

    int16_t sendCmd(uint16_t cmd);
    virtual void trackCmd(uint16_t cmd){};
    
    int16_t cmdShutterOn(void);
    int16_t cmdShutterOff(void);
    
  protected:
    bool _debug;
};

//--------------------------------------
// general methods

owGoProClass::owGoProClass(bool debug)
{
    _debug = debug;
}


int16_t owGoProClass::getInfo(void)
{
    GOPRO_DBG("gopro get info");
    return sendCmdviaHttp("/gp/gpControl/info");
}


int16_t owGoProClass::getStatus(void)
{
    GOPRO_DBG("gopro get status");
    return sendCmdviaHttp("/gp/gpControl/status");
}


int16_t owGoProClass::executeLivestreamStop(void)
{
    GOPRO_DBG("gopro execute livestream stop");
    return sendCmdviaHttp("/gp/gpControl/execute?p1=gpStream&a1=proto_v2&c1=stop");
}


int16_t owGoProClass::executeLivestreamRestart(void)
{
    GOPRO_DBG("gopro execute livestream restart");
    return sendCmdviaHttp("/gp/gpControl/execute?p1=gpStream&a1=proto_v2&c1=restart");
}

int16_t owGoProClass::sendCmdStr(const String& str)
{ 
    String req= String(GOPRO_CONTROLCOMMAND);
    req += str;
    GOPRO_DBG(req);
    return sendCmdviaHttp(req);
}

int16_t owGoProClass::sendSettingStr(const String& str)
{ 
    String req = String(GOPRO_CONTROLSETTING);
    req += str;
    GOPRO_DBG(req);
    return sendCmdviaHttp(req);
}

//--------------------------------------
// command methods

int16_t owGoProClass::sendCmd(uint16_t cmd)
{ 
    if( cmd < GOPRO_CMD_MAX ){
        String req = String(GOPRO_CONTROLCOMMAND);
        req += GOPRO_CMD_STR[cmd];
        GOPRO_DBG(req);
        int16_t res = sendCmdviaHttp(req);
        if( res == true ) trackCmd(cmd); //track mode changes
        return res;
    }
}

int16_t owGoProClass::cmdShutterOn(void)
{ 
    GOPRO_DBG("gopro shutter on");
    return sendCmd(GOPRO_CMD_SHUTTER_ON);
}
    
int16_t owGoProClass::cmdShutterOff(void)
{ 
    GOPRO_DBG("gopro shutter off");
    return sendCmd(GOPRO_CMD_SHUTTER_OFF);
}


#endif
//end of owGoProClass
  

