## Verkefni 5 (21%)

### 5.1 Interrupts 
1. Kynntu þér hvernig interrupts virkar og svaraðu eftirfarandi spurningum:
   1. Hvernig notar þú interrupts?
      - Þú attachar interrupt í kóða á pinna og þegar pinnin fær spennubreyttu hvort sem það er drop, hækkun eða almenn breyting á spennu sem er allt stýrt í gegnum                     kóða er hægt að keyra kóða strax og geymd kóða sem var verið að keyra á tímanum, svo er haldið áfram venjulega eftir að interrupt functionið er búinn að keyra.
   1. Hvenær er heppilegt að nota interrupts. komdu með dæmi?
      - Ef þú ert að nota Millisekundur fallið í arduino til að checka hvort það var ýtt á takka eða ekki, í staðinn er hægt að setja interrupt á hann og þegar það kemur                 spennubreyta keyrist kóðinn og það kemur við að þú þarft ekki að eyða klukkutíðni og processing í að kíkja hvort það var ýtt á takkan eða ekki.
   1. Hvað eru volatile breytur?
      - Það eru breytur sem eru loadaðir í volatile memory, t.d. RAM. Það er gert til að hraðvirkja kóðann sem breytann er notuð í. Það er mjög algengt að declare breytur               volatile sem eru notaðar í Interrupt. 
1. Settu upp verklega kóða sem notar takka og led með notkun interrupts.
   - [Myndband af virkni](https://youtu.be/JBGjoEG0Slo)
   - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.1_interrupts/interrupt/interrupt.ino)

