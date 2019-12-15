! Olliw, Olliw42 GPL3
! GoPro HERO7 Black
! Firmware Version HD7.01.01.80.00
! I went through all settings, both in the App and the camera


#### Video

?Video Video oder Videoschleife
?------------

##### Aspect Ratio     ?Bildformat
* 4:3     108/0
* 16:9    108/1

default = 1

##### Resolution  ?Auflösung
* 4K              2/1           $if Format = 1
* 4K 4:3          2/18          $if Format = 0
* 2.7K            2/4           $if Format = 1
* 2.7K 4:3        2/6           $if Format = 0
* 1440            2/7           $if Format = 0
* 1080            2/9           $if Format = 1
* 960             2/10          $if Format = 0
* 720             2/12          $if Format = 1

default = 9

##### FPS    ?Bilder pro Sekunde
* 240     3/0
* 200     3/13
* 120     3/1
* 100     3/2
* 60      3/5
* 50      3/6
* 30      3/8
* 25      3/9
* 24      3/10

default = 5

/////
Intevall (nur in Videoschleife)

Max             6/0
5 Minuten       6/1
20 Minuten      6/2
60 Minuten      geht nicht???
120 Minuten     geht nicht??
/////

##### FOV  ?Sichtfeld
* Linear      4/4
* Wide        4/0
* SuperView   4/3

default = 0

##### Stabilization   ?Videostabilisierung
* Off     78/0
* Auto    78/1

default = 0

##### Low Light   ?Restlicht
* Off     8/0
* Auto    8/1

default = 0

##### Short Clip      ?Kurzer Clip (nur in Video)
* Off    107/0
* 15 s   107/1
* 30 s   107/2

default = 0

##### Protune  ?(nur in Video)
* Off     10/0
* On      10/1

default = 0

?wenn Protune ein:

##### Shutter  $if Protune = 1
* Auto    73/0    
* 1/60    73/8
* 1/120   73/13
* 1/240   73/18
* 1/480   73/22
* 1/960   73/23

default = 0

##### EV Comp  $if Protune = 1
* -2.0    15/8
* -1.5    15/7
* -1.0    15/6
* -0.5    15/5
* 0.0     15/4
* +0.5    15/3
* +1.0    15/2
* +1.5    15/1
* +2.0    15/0

default = 4

#####ISO Min  $if Protune = 1
* 100     102/8
* 200     102/7
* 400     102/2
* 800     102/4
* 1600    102/1
* 3200    102/3
* 6400    102/0

default = 0

##### ISO Max     $if Protune = 1
* 6400    13/0
* 3200    13/3
* 1600    13/1
* 800     13/4
* 400     13/2
* 200     13/7
* 100     13/8

default = 1

##### White Balance  $if Protune = 1
* Auto      11/0
* 2300 K    11/8
* 2800 K    11/9
* 3200 K    11/10
* 4000 K    11/5
* 4500 K    11/11
* 5000 K    11/12
* 5500 K    11/2
* 6000 K    11/7
* 6500 K    11/3
* Native    11/4

default = 0

##### Sharpness   $if Protune = 1
* High        14/0
* Medium      14/1
* Low         14/2

default = 0

##### Color    $if Protune = 1
* GoPro       12/0
* Flat        12/1

default = 0

##### RAW Audio    $if Protune = 1
* Off         81/3
* Low         81/0
* Medium      81/1
* High        81/2

default = 3

##### Mics   $if Protune = 1
* Auto        80/2
* Wind        80/1
* Stereo      80/0

default = 2




#### Photo

?Photo Foto
?--------------------

##### FOV             ?Megapixel
* Linear  17/10
* Wide    17/0

default = 0

##### SuperPhoto     ?SuperFoto
* Off     109/0
* Auto    109/1
* HDR On  109/2

default = 0

##### RAW
* Off     82/0
* On      82/1

default = 0

##### Timer
* Off    105/0
* 3 s    105/1
* 10 s   105/2

