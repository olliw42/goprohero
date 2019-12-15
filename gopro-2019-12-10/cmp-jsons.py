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
'''

import re
import json


settings_jsoninputfilename = "settings-json.txt"
status_jsoninputfilename = "status-json.txt"
outputfilename = "cmp-jsons-result.txt"


if (1):
    
    F = open(settings_jsoninputfilename, "r")
    settings_json_str = F.read()
    F.close() 
    settings_dict = json.loads(settings_json_str)

    F = open(status_jsoninputfilename, "r")
    status_json_str = F.read()
    F.close() 
    status_dict = json.loads(status_json_str)

    print('---------------------------')

    table = ''
    '''   
    #find max nr
    max_nr = -1
    for setting, setting_options in settings_dict.items():
       if int(setting_options["nr"]) > max_nr: max_nr = int(setting_options["nr"])
    for statussetting, statussetting_options in status_dict.items():
       if int(statussetting_options["nr"]) > max_nr: max_nr = int(statussetting_options["nr"])
    '''
    
    for nr in range(200):
         
        #find setting with nr
        found_in_setting = False
        for setting, setting_options in settings_dict.items():
            if int(setting_options["nr"]) == nr:
                #print('Setting: ',setting,nr)
                found_in_setting = True
                break
        
        found_in_status = False
        for statussetting, statussetting_options in status_dict.items():
            if int(statussetting_options["nr"]) == nr:
                #print('Status: ',statussetting,nr)
                found_in_status = True
                break

        if (not found_in_setting) and (not found_in_status):
            continue
                
        #if found_in_setting and found_in_status:
        #build the comparsion table

        if not found_in_setting: setting = 'not found'
        if not found_in_status: statussetting = 'not found'
        
        table += '\n'+str(nr)+': '+setting+' <-> '+statussetting+'\n'
        
        if found_in_setting and not found_in_status:
            table += '!! ONLY in SETTING !!\n'
            for option, option_nr in setting_options['options'].items():
                table += '    '+str(option_nr)+' '+option+'\n'
            
        if not found_in_setting and found_in_status:
            table += '!! ONLY in STATUS !!\n'
            for option, option_nr in statussetting_options['options'].items():
                table += '    '+str(option_nr)+' '+option+'\n'
            
            
        if found_in_setting and found_in_status:
            if 'STATUS'+setting != statussetting:
                table += '!! NOT EQUAL !!\n'

            for option, option_nr in setting_options['options'].items():
                table += '    '+str(option_nr)+' '+option+'\n'
            table += '\n'
            for option, option_nr in statussetting_options['options'].items():
                table += '    '+str(option_nr)+' '+option+'\n'

                
    
    print(table)    


    F = open(outputfilename, "w")
    F.write(table)
    F.close() 

















        
