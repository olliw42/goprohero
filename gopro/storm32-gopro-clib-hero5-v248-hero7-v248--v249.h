//STorM32 version v249
//generated 2019-12-27 18:22:51.508740

#define GOPRO_DBG(x)


//--------------------------------------
// MAVCAMERA GOPRO HERO5
//--------------------------------------

#define MAVCAMERA_GOPROHERO5_VERSION       248

#ifndef MAVCAMERA_GOPROHERO5_NAME
  #define MAVCAMERA_GOPROHERO5_NAME        "STorM32 GoPro Hero5"
#endif

#ifndef MAVCAMERA_GOPROHERO5_URI
  #define MAVCAMERA_GOPROHERO5_URI         MAVCAMERA_URI MAVCAMERA_GOPROHERO5_XMLNAME
#endif

// MAVCAMERA PARAMETERS

#define MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5  43

typedef struct {
  uint16_t cam_mode;
  uint16_t VideoResolution;          //1   no = 2
  uint16_t VideoFrameRate;           //2   no = 3
  uint16_t VideoFov;                 //3   no = 4
  uint16_t VideoColor;               //4   no = 12
  uint16_t VideoWhiteBalance;        //5   no = 11
  uint16_t VideoIso;                 //6   no = 13
  uint16_t VideoShutter;             //7   no = 73
  uint16_t VideoEvComp;              //8   no = 15
  uint16_t VideoSharpness;           //9   no = 14
  uint16_t VideoRawAudioTrack;       //10  no = 81
  uint16_t VideoProtune;             //11  no = 10
  uint16_t VideoEis;                 //12  no = 78
  uint16_t VideoAutoLowLight;        //13  no = 8
  uint16_t VideoManualAudioControl;  //14  no = 80
  uint16_t VideoPhotoInterval;       //15  no = 7
  uint16_t VideoLoopingInterval;     //16  no = 6
  uint16_t PhotoFov;                 //17  no = 17
  uint16_t PhotoColor;               //18  no = 23
  uint16_t PhotoWhiteBalance;        //19  no = 22
  uint16_t PhotoIsoMin;              //20  no = 75
  uint16_t PhotoIsoMax;              //21  no = 24
  uint16_t PhotoShutter;             //22  no = 97
  uint16_t PhotoEvComp;              //23  no = 26
  uint16_t PhotoSharpness;           //24  no = 25
  uint16_t PhotoProtune;             //25  no = 21
  uint16_t PhotoWdr;                 //26  no = 77
  uint16_t PhotoRawFormat;           //27  no = 82
  uint16_t PhotoNightShutter;        //28  no = 19
  uint16_t PhotoBurstRate;           //29  no = 29
  uint16_t VoiceControl;             //30  no = 86
  uint16_t VoiceControlLanguage;     //31  no = 85
  uint16_t BeepVolume;               //32  no = 87
  uint16_t Led;                      //33  no = 91
  uint16_t Quickcapture;             //34  no = 54
  uint16_t DefaultMode;              //35  no = 89
  uint16_t AutoOff;                  //36  no = 59
  uint16_t Screensaver;              //37  no = 51
  uint16_t Brightness;               //38  no = 88
  uint16_t AutoRotation;             //39  no = 52
  uint16_t Gps;                      //40  no = 83
  uint16_t Language;                 //41  no = 84
  uint16_t VideoFormat;              //42  no = 57
} tMavCameraParameters_GoProHero5;
tMavCameraParameters_GoProHero5 _mavcameraparams_goprohero5;

