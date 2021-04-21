### 5.1 Interrupts 
1. Kynntu þér hvernig interrupts virkar og svaraðu eftirfarandi spurningum:
   1. Hvernig notar þú interrupts?
      * Þú attachar interrupt í kóða á pinna við takka og þegar pinnin fær spennubreyttu hvort sem það er drop, hækkun eða almenn breyting á spennu er hægt að keyra kóða strax           og geymd kóða sem er verið að keyra á tímanum.
   1. Hvenær er heppilegt að nota interrupts. komdu með dæmi?
      * Ef þú ert að nota Millisekundur fallið í arduino til að checka hvort það var ýtt á takka eða ekki, í staðinn er hægt að setja interrupt á hann og þegar það kemur                 spennubreyta keyrist kóðinn og það kemur við að þú þarft ekki að nota pullup/pulldown viðnám og þarft ekki að eyða klukkutíðni og processing í að kíkja hvort það var ýtt         á takkan eða ekki.
   1. Hvað eru volatile breytur?
      * Það eru breytur sem eru loadaðir í volatile memory, t.d. RAM. Það er gert til að hraðvirkja kóðann sem breytann er notuð í. Það er mjög algengt að declare breytur               volatile sem eru notaðar í Interrupt.
1. Settu upp verklega kóða sem notar takka og led með notkun interrupts.
   - [Myndband af virkni](https://youtu.be/JBGjoEG0Slo)

**Bjargir:**
- [Myndband; Arduino Interrupts](https://www.youtube.com/watch?v=QtyOiTw0oQc) 
- [Vefgrein: Interrupt Service Routines (ISR)](http://gammon.com.au/interrupts)
- [attachinterrupt()](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
- Adafruit - Multi-tasking the Arduino (notar class); [Part 1: millis](https://learn.adafruit.com/multi-tasking-the-arduino-part-1) og [Part 2: interrupts](https://learn.adafruit.com/multi-tasking-the-arduino-part-2/overview)

---

### 5.2 SPI samskiptastaðallinn. 
Lestu [BASICS OF THE SPI COMMUNICATION PROTOCOL](https://www.circuitbasics.com/basics-of-the-spi-communication-protocol), sjá einnig [myndband um SPI](https://www.youtube.com/watch?v=ldRkXTBw9_o) og svaraðu eftirfarandi spurningum:
   
   1. Hvað er átt við með samstilltum (e. synchronous) samskiptastaðli?
   1. Útskýrðu master-slave samskipti í SPI útfrá; MISO, MOSI, SCLK og CS/SS.
   1. Hverjir eru helstu kostir og ókostir við SPI?

---

### 5.3 SPI samskipti milli tveggja Arduino. 
Settu upp á Breadboard með Arduino Uno og [Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano) þannig að þeir geti notað SPI samskipti með [SPI safninu](https://www.arduino.cc/en/reference/SPI) til að tala saman.
1. Arduino Uno á að geta sent streng (nafnið þitt) til Arduino Nano sem birtir svo nafn á Serial Monitor. Sjá t.d. [How do you use SPI on an Arduino?](https://arduino.stackexchange.com/questions/16348/how-do-you-use-spi-on-an-arduino).
1. Bættu takka við Arduino Uno. Þegar ýtt er á hann þá á led sem er tengt við Arduino Nano að lýsa. 
   - [Myndband af virkni](https://youtu.be/d85kyIewoYc)
1. Bættu við öðrum takka og led, sjá [uppsetningu](https://raw.githubusercontent.com/VESM3/V21/master/Myndir/SPI.png)  þannig að hægt sé að eiga samskipti í báðar áttir með tökkum. Sjá [kóða](https://gist.github.com/gestskoli/d2069beb5c4d0cf7c9351d75dfc3e2b0) og [Communication between two Arduino Boards](https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial) 
   - [Myndband af virkni](https://youtu.be/w2A9PUIwKpY)

---

### 5.1 Interrupts 
1. Kynntu þér hvernig interrupts virkar og svaraðu eftirfarandi spurningum:
   1. Hvernig notar þú interrupts?
      * Þú attachar interrupt í kóða á pinna við takka og þegar pinnin fær spennubreyttu hvort sem það er drop, hækkun eða almenn breyting á spennu er hægt að keyra kóða strax           og geymd kóða sem er verið að keyra á tímanum.
   1. Hvenær er heppilegt að nota interrupts. komdu með dæmi?
      * Ef þú ert að nota Millisekundur fallið í arduino til að checka hvort það var ýtt á takka eða ekki, í staðinn er hægt að setja interrupt á hann og þegar það kemur                 spennubreyta keyrist kóðinn og það kemur við að þú þarft ekki að nota pullup/pulldown viðnám og þarft ekki að eyða klukkutíðni og processing í að kíkja hvort það var ýtt         á takkan eða ekki.
   1. Hvað eru volatile breytur?
      * Það eru breytur sem eru loadaðir í volatile memory, t.d. RAM. Það er gert til að hraðvirkja kóðann sem breytann er notuð í. Það er mjög algengt að declare breytur               volatile sem eru notaðar í Interrupt.
1. Settu upp verklega kóða sem notar takka og led með notkun interrupts.
   - [Myndband af virkni](https://youtu.be/JBGjoEG0Slo)

**Bjargir:**
- [Myndband; Arduino Interrupts](https://www.youtube.com/watch?v=QtyOiTw0oQc) 
- [Vefgrein: Interrupt Service Routines (ISR)](http://gammon.com.au/interrupts)
- [attachinterrupt()](https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/)
- Adafruit - Multi-tasking the Arduino (notar class); [Part 1: millis](https://learn.adafruit.com/multi-tasking-the-arduino-part-1) og [Part 2: interrupts](https://learn.adafruit.com/multi-tasking-the-arduino-part-2/overview)

---

### 5.2 SPI samskiptastaðallinn. 
Lestu [BASICS OF THE SPI COMMUNICATION PROTOCOL](https://www.circuitbasics.com/basics-of-the-spi-communication-protocol), sjá einnig [myndband um SPI](https://www.youtube.com/watch?v=ldRkXTBw9_o) og svaraðu eftirfarandi spurningum:
   
   1. Hvað er átt við með samstilltum (e. synchronous) samskiptastaðli?
   1. Útskýrðu master-slave samskipti í SPI útfrá; MISO, MOSI, SCLK og CS/SS.
   1. Hverjir eru helstu kostir og ókostir við SPI?

---

### 5.3 SPI samskipti milli tveggja Arduino. 
Settu upp á Breadboard með Arduino Uno og [Nano](https://www.arduino.cc/en/pmwiki.php?n=Main/ArduinoBoardNano) þannig að þeir geti notað SPI samskipti með [SPI safninu](https://www.arduino.cc/en/reference/SPI) til að tala saman.
1. Arduino Uno á að geta sent streng (nafnið þitt) til Arduino Nano sem birtir svo nafn á Serial Monitor. Sjá t.d. [How do you use SPI on an Arduino?](https://arduino.stackexchange.com/questions/16348/how-do-you-use-spi-on-an-arduino).
1. Bættu við tökkum og leds, sjá [uppsetningu](https://raw.githubusercontent.com/VESM3/V21/master/Myndir/SPI.png)  þannig að hægt sé að eiga samskipti í báðar áttir með tökkum. Sjá [kóða](https://gist.github.com/gestskoli/d2069beb5c4d0cf7c9351d75dfc3e2b0) og [Communication between two Arduino Boards](https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial)  
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

---
