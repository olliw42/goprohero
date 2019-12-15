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
  
  generated 2019-11-02 09:38:19.147485
*/


#include "owGoProClass.h"

//--------------------------------------
// owGoPro Advanced Class
//--------------------------------------

//--------------------------------------
// SETTINGS
//--------------------------------------

typedef enum {
    GOPRO_SET_VIDEO_RESOLUTION_4K = 0,                     // 0    2,1
    GOPRO_SET_VIDEO_RESOLUTION_2P7K,                       // 1    2,4
    GOPRO_SET_VIDEO_RESOLUTION_2P7K_4TO3,                  // 2    2,6
    GOPRO_SET_VIDEO_RESOLUTION_1440,                       // 3    2,7
    GOPRO_SET_VIDEO_RESOLUTION_1080,                       // 4    2,9
    GOPRO_SET_VIDEO_RESOLUTION_960,                        // 5    2,10
    GOPRO_SET_VIDEO_RESOLUTION_720,                        // 6    2,12
    GOPRO_SET_VIDEO_RESOLUTION_480,                        // 7    2,17
    GOPRO_SET_VIDEO_FRAME_RATE_240FPS,                     // 8    3,0
    GOPRO_SET_VIDEO_FRAME_RATE_120FPS,                     // 9    3,1
    GOPRO_SET_VIDEO_FRAME_RATE_100FPS,                     // 10   3,2
    GOPRO_SET_VIDEO_FRAME_RATE_90FPS,                      // 11   3,3
    GOPRO_SET_VIDEO_FRAME_RATE_80FPS,                      // 12   3,4
    GOPRO_SET_VIDEO_FRAME_RATE_60FPS,                      // 13   3,5
    GOPRO_SET_VIDEO_FRAME_RATE_50FPS,                      // 14   3,6
    GOPRO_SET_VIDEO_FRAME_RATE_48FPS,                      // 15   3,7
    GOPRO_SET_VIDEO_FRAME_RATE_30FPS,                      // 16   3,8
    GOPRO_SET_VIDEO_FRAME_RATE_25FPS,                      // 17   3,9
    GOPRO_SET_VIDEO_FRAME_RATE_24FPS,                      // 18   3,10
    GOPRO_SET_VIDEO_FOV_SUPERVIEW,                         // 19   4,3
    GOPRO_SET_VIDEO_FOV_WIDE,                              // 20   4,0
    GOPRO_SET_VIDEO_FOV_MEDIUM,                            // 21   4,1
    GOPRO_SET_VIDEO_FOV_LINEAR,                            // 22   4,4
    GOPRO_SET_VIDEO_FOV_NARROW,                            // 23   4,2
    GOPRO_SET_VIDEO_COLOR_GOPRO,                           // 24   12,0
    GOPRO_SET_VIDEO_COLOR_FLAT,                            // 25   12,1
    GOPRO_SET_VIDEO_WHITE_BALANCE_AUTO,                    // 26   11,0
    GOPRO_SET_VIDEO_WHITE_BALANCE_3000K,                   // 27   11,1
    GOPRO_SET_VIDEO_WHITE_BALANCE_4000K,                   // 28   11,5
    GOPRO_SET_VIDEO_WHITE_BALANCE_4800K,                   // 29   11,6
    GOPRO_SET_VIDEO_WHITE_BALANCE_5500K,                   // 30   11,2
    GOPRO_SET_VIDEO_WHITE_BALANCE_6000K,                   // 31   11,7
    GOPRO_SET_VIDEO_WHITE_BALANCE_6500K,                   // 32   11,3
    GOPRO_SET_VIDEO_WHITE_BALANCE_NATIVE,                  // 33   11,4
    GOPRO_SET_VIDEO_ISO_6400,                              // 34   13,0
    GOPRO_SET_VIDEO_ISO_3200,                              // 35   13,3
    GOPRO_SET_VIDEO_ISO_1600,                              // 36   13,1
    GOPRO_SET_VIDEO_ISO_1200,                              // 37   13,5
    GOPRO_SET_VIDEO_ISO_800,                               // 38   13,4
    GOPRO_SET_VIDEO_ISO_400,                               // 39   13,2
    GOPRO_SET_VIDEO_SHUTTER_AUTO,                          // 40   73,0
    GOPRO_SET_VIDEO_SHUTTER_1PER24,                        // 41   73,3
    GOPRO_SET_VIDEO_SHUTTER_1PER30,                        // 42   73,5
    GOPRO_SET_VIDEO_SHUTTER_1PER48,                        // 43   73,6
    GOPRO_SET_VIDEO_SHUTTER_1PER60,                        // 44   73,8
    GOPRO_SET_VIDEO_SHUTTER_1PER90,                        // 45   73,10
    GOPRO_SET_VIDEO_SHUTTER_1PER96,                        // 46   73,11
    GOPRO_SET_VIDEO_SHUTTER_1PER120,                       // 47   73,13
    GOPRO_SET_VIDEO_SHUTTER_1PER180,                       // 48   73,15
    GOPRO_SET_VIDEO_SHUTTER_1PER192,                       // 49   73,16
    GOPRO_SET_VIDEO_SHUTTER_1PER240,                       // 50   73,18
    GOPRO_SET_VIDEO_SHUTTER_1PER360,                       // 51   73,20
    GOPRO_SET_VIDEO_SHUTTER_1PER480,                       // 52   73,22
    GOPRO_SET_VIDEO_EV_COMP_PLUS2P0,                       // 53   15,0
    GOPRO_SET_VIDEO_EV_COMP_PLUS1P5,                       // 54   15,1
    GOPRO_SET_VIDEO_EV_COMP_PLUS1P0,                       // 55   15,2
    GOPRO_SET_VIDEO_EV_COMP_PLUS0P5,                       // 56   15,3
    GOPRO_SET_VIDEO_EV_COMP_0,                             // 57   15,4
    GOPRO_SET_VIDEO_EV_COMP_MINUS0P5,                      // 58   15,5
    GOPRO_SET_VIDEO_EV_COMP_MINUS1P0,                      // 59   15,6
    GOPRO_SET_VIDEO_EV_COMP_MINUS1P5,                      // 60   15,7
    GOPRO_SET_VIDEO_EV_COMP_MINUS2P0,                      // 61   15,8
    GOPRO_SET_VIDEO_SHARPNESS_HIGH,                        // 62   14,0
    GOPRO_SET_VIDEO_SHARPNESS_MEDIUM,                      // 63   14,1
    GOPRO_SET_VIDEO_SHARPNESS_LOW,                         // 64   14,2
    GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_OFF,                   // 65   81,3
    GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_LOW,                   // 66   81,0
    GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_MEDIUM,                // 67   81,1
    GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_HIGH,                  // 68   81,2
    GOPRO_SET_VIDEO_PROTUNE_OFF,                           // 69   10,0
    GOPRO_SET_VIDEO_PROTUNE_ON,                            // 70   10,1
    GOPRO_SET_VIDEO_EIS_OFF,                               // 71   78,0
    GOPRO_SET_VIDEO_EIS_ON,                                // 72   78,1
    GOPRO_SET_VIDEO_AUTO_LOW_LIGHT_OFF,                    // 73   8,0
    GOPRO_SET_VIDEO_AUTO_LOW_LIGHT_ON,                     // 74   8,1
    GOPRO_SET_VIDEO_MANUAL_AUDIO_CONTROL_OFF,              // 75   80,2
    GOPRO_SET_VIDEO_MANUAL_AUDIO_CONTROL_STERO_ONLY,       // 76   80,0
    GOPRO_SET_VIDEO_MANUAL_AUDIO_CONTROL_WIND_ONLY,        // 77   80,1
    GOPRO_SET_VIDEO_PHOTO_INTERVAL_5_SEC,                  // 78   7,1
    GOPRO_SET_VIDEO_PHOTO_INTERVAL_10_SEC,                 // 79   7,2
    GOPRO_SET_VIDEO_PHOTO_INTERVAL_30_SEC,                 // 80   7,3
    GOPRO_SET_VIDEO_PHOTO_INTERVAL_60_SEC,                 // 81   7,4
    GOPRO_SET_VIDEO_LOOPING_INTERVAL_MAX,                  // 82   6,0
    GOPRO_SET_VIDEO_LOOPING_INTERVAL_5_MIN,                // 83   6,1
    GOPRO_SET_VIDEO_LOOPING_INTERVAL_20_MIN,               // 84   6,2
    GOPRO_SET_VIDEO_LOOPING_INTERVAL_60_MIN,               // 85   6,3
    GOPRO_SET_VIDEO_LOOPING_INTERVAL_120_MIN,              // 86   6,4
    GOPRO_SET_PHOTO_FOV_WIDE,                              // 87   17,0
    GOPRO_SET_PHOTO_FOV_LINEAR,                            // 88   17,10
    GOPRO_SET_PHOTO_FOV_MEDIUM,                            // 89   17,8
    GOPRO_SET_PHOTO_FOV_NARROW,                            // 90   17,9
    GOPRO_SET_PHOTO_COLOR_GOPRO,                           // 91   23,0
    GOPRO_SET_PHOTO_COLOR_FLAT,                            // 92   23,1
    GOPRO_SET_PHOTO_WHITE_BALANCE_AUTO,                    // 93   22,0
    GOPRO_SET_PHOTO_WHITE_BALANCE_3000K,                   // 94   22,1
    GOPRO_SET_PHOTO_WHITE_BALANCE_4000K,                   // 95   22,5
    GOPRO_SET_PHOTO_WHITE_BALANCE_4800K,                   // 96   22,6
    GOPRO_SET_PHOTO_WHITE_BALANCE_5500K,                   // 97   22,2
    GOPRO_SET_PHOTO_WHITE_BALANCE_6000K,                   // 98   22,7
    GOPRO_SET_PHOTO_WHITE_BALANCE_6500K,                   // 99   22,3
    GOPRO_SET_PHOTO_WHITE_BALANCE_NATIVE,                  // 100  22,4
    GOPRO_SET_PHOTO_ISO_MIN_1600,                          // 101  75,4
    GOPRO_SET_PHOTO_ISO_MIN_800,                           // 102  75,0
    GOPRO_SET_PHOTO_ISO_MIN_400,                           // 103  75,1
    GOPRO_SET_PHOTO_ISO_MIN_200,                           // 104  75,2
    GOPRO_SET_PHOTO_ISO_MIN_100,                           // 105  75,3
    GOPRO_SET_PHOTO_ISO_MAX_1600,                          // 106  24,4
    GOPRO_SET_PHOTO_ISO_MAX_800,                           // 107  24,0
    GOPRO_SET_PHOTO_ISO_MAX_400,                           // 108  24,1
    GOPRO_SET_PHOTO_ISO_MAX_200,                           // 109  24,2
    GOPRO_SET_PHOTO_ISO_MAX_100,                           // 110  24,3
    GOPRO_SET_PHOTO_SHUTTER_AUTO,                          // 111  97,0
    GOPRO_SET_PHOTO_SHUTTER_1PER125,                       // 112  97,1
    GOPRO_SET_PHOTO_SHUTTER_1PER250,                       // 113  97,2
    GOPRO_SET_PHOTO_SHUTTER_1PER500,                       // 114  97,3
    GOPRO_SET_PHOTO_SHUTTER_1PER1000,                      // 115  97,4
    GOPRO_SET_PHOTO_SHUTTER_1PER2000,                      // 116  97,5
    GOPRO_SET_PHOTO_EV_COMP_PLUS2P0,                       // 117  26,0
    GOPRO_SET_PHOTO_EV_COMP_PLUS1P5,                       // 118  26,1
    GOPRO_SET_PHOTO_EV_COMP_PLUS1P0,                       // 119  26,2
    GOPRO_SET_PHOTO_EV_COMP_PLUS0P5,                       // 120  26,3
    GOPRO_SET_PHOTO_EV_COMP_0,                             // 121  26,4
    GOPRO_SET_PHOTO_EV_COMP_MINUS0P5,                      // 122  26,5
    GOPRO_SET_PHOTO_EV_COMP_MINUS1P0,                      // 123  26,6
    GOPRO_SET_PHOTO_EV_COMP_MINUS1P5,                      // 124  26,7
    GOPRO_SET_PHOTO_EV_COMP_MINUS2P0,                      // 125  26,8
    GOPRO_SET_PHOTO_SHARPNESS_HIGH,                        // 126  25,0
    GOPRO_SET_PHOTO_SHARPNESS_MEDIUM,                      // 127  25,1
    GOPRO_SET_PHOTO_SHARPNESS_LOW,                         // 128  25,2
    GOPRO_SET_PHOTO_PROTUNE_OFF,                           // 129  21,0
    GOPRO_SET_PHOTO_PROTUNE_ON,                            // 130  21,1
    GOPRO_SET_PHOTO_WDR_ON,                                // 131  77,1
    GOPRO_SET_PHOTO_WDR_OFF,                               // 132  77,0
    GOPRO_SET_PHOTO_RAW_FORMAT_ON,                         // 133  82,1
    GOPRO_SET_PHOTO_RAW_FORMAT_OFF,                        // 134  82,0
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_AUTO,                    // 135  19,0
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_2_SEC,                   // 136  19,1
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_5_SEC,                   // 137  19,2
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_10_SEC,                  // 138  19,3
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_15_SEC,                  // 139  19,4
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_20_SEC,                  // 140  19,5
    GOPRO_SET_PHOTO_NIGHT_SHUTTER_30_SEC,                  // 141  19,6
    GOPRO_SET_PHOTO_BURST_RATE_3PER1,                      // 142  29,0
    GOPRO_SET_PHOTO_BURST_RATE_5PER1,                      // 143  29,1
    GOPRO_SET_PHOTO_BURST_RATE_10PER1,                     // 144  29,2
    GOPRO_SET_PHOTO_BURST_RATE_10PER2,                     // 145  29,3
    GOPRO_SET_PHOTO_BURST_RATE_10PER3,                     // 146  29,4
    GOPRO_SET_PHOTO_BURST_RATE_30PER1,                     // 147  29,5
    GOPRO_SET_PHOTO_BURST_RATE_30PER2,                     // 148  29,6
    GOPRO_SET_PHOTO_BURST_RATE_30PER3,                     // 149  29,7
    GOPRO_SET_PHOTO_BURST_RATE_30PER6,                     // 150  29,8
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_0P5_SEC,  // 151  5,0
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_1_SEC,    // 152  5,1
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_2_SEC,    // 153  5,2
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_5_SEC,    // 154  5,3
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_10_SEC,   // 155  5,4
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_30_SEC,   // 156  5,5
    GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_60_SEC,   // 157  5,6
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_0P5_SEC,  // 158  30,0
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_1_SEC,    // 159  30,1
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_2_SEC,    // 160  30,2
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_5_SEC,    // 161  30,5
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_10_SEC,   // 162  30,10
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_30_SEC,   // 163  30,30
    GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_60_SEC,   // 164  30,60
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_AUTO,    // 165  32,3601
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_4_SEC,   // 166  32,4
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_5_SEC,   // 167  32,5
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_10_SEC,  // 168  32,10
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_15_SEC,  // 169  32,15
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_20_SEC,  // 170  32,20
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_30_SEC,  // 171  32,30
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_1_MIN,   // 172  32,60
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_2_MIN,   // 173  32,120
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_5_MIN,   // 174  32,300
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_30_MIN,  // 175  32,1800
    GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_60_MIN,  // 176  32,3600
    GOPRO_SET_VOICE_CONTROL_ON,                            // 177  86,1
    GOPRO_SET_VOICE_CONTROL_OFF,                           // 178  86,0
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_ENGLISH_US,           // 179  85,0
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_ENGLISH_UK,           // 180  85,1
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_ENGLISH_AUS,          // 181  85,2
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_GERMAN,               // 182  85,3
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_FRENCH,               // 183  85,4
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_ITALIAN,              // 184  85,5
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_SPANISH,              // 185  85,6
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_SPANISH_NA,           // 186  85,7
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_CHINESE,              // 187  85,8
    GOPRO_SET_VOICE_CONTROL_LANGUAGE_JAPANESE,             // 188  85,9
    GOPRO_SET_BEEP_VOLUME_MUTE,                            // 189  87,0
    GOPRO_SET_BEEP_VOLUME_LOW,                             // 190  87,40
    GOPRO_SET_BEEP_VOLUME_MEDIUM,                          // 191  87,70
    GOPRO_SET_BEEP_VOLUME_HIGH,                            // 192  87,100
    GOPRO_SET_LED_ALL_OFF,                                 // 193  91,0
    GOPRO_SET_LED_ALL_ON,                                  // 194  91,2
    GOPRO_SET_LED_FRONT_OFF_ONLY,                          // 195  91,1
    GOPRO_SET_QUICKCAPTURE_ON,                             // 196  54,1
    GOPRO_SET_QUICKCAPTURE_OFF,                            // 197  54,0
    GOPRO_SET_DEFAULT_MODE_VIDEO,                          // 198  89,12
    GOPRO_SET_DEFAULT_MODE_VIDEOPLUSPHOTO,                 // 199  89,14
    GOPRO_SET_DEFAULT_MODE_LOOPING,                        // 200  89,15
    GOPRO_SET_DEFAULT_MODE_PHOTO,                          // 201  89,17
    GOPRO_SET_DEFAULT_MODE_NIGHT,                          // 202  89,18
    GOPRO_SET_DEFAULT_MODE_BURST,                          // 203  89,19
    GOPRO_SET_DEFAULT_MODE_TIMELAPSE_VIDEO,                // 204  89,13
    GOPRO_SET_DEFAULT_MODE_TIMELAPSE_PHOTO,                // 205  89,20
    GOPRO_SET_DEFAULT_MODE_NIGHTLAPSE_PHOTO,               // 206  89,21
    GOPRO_SET_AUTO_OFF_NEVER,                              // 207  59,0
    GOPRO_SET_AUTO_OFF_5_MIN,                              // 208  59,4
    GOPRO_SET_AUTO_OFF_15_MIN,                             // 209  59,6
    GOPRO_SET_AUTO_OFF_30_MIN,                             // 210  59,7
    GOPRO_SET_SCREENSAVER_NEVER,                           // 211  51,0
    GOPRO_SET_SCREENSAVER_1_MIN,                           // 212  51,1
    GOPRO_SET_SCREENSAVER_2_MIN,                           // 213  51,2
    GOPRO_SET_SCREENSAVER_3_MIN,                           // 214  51,3
    GOPRO_SET_BRIGHTNESS_100_PERCENT,                      // 215  88,100
    GOPRO_SET_BRIGHTNESS_60_PERCENT,                       // 216  88,60
    GOPRO_SET_BRIGHTNESS_30_PERCENT,                       // 217  88,30
    GOPRO_SET_BRIGHTNESS_10_PERCENT,                       // 218  88,10
    GOPRO_SET_AUTO_ROTATION_UP,                            // 219  52,1
    GOPRO_SET_AUTO_ROTATION_DOWN,                          // 220  52,2
    GOPRO_SET_AUTO_ROTATION_AUTO,                          // 221  52,0
    GOPRO_SET_GPS_ON,                                      // 222  83,1
    GOPRO_SET_GPS_OFF,                                     // 223  83,0
    GOPRO_SET_LANGUAGE_ENGLISH,                            // 224  84,0
    GOPRO_SET_LANGUAGE_CHINESE,                            // 225  84,1
    GOPRO_SET_LANGUAGE_GERMAN,                             // 226  84,2
    GOPRO_SET_LANGUAGE_ITALIAN,                            // 227  84,3
    GOPRO_SET_LANGUAGE_SPANISH,                            // 228  84,4
    GOPRO_SET_LANGUAGE_JAPANESE,                           // 229  84,5
    GOPRO_SET_LANGUAGE_FRENCH,                             // 230  84,6
    GOPRO_SET_VIDEO_FORMAT_NTSC,                           // 231  57,0
    GOPRO_SET_VIDEO_FORMAT_PAL,                            // 232  57,1
    GOPRO_SET_MAX,
} GOPROSETTINGENUM;