const tMavCameraSetupParameter MavCameraParameters_GoProHero5[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  { (uint8_t*)&_mavcameraparams_goprohero5.cam_mode, MAV_PARAM_TYPE_UINT8, "CAM_MODE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoResolution,          MAV_PARAM_TYPE_UINT16,  "VID_RESOLUTION" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoFrameRate,           MAV_PARAM_TYPE_UINT16,  "VID_FRAMERATE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoFov,                 MAV_PARAM_TYPE_UINT16,  "VID_FOV" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoColor,               MAV_PARAM_TYPE_UINT16,  "VID_COLOR" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoWhiteBalance,        MAV_PARAM_TYPE_UINT16,  "VID_WHITEBALAN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoIso,                 MAV_PARAM_TYPE_UINT16,  "VID_ISO" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoShutter,             MAV_PARAM_TYPE_UINT16,  "VID_SHUTTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoEvComp,              MAV_PARAM_TYPE_UINT16,  "VID_EVCOMP" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoSharpness,           MAV_PARAM_TYPE_UINT16,  "VID_SHARPNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoRawAudioTrack,       MAV_PARAM_TYPE_UINT16,  "VID_RAWAUDIOTRAC" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoProtune,             MAV_PARAM_TYPE_UINT16,  "VID_PROTUNE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoEis,                 MAV_PARAM_TYPE_UINT16,  "VID_EIS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoAutoLowLight,        MAV_PARAM_TYPE_UINT16,  "VID_AUTOLOWLIGHT" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoManualAudioControl,  MAV_PARAM_TYPE_UINT16,  "VID_MANUAAUDIOCO" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoPhotoInterval,       MAV_PARAM_TYPE_UINT16,  "VID_PHOTOINTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoLoopingInterval,     MAV_PARAM_TYPE_UINT16,  "VID_LOOPIINTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoFov,                 MAV_PARAM_TYPE_UINT16,  "PHO_FOV" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoColor,               MAV_PARAM_TYPE_UINT16,  "PHO_COLOR" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoWhiteBalance,        MAV_PARAM_TYPE_UINT16,  "PHO_WHITEBALAN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoIsoMin,              MAV_PARAM_TYPE_UINT16,  "PHO_ISOMIN" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoIsoMax,              MAV_PARAM_TYPE_UINT16,  "PHO_ISOMAX" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoShutter,             MAV_PARAM_TYPE_UINT16,  "PHO_SHUTTER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoEvComp,              MAV_PARAM_TYPE_UINT16,  "PHO_EVCOMP" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoSharpness,           MAV_PARAM_TYPE_UINT16,  "PHO_SHARPNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoProtune,             MAV_PARAM_TYPE_UINT16,  "PHO_PROTUNE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoWdr,                 MAV_PARAM_TYPE_UINT16,  "PHO_WDR" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoRawFormat,           MAV_PARAM_TYPE_UINT16,  "PHO_RAWFORMA" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoNightShutter,        MAV_PARAM_TYPE_UINT16,  "PHO_NIGHTSHUTT" },
  { (uint16_t*)&_mavcameraparams_goprohero5.PhotoBurstRate,           MAV_PARAM_TYPE_UINT16,  "PHO_BURSTRATE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VoiceControl,             MAV_PARAM_TYPE_UINT16,  "VOI_CONTROL" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VoiceControlLanguage,     MAV_PARAM_TYPE_UINT16,  "VOI_CONTRLANGU" },
  { (uint16_t*)&_mavcameraparams_goprohero5.BeepVolume,               MAV_PARAM_TYPE_UINT16,  "BEE_VOLUME" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Led,                      MAV_PARAM_TYPE_UINT16,  "LED" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Quickcapture,             MAV_PARAM_TYPE_UINT16,  "QUICKCAPTURE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.DefaultMode,              MAV_PARAM_TYPE_UINT16,  "DEF_MODE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.AutoOff,                  MAV_PARAM_TYPE_UINT16,  "AUT_OFF" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Screensaver,              MAV_PARAM_TYPE_UINT16,  "SCREENSAVER" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Brightness,               MAV_PARAM_TYPE_UINT16,  "BRIGHTNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.AutoRotation,             MAV_PARAM_TYPE_UINT16,  "AUT_ROTATION" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Gps,                      MAV_PARAM_TYPE_UINT16,  "GPS" },
  { (uint16_t*)&_mavcameraparams_goprohero5.Language,                 MAV_PARAM_TYPE_UINT16,  "LANGUAGE" },
  { (uint16_t*)&_mavcameraparams_goprohero5.VideoFormat,              MAV_PARAM_TYPE_UINT16,  "VID_FORMAT" },
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

// SETTINGS

const char* GoProHero5Setting_str[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  "",
  "2","3","4","12","11","13","73","15","14","81","10","78","8","80","7","6","17","23","22","75",
  "24","97","26","25","21","77","82","19","29","86","85","87","91","54","89","59","51","88","52","83","84",
  "57",
};

const uint16_t GoProHero5Setting_u16[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  UINT16_MAX,
  2,3,4,12,11,13,73,15,14,81,10,78,8,80,7,6,17,23,22,75,
  24,97,26,25,21,77,82,19,29,86,85,87,91,54,89,59,51,88,52,83,84,
  57,
};
 

//--------------------------------------
// MAVCAMERA GOPRO HERO7
//--------------------------------------

#define MAVCAMERA_GOPROHERO7_VERSION       248

#ifndef MAVCAMERA_GOPROHERO7_NAME
  #define MAVCAMERA_GOPROHERO7_NAME        "STorM32 GoPro Hero7"
#endif

#ifndef MAVCAMERA_GOPROHERO7_URI
  #define MAVCAMERA_GOPROHERO7_URI         MAVCAMERA_URI MAVCAMERA_GOPROHERO7_XMLNAME
#endif

// MAVCAMERA PARAMETERS

#define MAVCAMERA_PARAMETER_ZAHL_GOPROHERO7  45

typedef struct {
  uint16_t cam_mode;
  uint16_t VideoAspectRatio;      //1   no = 108
  uint16_t VideoResolution;       //2   no = 2
  uint16_t VideoFps;              //3   no = 3
  uint16_t VideoFov;              //4   no = 4
  uint16_t VideoStabilization;    //5   no = 78
  uint16_t VideoLowLight;         //6   no = 8
  uint16_t VideoShortClip;        //7   no = 107
  uint16_t VideoProtune;          //8   no = 10
  uint16_t VideoShutter;          //9   no = 73
  uint16_t VideoEvComp;           //10  no = 15
  uint16_t VideoIsoMin;           //11  no = 102
  uint16_t VideoIsoMax;           //12  no = 13
  uint16_t VideoWhiteBalance;     //13  no = 11
  uint16_t VideoSharpness;        //14  no = 14
  uint16_t VideoColor;            //15  no = 12
  uint16_t VideoRawAudio;         //16  no = 81
  uint16_t VideoMics;             //17  no = 80
  uint16_t PhotoFov;              //18  no = 17
  uint16_t PhotoSuperphoto;       //19  no = 109
  uint16_t PhotoRaw;              //20  no = 82
  uint16_t PhotoTimer;            //21  no = 105
  uint16_t PhotoProtune;          //22  no = 21
  uint16_t PhotoShutter;          //23  no = 97
  uint16_t PhotoEvComp;           //24  no = 26
  uint16_t PhotoIsoMin;           //25  no = 75
  uint16_t PhotoIsoMax;           //26  no = 24
  uint16_t PhotoWhiteBalance;     //27  no = 22
  uint16_t PhotoSharpness;        //28  no = 25
  uint16_t PhotoColor;            //29  no = 23
  uint16_t VoiceControl;          //30  no = 86
  uint16_t WakeOnVoice;           //31  no = 104
  uint16_t VoiceControlLanguage;  //32  no = 85
  uint16_t BeepVolume;            //33  no = 87
  uint16_t Leds;                  //34  no = 91
  uint16_t QuickCapture;          //35  no = 54
  uint16_t DefaultMode;           //36  no = 89
  uint16_t AutoPowerOff;          //37  no = 59
  uint16_t LandscapeLock;         //38  no = 112
  uint16_t ScreenSaver;           //39  no = 51
  uint16_t Brigthness;            //40  no = 88
  uint16_t Gps;                   //41  no = 83
  uint16_t Language;              //42  no = 84
  uint16_t VideoFormat;           //43  no = 57
  uint16_t VideoCompression;      //44  no = 106
} tMavCameraParameters_GoProHero7;
tMavCameraParameters_GoProHero7 _mavcameraparams_goprohero7;

const tMavCameraSetupParameter MavCameraParameters_GoProHero7[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO7] = {
  { (uint8_t*)&_mavcameraparams_goprohero7.cam_mode, MAV_PARAM_TYPE_UINT8, "CAM_MODE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoAspectRatio,      MAV_PARAM_TYPE_UINT16,  "VID_ASPECRATIO" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoResolution,       MAV_PARAM_TYPE_UINT16,  "VID_RESOLUTION" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoFps,              MAV_PARAM_TYPE_UINT16,  "VID_FPS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoFov,              MAV_PARAM_TYPE_UINT16,  "VID_FOV" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoStabilization,    MAV_PARAM_TYPE_UINT16,  "VID_STABILIZATIO" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoLowLight,         MAV_PARAM_TYPE_UINT16,  "VID_LOWLIGHT" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoShortClip,        MAV_PARAM_TYPE_UINT16,  "VID_SHORTCLIP" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoProtune,          MAV_PARAM_TYPE_UINT16,  "VID_PROTUNE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoShutter,          MAV_PARAM_TYPE_UINT16,  "VID_SHUTTER" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoEvComp,           MAV_PARAM_TYPE_UINT16,  "VID_EVCOMP" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoIsoMin,           MAV_PARAM_TYPE_UINT16,  "VID_ISOMIN" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoIsoMax,           MAV_PARAM_TYPE_UINT16,  "VID_ISOMAX" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoWhiteBalance,     MAV_PARAM_TYPE_UINT16,  "VID_WHITEBALAN" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoSharpness,        MAV_PARAM_TYPE_UINT16,  "VID_SHARPNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoColor,            MAV_PARAM_TYPE_UINT16,  "VID_COLOR" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoRawAudio,         MAV_PARAM_TYPE_UINT16,  "VID_RAWAUDIO" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoMics,             MAV_PARAM_TYPE_UINT16,  "VID_MICS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoFov,              MAV_PARAM_TYPE_UINT16,  "PHO_FOV" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoSuperphoto,       MAV_PARAM_TYPE_UINT16,  "PHO_SUPERPHOTO" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoRaw,              MAV_PARAM_TYPE_UINT16,  "PHO_RAW" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoTimer,            MAV_PARAM_TYPE_UINT16,  "PHO_TIMER" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoProtune,          MAV_PARAM_TYPE_UINT16,  "PHO_PROTUNE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoShutter,          MAV_PARAM_TYPE_UINT16,  "PHO_SHUTTER" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoEvComp,           MAV_PARAM_TYPE_UINT16,  "PHO_EVCOMP" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoIsoMin,           MAV_PARAM_TYPE_UINT16,  "PHO_ISOMIN" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoIsoMax,           MAV_PARAM_TYPE_UINT16,  "PHO_ISOMAX" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoWhiteBalance,     MAV_PARAM_TYPE_UINT16,  "PHO_WHITEBALAN" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoSharpness,        MAV_PARAM_TYPE_UINT16,  "PHO_SHARPNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.PhotoColor,            MAV_PARAM_TYPE_UINT16,  "PHO_COLOR" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VoiceControl,          MAV_PARAM_TYPE_UINT16,  "VOI_CONTROL" },
  { (uint16_t*)&_mavcameraparams_goprohero7.WakeOnVoice,           MAV_PARAM_TYPE_UINT16,  "WAK_ONVOICE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VoiceControlLanguage,  MAV_PARAM_TYPE_UINT16,  "VOI_CONTRLANGU" },
  { (uint16_t*)&_mavcameraparams_goprohero7.BeepVolume,            MAV_PARAM_TYPE_UINT16,  "BEE_VOLUME" },
  { (uint16_t*)&_mavcameraparams_goprohero7.Leds,                  MAV_PARAM_TYPE_UINT16,  "LEDS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.QuickCapture,          MAV_PARAM_TYPE_UINT16,  "QUI_CAPTURE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.DefaultMode,           MAV_PARAM_TYPE_UINT16,  "DEF_MODE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.AutoPowerOff,          MAV_PARAM_TYPE_UINT16,  "AUT_POWEROFF" },
  { (uint16_t*)&_mavcameraparams_goprohero7.LandscapeLock,         MAV_PARAM_TYPE_UINT16,  "LAN_LOCK" },
  { (uint16_t*)&_mavcameraparams_goprohero7.ScreenSaver,           MAV_PARAM_TYPE_UINT16,  "SCR_SAVER" },
  { (uint16_t*)&_mavcameraparams_goprohero7.Brigthness,            MAV_PARAM_TYPE_UINT16,  "BRIGTHNESS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.Gps,                   MAV_PARAM_TYPE_UINT16,  "GPS" },
  { (uint16_t*)&_mavcameraparams_goprohero7.Language,              MAV_PARAM_TYPE_UINT16,  "LANGUAGE" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoFormat,           MAV_PARAM_TYPE_UINT16,  "VID_FORMAT" },
  { (uint16_t*)&_mavcameraparams_goprohero7.VideoCompression,      MAV_PARAM_TYPE_UINT16,  "VID_COMPRESSION" },
};

void goprohero7_default_parameters(void)
{
  memset( &_mavcameraparams_goprohero7, 0, sizeof(_mavcameraparams_goprohero7) );

  _mavcameraparams_goprohero7.VideoAspectRatio = 1;
  _mavcameraparams_goprohero7.VideoResolution = 9;
  _mavcameraparams_goprohero7.VideoFps = 5;
  _mavcameraparams_goprohero7.VideoEvComp = 4;
  _mavcameraparams_goprohero7.VideoIsoMax = 1;
  _mavcameraparams_goprohero7.VideoRawAudio = 3;
  _mavcameraparams_goprohero7.VideoMics = 2;
  _mavcameraparams_goprohero7.PhotoEvComp = 4;
  _mavcameraparams_goprohero7.PhotoIsoMin = 3;
  _mavcameraparams_goprohero7.PhotoIsoMax = 5;
  _mavcameraparams_goprohero7.BeepVolume = 70;
  _mavcameraparams_goprohero7.Leds = 2;
  _mavcameraparams_goprohero7.DefaultMode = 12;
  _mavcameraparams_goprohero7.Brigthness = 70;
};

// SETTINGS

const char* GoProHero7Setting_str[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO7] = {
  "",
  "108","2","3","4","78","8","107","10","73","15","102","13","11","14","12","81","80","17","109","82",
  "105","21","97","26","75","24","22","25","23","86","104","85","87","91","54","89","59","112","51","88","83",
  "84","57","106",
};

const uint16_t GoProHero7Setting_u16[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO7] = {
  UINT16_MAX,
  108,2,3,4,78,8,107,10,73,15,102,13,11,14,12,81,80,17,109,82,
  105,21,97,26,75,24,22,25,23,86,104,85,87,91,54,89,59,112,51,88,83,
  84,57,106,
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
  GOPRO_CMD_ZOOMRANGE,                    // 18
  GOPRO_CMD_MAX
} GOPROCMDENUM;

const char* GoProHeroCommand[GOPRO_CMD_MAX] = {
  "mode?p=0", "mode?p=1", "mode?p=2",
  "sub_mode?mode=0&sub_mode=0", "sub_mode?mode=0&sub_mode=1", "sub_mode?mode=0&sub_mode=2", "sub_mode?mode=0&sub_mode=3",
  "sub_mode?mode=1&sub_mode=1", "sub_mode?mode=1&sub_mode=2",
  "sub_mode?mode=2&sub_mode=0", "sub_mode?mode=2&sub_mode=1", "sub_mode?mode=2&sub_mode=2",
  "shutter?p=0", "shutter?p=1",
  "system/locate?p=0", "system/locate?p=1",
  "storage/tag_moment",
  "system/sleep",
  "digital_zoom?range_pcnt=", //complete with zoom level 0...100
};


//--------------------------------------
// STATUS
//--------------------------------------



//--------------------------------------
// MODELS
//--------------------------------------

typedef enum {
  GOPRO_MODEL_HERO5 = 0,
  GOPRO_MODEL_HERO7,
  GOPRO_MODEL_MAX,
} GOPROMODELENUM;


const uint16_t GoProHeroParameterZahl[2] = {
  MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5,
  MAVCAMERA_PARAMETER_ZAHL_GOPROHERO7,
 };


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

void _goprohero_indexerror(void)
{
  _gopro.buf[0] = 'i'; //index error
  _gopro.buf_len = 1;
  _gopro.response_char = _gopro.buf[0];
  _gopro.buf[_gopro.buf_len] = '\0'; //so that also str functions can be used
}


void goprohero_getsetting_byindex(uint16_t gpmodel, uint16_t index)
{
  if( (index < 1) || (index >= GoProHeroParameterZahl[gpmodel]) ){
    _goprohero_indexerror();
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "get");
  switch(gpmodel){
  case GOPRO_MODEL_HERO5: strcat(s, GoProHero5Setting_str[index]); break;
  case GOPRO_MODEL_HERO7: strcat(s, GoProHero7Setting_str[index]); break;
  }
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpGs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_setsetting_byindex(uint16_t gpmodel, uint16_t index, uint32_t value)
{
  if( (index < 1) || (index >=  GoProHeroParameterZahl[gpmodel]) ){
    _goprohero_indexerror();
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "set");
  switch( gpmodel ){
    case GOPRO_MODEL_HERO5: strcat(s, GoProHero5Setting_str[index]); break;
    case GOPRO_MODEL_HERO7: strcat(s, GoProHero7Setting_str[index]); break;
  }
  strcat(s, "/");
  strcat(s, utoBCD_s(value));
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpSs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_setandchecksetting_byindex(uint16_t gpmodel, uint16_t index, uint32_t value)
{
  if( (index < 1) || (index >=  GoProHeroParameterZahl[gpmodel]) ){
    _goprohero_indexerror();
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "setchk");
  switch( gpmodel ){
    case GOPRO_MODEL_HERO5: strcat(s, GoProHero5Setting_str[index]); break;
    case GOPRO_MODEL_HERO7: strcat(s, GoProHero7Setting_str[index]); break;
  }
  strcat(s, "/");
  strcat(s, utoBCD_s(value));
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpSacs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_cmd(uint16_t cmd)
{
  if( cmd >= GOPRO_CMD_MAX ){
    _goprohero_indexerror();
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "cmd");
  strcat(s, GoProHeroCommand[cmd]);
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpC:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_cmdandchecksettings(uint16_t cmd)
{
  if( cmd >= GOPRO_CMD_MAX ){
    _goprohero_indexerror();
    _gopro.state = GOPROSTATE_RECEIVE_COMPLETED;
    return;
  }

  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "cmdchk");
  strcat(s, GoProHeroCommand[cmd]);
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpCacs:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_ping(void)
{
  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "ping\n");

GOPRO_DBG(MAV_PUTS("  gpP:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_setzoomlevel(uint16_t zoom_level)
{
  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "setzoom");
  strcat(s, utoBCD_s(zoom_level));
  strcat(s, "\n");

GOPRO_DBG(MAV_PUTS("  gpSzl:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_getbattery(void)
{
  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "battery2\n");

GOPRO_DBG(MAV_PUTS("  gpGb2:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_parse_battery(uint16_t* battery_available, uint16_t* battery_status, uint16_t* battery_percentage, uint8_t* buf, uint16_t buf_len)
{
  *battery_available = 0;
  *battery_status = 0;
  *battery_percentage = 0;
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


void goprohero_getcapacity(void)
{
  //compose string
  char* s = (char*)_gopro.buf;
  strcpy(s, "capacity\n");

GOPRO_DBG(MAV_PUTS("  gpGc:");MAV_PUTS(s);)

  //send string and trigger receive
  gopro_hal_putbuf(_gopro.buf, strlen(s));
  gopro_receive_trigger();
}


void goprohero_parse_sdcardcapacity(uint16_t* sdcard_inserted, uint32_t* memory_available, uint8_t* buf, uint16_t buf_len)
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
