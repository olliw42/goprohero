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

#ifndef MYHELPER_PRINT
#  define MYHELPER_PRINT(x)  x  
#endif


//-------------------------------------------------------
// BLINK functions
//-------------------------------------------------------

#if defined(ARDUINO_SAMD_MKR1000) // MKR1000
# define BLINK_PIN   6
#endif
#if defined(ARDUINO_ARCH_ESP32) // ESP32
# define BLINK_PIN   13
#endif


bool blink_ison;
unsigned long blink_rate_ms;
unsigned long blink_next_ms;


void blink_init(void)
{
#ifdef BLINK_PIN
  pinMode(BLINK_PIN, OUTPUT);
  blink_rate_ms = 1000;
  blink_next_ms = 0;
  blink_ison = false;
  digitalWrite(BLINK_PIN, LOW);
#endif
}


void blink_toggle(void)
{
#ifdef BLINK_PIN
  if( blink_ison ){
    digitalWrite(BLINK_PIN, HIGH);
    blink_ison = false;
  }else{
    digitalWrite(BLINK_PIN, LOW);
    blink_ison = true;
  }
#endif  
}


void blink_rate(unsigned long rate_ms)
{
  blink_rate_ms = rate_ms;
}


void blink_do(unsigned long curtime_ms)
{
#ifdef BLINK_PIN
  if( curtime_ms > blink_next_ms ){ 
    //blink_next_ms += blink_rate_ms;
    blink_next_ms = (curtime_ms/blink_rate_ms)*blink_rate_ms + blink_rate_ms;
    blink_toggle();
  }
#endif  
}


//-------------------------------------------------------
// CLI functions
//-------------------------------------------------------

#define CLI_TIMEOUT_MS  25

typedef struct{
  uint16_t bufpos;
  char buf[64];
  unsigned long tmo;
} tCli;
tCli cli;


void cli_init(void)
{
  cli.bufpos = 0;
  cli.tmo = 0;
}


void cli_do(unsigned long curtime_ms)
{
  if( curtime_ms > cli.tmo ){ 
    cli.bufpos = 0;
  }
}


char cli_getc(void)
{
  char c = (char)Serial.read(); //this returns an int!
  cli.tmo = millis() + CLI_TIMEOUT_MS;
  cli.buf[cli.bufpos++] = c;
  if( cli.bufpos > 56 ) cli.bufpos = 56;
  return c;
}


bool cli_isenter(char c)
{
  if( (c == '\r') || (c == '\n') || (c == ';' ) ){
    cli.buf[cli.bufpos++] = '\0';
    cli.bufpos = 0;
    return true;
  }
  return false;
}


bool cli_bufiscmd(char* cmd)
{
  if( !strncmp(cli.buf, cmd, strlen(cmd)) ){
    MYHELPER_PRINT(Serial.print( cmd ); Serial.print( "\r\n" );)
    cli.buf[0] = '\0';
    return true;
  }
  return false;
}


bool cli_bufiscmdstr(char* cmd, char* str)
{
  if( !strncmp(cli.buf, cmd, strlen(cmd)) ){
    strcpy(str, cli.buf + strlen(cmd));
    if( str[0] != '\0' ) str[strlen(str)-1] = '\0';
    MYHELPER_PRINT(Serial.print( cmd ); Serial.print( " " ); Serial.print( str ); Serial.print( "\r\n" );)
    cli.buf[0] = '\0';
    return true;
  }
  return false;
}


bool cli_bufissetcmds16(char* cmdstr, int16_t* value)
{
  if( !strncmp(cli.buf, cmdstr, strlen(cmdstr)) ){
    char* argstr = cli.buf + strlen(cmdstr);
    int16_t v = atoi(argstr);
    *value = v;
    MYHELPER_PRINT(Serial.print( cmdstr ); Serial.print( " " ); Serial.print( v ); Serial.print( "\r\n" );)
    cli.buf[0] = '\0';
    return true;
  }
  return false;
}


bool cli_bufissetcmds32(char* cmdstr, int32_t* value)
{
  if( !strncmp(cli.buf, cmdstr, strlen(cmdstr)) ){
    char* argstr = cli.buf + strlen(cmdstr);
    int32_t v = atol(argstr);
    *value = v;
    MYHELPER_PRINT(Serial.print( cmdstr ); Serial.print( " " ); Serial.print( v ); Serial.print( "\r\n" );)
    cli.buf[0] = '\0';
    return true;
  }
  return false;
}


bool cli_bufissetcmdtwos16(char* cmdstr, int16_t* value1, int16_t* value2)
{
  if( !strncmp(cli.buf, cmdstr, strlen(cmdstr)) ){
    char* argstr = cli.buf + strlen(cmdstr);
    int16_t v = atoi(argstr);
    *value1 = v;
    uint16_t i = 0;
    for(i=0; i<strlen(argstr); i++){
      if( argstr[i] == ',' ) break;
    }
    if( i > strlen(argstr) ) return false;
    char* arg2str = argstr + i;
    v = atoi(argstr);
    *value2 = v;
    MYHELPER_PRINT(Serial.print( cmdstr ); Serial.print( " " + String(*value1) + " , " + String(*value2)); Serial.print( "\r\n" );)
    cli.buf[0] = '\0';
    return true;
  }
  return false;
}



