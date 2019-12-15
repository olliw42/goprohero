'''
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
'''
'''
  Settings Json Generator
  reads the .cmd files
  converts them into Json structures
  writes them into files
'''

import re

from generate_gopro_lib import *

cameras = ["Hero5","Hero7"]


json_strs = {}
for camera in cameras:
    json_strs[camera] = cvtSettingsToJsonStr(camera)

    #print(json_strs[camera)    
    
    F = open("gp-"+camera.lower()+"-settings-json.txt", "w", encoding='utf8') #encoding is important, since otherwise the ° lead to errors
    F.write(json_strs[camera])
    F.close()
    
    
    
    
