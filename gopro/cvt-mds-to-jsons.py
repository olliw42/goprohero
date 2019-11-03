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
  Json Generator
  reads the (edited) .md files fetched from KonradIT's github repository
  and converts it into Json ASCII files
  which can then be used in code generators
'''

import re


settings_inputfilename = "HERO5-Commands - edited.md"
settings_outputfilename = "settings-json.txt"

status_inputfilename = "CameraStatus - edited.md"
status_outputfilename = "status-json.txt"

resolution_inputfilename = "Framerates-Resolutions - edited.md"
resolution_outputfilename = "resolution-matrix-json.txt"


def cvtsettings():
    F = open(settings_inputfilename, "r")
    md = F.read()
    F.close() 
    
    print(md)
    
    mdList = md.split('\n')
    
    mode = ''
    setting = ''
    last_setting_nr = ''
    last_setting_default_nr = ''
    
    json_str = ''
    
    print(mdList)

    print('---------------------------')

    for line in mdList:
        line = line.lstrip()
        if line == '': continue
        #print("-> ", line)
    
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
            #print(mode)
            continue
            
        #extract a setting
        setting_match = re.match(r'######? ([\w\s]+)', line) # match #####, ######
        if setting_match:
            s = setting_match.group(1).strip()
            if mode != '':
                setting_name = mode+' '+s
            else:    
                setting_name = s
                
            #print(setting_name)
            
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
        option_match = re.match(r'\* ([\d\w\s\.\-\+\%|:/]+)http://10\.5\.5\.9/gp/gpControl/setting/(.*)', line) # match *
        if option_match:
            option_name = option_match.group(1).strip()[:-1].strip()
            option_values_list = option_match.group(2).split('/')
            option_nr = option_values_list[1].strip()
            setting_nr = option_values_list[0].strip()
            
            if option_name.lower() == 'on': option_name = 'On'
            if option_name.lower() == 'off': option_name = 'Off'

            print(header,setting,"=",option_name, option_values_list)

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

    print(json_str)     
            
    F = open(settings_outputfilename, "w")
    F.write(json_str)
    F.close() 
            

def cvtstatus():
    F = open(status_inputfilename, "r")
    md = F.read()
    F.close() 
    
    print(md)
    
    mode = ''
    setting = ''
    last_setting_nr = ''
    
    json_str = ''
    
    print('---------------------------')

    #extract status object
    # we don't use this
    status_search = re.search(r'### Status object:(.+?)### Settings object:', md, re.DOTALL)
    status_object_str = status_search.group(1)
    
    print(status_object_str)
    
    #extract settings object
    setting_search = re.search(r'### Settings object:(.+)', md, re.DOTALL)  #or (.+?)$
    setting_object_str = setting_search.group(1)
    
    print(setting_object_str)

    settingList = setting_object_str.split('\n')

    print('---------------------------')

    for line in settingList:
        line = line.rstrip()
        if line == '': continue
#        print("-> ", line)

        #extract a mode    
        mode_match = re.match(r'#### (\w+)', line) # match #### 
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
            print(line)
            print(m)
            print(mode)
            continue
        
        #extract a setting
        setting_match = re.match(r'\* ([\w\s\+\-]+?) \- (\d+)', line) # match *
        if setting_match:
            s = setting_match.group(1).strip()
            if mode != '':
                setting_name = mode+' '+s
            else:    
                setting_name = s
            setting_nr = setting_match.group(2).strip()
                
            print(setting_name, setting_nr)
            
            if last_setting_nr != '':
                json_str = json_str[:-2] +'\n'
                json_str += '        },\n'
                json_str += '        "nr": '+last_setting_nr+'\n'
                json_str += '    },\n'
            last_setting_nr = setting_nr
            
            header = 'STATUSSETTING_'+setting_name.upper().replace(' ','_')
            json_str += '    "'+header+'": {\n'
            json_str += '        "name": "'+setting_name+'",\n'
            json_str += '        "options": {\n'
            continue
            
        
        #extract a setting option
        option_match = re.match(r'\s+\* ([\w\s\.\+\-/]+?) \- (\d+)', line) 
        if option_match:
            option_name = option_match.group(1).strip()
            option_nr = option_match.group(2).strip()
            print("-",option_name, option_nr)
            
            if option_name.lower() == 'on': option_name = 'On'
            if option_name.lower() == 'off': option_name = 'Off'

            header = 'STATUSSETTING_'+setting_name.upper().replace(' ','_')+'_'+option_nr
            json_str += '            "'+option_name+'": '+option_nr+',\n'
            
    if last_setting_nr != '':
        json_str = json_str[:-2] +'\n'
        json_str += '        },\n'
        json_str += '        "nr": '+last_setting_nr+'\n'
        json_str += '    },\n'
        
    json_str = '{\n' + json_str[:-2] + '\n}\n'

    print(json_str)     
    
    F = open(status_outputfilename, "w")
    F.write(json_str)
    F.close() 


def cvtresolutionmatrix():
    F = open(resolution_inputfilename, "r")
    md = F.read()
    F.close() 
    
    #print(md)
    
    mdList = md.split('\n')
    
    model = ''
    resolution = ''
   
    json_str = ''
    
    #print(mdList)

    print('---------------------------')

    for line in mdList:
        line = line.lstrip()
        if line == '': continue
        #print("-> ", line)
    
        #extract a matrix    
        model_match = re.match(r'###?#?#? ([\w ]+)', line) # match ##, ###, ####, ######
        if model_match:
            m = model_match.group(1).lower().strip()
            if m == 'hero5 black':
                model = 'Hero5 Black'
            else:    
                model = ''
            #print(line)
            #print(m)
            #print(model)
            continue
            
        if model != 'Hero5 Black': continue
            
        #extract the matrix
        option_match = re.match(r'(.*?)\|([0-9/ ]*?)\|([\w, ].*)', line) # match xxx | xxx |
        if option_match:
            option_resolution = option_match.group(1).strip()
            option_fps = option_match.group(2).strip().replace(' ', '')
            option_fov = option_match.group(3).strip().replace(' ', '')
            
            if option_resolution != '': #and option_resolution != resolution:
                if resolution != '':
                    json_str = json_str[:-2]+'\n'
                    json_str +='    },\n'
                resolution = option_resolution 
                json_str +='    "'+resolution+'": {\n'
            
            json_str += '        "'+option_fps+'": {\n'
            
            fovlist = option_fov.split(',')
            for fov in fovlist:
                json_str += '            "'+fov+'": 0,\n'
            json_str = json_str[:-2]+'\n'
            
            json_str += '        },\n'

    json_str = json_str[:-2]+'\n'
    json_str += '    }\n'
    json_str = '{\n' + json_str + '}\n'

    print(json_str)     
            
    F = open(resolution_outputfilename, "w")
    F.write(json_str)
    F.close() 
    
    
if (1):
    cvtsettings()
    cvtstatus()
    cvtresolutionmatrix()
    
