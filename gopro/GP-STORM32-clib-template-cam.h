//--------------------------------------
// MAVCAMERA GOPRO HERO$$$GOPRO_NO$$$
//--------------------------------------

#define MAVCAMERA_GOPROHERO$$$GOPRO_NO$$$_VERSION       $$$GOPRO_VERSION$$$

#ifndef MAVCAMERA_GOPROHERO$$$GOPRO_NO$$$_NAME
  #define MAVCAMERA_GOPROHERO$$$GOPRO_NO$$$_NAME        "STorM32 GoPro Hero$$$GOPRO_NO$$$"
#endif

#ifndef MAVCAMERA_GOPROHERO$$$GOPRO_NO$$$_URI
  #define MAVCAMERA_GOPROHERO$$$GOPRO_NO$$$_URI         MAVCAMERA_URI MAVCAMERA_GOPROHERO$$$GOPRO_NO$$$_XMLNAME
#endif

// MAVCAMERA PARAMETERS

#define MAVCAMERA_PARAMETER_ZAHL_GOPROHERO$$$GOPRO_NO$$$  $$$GOPRO_PARAMETER_ZAHL$$$

typedef struct {
  uint16_t cam_mode;
$$$GOPRO_PARAMETERS$$$
} tMavCameraParameters_GoProHero$$$GOPRO_NO$$$;
tMavCameraParameters_GoProHero$$$GOPRO_NO$$$ _mavcameraparams_goprohero$$$GOPRO_NO$$$;

const tMavCameraSetupParameter MavCameraParameters_GoProHero$$$GOPRO_NO$$$[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO$$$GOPRO_NO$$$] = {
  { (uint8_t*)&_mavcameraparams_goprohero$$$GOPRO_NO$$$.cam_mode, MAV_PARAM_TYPE_UINT8, "CAM_MODE" },
$$$GOPRO_SETUP_PARAMETERS$$$
};

void goprohero$$$GOPRO_NO$$$_default_parameters(void)
{
  memset( &_mavcameraparams_goprohero$$$GOPRO_NO$$$, 0, sizeof(_mavcameraparams_goprohero$$$GOPRO_NO$$$) );

$$$GOPRO_DEFAULTS$$$
};

// SETTINGS

const char* GoProHero$$$GOPRO_NO$$$Setting_str[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO$$$GOPRO_NO$$$] = {
  "",
$$$GOPRO_SETTING_STR$$$
};

const uint16_t GoProHero$$$GOPRO_NO$$$Setting_u16[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO$$$GOPRO_NO$$$] = {
  UINT16_MAX,
$$$GOPRO_SETTING_U16$$$
};
 