default = 0

##### Protune
* Off     21/0
* On      21/1

default = 0

?wenn Protune EIN:
 
##### Shutter   $if Protune = 1
* Auto        97/0
* 1/125       97/1
* 1/250       97/2
* 1/500       97/3
* 1/1000      97/4
* 1/2000      97/5

default = 0

##### EV Comp     $if Protune = 1
* -2.0        26/8
* -1.5        26/7
* -1.0        26/6
* -0.5        26/5
* 0.0         26/4
* +0.5        26/3
* +1.0        26/2
* +1.5        26/1
* +2.0        26/0

default = 4

##### ISO Min   $if Protune = 1
* 100         75/3
* 200         75/2
* 400         75/1
* 800         75/0
* 1600        75/4
* 3200        75/5

default = 3

##### ISO Max         $if Protune = 1
* 3200        24/5
* 1600        24/4
* 800         24/0
* 400         24/1
* 200         24/2
* 100         24/3

default = 5

##### White Balance     $if Protune = 1
* Auto        22/0
* 2300 K      22/8
* 2800 K      22/9
* 3200 K      22/10
* 4000 K      22/5
* 4500 K      22/11
* 5000 K      22/12
* 5500 K      22/2
* 6000 K      22/7
* 6500 K      22/3
* Native      22/4

default = 0

##### Sharpness        $if Protune = 1
* High        25/0
* Medium      25/1
* Low         25/2

default = 0

##### Color      $if Protune = 1
* GoPro       23/0
* Flat        23/1

default = 0


/////
Photo Serienaufnahme
--------------------

Rate

Auto                29/9
30 Fotos / 6 Sek    29/8
30 Fotos / 3 Sek    29/7
30 Fotos / 2 Sek    29/6
30 Fotos / 1 Sek    29/5
10 Fotos / 3 Sek    29/4
10 Fotos / 2 Sek    29/3
10 Fotos / 1 Sek    29/2
5 Fotos / 1 Sek     29/1
3 Fotos / 1 Sek     29/0

Megapixel

12 MP Linear    28/10
12 MP Weit      28/0

Protune

aus     34/0
ein     34/1

wenn Protune EIN:

Belichtungskorr.

-2.0        39/8
-1.5        39/7
-1.0        39/6
-0.5        39/5
0.0         39/4
+0.5        39/3
+1.0        39/2
+1.5        39/1
+2.0        39/0

default 39/4

ISO Min.

100         76/3
200         76/2
400         76/1
800         76/0
1600        76/4
3200        76/5

default 76/3

ISO-Limit

3200        37/5
1600        37/4
800         37/0
400         37/1
200         37/2
100         37/3

default 37/5

Weißabgleich

Auto        35/0
2300 K      35/8
2800 K      35/9
3200 K      35/10
4000 K      35/5
4500 K      35/11
5000 K      35/12
5500 K      35/2
6000 K      35/7
6500 K      35/3
Nativ       35/4

default  35/0

Schärfe

Hoch        38/0
Mittel      38/1
Niedrig     38/2

default     38/0

Farbe

GoPro Farbe 36/0
Matt        36/1

default     36/0


Photo Nachtbildaufnahme
--------------------

Auslöser

Auto            19/0
30 Sekunden     19/6
20 Sekunden     19/5
15 Sekunden     19/4
10 Sekunden     19/3
5 Sekunden      19/2
2 Sekunden      19/1

Megapixel

12 MP Linear    17/10
12 MP Weit      17/0

RAW

aus     98/0
ein     98/1

Protune  (entspricht exakt Photo Foto, nur ein paar defaults anders !!!!)

aus     21/0
ein     21/1

wenn Protune EIN:

ISO Min.

100         75/3
200         75/2
400         75/1
800         75/0
1600        75/4
3200        75/5

default 75/3

ISO-Limit

3200        24/5
1600        24/4
800         24/0
400         24/1
200         24/2
100         24/3

