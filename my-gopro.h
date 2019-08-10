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


#define GOPRO_DBG(x)  if(_debug){Serial.println(x);}


/*
ESP8266 and MKR1000 behave differently in many aspects!

the ESP8266 seems to do it's WiFi stuff in the background
the MKR1000 in contrast kind of not

e.g. WiFi.Status == WL_CONNECTED
it changes for the ESP8266 when e.g. teh gopro is swicthed off/goes to sleep
for the MKR1000 it doesn't chnage except after startup

e.g. _wifiClient.connect()
this seems to have a hardwired timeout for MKR1000 and blocks for many seconds if there is no WLAN

e.g. a WiFi.disconnect() in setup at first place I found very helpfull for the ESP8266, but the MKR1000 won't work

=> how to detect that a WLAN connection is still valid for teh MKR100 withput blocking ????
*/

/* MKR1000 behavior
   it seems it connects to a WLAN only at startup
   it can detect if WLAN goes away, but can't reconnect when the WLAN is back again
*/


//some global settings

#define GOPRO_RESPONSE_TIMEOUT_MS  2000
#define GOPRO_LOOP_MS  1000
#define GOPRO_KEEPALIVE_MS  1512


//some GoPro credentials

#define GOPRO_HOST  "10.5.5.9"
#define GOPRO_WIFI_PORT  80
#define GOPRO_UDP_PORT  9


//include Arduino library

#include <Arduino.h>


//some globally useful constants

#define MAC_ADDRESS_LENGTH  6


//include the WiFi library

#if defined(ARDUINO_ARCH_ESP32) // ESP32
#  include <WiFi.h>
#elif defined(ARDUINO_ARCH_ESP8266) // ESP8266
#  include <ESP8266WiFi.h>
#elif defined(ARDUINO_SAMD_MKR1000) // MKR1000
#  include <WiFi101.h>
#else
#  error "Not supported board"
#endif


//inlcude the UDP library

#include <WiFiUdp.h>


// include the appropriate file

#if defined(ARDUINO_ARCH_ESP32) // ESP32
#  include "my-gopro-esp32.h"
//#elif defined(ARDUINO_ARCH_ESP8266) // ESP8266
//#  include "my-gopro-esp8266.h"
//#elif defined(ARDUINO_SAMD_MKR1000) // MKR1000
//#  include "my-gopro-mkr1000.h"
#else
#  error "Not supported board"
#endif


