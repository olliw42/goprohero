
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

#define MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5  $$$GOPRO_PARAMETER_ZAHL$$$

typedef struct {
  uint16_t cam_mode;
$$$GOPRO_PARAMETERS$$$
} tMavCameraParameters_GoProHero5;
tMavCameraParameters_GoProHero5 _mavcameraparams_goprohero5;

const tMavCameraSetupParameter MavCameraParameters_GoProHero5[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  { (uint8_t*)&_mavcameraparams_goprohero5.cam_mode, MAV_PARAM_TYPE_UINT8, "CAM_MODE" },
$$$GOPRO_SETUP_PARAMETERS$$$
};

void goprohero5_default_parameters(void)
{
  memset( &_mavcameraparams_goprohero5, 0, sizeof(_mavcameraparams_goprohero5) );

$$$GOPRO_DEFAULTS$$$
};


//--------------------------------------
// SETTINGS
//--------------------------------------

const char* GoProHero5Setting_str[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  "",
$$$GOPRO_SETTING_STR$$$
};

const uint16_t GoProHero5Setting_u16[MAVCAMERA_PARAMETER_ZAHL_GOPROHERO5] = {
  UINT16_MAX,
$$$GOPRO_SETTING_U16$$$
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