default 24/0

Weißabgleich

Auto        22/0
2300 K      22/8
2800 K      22/9
3200 K      22/10
4000 K      22/5
4500 K      22/11
5000 K      22/12
5500 K      22/2
6000 K      22/7
6500 K      22/3
Nativ       22/4

default  22/2

Schärfe

Hoch        25/0
Mittel      25/1
Niedrig     25/2

default     25/0

Farbe

GoPro Farbe 23/0
Matt        23/1

default     23/0




Zeitraffer

Zeitraffer TimeWarp-Video
--------------------------

Bildformat

Auflösung

Geschw.

Sichtfeld


Zeitraffer Zeitraffervideo
--------------------------

Bildformat

Auflösung

Intervall

Sichtfeld


Zeitraffer Zeitrafferfoto
--------------------------

Intervall

Megapixel

RAW

Protune


Zeitraffer Zeitraf. b. Nacht
--------------------------

Auslöser

Intervall

Megapixel

RAW

Protune



/////








#### Setup

##### Voice Control       ?Sprachsteurung aktivieren
* Off         86/0
* On          86/1

default = 0

##### Wake on Voice       ?Aktivieren durch Stimeingabe
* Off         104/0
* On          104/1

default = 0

##### Voice Control Language   ?Sprache für Sprachsteuerung
* Chinese           85/8
* English (AUS)     85/2
* English (IND)     85/13
* English (UK)      85/1
* English (US)      85/0
* French            85/4
* German            85/3
* Italian           85/5
* Japanese          85/9
* Korean            85/10
* Portugese (BR)    85/11
* Russian           85/12
* Spanish (EU)      85/6
* Spanish (NA)      85/7

default = 0

##### Beep Volume     ?Signaltöne
* Mute        87/0
* Low         87/40
* Medium      87/70
* High        87/100

default = 70

##### LEDS         ?LED-Blinken
* All Off         91/0
* All On          91/2
* Front Off Only  91/1

default = 2

##### Quick Capture
* Off         54/0
* On          54/1

default = 0

##### Default Mode       ?Standardmodus
* Video               89/12
* Looping             89/15
* Photo               89/17
* Night Photo         89/18
* Burst Photo         89/19
* Time Warp Video     89/24
* Time Lapse Video    89/13
* Time Lapse Photo    89/20
* Night Lapse Photo   89/21

default = 12

##### Auto Power Off        ?Autom. Abschaltung
* Never       59/0
* 5 Min       59/4
* 15 Min      59/6
* 30 Min      59/7

default = 0

##### Landscape Lock     ?Querformatsperre
* Off         112/0
* Up          112/1
* Down        112/2

default = 0

##### Screen Saver        ?Bildschirmschoner
* Never       51/0
* 1 Min       51/1
* 2 Min       51/2
* 3 Min       51/3

default = 0

?##### Brigthness      ?LCD-Helligkeit  ?//TODO
?* 0% - 100%         88/0-100

##### Brigthness      ?LCD-Helligkeit  ?TODO
* Off       88/0
* Low       88/40
* Medium    88/70
* High      88/100

default = 70

/////
Auto-Sperre   ???????  Auto Screen Lock ?????  this exist in the App, but not clear what it does
aus         103/3
ein         103/5

default = 
/////

##### GPS
* Off         83/0
* On          83/1

default = 0

##### Language      ?Sprache
* English       84/0
* Francais      84/6
* Deutsch       84/2
* Italiano      84/3
* Espanol       84/4
* Chinese       84/1
* Japanese      84/5
* Korean        84/7
* Portugues     84/8
* Russian       84/9

default =  0

##### Video Format
* NTSC        57/0     ?(this also sets 42:5)
* PAL         57/1     ?(this also sets 42:6)

default = 0

##### Video Compression    ?Videokompression
* H.264 + HEVC    106/0
* HEVC            106/1

default = 0
