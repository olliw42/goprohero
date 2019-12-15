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
  C-Code generator
  reads the generated Json ASCII files
  and generates the desired C++ code by filling a template
'''

import re
import json
import datetime


jsoninputfilename = "settings-json.txt"
templateinputfilename = "owGoProAdvancedClass-template.h"
outputfilename = "owGoProAdvancedClass.h"


def option_replace(option_name):
    option_name = option_name.replace('_-_','_')
    option_name = option_name.replace(':','to')
    option_name = option_name.replace('.','p')
    option_name = option_name.replace('/','per')
    option_name = option_name.replace('+','plus')
    option_name = option_name.replace('-','minus')
    option_name = option_name.replace('%','Percent')
    return option_name


if (1):
    
    F = open(jsoninputfilename, "r")
    json_str = F.read()
    F.close() 
    
#    print(json_str)
    
    settings_dict = json.loads(json_str)
    
#    print(settings_dict)

    F = open(templateinputfilename, "r")
    code_template_h = F.read()
    F.close() 
    
    print('---------------------------')

#    for setting, options in settings_dict.items():
#        print(setting, options)
    
#    for setting in sorted(settings_dict.keys()):
#        print(setting, settings_dict[setting])


    #convert into new dict
    # key = index + setting name + option_nr
    dict = {}
    index = 0
    for setting in settings_dict.keys():
        print(setting, settings_dict[setting])

        option_index = 0        
        for option, option_value in settings_dict[setting]['options'].items():
            dict_name = setting+'_'+str(option_index).zfill(10)
            o = {}
            o['setting_name'] = settings_dict[setting]['name']
            o['setting_nr'] = settings_dict[setting]['nr']
            o['option_name'] = option
            o['option_nr'] = option_value
            o['index'] = index
            o['option_index'] = option_index
            dict[dict_name] = o
            index += 1
            option_index += 1
            
    print(dict)

    
    # $$$GOPROSETTINGS$$$
    enumoption_name_maxlen = 0
    for setting, option in dict.items():
        enum_name = 'GOPRO_SET_'+option['setting_name'].strip().replace(' ','_').upper()
        option_name = option['option_name'].strip().replace(' ','_')
        option_name = option_replace(option_name)
        enumoption_name = enum_name+'_'+option_name
        if len(enumoption_name) > enumoption_name_maxlen: enumoption_name_maxlen = len(enumoption_name)
    
    code = ''
    code += 'typedef enum {\n'
    first = True
    for setting, option in dict.items():
        enum_name = 'GOPRO_SET_'+option['setting_name'].strip().replace(' ','_').upper()
        option_name = option['option_name'].strip().replace(' ','_')
        option_name = option_replace(option_name)
        option_name = option_name.upper()
        enumoption_name = enum_name+'_'+option_name
        
        if first:
            first = False
            code += '    '+(enumoption_name+' = 0,').ljust(enumoption_name_maxlen+1)
        else:
            code += '    '+(enumoption_name+',').ljust(enumoption_name_maxlen+1)   
        code += '  // '+str(option['index']).ljust(3)+'  '+str(option['setting_nr'])+','+str(option['option_nr'])+'\n'
    code += '    GOPRO_SET_MAX,\n'
    code += '} GOPROSETTINGENUM;\n'

    code += '\n'
    code += 'const char* GOPRO_SET_STR[] = {'
    last_nr = -1
    for setting, option in dict.items():
        if option['setting_nr'] != last_nr:
            code += '\n'
            code += '    "/'+str(option['setting_nr'])+'/'+str(option['option_nr'])+'",'
        else:    
            code += ' "'+str(option['setting_nr'])+'/'+str(option['option_nr'])+'",'
        last_nr = option['setting_nr']
    code += '\n};'
    
    print(code)    
    
    code_template_h = code_template_h.replace('$$$GOPROSETTINGS$$$',code)
    
    
    # $$$GOPROMETHODPROTOTYPES$$$
    code = ''
    for setting, option in dict.items():
        function_name = option['setting_name'].strip().lower().title().replace(' ','')
        option_name = option['option_name'].strip().lower().title().replace(' ','')
        option_name = option_replace(option_name)
        
        code += '    int16_t set'+function_name+'_'+option_name+'(void);\n'
    code = code[:-1]
    
    print(code)

    code_template_h = code_template_h.replace('$$$GOPROMETHODPROTOTYPES$$$',code)

    
    # $$$GOPROMETHODHS$$$
    code = ''
    for setting, option in dict.items():
        function_name = option['setting_name'].strip().lower().title().replace(' ','')
        option_name = option['option_name'].strip().lower().title().replace(' ','')
        option_name = option_replace(option_name)
        
        enum_name = 'GOPRO_SET_'+option['setting_name'].strip().replace(' ','_').upper()
        enumoption_name = option['option_name'].strip().replace(' ','_')
        enumoption_name = option_replace(enumoption_name)
        enumoption_name = enumoption_name.upper()
        
        dbg_name = 'gopro '+option['setting_name'].strip().lower()
        dbgoption_name = option['option_name'].strip().lower()
        
        code += 'int16_t owGoProAdvancedClass::set'+function_name+'_'+option_name+'(void)\n'
        code += '{\n'
        code += '    GOPRO_DBG("'+dbg_name+' '+dbgoption_name+'");\n'
        code += '    return setSetting('+enum_name+'_'+enumoption_name+');\n'
        code += '}\n\n\n'
    code = code[:-3]

    print(code)

    code_template_h = code_template_h.replace('$$$GOPROMETHODHS$$$',code)


    code_template_h = code_template_h.replace('$$$GOPROVERSION$$$','  generated '+str(datetime.datetime.now()))
    
    F = open(outputfilename, "w")
    F.write(code_template_h)
    F.close() 
            
            
    
