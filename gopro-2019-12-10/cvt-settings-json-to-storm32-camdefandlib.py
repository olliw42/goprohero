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
  camera definition file XML code generator
  1. reads the generated Json ASCII files
     - requires 'settings-json.txt'
     - requires 'resolution-matrix-json.txt'
     generates the desired XML camera definition file
  2. reads the C code template file
     - requires 'storm32-goprohero5-lib-template.h'
     generates the C .h file for STorM32
'''

import re
import json
import datetime


#this is important: is appended to the xml file name
VERSION = 244


jsoninputfilename = "settings-json.txt"
matrixjsoninputfilename = "resolution-matrix-json.txt"
xmloutputfilename = "storm32_camdef_goprohero5" #extension will be added

codetemplateinputfilename = "storm32-goprohero5-lib-template.h"
codeoutputfilename = "storm32-goprohero5-lib" #extension will be added

do_with_matrix_resolution = 0 # enable for "FULL" method, adds parameterranges to VID_RESOLUTION section
do_with_format = 0 # enable for NTSC/PAL method, adds parameterranges to VID_FORMAT section to only handle 60/50, 30/25

    
def make_mavlink_name(name):
    l = name.split(' ')
    print(l)
    n = ''
    
    if len(l) == 1:
        return l[0][:16].upper()

    if len(l) == 2:
        n += l[0][:3]+'_'+l[1]
        return n[:16].upper()
    
    index = 0
    for x in l:
        if index == 0:
            n += x[:3]+'_'
        elif index == 1:
            n += x[:5]
        else:    
            n += x[:5]
        index += 1    

    return n[:16].upper() #'HH'+name


if (1):
    
    F = open(jsoninputfilename, "r")
    json_str = F.read()
    F.close() 
    settings_dict = json.loads(json_str)
    
    F = open(matrixjsoninputfilename, "r")
    matrixjson_str = F.read()
    F.close() 
    matrix_dict = json.loads(matrixjson_str)
    
    '''generate camera definition xml file'''
    print('---------------------------')
    print('generate camera definition xml file')
    
    # uses the original json/dict, i.e. settings_dict
    xml = ''
    xml += '<?xml version="1.0" encoding="UTF-8" ?>\n'
    xml += '<mavlinkcamera>\n'
    xml += '    <definition version="1">\n'
    xml += '        <model>STorM32 Hero5 Black</model>\n'
    xml += '        <vendor>www.olliw.eu</vendor>\n'
    xml += '    </definition>\n'
    xml += '    <parameters>\n'
    xml += '        <!-- control = 0 tells us this should not create an automatic UI control -->\n'
    #-- generate CAM_MODE parameter entry
    xml += '        <parameter name="CAM_MODE" type="uint32" default="1" control="0">\n'
    xml += '            <description>Camera Mode</description>\n'
    xml += '            <options>\n'
    xml += '                <option name="Photo" value="0">\n'
    xml += '                    <exclusions>\n'
    for setting, options in settings_dict.items():
        if re.match(r'Video', options['name']) or re.match(r'Multishot', options['name']) : #only params with 'Video' or 'Multishot' in their name
            setting_mavlink_name = make_mavlink_name(options['name'])
            xml += '                        <exclude>'+setting_mavlink_name+'</exclude>\n'
    xml += '                    </exclusions>\n'
    xml += '                </option>\n'
    xml += '                <option name="Video" value="1">\n'
    xml += '                    <exclusions>\n'
    for setting, options in settings_dict.items():
        if re.match(r'Photo', options['name']) or re.match(r'Multishot', options['name']) : #only params with 'Photo' or 'Multishot' in their name
            setting_mavlink_name = make_mavlink_name(options['name'])
            xml += '                        <exclude>'+setting_mavlink_name+'</exclude>\n'
    xml += '                    </exclusions>\n'
    xml += '                </option>\n'
    xml += '            </options>\n'
    xml += '        </parameter>\n'

    #-- extract FPS and FOV options
    settings_fps_dict = settings_dict['SETTING_VIDEO_FRAME_RATE']['options']
    settings_fov_dict = settings_dict['SETTING_VIDEO_FOV']['options']
    
    #-- run through each parameter
    for setting, options in settings_dict.items():
        setting_mavlink_name = make_mavlink_name(options['name'])
        setting_description = options['name'] #+': '+str(options['options'].keys()).replace('dict_keys','').replace('[','').replace(']','').replace('(','').replace(')','').replace('\'','')
        setting_default_nr = options['default']
        #-- remove 'Video', 'Photo','Multishot' from name
        setting_description = setting_description.replace('Video ','') 
        setting_description = setting_description.replace('Photo ','')
        setting_description = setting_description.replace('Multishot ','')
        #-- figure out if it's a boolean, or a unit32 parameter
        isBool = True
        for option, option_nr in options['options'].items():
            if (option.lower() == 'off' and option_nr == 0) or (option.lower() == 'on' and option_nr == 1): continue
            isBool = False
            break
        #-- do it for a bool parameter
        if isBool:
            xml += '        <parameter name="'+setting_mavlink_name+'" type="bool" default="'+str(setting_default_nr)+'">\n'
            xml += '            <description>'+setting_description+'</description>\n'
            xml += '        </parameter>\n'
            continue
        #-- do it for a unit32 parameter
        xml += '        <parameter name="'+setting_mavlink_name+'" type="uint32" default="'+str(setting_default_nr)+'">\n'
        xml += '            <description>'+setting_description+'</description>\n'
        xml += '            <options>\n'
        #-- in case the full resolution matrix shall be done, do it for Video Resolution parameter
        if (do_with_matrix_resolution > 0) and (setting_mavlink_name == 'VID_RESOLUTION'):
            for option, option_nr in options['options'].items():
                fpsdict = matrix_dict[option] #TODO: test if available
                xml += '                <option name="'+option+'" value="'+str(option_nr)+'">\n'
                xml += '                    <parameterranges>\n'
                #fps
                xml += '                        <parameterrange parameter="VID_FRAMERATE" condition="VID_FORMAT=0">\n'
                for fps in fpsdict:
                    fpslist = fps.split('/')
                    if len(fpslist) > 1: fps = fpslist[0]
                    fps_value = settings_fps_dict[fps+'fps'] #TODO: test if available
                    xml += '                            <roption name="'+fps+'fps" value="'+str(fps_value)+'" />\n'
                xml += '                        </parameterrange>\n'
                xml += '                        <parameterrange parameter="VID_FRAMERATE" condition="VID_FORMAT=1">\n'
                for fps in fpsdict:
                    fpslist = fps.split('/')
                    if len(fpslist) > 1: fps = fpslist[1]
                    fps_value = settings_fps_dict[fps+'fps'] #TODO: test if available
                    xml += '                            <roption name="'+fps+'fps" value="'+str(fps_value)+'" />\n'
                xml += '                        </parameterrange>\n'
                #fov
                for fps in fpsdict:
                    fovdict = fpsdict[fps]
                    fpslist = fps.split('/')
                    xml += '                        <parameterrange parameter="VID_FOV" condition="VID_FRAMERATE='
                    fps_value = settings_fps_dict[fpslist[0]+'fps']
                    xml += str(fps_value)
                    if len(fpslist) > 1:
                        fps_value = settings_fps_dict[fpslist[1]+'fps']                    
                        xml += ' OR VID_FRAMERATE='+str(fps_value)
                    xml += '">\n'
                    for fov in fovdict:
                        fov_value = settings_fov_dict[fov]
                        xml += '                            <roption name="'+fov+'" value="'+str(fov_value)+'" />\n'
                    xml += '                        </parameterrange>\n'
                xml += '                    </parameterranges>\n'
                xml += '                </option>\n'
        #-- in case the full resolution matrix shal be done, do it for Video Format parameter
        elif (do_with_format > 0) and (setting_mavlink_name == 'VID_FORMAT'):
            for option, option_nr in options['options'].items():
                xml += '                <option name="'+option+'" value="'+str(option_nr)+'">\n'
                xml += '                    <parameterranges>\n'
                xml += '                        <parameterrange parameter="VID_FRAMERATE" condition="VID_FORMAT='+str(option_nr)+'">\n'
                for fps in settings_fps_dict:
                    fps_value = settings_fps_dict[fps] #TODO: test if available
                    if option_nr == 0 and (fps == '25fps' or fps == '50fps'): continue
                    if option_nr == 1 and (fps == '30fps' or fps == '60fps'): continue
                    xml += '                            <roption name="'+fps+'" value="'+str(fps_value)+'" />\n'
                xml += '                        </parameterrange>\n'
                xml += '                    </parameterranges>\n'
                xml += '                </option>\n'
        #-- normal parameter
        else:
            for option, option_nr in options['options'].items():
                xml += '                <option name="'+option+'" value="'+str(option_nr)+'" />\n'
        #-- closing footer for unit32 parameter
        xml += '            </options>\n'
        xml += '        </parameter>\n'
    
    xml += '    </parameters>\n'
    xml += '</mavlinkcamera>\n\n'

    F = open(xmloutputfilename+'_v'+str(VERSION)+'.xml', "w")
    F.write(xml)
    F.close() 

##    exit()
    
    '''generate STorM32 lib h file'''
    print('---------------------------')
    print('generate STorM32 lib h file')
    
    F = open(codetemplateinputfilename, "r")
    code_template_h = F.read()
    F.close() 

    code_template_h = '//generated '+str(datetime.datetime.now())+'\n' + code_template_h
    
    setting_name_maxlen = 0
    setup_zahl = 0
    for setting, options in settings_dict.items():
        setting_name = options['name'].title().replace(' ','')
        if len(setting_name) > setting_name_maxlen: setting_name_maxlen = len(setting_name)
        setup_zahl += 1 

    # $$GOPRO_PARAMETER_ZAHL$$  
    code_h = ''
    code_h = str(setup_zahl+1)
    code_template_h = code_template_h.replace('$$$GOPRO_PARAMETER_ZAHL$$$',code_h)

    # $$GOPRO_PARAMETERS$$  
    code_h = ''
    for setting, options in settings_dict.items():
        setting_name = options['name'].title().replace(' ','')
        setting_mavlink_name = make_mavlink_name(options['name'])
        option_nr_max = 0
        for option, option_nr in options['options'].items():
            if option_nr > option_nr_max: option_nr_max = option_nr
        if option_nr_max > 65536:
            type = 'uint32_t'
        else: 
            type = 'uint16_t'
        code_h += '  '+type+' '+(setting_name+';').ljust(setting_name_maxlen+1)+'  // '+str(options['nr'])+'\n' #  // '+setting_mavlink_name+'\n'

    code_template_h = code_template_h.replace('$$$GOPRO_PARAMETERS$$$',code_h[:-1])

    # $$GOPRO_SETUP_PARAMETERS$$  
    code_h = ''
    for setting, options in settings_dict.items():
        setting_name = options['name'].title().replace(' ','')
        setting_mavlink_name = make_mavlink_name(options['name'])
        setting_default_nr = options['default']
        option_nr_max = 0
        for option, option_nr in options['options'].items():
            if option_nr > option_nr_max: option_nr_max = option_nr
        if option_nr_max > 65536:
            type = 'UINT32'
        else: 
            type = 'UINT16'
        code_h += '  { ('+type.lower()+'_t*)&_mavcameraparams_goprohero5.'+(setting_name+',').ljust(setting_name_maxlen+3)+'MAV_PARAM_TYPE_'+type+','
        code_h += '  "'+setting_mavlink_name+'" },\n'
        
    code_template_h = code_template_h.replace('$$$GOPRO_SETUP_PARAMETERS$$$',code_h[:-1])
        
    # $$GOPRO_DEFAULTS$$  
    code_h = ''
    for setting, options in settings_dict.items():
        setting_name = options['name'].title().replace(' ','')
        setting_mavlink_name = make_mavlink_name(options['name'])
        setting_default_nr = options['default']
        if setting_default_nr != 0:
            code_h += '  _mavcameraparams_goprohero5.'+setting_name+' = '+str(setting_default_nr)+';\n'

    code_template_h = code_template_h.replace('$$$GOPRO_DEFAULTS$$$',code_h[:-1])

    # $$GOPRO_SETTING_STR$$    
    code_h = '  '
    cnt = 0
    for setting, options in settings_dict.items():
        cnt += 1
        if cnt > 20:
            cnt = 0;
            code_h += '\n  '
        code_h += '"'+str(options['nr'])+'",'

    code_template_h = code_template_h.replace('$$$GOPRO_SETTING_STR$$$',code_h)
    
    # $$GOPRO_SETTING_U16$$
    code_h = '  '
    cnt = 0
    for setting, options in settings_dict.items():
        cnt += 1
        if cnt > 20:
            cnt = 0;
            code_h += '\n  '
        code_h += ''+str(options['nr'])+','

    code_template_h = code_template_h.replace('$$$GOPRO_SETTING_U16$$$',code_h)
        
    
    F = open(codeoutputfilename+'-v'+str(VERSION)+'.h', "w")
    F.write(code_template_h)
    F.close() 
    
