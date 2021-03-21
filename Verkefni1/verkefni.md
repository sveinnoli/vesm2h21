#### DHT11 og serial monitor (3%)
1. Útskýrðu með eigin orðum hvernig rakinn er mældur.    
    - DHT11 reiknar hlutfallslegan rakastig með því að mæla rafmótstöðu milli tveggja rafskauta.
      Rakskynjunarþáttur DHT11 er undirlag sem gefur raka og rafskautin borin á yfirborðið. Þegar vatnsgufa frásogast af undirlaginu losna ions af undirlaginu sem eykur leiðni         milli rafskautanna. Breyting á viðnámi rafskautanna tveggja er í réttu hlutfalli við hlutfallslegan raka. Hærri rakastig minnkar viðnám milli rafskautanna en lægra               rakastig eykur viðnám rafskautanna.

1. Settu upp fyrri rásina í greininni (það á ekki að setja upp rásina með LCD skjánum).
    > [Myndband af virkni](https://youtu.be/zTZluUC8H4Q)
    > 
    > [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni1/Code/dht_11_sensor.ino)

#### 7-Segment ein tala (3%)
1. Hvort er þitt 7-Segment Display common anode eða common cathode og hver er munurinn á þessu tvennu?
    - Mitt 7 segment display(5011AS) er common cathode. munurinn milli common cathode og common anode er að í common cathode(-) eru að öll cathodinn á LEDonum eru tengd saman.         En í common anode(+) eru að öll anodes eru tengd saman í displayinu. 
1. Í greininni er sýnd útfærsla á teljara. Settu teljarann upp á brauðbretti og settu kóðann á Arduino tölvuna þína.
    - [Myndband af virkni](https://youtu.be/AnbcqrnWTcg)
1. Þú veist að loop fallið er lykkja en í kóðadæminu er eina sem er í fallinu for lykkja. Breyttu útfærslunni á fallinu þannig að það þurfi ekki að nota "auka" lykkju.
    - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni1/Code/sevseg_display_counter.ino)
1. Útfærðu teninginn sem er neðst í greininni en breyttu útfærslunni þannig að þú þurfir ekki "pullup" viðnámið heldur sé það leyst í kóða. Bættu líka við "debounce" á takkann.
    - [Myndband af virkni](https://www.youtube.com/watch?v=gMiIXZqqqkk&ab_channel=Icgxstriker)
    - [Kóði](https://github.com/sveinnoli/vesm2h21/blob/main/Verkefni1/Code/sevseg_display_dice.ino)

#### 7-Segment fjórar tölur (3%)
Kynntu þér hvernig 7-Segment með fjórum tölustöfum virkar með því að lesa seinni hluta [þessarar greinar](https://www.circuitbasics.com/arduino-7-segment-display-tutorial/) (kaflinn *4 DIGIT 7-SEGMENT DISPLAYS*). Skoðaðu einnig stillingar og aðgerðir í [SevSeg safninu](https://github.com/DeanIsMe/SevSeg)
1. Settu upp fyrri rásina (sem birtir 4999) ekki á að setja upp seinni rásina.
1. Bættu inn í ```loop``` fallið einni ```delay``` skipun. Prófaðu að hafa ```delay``` í eina sekúndu (1000 ms) og svaraðu svo eftirfarandi spurningum.
   1. Hvað gerist?
        - Það birtir eina tölu í einu frá vinstri til hægri.
   1. Af hverju gerist það?
        - Þegar forritið keyrist þá byrjar það að kveikja á díoðunum sem eru í seven segmen displayinu. Það gerir það eitt í einu. Að bæta við delay fallið veldur því vandamál             að forritið lýsur up einu tölu en stopar svo í eina sekondu og slökkvir á fyrirverandi ljósinu og kveikjir á því næsta og byrjar að telja aftur. og þar sem arduino er           með 16mhz tíðni(16 milljón leiðbeningar á sekundu) er ekki hægt að taka eftir því að tölurnar slökkvist þegar delay fallið er ekki í kóðanum.
#### 7-Segment 4 tölustafir með dht11 og takka. (5%)
1. Settu upp rás sem getur mælt hita og rakastig og birt það á 4 tölustafa 7-Segment skjá. Það þarf að vera hægt að skipta á milli þess hvort skjárinn sýnir hita eða raka stig með takka.
    - Vantar

##### Bjargir
- [dht 11 upplysingar](https://github.com/VESM2VT/Efni/blob/main/Skynjarar/dht11.md)
- [dht 11 tutorial](https://lastminuteengineers.com/dht11-module-arduino-tutorial/)
- [Timasetningar](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/Timasetning.md)
- [Seven segment display tutorial](https://lastminuteengineers.com/seven-segment-arduino-tutorial/)
