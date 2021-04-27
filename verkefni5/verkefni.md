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
1. Til hvers er `IRQ` pinninn og hvernig væri hægt að nota hann td. fyrir fjarstýrða bílinn?

---

### 5.5 Þráðlaus samskipti í báðar áttir með tveimur Arduino. 
Sýndu samskipti sem fara í báðar áttir með notkun takka og led. Sjá síðara sýnidæmið í [myndbandinu](https://howtomechatronics.com/tutorials/arduino/arduino-wireless-communication-nrf24l01-tutorial/)
   - [Myndband af virkni](https://youtu.be/8b_cnncqXsI)
   - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni5/5.5_Wireless_nRF24L01_twoway/5.5_wirless_comm_twoway/5.5_wirless_comm_twoway.ino)

   ath: til að master-slave samskiptin virki þarf slave að hafa read, write addressin að vera öfug. t.d. master með read = addr 0, write = addr 1 þá þarf slave að hafa 
   read = 1 og write = 0
---

### 5.6 Inter-Integrated Circuit (I2C) Protocol (1%)
Lestu [I2C](https://www.circuitbasics.com/basics-of-the-i2c-communication-protocol/) og svaraðu eftirfarandi spurningum:

   1. I2C notar message og address, hvað er það og hvernig virkar það?
   1. Hvað er hægt að senda mikið af gögnum (bits) í einu?
   1. Hver er helsti munurinn á SPI og I2C? 

---

### 5.7. I2C með tvo Arduino (3%)
Kynntu þér [I2C Communications](https://dronebotworkshop.com/i2c-arduino-arduino/). Sjá einnig [Wire library](https://www.arduino.cc/en/reference/wire)

1. Settu upp kóðasýnidæmin í Arduino IDE -> File -> Examples -> Wire -> slave_sender og master_reader
1. Útskýrðu hvað eftirfarandi kóði gerir:
   1. `Wire.beginTransmission(ADDRESS);` Hvaða ADDRESS eru ekki í boði?
   1. `Wire.onReceive(receiveEvent);` og `Wire.onRequest(requestEvent);` 

<!--
1. Settu upp síðari tilraunina **Arduino Remote Using I2C** (með breytiviðnámi og led) sem kemur fyrir í [I2C Communications](https://dronebotworkshop.com/i2c-arduino-arduino/) verklega. 
-->
---

### 5.8 MPU6050 (3%) 
1. Kynntu þér [MPU6050](https://lastminuteengineers.com/mpu6050-accel-gyro-arduino-tutorial/) og settu upp verklega bæði kóðadæmin í greininni. Sjá einnig skýringar í [Workshop myndbandi](https://dronebotworkshop.com/mpu-6050-level/).
1. Svaraðu eftirfarandi spurningum:
   1. Hvernig virkar MPU6050 og hvað að er hægt að gera með honum?
   1. Hvað gera XDA og XCL pinnarnir?
 
---

### 5.9 Að stjórna servo motor með MPU6050 (2%) 
Notaðu MPU6050 til að stjórna servo mótor. Skoðaðu t.d. [LED](https://www.youtube.com/watch?v=7ZmmFVJ8dAI) og [Servo](https://maker.pro/arduino/tutorial/how-to-control-a-servo-with-an-arduino-and-mpu6050)

<!--
- [Workshop: 3D Simulation With Processing](https://www.instructables.com/id/Arduino-MPU6050-GY521-6-Axis-Accelerometer-Gyro-3D/)
-->
