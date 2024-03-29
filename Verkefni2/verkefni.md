## Verkefni 2

#### 1. Að vinna með hliðræn gildi (4%)

1. Notaðu [LDR](https://create.arduino.cc/projecthub/tarantula3/using-an-ldr-sensor-with-arduino-807b1c) ljósnema til að stýra birtustigi og litum á [RGB LED](https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/overview). Þegar það verður minni birta í umhverfinu þá eykst birtan smám saman (fade in) á RGB LED á móti með mismunandi litablæbrigðum og svo öfugt þegar birtan eykst í umhverfinu.
    1. Hvað er átt við með *duty cycle* í PWM?
        - Duty cycle í pwm er brot af hve oft það er verið að senda rafmagn á moti hvenar er ekki verið að senda rafmagn. Það er líka brot af heildar rafmagninu sem er verið að           senda. t.d. ef það er duty cycle af 90% og er verið að senda 5V þá er verið að senda 4.5V. 5V*0.9 = 4.5V þar sem 0.9 er prósentar eining af duty cycle.
    1. Afhverju skilar analogRead() heiltölu á bilinu 0-1023?
        - Fallið skilar voltum milli 0 til 5 og það gerir það með tölu sem er 10 bit integer. Hæðsta tala sem 10 bit tala kemst í er 1023 og lægsta 0 sem er 1024 tölur.
    - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni2/Code/RGB_LED_HEX.ino)
    - [Myndband af virkni](https://youtu.be/MHK1dHWkINs)
       
---

#### 2. HC-SR04 Ultrasonic Sensor (4%)
1. Kynntu þér hvernig HC-SR04 Ultrasonic Sensor virkar með því að lesa [þessa grein](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/). 
    1. Hversu nákvæmar eru mælingarnar með Ultrasonic Sensor?
        - Mælingarnar eru með 3mm mákvæmi.
1. Tengdu HC-SR04 við Arduino Uno og skoðaðu eftirfarandi [kóðasbút](https://github.com/VESM2VT/Efni/blob/main/Kodi/sonic.ino). Bættu við kóðann eftirfarandi:
   1. hann birtir fjarlægðir í cm í Serial monitor.
   2. ef fjarlægð er meiri en 4 metrar þá prentast á Serial monitor "Out of range". 
       - [Myndband af virkni](https://youtu.be/d8JXmF1WAME)
       - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni2/Code/sonic_sensor.ino)
   
   
---

#### 3. LCD (4%)
1. Kynntu þér hvernig 16×2 Character LCD virkar með því að lesa [þessa grein](https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/) og svaraðu eftirfarandi spurningum:
   1. Afhverju er R/W tengt í GND?
        - Ef það er tengt í GND festir það í Write þar sem við þurfum ekki Read er það fest í GND.
   1. Ahverju þarf að stýra LCD1602 með nokkrum pinnum (4 eða 8) á sama tíma? útskýrðu!
        - Ef þú ert með 4 pinna tengda þarf að splita bytei í hálft og framvkæma tvær write skipanir. Það er tvisvar sinum hraðari að nota 8 pina en þeir nota mikið I/O á                  arduinoinu. Þannig það er tengd 4 pina til að gera plás fyrir aðra hluti eins og t.d. Sonic sensor.
1. Settu upp [Halló heimur](https://lastminuteengineers.com/arduino-1602-character-lcd-tutorial/#arduino-code) en breyttu kóðanum þannig að nafnið þitt birtist í efri línunni á skjánum, einn stafur í einu. Í neðri línunni á að standa Tolvubraut. Skoðaðu aðferðir í [LiquidCrystal Library](https://www.arduino.cc/en/Reference/LiquidCrystal).
    - [Myndband](https://youtu.be/i0epgOb2OI8)
    - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni2/Code/LCD.ino)
 

---

#### 4. Ultrasonic og LCD (2%)

1. Fylgdu eftir [Contactless Distance Finder + LCD + LCDBarGraph](https://lastminuteengineers.com/arduino-sr04-ultrasonic-sensor-tutorial/#arduino-project-contactless-distance-finder) og settu upp verklega.
   1. Hvernig getur hitastig og raki úti haft áhrif á fjarlægðarmælingar með HC-SR04?
        - HC-SR04 mælir fjarlægð með hljóðbylgjum sem er á hraða hljóði. Samkvæmt þessa formúlu Speed of sound m/s = 331.4 + (0.606 * Temp) + (0.0124 * Humidity)
          hefur hitastig og rakastig áhrif á hraðan á hljóðinu sem getur valdið delay á hvenar bylgjurnar koma til baka til að geta mæld fjarlægð. Það er hægt að hafa góðan raka           og hitamælir til að setja í þessar formúlur sem er með lítið skeggjumark til að koma við að reikningurinn er nákvæmur.
        - [Myndband](https://www.youtube.com/watch?v=0KHbfkyl__Q&ab_channel=Icgxstriker)
        - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni2/Code/LCD_bar_graph.ino)
        
