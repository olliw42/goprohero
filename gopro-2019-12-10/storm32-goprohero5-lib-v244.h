//generated 2019-11-02 10:30:33.138812

#define GOPRO_DBG(x)


#ifndef MAVCAMERA_GOPROHERO5_NAME
  #define MAVCAMERA_GOPROHERO5_NAME        "STorM32 GoPro Hero5"
#endif
#ifndef MAVCAMERA_GOPROHERO5_URI
  #define MAVCAMERA_GOPROHERO5_URI         MAVCAMERA_URI MAVCAMERA_GOPROHERO5_XMLNAME
#endif


//--------------------------------------
// MAVCAMERA PARAMETERS
//--------------------------------------

#define MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5  46

typedef struct {
  uint16_t cam_mode;
  uint16_t VideoResolution;                   // 2
  uint16_t VideoFrameRate;                    // 3
  uint16_t VideoFov;                          // 4
  uint16_t VideoColor;                        // 12
  uint16_t VideoWhiteBalance;                 // 11
  uint16_t VideoIso;                          // 13
  uint16_t VideoShutter;                      // 73
  uint16_t VideoEvComp;                       // 15
  uint16_t VideoSharpness;                    // 14
  uint16_t VideoRawAudioTrack;                // 81
  uint16_t VideoProtune;                      // 10
  uint16_t VideoEis;                          // 78
  uint16_t VideoAutoLowLight;                 // 8
  uint16_t VideoManualAudioControl;           // 80
  uint16_t VideoPhotoInterval;                // 7
  uint16_t VideoLoopingInterval;              // 6
  uint16_t PhotoFov;                          // 17
  uint16_t PhotoColor;                        // 23
  uint16_t PhotoWhiteBalance;                 // 22
  uint16_t PhotoIsoMin;                       // 75
  uint16_t PhotoIsoMax;                       // 24
  uint16_t PhotoShutter;                      // 97
  uint16_t PhotoEvComp;                       // 26
  uint16_t PhotoSharpness;                    // 25
  uint16_t PhotoProtune;                      // 21
  uint16_t PhotoWdr;                          // 77
  uint16_t PhotoRawFormat;                    // 82
  uint16_t PhotoNightShutter;                 // 19
  uint16_t PhotoBurstRate;                    // 29
  uint16_t MultishotTimelapseVideoInterval;   // 5
  uint16_t MultishotTimelapsePhotoInterval;   // 30
  uint16_t MultishotNightlapsePhotoInterval;  // 32
  uint16_t VoiceControl;                      // 86
  uint16_t VoiceControlLanguage;              // 85
  uint16_t BeepVolume;                        // 87
  uint16_t Led;                               // 91
  uint16_t Quickcapture;                      // 54
  uint16_t DefaultMode;                       // 89
  uint16_t AutoOff;                           // 59
  uint16_t Screensaver;                       // 51
  uint16_t Brightness;                        // 88
  uint16_t AutoRotation;                      // 52
  uint16_t Gps;                               // 83
  uint16_t Language;                          // 84
  uint16_t VideoFormat;                       // 57
} tMavCameraParameters_GoProHero5;
tMavCameraParameters_GoProHero5 _mavcameraparams_goprohero5;

