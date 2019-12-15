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
  Library of some basic function
'''

import re
import json
import datetime


'''
reads the .cmd file and converts it into a Json, and returns it as string
'''
def cvtSettingsToJsonStr(camera):

    F = open("GP-"+camera.upper()+"-commands.cmd", "r")
    md = F.read()
    F.close()

    print(md)

    mdList = md.split('\n')

    mode = ''
    setting = ''
    last_setting_nr = ''
    last_setting_default_nr = ''
    comment_on = False

    json_str = ''

    print(mdList)

    print('---------------------------')

    for line in mdList:
        #remove anything behind '!'
        line = re.sub(r'(.?)!.*', '', line)
        #remove anything behind '?'
        line = re.sub(r'(.?)\?.*', '', line)

        #handle comments embraced by /////
        comment_match = re.match(r'(\s*)/////', line) # match /////
        if comment_match:
            if comment_on:
                comment_on = False
            else:    
                comment_on = True
        if comment_on or comment_match:
            continue

        #get condition after '$'
        # TODO
        line = re.sub(r'(.?)\$.*', '', line)
    
        line = line.lstrip()
        if line == '': continue
        print("-> ", line)
        
        #extract a mode
        mode_match = re.match(r'###?#? (\w+)', line) # match ##, ###, ####
        if mode_match:
            m = mode_match.group(1).lower()
            if m == 'video':
                mode = 'Video'
            elif m == 'photo':
                mode = 'Photo'
            elif m == 'multishot':
                mode = 'Multishot'
            else:
                mode = ''
            #print(line)
            #print(m)
            print(mode)
            continue

        #extract a setting
        setting_match = re.match(r'######? ([\w\s]+)', line) # match #####, ######
        if setting_match:
            s = setting_match.group(1).strip()
            if mode != '':
                setting_name = mode+' '+s
            else:
                setting_name = s

            print(setting_name)

            if last_setting_nr != '':
                json_str = json_str[:-2] +'\n'
                json_str += '        },\n'
                json_str += '        "nr": '+last_setting_nr+',\n'
                if last_setting_default_nr != '':
                    json_str += '        "default": '+last_setting_default_nr+'\n'
                else:
                    json_str += '        "default": 0\n'
                last_setting_default_nr = ''
                json_str += '    },\n'

            header = 'SETTING_'+setting_name.upper().replace(' ','_')
            json_str += '    "'+header+'": {\n'
            json_str += '        "name": "'+setting_name+'",\n'
            json_str += '        "options": {\n'
            continue

        #extract a setting option
        option_match = re.match(r'\* ([\d\w\s\.\-\+\%|:/]+?) \s*(\d+)/(\d+)', line) # match *
        if option_match:
            option_name = option_match.group(1).strip()
            option_nr = option_match.group(3).strip()
            setting_nr = option_match.group(2).strip()
            
            if option_name.lower() == 'on': option_name = 'On'
            if option_name.lower() == 'off': option_name = 'Off'

            print(header,setting,"=",option_name, setting_nr, option_nr)

            json_str += '            "'+option_name+'": '+option_nr+',\n'
            last_setting_nr = setting_nr

        default_match = re.match(r'default *= *(\d+)', line) # match default =
        if default_match:
            last_setting_default_nr = default_match.group(1).strip()
            
    if last_setting_nr != '':
        json_str = json_str[:-2] +'\n'
        json_str += '        },\n'
        json_str += '        "nr": '+last_setting_nr+',\n'
        if last_setting_default_nr != '':
            json_str += '        "default": '+last_setting_default_nr+'\n'
        else:
            json_str += '        "default": 0\n'
        json_str += '    },\n'
 
    json_str = '{\n' + json_str[:-2] + '\n}\n'

    #print(json_str)

    return json_str



'''
Creates a MAVLink-parameter name form the human readable name of the setting
'''
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

    

'''
reads the json .txt file
generates the STorM32 camera definition xml file, and returns it as string
'''
def generateSTorM32CamDefXMLForCamera(camera, version):
    
    F = open("gp-"+camera.lower()+"-settings-json.txt", "r")
    json_str = F.read()
    F.close() 
    settings_dict = json.loads(json_str)
    
    # uses the original json/dict, i.e. settings_dict
    xml = ''
    xml += '<?xml version="1.0" encoding="UTF-8" ?>\n'
    xml += '<mavlinkcamera>\n'
    xml += '    <definition version="1">\n'
    xml += '        <model>STorM32 '+camera+' Black</model>\n'
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
        #-- normal parameter
        for option, option_nr in options['options'].items():
            xml += '                <option name="'+option+'" value="'+str(option_nr)+'" />\n'
        #-- closing footer for unit32 parameter
        xml += '            </options>\n'
        xml += '        </parameter>\n'
    
    xml += '    </parameters>\n'
    xml += '</mavlinkcamera>\n\n'

    return xml

    

'''
reads the json .txt file
reads the cam template code file
generates the STorM32 lib h file content for the camera specific parts, and returns it as string
'''
def generateSTorM32LibForCamera(camera, version):
    
    F = open("gp-"+camera.lower()+"-settings-json.txt", "r")
    json_str = F.read()
    F.close() 
    settings_dict = json.loads(json_str)
    
    F = open("GP-STORM32-clib-template-cam.h", "r")
    code_template_h = F.read()
    F.close() 

    # $$$GOPRO_NO$$$
    camera_no = camera[-1:]
    code_template_h = code_template_h.replace('$$$GOPRO_NO$$$',camera_no)
    
    # $$$GOPRO_VERSION$$$
    code_template_h = code_template_h.replace('$$$GOPRO_VERSION$$$',str(version))

    #do some counting    
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
        code_h += '  { ('+type.lower()+'_t*)&_mavcameraparams_gopro'+camera.lower()+'.'+(setting_name+',').ljust(setting_name_maxlen+3)+'MAV_PARAM_TYPE_'+type+','
        code_h += '  "'+setting_mavlink_name+'" },\n'
        
    code_template_h = code_template_h.replace('$$$GOPRO_SETUP_PARAMETERS$$$',code_h[:-1])
        
    # $$GOPRO_DEFAULTS$$  
    code_h = ''
    for setting, options in settings_dict.items():
        setting_name = options['name'].title().replace(' ','')
        setting_mavlink_name = make_mavlink_name(options['name'])
        setting_default_nr = options['default']
        if setting_default_nr != 0:
            code_h += '  _mavcameraparams_gopro'+camera.lower()+'.'+setting_name+' = '+str(setting_default_nr)+';\n'

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
    
    return code_template_h


'''
reads the json .txt file
reads the cam template code file
reads the template code file
generates the complete STorM32 lib h file, and returns it as string
'''
def generateSTorM32Lib(cameras, versions):

    F = open("GP-STORM32-clib-template.h", "r")
    code_template_h = F.read()
    F.close() 

    code_template_h = '//generated '+str(datetime.datetime.now())+'\n' + code_template_h
    
    cam_code_h = ''
    for i in range(len(cameras)):
        camera = cameras[i]
        cam_code_h += generateSTorM32LibForCamera(camera, versions[i])
        cam_code_h += '\n\n'
    cam_code_h = cam_code_h[:-4]
    
    code_template_h = code_template_h.replace('$$$GOPRO_MAVCAMERAS$$$',cam_code_h)
    
    return code_template_h
    