const char* GOPRO_SET_STR[] = {
    "/2/1", "2/4", "2/6", "2/7", "2/9", "2/10", "2/12", "2/17",
    "/3/0", "3/1", "3/2", "3/3", "3/4", "3/5", "3/6", "3/7", "3/8", "3/9", "3/10",
    "/4/3", "4/0", "4/1", "4/4", "4/2",
    "/12/0", "12/1",
    "/11/0", "11/1", "11/5", "11/6", "11/2", "11/7", "11/3", "11/4",
    "/13/0", "13/3", "13/1", "13/5", "13/4", "13/2",
    "/73/0", "73/3", "73/5", "73/6", "73/8", "73/10", "73/11", "73/13", "73/15", "73/16", "73/18", "73/20", "73/22",
    "/15/0", "15/1", "15/2", "15/3", "15/4", "15/5", "15/6", "15/7", "15/8",
    "/14/0", "14/1", "14/2",
    "/81/3", "81/0", "81/1", "81/2",
    "/10/0", "10/1",
    "/78/0", "78/1",
    "/8/0", "8/1",
    "/80/2", "80/0", "80/1",
    "/7/1", "7/2", "7/3", "7/4",
    "/6/0", "6/1", "6/2", "6/3", "6/4",
    "/17/0", "17/10", "17/8", "17/9",
    "/23/0", "23/1",
    "/22/0", "22/1", "22/5", "22/6", "22/2", "22/7", "22/3", "22/4",
    "/75/4", "75/0", "75/1", "75/2", "75/3",
    "/24/4", "24/0", "24/1", "24/2", "24/3",
    "/97/0", "97/1", "97/2", "97/3", "97/4", "97/5",
    "/26/0", "26/1", "26/2", "26/3", "26/4", "26/5", "26/6", "26/7", "26/8",
    "/25/0", "25/1", "25/2",
    "/21/0", "21/1",
    "/77/1", "77/0",
    "/82/1", "82/0",
    "/19/0", "19/1", "19/2", "19/3", "19/4", "19/5", "19/6",
    "/29/0", "29/1", "29/2", "29/3", "29/4", "29/5", "29/6", "29/7", "29/8",
    "/5/0", "5/1", "5/2", "5/3", "5/4", "5/5", "5/6",
    "/30/0", "30/1", "30/2", "30/5", "30/10", "30/30", "30/60",
    "/32/3601", "32/4", "32/5", "32/10", "32/15", "32/20", "32/30", "32/60", "32/120", "32/300", "32/1800", "32/3600",
    "/86/1", "86/0",
    "/85/0", "85/1", "85/2", "85/3", "85/4", "85/5", "85/6", "85/7", "85/8", "85/9",
    "/87/0", "87/40", "87/70", "87/100",
    "/91/0", "91/2", "91/1",
    "/54/1", "54/0",
    "/89/12", "89/14", "89/15", "89/17", "89/18", "89/19", "89/13", "89/20", "89/21",
    "/59/0", "59/4", "59/6", "59/7",
    "/51/0", "51/1", "51/2", "51/3",
    "/88/100", "88/60", "88/30", "88/10",
    "/52/1", "52/2", "52/0",
    "/83/1", "83/0",
    "/84/0", "84/1", "84/2", "84/3", "84/4", "84/5", "84/6",
    "/57/0", "57/1",
};