**Bjargir:**
- [Myndband; Arduino Interrupts](https://www.youtube.com/watch?v=QtyOiTw0oQc) 
- [Vefgrein: Interrupt Service Routines (ISR)](http://gammon.com.au/interrupts)
- [attachinterrupt()](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
- Adafruit - Multi-tasking the Arduino (notar class); [Part 1: millis](https://learn.adafruit.com/multi-tasking-the-arduino-part-1) og [Part 2: interrupts](https://learn.adafruit.com/multi-tasking-the-arduino-part-2/overview)

---

### 5.2 SPI samskiptastaðallinn. 
Lestu [BASICS OF THE SPI COMMUNICATION PROTOCOL](https://www.circuitbasics.com/basics-of-the-spi-communication-protocol), sjá einnig [myndband um SPI](https://www.youtube.com/watch?v=ldRkXTBw9_o) og svaraðu eftirfarandi spurningum:
   
   1. Hvað er átt við með samstilltum (e. synchronous) samskiptastaðli?
      - Það á við hvernig bits færast á milli master og slave með clock signal, með synchronous samskiðpastaðli synchronisar masterinn clockið sem stjórnar hvernig samskiptinn           milli master og slave mun hegða sér. Hraðinn á synchronous samskipstaðli er stýrt af frequency af clock signalinu.
   3. Útskýrðu master-slave samskipti í SPI útfrá; MISO, MOSI, SCLK og CS/SS.
      - SCLK eða Serial Clock er til að stjórna samskipti milli Microcontroller og hvað sem það er tengd við.
      - MISO (Master in slave out) er input fyrir Masterinn í master-slave samskipti.
      - MOSI (Master out slave in) er input fyrir slave í master-slave samskipti.
      - CS/SS (Chip select / Slave select) er til að segja slave að vera viðbúinn að taka á móti signali og ef það er fleiri en einn slave er sagt hvor slave á að taka móti             signalinu.
      Með þessum tengíngum er hægt að koma við Master-slave samskipti og er mögulegt að taka út CS/SS, MOSI eða MISO eftir því hvað þarfnast í samskiptinu.
   4. Hverjir eru helstu kostir og ókostir við SPI?
      - óKostir við SPI eru:
         - Notar fjóra víra meðan I2C og UART notar tvo.
         - Er ekki með ACK af því að gögnin hafi borist með góðum árangri.
         - er ekki með error checking eins og UART sem notar parity bit.
         - Aðeins leyfir fyrir einn master í Master-slave samskipti.
      - Kostir við SPI eru 
          - Þar sem það er ekki error checking er allt send í einu sem kemur að þvi að gögnin eru send án start og stop bits sem þýðir fljótari millufærsla af bitum.
          - er einfald meðan við önnur communications protocols.
          - Mun fljótari að millifæra bits meðan við hinn communications protocolin.
          - Það er með full duplex (MISO, MOSI) er með sitthvora tengingu.

---

### 5.3 SPI samskipti milli tveggja Arduino. 
Settu upp á Breadboard með Arduino Uno og [Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano) þannig að þeir geti notað SPI samskipti með [SPI safninu](https://www.arduino.cc/en/reference/SPI) til að tala saman.
1. Arduino Uno á að geta sent streng (nafnið þitt) til Arduino Nano sem birtir svo nafn á Serial Monitor. Sjá t.d. [How do you use SPI on an Arduino?](https://arduino.stackexchange.com/questions/16348/how-do-you-use-spi-on-an-arduino).
   - [Myndband af virkni](https://youtu.be/N7RIMoUrLho)
   - [Kóði - Master](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.3_SPI_Communications_Arduino/5.3_1_ardu_comm_text/Master/Master.ino)
   - [Kóði - Slave](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.3_SPI_Communications_Arduino/5.3_1_ardu_comm_text/Slave/Slave.ino)
1. Bættu takka við Arduino Uno. Þegar ýtt er á hann þá á led sem er tengt við Arduino Nano að lýsa. 
   - [Myndband af virkni](https://youtu.be/d85kyIewoYc)
   - [Kóði - Master](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.3_SPI_Communications_Arduino/5.3_2-3_ardu_comm_btn_lights/Master_SPI/Master_SPI.ino)
   - [Kóði - Slave](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.3_SPI_Communications_Arduino/5.3_2-3_ardu_comm_btn_lights/Slave_SPI/Slave_SPI.ino)
1. Bættu við öðrum takka og led, sjá [uppsetningu](https://raw.githubusercontent.com/VESM3/V21/master/Myndir/SPI.png)  þannig að hægt sé að eiga samskipti í báðar áttir með tökkum. Sjá [kóða](https://gist.github.com/gestskoli/d2069beb5c4d0cf7c9351d75dfc3e2b0) og [Communication between two Arduino Boards](https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial) 
   - [Myndband af virkni](https://youtu.be/w2A9PUIwKpY)
   - [Kóði - Master](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.3_SPI_Communications_Arduino/5.3_2-3_ardu_comm_btn_lights/Master_SPI/Master_SPI.ino)
   - [Kóði - Slave](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.3_SPI_Communications_Arduino/5.3_2-3_ardu_comm_btn_lights/Slave_SPI/Slave_SPI.ino)
<!-- 1. Bættu takka við Arduino Uno. Þegar ýtt er á hann þá á led sem er tengt við Arduino Nano að lýsa. -->

---

### 5.4 Þráðlaus samskipti tveggja Arduino með notkun nRF24L01 (í eina átt) 
Lestu vel og vandlega og fylgdu tutorial: [How nRF24L01+ Wireless Module Works & Interface with Arduino](https://lastminuteengineers.com/nrf24l01-arduino-wireless-communication/). Skoðaðu einnig fyrra sýnidæmið í [myndbandinu](https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/)

1. Notaðu [RF24 safnið](https://github.com/nRF24/RF24) og settu upp verklega með Arduino Uno og Nano. Tengdu nRF24L01 sem hefur **ekki** nRF24L01+ Adapter við 3.3V output, ekki tengja í 5V, það mun skemma nRF24L01. Notaðu einnig 9V batterí (stöðugra) fremur en usb portið á tölvunni. Einnig gott að nota 100f rafþéttir (capacitor).
1. Passaðu að hafa sömu tíðnina (Radio Frequency) og fremur há gildi með `.setChannel()` í setup falli.
1. Strengurinn inniheldur nafnið þitt (ekki Hello World)
1. Láttu LED lýsa hjá `transmitter` sem staðfestir að strengur hafi borist til `receiver`. 
   - [Kóði - Receiver](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.4_Wireless_nRF24L01_oneway/Receiver/Receiver.ino)
   - [Kóði - Transmitter](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.4_Wireless_nRF24L01_oneway/transmitter/transmitter.ino)
   - [Myndband af virkni - SERIAL MONITOR](https://youtu.be/kiTj3d13LVQ)
   - [Myndband af virkni - LED](https://youtu.be/tdYbaj1a9CA)

Það eru tvö myndbönd vegna þess að ég gleymdi að taka upp seríal monitorinn í LED myndbandinu, en ef þú kíkjir í fyrsta myndbandið sérðu að það virkar og getur kíkt á kóðan til að sjá að það er skilaboðið sem lætur LEDið blikka.
1. Til hvers er `IRQ` pinninn og hvernig væri hægt að nota hann td. fyrir fjarstýrða bílinn?
   - Það er interrupt pini sem gerir masterinum var við nýjum gögnum. Það er hægt að nota hann með sonic sensorinum til að stopa bílinn ef hann kemur of nálægt veggi.  

---

### 5.5 Þráðlaus samskipti í báðar áttir með tveimur Arduino. 
Sýndu samskipti sem fara í báðar áttir með notkun takka og led. Sjá síðara sýnidæmið í [myndbandinu](https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/)
   - [Myndband af virkni](https://youtu.be/8b_cnncqXsI)
   - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.5_Wireless_nRF24L01_twoway/5.5_wirless_comm_twoway/5.5_wirless_comm_twoway.ino)

   ath: til að master-slave samskiptin virki verður slave að hafa öfuga read, write addressur á moti masterinum. t.d. master með read = addr 0, write = addr 1 þá þarf slave að      hafa read = 1 og write = 0

---

### 5.6 Inter-Integrated Circuit (I2C) Protocol (1%)
Lestu [I2C](https://www.circuitbasics.com/basics-of-the-i2c-communication-protocol/) og svaraðu eftirfarandi spurningum:

   1. I2C notar message og address, hvað er það og hvernig virkar það?
      - I2C virkar svipað og OSI - datalink layerinn virkar, það sendir frame sem inniheldur skilaboði sem er brotinn niður í minni hluta, og einn partur af messsageinu er Address frame sem inniheldur 7 bita (eða 10 en flestar greinir benda á að það eru aðeins 7) sem eru í einstaku röð sem greinir hvern slave er verið að ná í. Ef það er send 7 bita þá er max slaves sem kemur til greina 2^7 = 128.
   2. Hvað er hægt að senda mikið af gögnum (bits) í einu?
      - 8 bits með most significant bit sem fyrsta bit. 
   3. Hver er helsti munurinn á SPI og I2C? 
      - I2C er með ACK/NACK bit sem gefur staðfestingu að gögnin millifærðust með góðum árangri.
      - Það tekur aðeins tvo víra sem er mjög gott ef verið að nota marga slaves.
      - Styður marga masters miðað við SPI sem styður aðeins 1

---

### 5.7. I2C með tvo Arduino (3%)
Kynntu þér [I2C Communications](https://dronebotworkshop.com/i2c-arduino-arduino/). Sjá einnig [Wire library](https://www.arduino.cc/en/reference/wire)

1. Settu upp kóðasýnidæmin í Arduino IDE -> File -> Examples -> Wire -> slave_sender og master_reader
   - [Myndband af virkni](https://www.youtube.com/watch?v=sIL3RBXLBGM&ab_channel=Icgxstriker)
   - [Kóði - Master](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.7_I2C/master_reader/master_reader.ino)
   - [Kóði - Slave](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.7_I2C/slave_sender/slave_sender.ino)
1. Útskýrðu hvað eftirfarandi kóði gerir:
   1. `Wire.beginTransmission(ADDRESS);` Hvaða ADDRESS eru ekki í boði?
      - Það byrjar samskiptin með slave sem er með addressið sem er set í functionið. Þar sem address eru 7 bitar eru aðeins addressin á 0-127 til og allt utan fyrir þessar             tölur virka ekki. Addressin eru í binary.
   3. `Wire.onReceive(receiveEvent);` og `Wire.onRequest(requestEvent);` 
   - Wire.onReceive(receiveEvent) keyrir function þegar slave fær transmission frá masterinum.
   - Wire.onRequest(requestEvent) keyrir function þegar master biður um gögn frá slave device.

<!--
1. Settu upp síðari tilraunina **Arduino Remote Using I2C** (með breytiviðnámi og led) sem kemur fyrir í [I2C Communications](https://dronebotworkshop.com/i2c-arduino-arduino/) verklega. 
-->
---

### 5.8 MPU6050 (3%) 
1. Kynntu þér [MPU6050](https://lastminuteengineers.com/mpu6050-accel-gyro-arduino-tutorial/) og settu upp verklega bæði kóðadæmin í greininni. Sjá einnig skýringar í [Workshop myndbandi](https://dronebotworkshop.com/mpu-6050-level/).
1. Svaraðu eftirfarandi spurningum:
   1. Hvernig virkar MPU6050 og hvað að er hægt að gera með honum?
      - MPU 6050 er gyroscope, accelerometer og hitamælir, sem þýðir að hann getur mælt snúníng, hraða og hita. 
        1. Til að mæla hraða getur accelerometer tekið in aflið sem valdi breytu í hreyfinguni sem veldur því að massin kreistir eitthvað þekkt sem 'piezoelectric efni' sem                 skilar frá sér rafhleðslu sem er í rettu hlutfalli við kraftinn sem var beittur á hann.
            - í MPU6050 er notað eitthvað sem er kallað MEM Accelerometer sem notar sílikísil sem beygir þegar hröðun er beit á tiltekna ás og Vegna sveigju er rýmd milli fastra               platna og platna sem eru festir við sviflausnina breytt. Þessi breyting á rýmd er í réttu hlutfalli við hröðunina á þeim ás.
        1. Til að mæla snúning er notað eitthvað þekkt sem Coriolis Effect segir okkur að þegar massa (m) hreyfist í tiltekna átt með hraða (v) og ytri hornhraða (Ω) er beitt              Coriolis áhrif mynda kraft sem veldur hornréttri tilfærslu á massa. Gildi þessarar tilfærslu er í beinu samhengi við beittan hlutfallshorn.
            - MPU6050 notar eitthvað þekkt sem MEMS gyroscope sem er samsettur af sönnunarmassa sem inniheldur 4 hluta (m1, m2, m3, m4) sem er haldið í stöðugum                               sveifluhreyfingum þannig að það bregst við coriolis áhrifunum. Þau hreyfast inn og út samtímis í lárétta planinu. Þegar við byrjum að snúa uppbyggingunni breytir                 Coriolis-krafturinn sem virkar á hreyfanlegan sönnunarmassa titring titringsins frá láréttri til lóðréttrar. Það eru þrjár stillingar eftir því hvaða ás                         hornhringurinn er beittur og þessi þrjár stillingar gefa út rýmisbreytingu sem skynjurabyggingin tekur upp og breytist síðan í spennumerki.
       Það er hægt að nota MPU6050 í mörg tillföll þar sem hraðamæling, snúningsmælingar eða hitamælingar eru vantaðar. 
   - [Myndband af virkni](https://youtu.be/b3BR2_ULqwg)
   - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.8_MPU6050/5.8_MPU6050_DATA/5.8_MPU6050_DATA.ino)
 
---

### 5.9 Að stjórna servo motor með MPU6050 (2%) 
Notaðu MPU6050 til að stjórna servo mótor. Skoðaðu t.d. [LED](https://www.youtube.com/watch?v=7ZmmFVJ8dAI) og [Servo](https://maker.pro/arduino/tutorial/how-to-control-a-servo-with-an-arduino-and-mpu6050)
   - [Myndband af virkni](https://youtu.be/p-cR5t2Ps98)
   - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.9_MPU6050_SERVO_MOTOR/5.9_mpu6050_Servo/5.9_mpu6050_Servo.ino)

<!--
- [Workshop: 3D Simulation With Processing](https://www.instructables.com/id/Arduino-MPU6050-GY521-6-Axis-Accelerometer-Gyro-3D/)
-->
