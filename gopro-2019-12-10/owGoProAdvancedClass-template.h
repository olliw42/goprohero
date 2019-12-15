#ifndef OWGOPROADVANCEDCLASS_H
#define OWGOPROADVANCEDCLASS_H
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
  C++ class owGoProAdvancedClass
  
$$$GOPROVERSION$$$
*/


#include "owGoProClass.h"

//--------------------------------------
// owGoPro Advanced Class
//--------------------------------------

//--------------------------------------
// SETTINGS
//--------------------------------------

$$$GOPROSETTINGS$$$

class owGoProAdvancedClass: public owGoProClass
{
    int16_t setSetting(uint16_t setting);

$$$GOPROMETHODPROTOTYPES$$$
};

//--------------------------------------
// setting methods

int16_t owGoProAdvancedClass::setSetting(uint16_t setting)
{ 
    if( setting < GOPRO_SET_MAX ){
        String req = String(GOPRO_CONTROLSETTING) + GOPRO_SET_STR[setting];
        GOPRO_DBG(req);
        int16_t res = sendCmdviaHttp(req);
        return res;
    }
}

$$$GOPROMETHODHS$$$

#endif
//end of owGoProAdvancedClass
  