class owGoProAdvancedClass: public owGoProClass
{
    int16_t setSetting(uint16_t setting);

    int16_t setVideoResolution_4K(void);
    int16_t setVideoResolution_2p7K(void);
    int16_t setVideoResolution_2p7K4to3(void);
    int16_t setVideoResolution_1440(void);
    int16_t setVideoResolution_1080(void);
    int16_t setVideoResolution_960(void);
    int16_t setVideoResolution_720(void);
    int16_t setVideoResolution_480(void);
    int16_t setVideoFrameRate_240Fps(void);
    int16_t setVideoFrameRate_120Fps(void);
    int16_t setVideoFrameRate_100Fps(void);
    int16_t setVideoFrameRate_90Fps(void);
    int16_t setVideoFrameRate_80Fps(void);
    int16_t setVideoFrameRate_60Fps(void);
    int16_t setVideoFrameRate_50Fps(void);
    int16_t setVideoFrameRate_48Fps(void);
    int16_t setVideoFrameRate_30Fps(void);
    int16_t setVideoFrameRate_25Fps(void);
    int16_t setVideoFrameRate_24Fps(void);
    int16_t setVideoFov_Superview(void);
    int16_t setVideoFov_Wide(void);
    int16_t setVideoFov_Medium(void);
    int16_t setVideoFov_Linear(void);
    int16_t setVideoFov_Narrow(void);
    int16_t setVideoColor_Gopro(void);
    int16_t setVideoColor_Flat(void);
    int16_t setVideoWhiteBalance_Auto(void);
    int16_t setVideoWhiteBalance_3000K(void);
    int16_t setVideoWhiteBalance_4000K(void);
    int16_t setVideoWhiteBalance_4800K(void);
    int16_t setVideoWhiteBalance_5500K(void);
    int16_t setVideoWhiteBalance_6000K(void);
    int16_t setVideoWhiteBalance_6500K(void);
    int16_t setVideoWhiteBalance_Native(void);
    int16_t setVideoIso_6400(void);
    int16_t setVideoIso_3200(void);
    int16_t setVideoIso_1600(void);
    int16_t setVideoIso_1200(void);
    int16_t setVideoIso_800(void);
    int16_t setVideoIso_400(void);
    int16_t setVideoShutter_Auto(void);
    int16_t setVideoShutter_1per24(void);
    int16_t setVideoShutter_1per30(void);
    int16_t setVideoShutter_1per48(void);
    int16_t setVideoShutter_1per60(void);
    int16_t setVideoShutter_1per90(void);
    int16_t setVideoShutter_1per96(void);
    int16_t setVideoShutter_1per120(void);
    int16_t setVideoShutter_1per180(void);
    int16_t setVideoShutter_1per192(void);
    int16_t setVideoShutter_1per240(void);
    int16_t setVideoShutter_1per360(void);
    int16_t setVideoShutter_1per480(void);
    int16_t setVideoEvComp_plus2p0(void);
    int16_t setVideoEvComp_plus1p5(void);
    int16_t setVideoEvComp_plus1p0(void);
    int16_t setVideoEvComp_plus0p5(void);
    int16_t setVideoEvComp_0(void);
    int16_t setVideoEvComp_minus0p5(void);
    int16_t setVideoEvComp_minus1p0(void);
    int16_t setVideoEvComp_minus1p5(void);
    int16_t setVideoEvComp_minus2p0(void);
    int16_t setVideoSharpness_High(void);
    int16_t setVideoSharpness_Medium(void);
    int16_t setVideoSharpness_Low(void);
    int16_t setVideoRawAudioTrack_Off(void);
    int16_t setVideoRawAudioTrack_Low(void);
    int16_t setVideoRawAudioTrack_Medium(void);
    int16_t setVideoRawAudioTrack_High(void);
    int16_t setVideoProtune_Off(void);
    int16_t setVideoProtune_On(void);
    int16_t setVideoEis_Off(void);
    int16_t setVideoEis_On(void);
    int16_t setVideoAutoLowLight_Off(void);
    int16_t setVideoAutoLowLight_On(void);
    int16_t setVideoManualAudioControl_Off(void);
    int16_t setVideoManualAudioControl_SteroOnly(void);
    int16_t setVideoManualAudioControl_WindOnly(void);
    int16_t setVideoPhotoInterval_5Sec(void);
    int16_t setVideoPhotoInterval_10Sec(void);
    int16_t setVideoPhotoInterval_30Sec(void);
    int16_t setVideoPhotoInterval_60Sec(void);
    int16_t setVideoLoopingInterval_Max(void);
    int16_t setVideoLoopingInterval_5Min(void);
    int16_t setVideoLoopingInterval_20Min(void);
    int16_t setVideoLoopingInterval_60Min(void);
    int16_t setVideoLoopingInterval_120Min(void);
    int16_t setPhotoFov_Wide(void);
    int16_t setPhotoFov_Linear(void);
    int16_t setPhotoFov_Medium(void);
    int16_t setPhotoFov_Narrow(void);
    int16_t setPhotoColor_Gopro(void);
    int16_t setPhotoColor_Flat(void);
    int16_t setPhotoWhiteBalance_Auto(void);
    int16_t setPhotoWhiteBalance_3000K(void);
    int16_t setPhotoWhiteBalance_4000K(void);
    int16_t setPhotoWhiteBalance_4800K(void);
    int16_t setPhotoWhiteBalance_5500K(void);
    int16_t setPhotoWhiteBalance_6000K(void);
    int16_t setPhotoWhiteBalance_6500K(void);
    int16_t setPhotoWhiteBalance_Native(void);
    int16_t setPhotoIsoMin_1600(void);
    int16_t setPhotoIsoMin_800(void);
    int16_t setPhotoIsoMin_400(void);
    int16_t setPhotoIsoMin_200(void);
    int16_t setPhotoIsoMin_100(void);
    int16_t setPhotoIsoMax_1600(void);
    int16_t setPhotoIsoMax_800(void);
    int16_t setPhotoIsoMax_400(void);
    int16_t setPhotoIsoMax_200(void);
    int16_t setPhotoIsoMax_100(void);
    int16_t setPhotoShutter_Auto(void);
    int16_t setPhotoShutter_1per125(void);
    int16_t setPhotoShutter_1per250(void);
    int16_t setPhotoShutter_1per500(void);
    int16_t setPhotoShutter_1per1000(void);
    int16_t setPhotoShutter_1per2000(void);
    int16_t setPhotoEvComp_plus2p0(void);
    int16_t setPhotoEvComp_plus1p5(void);
    int16_t setPhotoEvComp_plus1p0(void);
    int16_t setPhotoEvComp_plus0p5(void);
    int16_t setPhotoEvComp_0(void);
    int16_t setPhotoEvComp_minus0p5(void);
    int16_t setPhotoEvComp_minus1p0(void);
    int16_t setPhotoEvComp_minus1p5(void);
    int16_t setPhotoEvComp_minus2p0(void);
    int16_t setPhotoSharpness_High(void);
    int16_t setPhotoSharpness_Medium(void);
    int16_t setPhotoSharpness_Low(void);
    int16_t setPhotoProtune_Off(void);
    int16_t setPhotoProtune_On(void);
    int16_t setPhotoWdr_On(void);
    int16_t setPhotoWdr_Off(void);
    int16_t setPhotoRawFormat_On(void);
    int16_t setPhotoRawFormat_Off(void);
    int16_t setPhotoNightShutter_Auto(void);
    int16_t setPhotoNightShutter_2Sec(void);
    int16_t setPhotoNightShutter_5Sec(void);
    int16_t setPhotoNightShutter_10Sec(void);
    int16_t setPhotoNightShutter_15Sec(void);
    int16_t setPhotoNightShutter_20Sec(void);
    int16_t setPhotoNightShutter_30Sec(void);
    int16_t setPhotoBurstRate_3per1(void);
    int16_t setPhotoBurstRate_5per1(void);
    int16_t setPhotoBurstRate_10per1(void);
    int16_t setPhotoBurstRate_10per2(void);
    int16_t setPhotoBurstRate_10per3(void);
    int16_t setPhotoBurstRate_30per1(void);
    int16_t setPhotoBurstRate_30per2(void);
    int16_t setPhotoBurstRate_30per3(void);
    int16_t setPhotoBurstRate_30per6(void);
    int16_t setMultishotTimelapseVideoInterval_0p5Sec(void);
    int16_t setMultishotTimelapseVideoInterval_1Sec(void);
    int16_t setMultishotTimelapseVideoInterval_2Sec(void);
    int16_t setMultishotTimelapseVideoInterval_5Sec(void);
    int16_t setMultishotTimelapseVideoInterval_10Sec(void);
    int16_t setMultishotTimelapseVideoInterval_30Sec(void);
    int16_t setMultishotTimelapseVideoInterval_60Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_0p5Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_1Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_2Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_5Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_10Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_30Sec(void);
    int16_t setMultishotTimelapsePhotoInterval_60Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_Auto(void);
    int16_t setMultishotNightlapsePhotoInterval_4Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_5Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_10Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_15Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_20Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_30Sec(void);
    int16_t setMultishotNightlapsePhotoInterval_1Min(void);
    int16_t setMultishotNightlapsePhotoInterval_2Min(void);
    int16_t setMultishotNightlapsePhotoInterval_5Min(void);
    int16_t setMultishotNightlapsePhotoInterval_30Min(void);
    int16_t setMultishotNightlapsePhotoInterval_60Min(void);
    int16_t setVoiceControl_On(void);
    int16_t setVoiceControl_Off(void);
    int16_t setVoiceControlLanguage_EnglishUs(void);
    int16_t setVoiceControlLanguage_EnglishUk(void);
    int16_t setVoiceControlLanguage_EnglishAus(void);
    int16_t setVoiceControlLanguage_German(void);
    int16_t setVoiceControlLanguage_French(void);
    int16_t setVoiceControlLanguage_Italian(void);
    int16_t setVoiceControlLanguage_Spanish(void);
    int16_t setVoiceControlLanguage_SpanishNa(void);
    int16_t setVoiceControlLanguage_Chinese(void);
    int16_t setVoiceControlLanguage_Japanese(void);
    int16_t setBeepVolume_Mute(void);
    int16_t setBeepVolume_Low(void);
    int16_t setBeepVolume_Medium(void);
    int16_t setBeepVolume_High(void);
    int16_t setLed_AllOff(void);
    int16_t setLed_AllOn(void);
    int16_t setLed_FrontOffOnly(void);
    int16_t setQuickcapture_On(void);
    int16_t setQuickcapture_Off(void);
    int16_t setDefaultMode_Video(void);
    int16_t setDefaultMode_VideoplusPhoto(void);
    int16_t setDefaultMode_Looping(void);
    int16_t setDefaultMode_Photo(void);
    int16_t setDefaultMode_Night(void);
    int16_t setDefaultMode_Burst(void);
    int16_t setDefaultMode_TimelapseVideo(void);
    int16_t setDefaultMode_TimelapsePhoto(void);
    int16_t setDefaultMode_NightlapsePhoto(void);
    int16_t setAutoOff_Never(void);
    int16_t setAutoOff_5Min(void);
    int16_t setAutoOff_15Min(void);
    int16_t setAutoOff_30Min(void);
    int16_t setScreensaver_Never(void);
    int16_t setScreensaver_1Min(void);
    int16_t setScreensaver_2Min(void);
    int16_t setScreensaver_3Min(void);
    int16_t setBrightness_100Percent(void);
    int16_t setBrightness_60Percent(void);
    int16_t setBrightness_30Percent(void);
    int16_t setBrightness_10Percent(void);
    int16_t setAutoRotation_Up(void);
    int16_t setAutoRotation_Down(void);
    int16_t setAutoRotation_Auto(void);
    int16_t setGps_On(void);
    int16_t setGps_Off(void);
    int16_t setLanguage_English(void);
    int16_t setLanguage_Chinese(void);
    int16_t setLanguage_German(void);
    int16_t setLanguage_Italian(void);
    int16_t setLanguage_Spanish(void);
    int16_t setLanguage_Japanese(void);
    int16_t setLanguage_French(void);
    int16_t setVideoFormat_Ntsc(void);
    int16_t setVideoFormat_Pal(void);
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

int16_t owGoProAdvancedClass::setVideoResolution_4K(void)
{
    GOPRO_DBG("gopro video resolution 4k");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_4K);
}