const tMavCameraSetupParameter MavCameraParameters_GoProHero5[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  { (uint8_t*)&_mavcameraparams_goprohero5.cam_mode, MAV_PARAM_TYPE_UINT8, "CAM_MODE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoResolution,                   MAV_PARAM_TYPE_UINT16,  "VID_RESOLUTION" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoFrameRate,                    MAV_PARAM_TYPE_UINT16,  "VID_FRAMERATE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoFov,                          MAV_PARAM_TYPE_UINT16,  "VID_FOV" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoColor,                        MAV_PARAM_TYPE_UINT16,  "VID_COLOR" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoWhiteBalance,                 MAV_PARAM_TYPE_UINT16,  "VID_WHITEBALAN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoIso,                          MAV_PARAM_TYPE_UINT16,  "VID_ISO" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoShutter,                      MAV_PARAM_TYPE_UINT16,  "VID_SHUTTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoEvComp,                       MAV_PARAM_TYPE_UINT16,  "VID_EVCOMP" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoSharpness,                    MAV_PARAM_TYPE_UINT16,  "VID_SHARPNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoRawAudioTrack,                MAV_PARAM_TYPE_UINT16,  "VID_RAWAUDIOTRAC" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoProtune,                      MAV_PARAM_TYPE_UINT16,  "VID_PROTUNE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoEis,                          MAV_PARAM_TYPE_UINT16,  "VID_EIS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoAutoLowLight,                 MAV_PARAM_TYPE_UINT16,  "VID_AUTOLOWLIGHT" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoManualAudioControl,           MAV_PARAM_TYPE_UINT16,  "VID_MANUAAUDIOCO" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoPhotoInterval,                MAV_PARAM_TYPE_UINT16,  "VID_PHOTOINTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoLoopingInterval,              MAV_PARAM_TYPE_UINT16,  "VID_LOOPIINTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoFov,                          MAV_PARAM_TYPE_UINT16,  "PHO_FOV" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoColor,                        MAV_PARAM_TYPE_UINT16,  "PHO_COLOR" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoWhiteBalance,                 MAV_PARAM_TYPE_UINT16,  "PHO_WHITEBALAN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoIsoMin,                       MAV_PARAM_TYPE_UINT16,  "PHO_ISOMIN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoIsoMax,                       MAV_PARAM_TYPE_UINT16,  "PHO_ISOMAX" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoShutter,                      MAV_PARAM_TYPE_UINT16,  "PHO_SHUTTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoEvComp,                       MAV_PARAM_TYPE_UINT16,  "PHO_EVCOMP" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoSharpness,                    MAV_PARAM_TYPE_UINT16,  "PHO_SHARPNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoProtune,                      MAV_PARAM_TYPE_UINT16,  "PHO_PROTUNE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoWdr,                          MAV_PARAM_TYPE_UINT16,  "PHO_WDR" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoRawFormat,                    MAV_PARAM_TYPE_UINT16,  "PHO_RAWFORMA" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoNightShutter,                 MAV_PARAM_TYPE_UINT16,  "PHO_NIGHTSHUTT" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoBurstRate,                    MAV_PARAM_TYPE_UINT16,  "PHO_BURSTRATE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.MultishotTimelapseVideoInterval,   MAV_PARAM_TYPE_UINT16,  "MUL_TIMELVIDEOIN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.MultishotTimelapsePhotoInterval,   MAV_PARAM_TYPE_UINT16,  "MUL_TIMELPHOTOIN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.MultishotNightlapsePhotoInterval,  MAV_PARAM_TYPE_UINT16,  "MUL_NIGHTPHOTOIN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VoiceControl,                      MAV_PARAM_TYPE_UINT16,  "VOI_CONTROL" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VoiceControlLanguage,              MAV_PARAM_TYPE_UINT16,  "VOI_CONTRLANGU" },
  { (uint16_t*)&_mavcameraparams_goprohero5.BeepVolume,                        MAV_PARAM_TYPE_UINT16,  "BEE_VOLUME" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Led,                               MAV_PARAM_TYPE_UINT16,  "LED" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Quickcapture,                      MAV_PARAM_TYPE_UINT16,  "QUICKCAPTURE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.DefaultMode,                       MAV_PARAM_TYPE_UINT16,  "DEF_MODE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.AutoOff,                           MAV_PARAM_TYPE_UINT16,  "AUT_OFF" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Screensaver,                       MAV_PARAM_TYPE_UINT16,  "SCREENSAVER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Brightness,                        MAV_PARAM_TYPE_UINT16,  "BRIGHTNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.AutoRotation,                      MAV_PARAM_TYPE_UINT16,  "AUT_ROTATION" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Gps,                               MAV_PARAM_TYPE_UINT16,  "GPS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Language,                          MAV_PARAM_TYPE_UINT16,  "LANGUAGE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoFormat,                       MAV_PARAM_TYPE_UINT16,  "VID_FORMAT" },
};

