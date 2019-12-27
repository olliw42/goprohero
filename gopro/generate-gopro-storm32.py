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
  reads the json str files, generated with generate-settings-jsons.py
     - requires 'gp-heroX-settings-json.txt'
  generates the desired XML camera definition file
'''

import re
import json
import datetime

from generate_gopro_lib import *


STORM32VERSION = 249

VERSIONS = [248,248]

cameras = ["Hero5","Hero7"]   #ONLY for GoPro cameras !!!!



''' generate XML files '''
   
for i in range(len(cameras)):
    camera = cameras[i]
    version = VERSIONS[i]
    
    xml = generateSTorM32CamDefXMLForCamera(camera, version)
    
    xmlfilename = 'storm32_camdef_gopro'+camera.lower()+'_v'+str(version)+'.xml'
    F = open(xmlfilename, "w", encoding='utf8') #encoding is important, since otherwise the ° lead to errors
    F.write(xml)
    F.close() 

    

''' generate C code file '''
    
codeoutputfilename = "storm32-gopro-clib" #extension will be added
   
code_h = generateSTorM32Lib(cameras, VERSIONS)

outputfilename = codeoutputfilename
for i in range(len(cameras)):
    outputfilename += "-"+cameras[i].lower()+"-v"+str(VERSIONS[i])
outputfilename += "--v"+str(STORM32VERSION)+".h"
    
F = open(outputfilename, "w", encoding='utf8') #encoding is important, since otherwise the ° lead to errors
F.write("//STorM32 version v"+str(STORM32VERSION)+"\n")
F.write(code_h)
F.close() 
    