int16_t owGoProAdvancedClass::setVideoResolution_2p7K(void)
{
    GOPRO_DBG("gopro video resolution 2.7k");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_2P7K);
}


int16_t owGoProAdvancedClass::setVideoResolution_2p7K4to3(void)
{
    GOPRO_DBG("gopro video resolution 2.7k 4:3");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_2P7K_4TO3);
}


int16_t owGoProAdvancedClass::setVideoResolution_1440(void)
{
    GOPRO_DBG("gopro video resolution 1440");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_1440);
}


int16_t owGoProAdvancedClass::setVideoResolution_1080(void)
{
    GOPRO_DBG("gopro video resolution 1080");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_1080);
}


int16_t owGoProAdvancedClass::setVideoResolution_960(void)
{
    GOPRO_DBG("gopro video resolution 960");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_960);
}


int16_t owGoProAdvancedClass::setVideoResolution_720(void)
{
    GOPRO_DBG("gopro video resolution 720");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_720);
}


int16_t owGoProAdvancedClass::setVideoResolution_480(void)
{
    GOPRO_DBG("gopro video resolution 480");
    return setSetting(GOPRO_SET_VIDEO_RESOLUTION_480);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_240Fps(void)
{
    GOPRO_DBG("gopro video frame rate 240fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_240FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_120Fps(void)
{
    GOPRO_DBG("gopro video frame rate 120fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_120FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_100Fps(void)
{
    GOPRO_DBG("gopro video frame rate 100fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_100FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_90Fps(void)
{
    GOPRO_DBG("gopro video frame rate 90fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_90FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_80Fps(void)
{
    GOPRO_DBG("gopro video frame rate 80fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_80FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_60Fps(void)
{
    GOPRO_DBG("gopro video frame rate 60fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_60FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_50Fps(void)
{
    GOPRO_DBG("gopro video frame rate 50fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_50FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_48Fps(void)
{
    GOPRO_DBG("gopro video frame rate 48fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_48FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_30Fps(void)
{
    GOPRO_DBG("gopro video frame rate 30fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_30FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_25Fps(void)
{
    GOPRO_DBG("gopro video frame rate 25fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_25FPS);
}


int16_t owGoProAdvancedClass::setVideoFrameRate_24Fps(void)
{
    GOPRO_DBG("gopro video frame rate 24fps");
    return setSetting(GOPRO_SET_VIDEO_FRAME_RATE_24FPS);
}


int16_t owGoProAdvancedClass::setVideoFov_Superview(void)
{
    GOPRO_DBG("gopro video fov superview");
    return setSetting(GOPRO_SET_VIDEO_FOV_SUPERVIEW);
}


int16_t owGoProAdvancedClass::setVideoFov_Wide(void)
{
    GOPRO_DBG("gopro video fov wide");
    return setSetting(GOPRO_SET_VIDEO_FOV_WIDE);
}


int16_t owGoProAdvancedClass::setVideoFov_Medium(void)
{
    GOPRO_DBG("gopro video fov medium");
    return setSetting(GOPRO_SET_VIDEO_FOV_MEDIUM);
}


int16_t owGoProAdvancedClass::setVideoFov_Linear(void)
{
    GOPRO_DBG("gopro video fov linear");
    return setSetting(GOPRO_SET_VIDEO_FOV_LINEAR);
}


int16_t owGoProAdvancedClass::setVideoFov_Narrow(void)
{
    GOPRO_DBG("gopro video fov narrow");
    return setSetting(GOPRO_SET_VIDEO_FOV_NARROW);
}


int16_t owGoProAdvancedClass::setVideoColor_Gopro(void)
{
    GOPRO_DBG("gopro video color gopro");
    return setSetting(GOPRO_SET_VIDEO_COLOR_GOPRO);
}


int16_t owGoProAdvancedClass::setVideoColor_Flat(void)
{
    GOPRO_DBG("gopro video color flat");
    return setSetting(GOPRO_SET_VIDEO_COLOR_FLAT);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_Auto(void)
{
    GOPRO_DBG("gopro video white balance auto");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_AUTO);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_3000K(void)
{
    GOPRO_DBG("gopro video white balance 3000k");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_3000K);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_4000K(void)
{
    GOPRO_DBG("gopro video white balance 4000k");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_4000K);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_4800K(void)
{
    GOPRO_DBG("gopro video white balance 4800k");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_4800K);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_5500K(void)
{
    GOPRO_DBG("gopro video white balance 5500k");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_5500K);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_6000K(void)
{
    GOPRO_DBG("gopro video white balance 6000k");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_6000K);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_6500K(void)
{
    GOPRO_DBG("gopro video white balance 6500k");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_6500K);
}


int16_t owGoProAdvancedClass::setVideoWhiteBalance_Native(void)
{
    GOPRO_DBG("gopro video white balance native");
    return setSetting(GOPRO_SET_VIDEO_WHITE_BALANCE_NATIVE);
}


int16_t owGoProAdvancedClass::setVideoIso_6400(void)
{
    GOPRO_DBG("gopro video iso 6400");
    return setSetting(GOPRO_SET_VIDEO_ISO_6400);
}


int16_t owGoProAdvancedClass::setVideoIso_3200(void)
{
    GOPRO_DBG("gopro video iso 3200");
    return setSetting(GOPRO_SET_VIDEO_ISO_3200);
}


int16_t owGoProAdvancedClass::setVideoIso_1600(void)
{
    GOPRO_DBG("gopro video iso 1600");
    return setSetting(GOPRO_SET_VIDEO_ISO_1600);
}


int16_t owGoProAdvancedClass::setVideoIso_1200(void)
{
    GOPRO_DBG("gopro video iso 1200");
    return setSetting(GOPRO_SET_VIDEO_ISO_1200);
}


int16_t owGoProAdvancedClass::setVideoIso_800(void)
{
    GOPRO_DBG("gopro video iso 800");
    return setSetting(GOPRO_SET_VIDEO_ISO_800);
}


int16_t owGoProAdvancedClass::setVideoIso_400(void)
{
    GOPRO_DBG("gopro video iso 400");
    return setSetting(GOPRO_SET_VIDEO_ISO_400);
}


int16_t owGoProAdvancedClass::setVideoShutter_Auto(void)
{
    GOPRO_DBG("gopro video shutter auto");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_AUTO);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per24(void)
{
    GOPRO_DBG("gopro video shutter 1/24");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER24);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per30(void)
{
    GOPRO_DBG("gopro video shutter 1/30");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER30);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per48(void)
{
    GOPRO_DBG("gopro video shutter 1/48");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER48);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per60(void)
{
    GOPRO_DBG("gopro video shutter 1/60");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER60);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per90(void)
{
    GOPRO_DBG("gopro video shutter 1/90");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER90);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per96(void)
{
    GOPRO_DBG("gopro video shutter 1/96");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER96);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per120(void)
{
    GOPRO_DBG("gopro video shutter 1/120");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER120);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per180(void)
{
    GOPRO_DBG("gopro video shutter 1/180");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER180);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per192(void)
{
    GOPRO_DBG("gopro video shutter 1/192");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER192);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per240(void)
{
    GOPRO_DBG("gopro video shutter 1/240");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER240);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per360(void)
{
    GOPRO_DBG("gopro video shutter 1/360");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER360);
}


int16_t owGoProAdvancedClass::setVideoShutter_1per480(void)
{
    GOPRO_DBG("gopro video shutter 1/480");
    return setSetting(GOPRO_SET_VIDEO_SHUTTER_1PER480);
}


int16_t owGoProAdvancedClass::setVideoEvComp_plus2p0(void)
{
    GOPRO_DBG("gopro video ev comp +2.0");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_PLUS2P0);
}


int16_t owGoProAdvancedClass::setVideoEvComp_plus1p5(void)
{
    GOPRO_DBG("gopro video ev comp +1.5");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_PLUS1P5);
}


int16_t owGoProAdvancedClass::setVideoEvComp_plus1p0(void)
{
    GOPRO_DBG("gopro video ev comp +1.0");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_PLUS1P0);
}


int16_t owGoProAdvancedClass::setVideoEvComp_plus0p5(void)
{
    GOPRO_DBG("gopro video ev comp +0.5");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_PLUS0P5);
}


int16_t owGoProAdvancedClass::setVideoEvComp_0(void)
{
    GOPRO_DBG("gopro video ev comp 0");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_0);
}


int16_t owGoProAdvancedClass::setVideoEvComp_minus0p5(void)
{
    GOPRO_DBG("gopro video ev comp -0.5");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_MINUS0P5);
}


int16_t owGoProAdvancedClass::setVideoEvComp_minus1p0(void)
{
    GOPRO_DBG("gopro video ev comp -1.0");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_MINUS1P0);
}


int16_t owGoProAdvancedClass::setVideoEvComp_minus1p5(void)
{
    GOPRO_DBG("gopro video ev comp -1.5");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_MINUS1P5);
}


int16_t owGoProAdvancedClass::setVideoEvComp_minus2p0(void)
{
    GOPRO_DBG("gopro video ev comp -2.0");
    return setSetting(GOPRO_SET_VIDEO_EV_COMP_MINUS2P0);
}


int16_t owGoProAdvancedClass::setVideoSharpness_High(void)
{
    GOPRO_DBG("gopro video sharpness high");
    return setSetting(GOPRO_SET_VIDEO_SHARPNESS_HIGH);
}


int16_t owGoProAdvancedClass::setVideoSharpness_Medium(void)
{
    GOPRO_DBG("gopro video sharpness medium");
    return setSetting(GOPRO_SET_VIDEO_SHARPNESS_MEDIUM);
}


int16_t owGoProAdvancedClass::setVideoSharpness_Low(void)
{
    GOPRO_DBG("gopro video sharpness low");
    return setSetting(GOPRO_SET_VIDEO_SHARPNESS_LOW);
}


int16_t owGoProAdvancedClass::setVideoRawAudioTrack_Off(void)
{
    GOPRO_DBG("gopro video raw audio track off");
    return setSetting(GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_OFF);
}


int16_t owGoProAdvancedClass::setVideoRawAudioTrack_Low(void)
{
    GOPRO_DBG("gopro video raw audio track low");
    return setSetting(GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_LOW);
}


int16_t owGoProAdvancedClass::setVideoRawAudioTrack_Medium(void)
{
    GOPRO_DBG("gopro video raw audio track medium");
    return setSetting(GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_MEDIUM);
}


int16_t owGoProAdvancedClass::setVideoRawAudioTrack_High(void)
{
    GOPRO_DBG("gopro video raw audio track high");
    return setSetting(GOPRO_SET_VIDEO_RAW_AUDIO_TRACK_HIGH);
}


int16_t owGoProAdvancedClass::setVideoProtune_Off(void)
{
    GOPRO_DBG("gopro video protune off");
    return setSetting(GOPRO_SET_VIDEO_PROTUNE_OFF);
}


int16_t owGoProAdvancedClass::setVideoProtune_On(void)
{
    GOPRO_DBG("gopro video protune on");
    return setSetting(GOPRO_SET_VIDEO_PROTUNE_ON);
}


int16_t owGoProAdvancedClass::setVideoEis_Off(void)
{
    GOPRO_DBG("gopro video eis off");
    return setSetting(GOPRO_SET_VIDEO_EIS_OFF);
}


int16_t owGoProAdvancedClass::setVideoEis_On(void)
{
    GOPRO_DBG("gopro video eis on");
    return setSetting(GOPRO_SET_VIDEO_EIS_ON);
}


int16_t owGoProAdvancedClass::setVideoAutoLowLight_Off(void)
{
    GOPRO_DBG("gopro video auto low light off");
    return setSetting(GOPRO_SET_VIDEO_AUTO_LOW_LIGHT_OFF);
}


int16_t owGoProAdvancedClass::setVideoAutoLowLight_On(void)
{
    GOPRO_DBG("gopro video auto low light on");
    return setSetting(GOPRO_SET_VIDEO_AUTO_LOW_LIGHT_ON);
}


int16_t owGoProAdvancedClass::setVideoManualAudioControl_Off(void)
{
    GOPRO_DBG("gopro video manual audio control off");
    return setSetting(GOPRO_SET_VIDEO_MANUAL_AUDIO_CONTROL_OFF);
}


int16_t owGoProAdvancedClass::setVideoManualAudioControl_SteroOnly(void)
{
    GOPRO_DBG("gopro video manual audio control stero only");
    return setSetting(GOPRO_SET_VIDEO_MANUAL_AUDIO_CONTROL_STERO_ONLY);
}


int16_t owGoProAdvancedClass::setVideoManualAudioControl_WindOnly(void)
{
    GOPRO_DBG("gopro video manual audio control wind only");
    return setSetting(GOPRO_SET_VIDEO_MANUAL_AUDIO_CONTROL_WIND_ONLY);
}


int16_t owGoProAdvancedClass::setVideoPhotoInterval_5Sec(void)
{
    GOPRO_DBG("gopro video photo interval 5 sec");
    return setSetting(GOPRO_SET_VIDEO_PHOTO_INTERVAL_5_SEC);
}


int16_t owGoProAdvancedClass::setVideoPhotoInterval_10Sec(void)
{
    GOPRO_DBG("gopro video photo interval 10 sec");
    return setSetting(GOPRO_SET_VIDEO_PHOTO_INTERVAL_10_SEC);
}


int16_t owGoProAdvancedClass::setVideoPhotoInterval_30Sec(void)
{
    GOPRO_DBG("gopro video photo interval 30 sec");
    return setSetting(GOPRO_SET_VIDEO_PHOTO_INTERVAL_30_SEC);
}


int16_t owGoProAdvancedClass::setVideoPhotoInterval_60Sec(void)
{
    GOPRO_DBG("gopro video photo interval 60 sec");
    return setSetting(GOPRO_SET_VIDEO_PHOTO_INTERVAL_60_SEC);
}


int16_t owGoProAdvancedClass::setVideoLoopingInterval_Max(void)
{
    GOPRO_DBG("gopro video looping interval max");
    return setSetting(GOPRO_SET_VIDEO_LOOPING_INTERVAL_MAX);
}


int16_t owGoProAdvancedClass::setVideoLoopingInterval_5Min(void)
{
    GOPRO_DBG("gopro video looping interval 5 min");
    return setSetting(GOPRO_SET_VIDEO_LOOPING_INTERVAL_5_MIN);
}


int16_t owGoProAdvancedClass::setVideoLoopingInterval_20Min(void)
{
    GOPRO_DBG("gopro video looping interval 20 min");
    return setSetting(GOPRO_SET_VIDEO_LOOPING_INTERVAL_20_MIN);
}


int16_t owGoProAdvancedClass::setVideoLoopingInterval_60Min(void)
{
    GOPRO_DBG("gopro video looping interval 60 min");
    return setSetting(GOPRO_SET_VIDEO_LOOPING_INTERVAL_60_MIN);
}


int16_t owGoProAdvancedClass::setVideoLoopingInterval_120Min(void)
{
    GOPRO_DBG("gopro video looping interval 120 min");
    return setSetting(GOPRO_SET_VIDEO_LOOPING_INTERVAL_120_MIN);
}


int16_t owGoProAdvancedClass::setPhotoFov_Wide(void)
{
    GOPRO_DBG("gopro photo fov wide");
    return setSetting(GOPRO_SET_PHOTO_FOV_WIDE);
}


int16_t owGoProAdvancedClass::setPhotoFov_Linear(void)
{
    GOPRO_DBG("gopro photo fov linear");
    return setSetting(GOPRO_SET_PHOTO_FOV_LINEAR);
}


int16_t owGoProAdvancedClass::setPhotoFov_Medium(void)
{
    GOPRO_DBG("gopro photo fov medium");
    return setSetting(GOPRO_SET_PHOTO_FOV_MEDIUM);
}


int16_t owGoProAdvancedClass::setPhotoFov_Narrow(void)
{
    GOPRO_DBG("gopro photo fov narrow");
    return setSetting(GOPRO_SET_PHOTO_FOV_NARROW);
}


int16_t owGoProAdvancedClass::setPhotoColor_Gopro(void)
{
    GOPRO_DBG("gopro photo color gopro");
    return setSetting(GOPRO_SET_PHOTO_COLOR_GOPRO);
}


int16_t owGoProAdvancedClass::setPhotoColor_Flat(void)
{
    GOPRO_DBG("gopro photo color flat");
    return setSetting(GOPRO_SET_PHOTO_COLOR_FLAT);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_Auto(void)
{
    GOPRO_DBG("gopro photo white balance auto");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_AUTO);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_3000K(void)
{
    GOPRO_DBG("gopro photo white balance 3000k");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_3000K);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_4000K(void)
{
    GOPRO_DBG("gopro photo white balance 4000k");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_4000K);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_4800K(void)
{
    GOPRO_DBG("gopro photo white balance 4800k");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_4800K);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_5500K(void)
{
    GOPRO_DBG("gopro photo white balance 5500k");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_5500K);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_6000K(void)
{
    GOPRO_DBG("gopro photo white balance 6000k");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_6000K);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_6500K(void)
{
    GOPRO_DBG("gopro photo white balance 6500k");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_6500K);
}


int16_t owGoProAdvancedClass::setPhotoWhiteBalance_Native(void)
{
    GOPRO_DBG("gopro photo white balance native");
    return setSetting(GOPRO_SET_PHOTO_WHITE_BALANCE_NATIVE);
}


int16_t owGoProAdvancedClass::setPhotoIsoMin_1600(void)
{
    GOPRO_DBG("gopro photo iso min 1600");
    return setSetting(GOPRO_SET_PHOTO_ISO_MIN_1600);
}


int16_t owGoProAdvancedClass::setPhotoIsoMin_800(void)
{
    GOPRO_DBG("gopro photo iso min 800");
    return setSetting(GOPRO_SET_PHOTO_ISO_MIN_800);
}


int16_t owGoProAdvancedClass::setPhotoIsoMin_400(void)
{
    GOPRO_DBG("gopro photo iso min 400");
    return setSetting(GOPRO_SET_PHOTO_ISO_MIN_400);
}


int16_t owGoProAdvancedClass::setPhotoIsoMin_200(void)
{
    GOPRO_DBG("gopro photo iso min 200");
    return setSetting(GOPRO_SET_PHOTO_ISO_MIN_200);
}


int16_t owGoProAdvancedClass::setPhotoIsoMin_100(void)
{
    GOPRO_DBG("gopro photo iso min 100");
    return setSetting(GOPRO_SET_PHOTO_ISO_MIN_100);
}


int16_t owGoProAdvancedClass::setPhotoIsoMax_1600(void)
{
    GOPRO_DBG("gopro photo iso max 1600");
    return setSetting(GOPRO_SET_PHOTO_ISO_MAX_1600);
}


int16_t owGoProAdvancedClass::setPhotoIsoMax_800(void)
{
    GOPRO_DBG("gopro photo iso max 800");
    return setSetting(GOPRO_SET_PHOTO_ISO_MAX_800);
}


int16_t owGoProAdvancedClass::setPhotoIsoMax_400(void)
{
    GOPRO_DBG("gopro photo iso max 400");
    return setSetting(GOPRO_SET_PHOTO_ISO_MAX_400);
}


int16_t owGoProAdvancedClass::setPhotoIsoMax_200(void)
{
    GOPRO_DBG("gopro photo iso max 200");
    return setSetting(GOPRO_SET_PHOTO_ISO_MAX_200);
}


int16_t owGoProAdvancedClass::setPhotoIsoMax_100(void)
{
    GOPRO_DBG("gopro photo iso max 100");
    return setSetting(GOPRO_SET_PHOTO_ISO_MAX_100);
}


int16_t owGoProAdvancedClass::setPhotoShutter_Auto(void)
{
    GOPRO_DBG("gopro photo shutter auto");
    return setSetting(GOPRO_SET_PHOTO_SHUTTER_AUTO);
}


int16_t owGoProAdvancedClass::setPhotoShutter_1per125(void)
{
    GOPRO_DBG("gopro photo shutter 1/125");
    return setSetting(GOPRO_SET_PHOTO_SHUTTER_1PER125);
}


int16_t owGoProAdvancedClass::setPhotoShutter_1per250(void)
{
    GOPRO_DBG("gopro photo shutter 1/250");
    return setSetting(GOPRO_SET_PHOTO_SHUTTER_1PER250);
}


int16_t owGoProAdvancedClass::setPhotoShutter_1per500(void)
{
    GOPRO_DBG("gopro photo shutter 1/500");
    return setSetting(GOPRO_SET_PHOTO_SHUTTER_1PER500);
}


int16_t owGoProAdvancedClass::setPhotoShutter_1per1000(void)
{
    GOPRO_DBG("gopro photo shutter 1/1000");
    return setSetting(GOPRO_SET_PHOTO_SHUTTER_1PER1000);
}


int16_t owGoProAdvancedClass::setPhotoShutter_1per2000(void)
{
    GOPRO_DBG("gopro photo shutter 1/2000");
    return setSetting(GOPRO_SET_PHOTO_SHUTTER_1PER2000);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_plus2p0(void)
{
    GOPRO_DBG("gopro photo ev comp +2.0");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_PLUS2P0);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_plus1p5(void)
{
    GOPRO_DBG("gopro photo ev comp +1.5");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_PLUS1P5);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_plus1p0(void)
{
    GOPRO_DBG("gopro photo ev comp +1.0");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_PLUS1P0);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_plus0p5(void)
{
    GOPRO_DBG("gopro photo ev comp +0.5");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_PLUS0P5);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_0(void)
{
    GOPRO_DBG("gopro photo ev comp 0");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_0);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_minus0p5(void)
{
    GOPRO_DBG("gopro photo ev comp -0.5");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_MINUS0P5);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_minus1p0(void)
{
    GOPRO_DBG("gopro photo ev comp -1.0");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_MINUS1P0);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_minus1p5(void)
{
    GOPRO_DBG("gopro photo ev comp -1.5");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_MINUS1P5);
}


int16_t owGoProAdvancedClass::setPhotoEvComp_minus2p0(void)
{
    GOPRO_DBG("gopro photo ev comp -2.0");
    return setSetting(GOPRO_SET_PHOTO_EV_COMP_MINUS2P0);
}


int16_t owGoProAdvancedClass::setPhotoSharpness_High(void)
{
    GOPRO_DBG("gopro photo sharpness high");
    return setSetting(GOPRO_SET_PHOTO_SHARPNESS_HIGH);
}


int16_t owGoProAdvancedClass::setPhotoSharpness_Medium(void)
{
    GOPRO_DBG("gopro photo sharpness medium");
    return setSetting(GOPRO_SET_PHOTO_SHARPNESS_MEDIUM);
}


int16_t owGoProAdvancedClass::setPhotoSharpness_Low(void)
{
    GOPRO_DBG("gopro photo sharpness low");
    return setSetting(GOPRO_SET_PHOTO_SHARPNESS_LOW);
}


int16_t owGoProAdvancedClass::setPhotoProtune_Off(void)
{
    GOPRO_DBG("gopro photo protune off");
    return setSetting(GOPRO_SET_PHOTO_PROTUNE_OFF);
}


int16_t owGoProAdvancedClass::setPhotoProtune_On(void)
{
    GOPRO_DBG("gopro photo protune on");
    return setSetting(GOPRO_SET_PHOTO_PROTUNE_ON);
}


int16_t owGoProAdvancedClass::setPhotoWdr_On(void)
{
    GOPRO_DBG("gopro photo wdr on");
    return setSetting(GOPRO_SET_PHOTO_WDR_ON);
}


int16_t owGoProAdvancedClass::setPhotoWdr_Off(void)
{
    GOPRO_DBG("gopro photo wdr off");
    return setSetting(GOPRO_SET_PHOTO_WDR_OFF);
}


int16_t owGoProAdvancedClass::setPhotoRawFormat_On(void)
{
    GOPRO_DBG("gopro photo raw format on");
    return setSetting(GOPRO_SET_PHOTO_RAW_FORMAT_ON);
}


int16_t owGoProAdvancedClass::setPhotoRawFormat_Off(void)
{
    GOPRO_DBG("gopro photo raw format off");
    return setSetting(GOPRO_SET_PHOTO_RAW_FORMAT_OFF);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_Auto(void)
{
    GOPRO_DBG("gopro photo night shutter auto");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_AUTO);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_2Sec(void)
{
    GOPRO_DBG("gopro photo night shutter 2 sec");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_2_SEC);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_5Sec(void)
{
    GOPRO_DBG("gopro photo night shutter 5 sec");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_5_SEC);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_10Sec(void)
{
    GOPRO_DBG("gopro photo night shutter 10 sec");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_10_SEC);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_15Sec(void)
{
    GOPRO_DBG("gopro photo night shutter 15 sec");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_15_SEC);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_20Sec(void)
{
    GOPRO_DBG("gopro photo night shutter 20 sec");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_20_SEC);
}


int16_t owGoProAdvancedClass::setPhotoNightShutter_30Sec(void)
{
    GOPRO_DBG("gopro photo night shutter 30 sec");
    return setSetting(GOPRO_SET_PHOTO_NIGHT_SHUTTER_30_SEC);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_3per1(void)
{
    GOPRO_DBG("gopro photo burst rate 3/1");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_3PER1);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_5per1(void)
{
    GOPRO_DBG("gopro photo burst rate 5/1");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_5PER1);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_10per1(void)
{
    GOPRO_DBG("gopro photo burst rate 10/1");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_10PER1);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_10per2(void)
{
    GOPRO_DBG("gopro photo burst rate 10/2");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_10PER2);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_10per3(void)
{
    GOPRO_DBG("gopro photo burst rate 10/3");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_10PER3);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_30per1(void)
{
    GOPRO_DBG("gopro photo burst rate 30/1");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_30PER1);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_30per2(void)
{
    GOPRO_DBG("gopro photo burst rate 30/2");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_30PER2);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_30per3(void)
{
    GOPRO_DBG("gopro photo burst rate 30/3");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_30PER3);
}


int16_t owGoProAdvancedClass::setPhotoBurstRate_30per6(void)
{
    GOPRO_DBG("gopro photo burst rate 30/6");
    return setSetting(GOPRO_SET_PHOTO_BURST_RATE_30PER6);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_0p5Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 0.5 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_0P5_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_1Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 1 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_1_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_2Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 2 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_2_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_5Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 5 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_5_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_10Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 10 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_10_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_30Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 30 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_30_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapseVideoInterval_60Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse video interval 60 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_VIDEO_INTERVAL_60_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_0p5Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 0.5 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_0P5_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_1Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 1 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_1_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_2Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 2 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_2_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_5Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 5 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_5_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_10Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 10 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_10_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_30Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 30 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_30_SEC);
}


int16_t owGoProAdvancedClass::setMultishotTimelapsePhotoInterval_60Sec(void)
{
    GOPRO_DBG("gopro multishot timelapse photo interval 60 sec");
    return setSetting(GOPRO_SET_MULTISHOT_TIMELAPSE_PHOTO_INTERVAL_60_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_Auto(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval auto");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_AUTO);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_4Sec(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 4 sec");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_4_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_5Sec(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 5 sec");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_5_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_10Sec(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 10 sec");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_10_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_15Sec(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 15 sec");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_15_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_20Sec(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 20 sec");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_20_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_30Sec(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 30 sec");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_30_SEC);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_1Min(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 1 min");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_1_MIN);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_2Min(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 2 min");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_2_MIN);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_5Min(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 5 min");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_5_MIN);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_30Min(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 30 min");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_30_MIN);
}


int16_t owGoProAdvancedClass::setMultishotNightlapsePhotoInterval_60Min(void)
{
    GOPRO_DBG("gopro multishot nightlapse photo interval 60 min");
    return setSetting(GOPRO_SET_MULTISHOT_NIGHTLAPSE_PHOTO_INTERVAL_60_MIN);
}


int16_t owGoProAdvancedClass::setVoiceControl_On(void)
{
    GOPRO_DBG("gopro voice control on");
    return setSetting(GOPRO_SET_VOICE_CONTROL_ON);
}


int16_t owGoProAdvancedClass::setVoiceControl_Off(void)
{
    GOPRO_DBG("gopro voice control off");
    return setSetting(GOPRO_SET_VOICE_CONTROL_OFF);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_EnglishUs(void)
{
    GOPRO_DBG("gopro voice control language english us");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_ENGLISH_US);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_EnglishUk(void)
{
    GOPRO_DBG("gopro voice control language english uk");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_ENGLISH_UK);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_EnglishAus(void)
{
    GOPRO_DBG("gopro voice control language english aus");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_ENGLISH_AUS);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_German(void)
{
    GOPRO_DBG("gopro voice control language german");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_GERMAN);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_French(void)
{
    GOPRO_DBG("gopro voice control language french");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_FRENCH);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_Italian(void)
{
    GOPRO_DBG("gopro voice control language italian");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_ITALIAN);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_Spanish(void)
{
    GOPRO_DBG("gopro voice control language spanish");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_SPANISH);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_SpanishNa(void)
{
    GOPRO_DBG("gopro voice control language spanish na");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_SPANISH_NA);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_Chinese(void)
{
    GOPRO_DBG("gopro voice control language chinese");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_CHINESE);
}


int16_t owGoProAdvancedClass::setVoiceControlLanguage_Japanese(void)
{
    GOPRO_DBG("gopro voice control language japanese");
    return setSetting(GOPRO_SET_VOICE_CONTROL_LANGUAGE_JAPANESE);
}


int16_t owGoProAdvancedClass::setBeepVolume_Mute(void)
{
    GOPRO_DBG("gopro beep volume mute");
    return setSetting(GOPRO_SET_BEEP_VOLUME_MUTE);
}


int16_t owGoProAdvancedClass::setBeepVolume_Low(void)
{
    GOPRO_DBG("gopro beep volume low");
    return setSetting(GOPRO_SET_BEEP_VOLUME_LOW);
}


int16_t owGoProAdvancedClass::setBeepVolume_Medium(void)
{
    GOPRO_DBG("gopro beep volume medium");
    return setSetting(GOPRO_SET_BEEP_VOLUME_MEDIUM);
}


int16_t owGoProAdvancedClass::setBeepVolume_High(void)
{
    GOPRO_DBG("gopro beep volume high");
    return setSetting(GOPRO_SET_BEEP_VOLUME_HIGH);
}


int16_t owGoProAdvancedClass::setLed_AllOff(void)
{
    GOPRO_DBG("gopro led all off");
    return setSetting(GOPRO_SET_LED_ALL_OFF);
}


int16_t owGoProAdvancedClass::setLed_AllOn(void)
{
    GOPRO_DBG("gopro led all on");
    return setSetting(GOPRO_SET_LED_ALL_ON);
}


int16_t owGoProAdvancedClass::setLed_FrontOffOnly(void)
{
    GOPRO_DBG("gopro led front off only");
    return setSetting(GOPRO_SET_LED_FRONT_OFF_ONLY);
}


int16_t owGoProAdvancedClass::setQuickcapture_On(void)
{
    GOPRO_DBG("gopro quickcapture on");
    return setSetting(GOPRO_SET_QUICKCAPTURE_ON);
}


int16_t owGoProAdvancedClass::setQuickcapture_Off(void)
{
    GOPRO_DBG("gopro quickcapture off");
    return setSetting(GOPRO_SET_QUICKCAPTURE_OFF);
}


int16_t owGoProAdvancedClass::setDefaultMode_Video(void)
{
    GOPRO_DBG("gopro default mode video");
    return setSetting(GOPRO_SET_DEFAULT_MODE_VIDEO);
}


int16_t owGoProAdvancedClass::setDefaultMode_VideoplusPhoto(void)
{
    GOPRO_DBG("gopro default mode video+photo");
    return setSetting(GOPRO_SET_DEFAULT_MODE_VIDEOPLUSPHOTO);
}


int16_t owGoProAdvancedClass::setDefaultMode_Looping(void)
{
    GOPRO_DBG("gopro default mode looping");
    return setSetting(GOPRO_SET_DEFAULT_MODE_LOOPING);
}


int16_t owGoProAdvancedClass::setDefaultMode_Photo(void)
{
    GOPRO_DBG("gopro default mode photo");
    return setSetting(GOPRO_SET_DEFAULT_MODE_PHOTO);
}


int16_t owGoProAdvancedClass::setDefaultMode_Night(void)
{
    GOPRO_DBG("gopro default mode night");
    return setSetting(GOPRO_SET_DEFAULT_MODE_NIGHT);
}


int16_t owGoProAdvancedClass::setDefaultMode_Burst(void)
{
    GOPRO_DBG("gopro default mode burst");
    return setSetting(GOPRO_SET_DEFAULT_MODE_BURST);
}


int16_t owGoProAdvancedClass::setDefaultMode_TimelapseVideo(void)
{
    GOPRO_DBG("gopro default mode timelapse video");
    return setSetting(GOPRO_SET_DEFAULT_MODE_TIMELAPSE_VIDEO);
}


int16_t owGoProAdvancedClass::setDefaultMode_TimelapsePhoto(void)
{
    GOPRO_DBG("gopro default mode timelapse photo");
    return setSetting(GOPRO_SET_DEFAULT_MODE_TIMELAPSE_PHOTO);
}


int16_t owGoProAdvancedClass::setDefaultMode_NightlapsePhoto(void)
{
    GOPRO_DBG("gopro default mode nightlapse photo");
    return setSetting(GOPRO_SET_DEFAULT_MODE_NIGHTLAPSE_PHOTO);
}


int16_t owGoProAdvancedClass::setAutoOff_Never(void)
{
    GOPRO_DBG("gopro auto off never");
    return setSetting(GOPRO_SET_AUTO_OFF_NEVER);
}


int16_t owGoProAdvancedClass::setAutoOff_5Min(void)
{
    GOPRO_DBG("gopro auto off 5 min");
    return setSetting(GOPRO_SET_AUTO_OFF_5_MIN);
}


int16_t owGoProAdvancedClass::setAutoOff_15Min(void)
{
    GOPRO_DBG("gopro auto off 15 min");
    return setSetting(GOPRO_SET_AUTO_OFF_15_MIN);
}


int16_t owGoProAdvancedClass::setAutoOff_30Min(void)
{
    GOPRO_DBG("gopro auto off 30 min");
    return setSetting(GOPRO_SET_AUTO_OFF_30_MIN);
}


int16_t owGoProAdvancedClass::setScreensaver_Never(void)
{
    GOPRO_DBG("gopro screensaver never");
    return setSetting(GOPRO_SET_SCREENSAVER_NEVER);
}


int16_t owGoProAdvancedClass::setScreensaver_1Min(void)
{
    GOPRO_DBG("gopro screensaver 1 min");
    return setSetting(GOPRO_SET_SCREENSAVER_1_MIN);
}


int16_t owGoProAdvancedClass::setScreensaver_2Min(void)
{
    GOPRO_DBG("gopro screensaver 2 min");
    return setSetting(GOPRO_SET_SCREENSAVER_2_MIN);
}


int16_t owGoProAdvancedClass::setScreensaver_3Min(void)
{
    GOPRO_DBG("gopro screensaver 3 min");
    return setSetting(GOPRO_SET_SCREENSAVER_3_MIN);
}


int16_t owGoProAdvancedClass::setBrightness_100Percent(void)
{
    GOPRO_DBG("gopro brightness 100 %");
    return setSetting(GOPRO_SET_BRIGHTNESS_100_PERCENT);
}


int16_t owGoProAdvancedClass::setBrightness_60Percent(void)
{
    GOPRO_DBG("gopro brightness 60 %");
    return setSetting(GOPRO_SET_BRIGHTNESS_60_PERCENT);
}


int16_t owGoProAdvancedClass::setBrightness_30Percent(void)
{
    GOPRO_DBG("gopro brightness 30 %");
    return setSetting(GOPRO_SET_BRIGHTNESS_30_PERCENT);
}


int16_t owGoProAdvancedClass::setBrightness_10Percent(void)
{
    GOPRO_DBG("gopro brightness 10 %");
    return setSetting(GOPRO_SET_BRIGHTNESS_10_PERCENT);
}


int16_t owGoProAdvancedClass::setAutoRotation_Up(void)
{
    GOPRO_DBG("gopro auto rotation up");
    return setSetting(GOPRO_SET_AUTO_ROTATION_UP);
}


int16_t owGoProAdvancedClass::setAutoRotation_Down(void)
{
    GOPRO_DBG("gopro auto rotation down");
    return setSetting(GOPRO_SET_AUTO_ROTATION_DOWN);
}


int16_t owGoProAdvancedClass::setAutoRotation_Auto(void)
{
    GOPRO_DBG("gopro auto rotation auto");
    return setSetting(GOPRO_SET_AUTO_ROTATION_AUTO);
}


int16_t owGoProAdvancedClass::setGps_On(void)
{
    GOPRO_DBG("gopro gps on");
    return setSetting(GOPRO_SET_GPS_ON);
}


int16_t owGoProAdvancedClass::setGps_Off(void)
{
    GOPRO_DBG("gopro gps off");
    return setSetting(GOPRO_SET_GPS_OFF);
}


int16_t owGoProAdvancedClass::setLanguage_English(void)
{
    GOPRO_DBG("gopro language english");
    return setSetting(GOPRO_SET_LANGUAGE_ENGLISH);
}


int16_t owGoProAdvancedClass::setLanguage_Chinese(void)
{
    GOPRO_DBG("gopro language chinese");
    return setSetting(GOPRO_SET_LANGUAGE_CHINESE);
}


int16_t owGoProAdvancedClass::setLanguage_German(void)
{
    GOPRO_DBG("gopro language german");
    return setSetting(GOPRO_SET_LANGUAGE_GERMAN);
}


int16_t owGoProAdvancedClass::setLanguage_Italian(void)
{
    GOPRO_DBG("gopro language italian");
    return setSetting(GOPRO_SET_LANGUAGE_ITALIAN);
}


int16_t owGoProAdvancedClass::setLanguage_Spanish(void)
{
    GOPRO_DBG("gopro language spanish");
    return setSetting(GOPRO_SET_LANGUAGE_SPANISH);
}


int16_t owGoProAdvancedClass::setLanguage_Japanese(void)
{
    GOPRO_DBG("gopro language japanese");
    return setSetting(GOPRO_SET_LANGUAGE_JAPANESE);
}


int16_t owGoProAdvancedClass::setLanguage_French(void)
{
    GOPRO_DBG("gopro language french");
    return setSetting(GOPRO_SET_LANGUAGE_FRENCH);
}


int16_t owGoProAdvancedClass::setVideoFormat_Ntsc(void)
{
    GOPRO_DBG("gopro video format ntsc");
    return setSetting(GOPRO_SET_VIDEO_FORMAT_NTSC);
}


int16_t owGoProAdvancedClass::setVideoFormat_Pal(void)
{
    GOPRO_DBG("gopro video format pal");
    return setSetting(GOPRO_SET_VIDEO_FORMAT_PAL);
}

#endif
//end of owGoProAdvancedClass
  