void goprohero5_default_parameters(void)
{
  memset( &_mavcameraparams_goprohero5, 0, sizeof(_mavcameraparams_goprohero5) );

  _mavcameraparams_goprohero5.VideoResolution = 9;
  _mavcameraparams_goprohero5.VideoFrameRate = 5;
  _mavcameraparams_goprohero5.VideoIso = 1;
  _mavcameraparams_goprohero5.VideoEvComp = 4;
  _mavcameraparams_goprohero5.VideoSharpness = 1;
  _mavcameraparams_goprohero5.VideoRawAudioTrack = 3;
  _mavcameraparams_goprohero5.VideoProtune = 1;
  _mavcameraparams_goprohero5.VideoManualAudioControl = 2;
  _mavcameraparams_goprohero5.PhotoIsoMin = 3;
  _mavcameraparams_goprohero5.PhotoIsoMax = 4;
  _mavcameraparams_goprohero5.PhotoEvComp = 4;
  _mavcameraparams_goprohero5.PhotoProtune = 1;
};


//--------------------------------------
// SETTINGS
//--------------------------------------

const char* GoProHero5Setting_str[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  "",
  "2","3","4","12","11","13","73","15","14","81","10","78","8","80","7","6","17","23","22","75",
  "24","97","26","25","21","77","82","19","29","5","30","32","86","85","87","91","54","89","59","51","88",
  "52","83","84","57",
};

const uint16_t GoProHero5Setting_u16[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  UINT16_MAX,
  2,3,4,12,11,13,73,15,14,81,10,78,8,80,7,6,17,23,22,75,
  24,97,26,25,21,77,82,19,29,5,30,32,86,85,87,91,54,89,59,51,88,
  52,83,84,57,
 };


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

const char* GoProHero5Command[GOPRO_CMD_MAX] = {
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


//-------------------------------------------------------
// GOPRO HAL
//-------------------------------------------------------
// forward declarations

inline void gopro_hal_putbuf(uint8_t* buf, uint16_t len);
inline uint16_t gopro_hal_rx_available(void);
inline char gopro_hal_getc(void);
inline void gopro_hal_rx_flush(void);


#define GOPRO_BUF_SIZE    128


//--------------------------------------
// STATE HANDLERS
//--------------------------------------

typedef enum {
  GOPROSTATE_IDLE = 0,
  GOPROSTATE_RECEIVE,
  GOPROSTATE_RECEIVE_COMPLETED,
} GOPROSTATEENUM;


typedef struct {
  uint16_t cmd; //that's the command for which we wait for the response
  uint16_t settingid; //that's the settingid used by that command, if it has one

  uint16_t state;
  uint16_t len;

  uint16_t buf_len;
  uint8_t buf[GOPRO_BUF_SIZE];

  char response_char;
  uint32_t response_value_u32;

} tGoPro;
tGoPro _gopro;


void gopro_init(void)
{
  _gopro.state = GOPROSTATE_IDLE;
}


void gopro_receive_trigger(void)
{
  _gopro.buf_len = 0;
  _gopro.state = GOPROSTATE_RECEIVE;
  _gopro.response_char = 't';

  gopro_hal_rx_flush();

/*
  _gopro.buf[0] = 'o';
  _gopro.buf_len = 1;
  _gopro.response_value_u32 = 12;
  _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;  */
}


//to check if the response has been received, and clear to idle
uint16_t gopro_isreceived(void)
{
  if( _gopro.state >= GOPROSTATE_RECEIVE_COMPLETED ){
    _gopro.state = GOPROSTATE_IDLE;
    return 1;
  }
  return 0;
}


void gopro_do(void)
{
uint8_t c;

  if( !_gopro.state ) return; //quick way out

  switch( _gopro.state ){
    case GOPROSTATE_IDLE:
    case GOPROSTATE_RECEIVE_COMPLETED:
        break;

    case GOPROSTATE_RECEIVE:
        if( !gopro_hal_rx_available() ) return;
        c = gopro_hal_getc();
        _gopro.buf[_gopro.buf_len++] = c;
        if( (c == 'o') || (c == 't') || (c == 'e') || (c == 'n') || (c == 'u') ){
          if( c == 'o' ){
            _gopro.buf[_gopro.buf_len-1] = '\0'; //to make atoi() to work
            _gopro.response_value_u32 = atoi((char*)_gopro.buf);
            _gopro.buf[_gopro.buf_len-1] = c; //fill in back the original
          }
          _gopro.response_char = c;
          _gopro.buf[_gopro.buf_len] = '\0'; //so that also str functions can be used
          _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;

GOPRO_DBG(MAV_PUTS("  gp:");MAV_PUTBUF(_gopro.buf,_gopro.buf_len);MAV_PUTC(' ');
MAV_PUTS(utoBCD_s(_gopro.response_value_u32));MAV_PUTC('\n');)
        }
        break;
  }
}


//-------------------------------------------------------
// GOPRO user calls
//-------------------------------------------------------

void goprohero5_getsetting_byindex(uint16_t index)
{
  if( (index < 1) || (index >= MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5) ){
    _gopro.buf[0] = 'i'; //index error
    _gopro.buf_len = 1;
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "get");
  strcat(s, GoProHero5Setting_str[index]);
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpGs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero5_setsetting_byindex(uint16_t index, uint32_t value)
{
  if( (index < 1) || (index >= MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5) ){
    _gopro.buf[0] = 'i'; //index error
    _gopro.buf_len = 1;
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "set");
  strcat(s, GoProHero5Setting_str[index]);
  strcat(s, "/");
  strcat(s, utoBCD_s(value));
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpSs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero5_setandchecksetting_byindex(uint16_t index, uint32_t value)
{
  if( (index < 1) || (index >= MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5) ){
    _gopro.buf[0] = 'i'; //index error
    _gopro.buf_len = 1;
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "setchk");
  strcat(s, GoProHero5Setting_str[index]);
  strcat(s, "/");
  strcat(s, utoBCD_s(value));
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpSacs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero5_cmd(uint16_t cmd)
{
  if( cmd >= GOPRO_CMD_MAX ){
    _gopro.buf[0] = 'i'; //index error
    _gopro.buf_len = 1;
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "cmd");
  strcat(s, GoProHero5Command[cmd]);
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpC:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero5_getbattery(void)
{
  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "battery2\n");

GOPRO_DBG(MAV_PUTS("  gpGb2:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero5_parse_battery(uint16_t* battery_available, uint16_t* battery_status, uint16_t* battery_percentage, uint8_t* buf, uint16_t buf_len)
{
  *battery_available = 0;
  *battery_status = 0;
  *battery_percentage = 0;
/*  uint16_t i = 0;  //this doesn't work for some reason I didn't see, batterystatus is 0, and batterypercentage too large
  for(; i<buf_len; i++){
    if( buf[i] == ',' ) break;
    if( (buf[i] >= '0') && (buf[i] <= '9') ) *battery_available = buf[i] - '0';
  }
  for(; i<buf_len; i++){
    if( buf[i] == ',' ) break;
    if( (buf[i] >= '0') && (buf[i] <= '9') ) *battery_status = buf[i] - '0';
  }
  for(; i<buf_len; i++){
    if( (buf[i] >= '0') && (buf[i] <= '9') ) *battery_percentage = (*battery_percentage)*10 + (buf[i] - '0');
  }
*/
  uint16_t nr = 0;
  for( uint16_t i=0; i<buf_len; i++){
    if( buf[i] == ',' ){ nr++; continue; }
    if( (buf[i] >= '0') && (buf[i] <= '9') ){
      if( nr == 0 ) *battery_available = buf[i] - '0';
      if( nr == 1 ) *battery_status = buf[i] - '0';
      if( nr == 2 ) *battery_percentage = (*battery_percentage)*10 + (buf[i] - '0');
    }
  }
}


void goprohero5_getcapacity(void)
{
  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "capacity\n");

GOPRO_DBG(MAV_PUTS("  gpGc:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero5_parse_sdcardcapacity(uint16_t* sdcard_inserted, uint32_t* memory_available, uint8_t* buf, uint16_t buf_len)
{
  //memory_available is in kBytes
  // format of capacity command is x,xxxxxxxxxxo

  *sdcard_inserted = 0;
  *memory_available = 0;

  uint16_t i = 0;
  for(; i<buf_len; i++){
    if( buf[i] == ',' ) break;
    if( (buf[i] >= '0') && (buf[i] <= '9') ) *sdcard_inserted = (*sdcard_inserted)*10 + (buf[i] - '0');
  }
  for(; i<buf_len; i++){
    if( (buf[i] >= '0') && (buf[i] <= '9') ) *memory_available = (*memory_available)*10 + (buf[i] - '0');
  }
}
