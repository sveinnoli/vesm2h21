#### DHT11 og serial monitor (3%)
1. Útskýrðu með eigin orðum hvernig rakinn er mældur.    
    - DHT11 reiknar hlutfallslegan rakastig með því að mæla rafmótstöðu milli tveggja rafskauta.
      Rakskynjunarþáttur DHT11 er undirlag sem gefur raka og rafskautin borin á yfirborðið. Þegar vatnsgufa frásogast af undirlaginu losna ions af undirlaginu sem eykur leiðni         milli rafskautanna. Breyting á viðnámi rafskautanna tveggja er í réttu hlutfalli við hlutfallslegan raka. Hærri rakastig minnkar viðnám milli rafskautanna en lægra               rakastig eykur viðnám rafskautanna.

1. Settu upp fyrri rásina í greininni (það á ekki að setja upp rásina með LCD skjánum).
    > [Myndband af virkni](https://youtu.be/zTZluUC8H4Q)
    > 
    > [Kóði - Vantar]()

#### 7-Segment ein tala (3%)
1. Hvort er þitt 7-Segment Display common anode eða common cathode og hver er munurinn á þessu tvennu?
    - Vantar
1. Í greininni er sýnd útfærsla á teljara. Settu teljarann upp á brauðbretti og settu kóðann á Arduino tölvuna þína.
    - [Myndband af virkni](https://youtu.be/AnbcqrnWTcg)
1. Þú veist að loop fallið er lykkja en í kóðadæminu er eina sem er í fallinu for lykkja. Breyttu útfærslunni á fallinu þannig að það þurfi ekki að nota "auka" lykkju.
    - Vantar
1. Útfærðu teninginn sem er neðst í greininni en breyttu útfærslunni þannig að þú þurfir ekki "pullup" viðnámið heldur sé það leyst í kóða. Bættu líka við "debounce" á takkann.
    - Vantar

#### 7-Segment fjórar tölur (3%)
1. Settu upp fyrri rásina (sem birtir 4999) ekki á að setja upp seinni rásina.
1. Bættu inn í ```loop``` fallið einni ```delay``` skipun. Prófaðu að hafa ```delay``` í eina sekúndu (1000 ms) og svaraðu svo eftirfarandi spurningum.
   1. Hvað gerist?
        - Vantar
   1. Af hverju gerist það?
        - Vantar
#### 7-Segment 4 tölustafir með dht11 og takka. (5%)
1. Settu upp rás sem getur mælt hita og rakastig og birt það á 4 tölustafa 7-Segment skjá. Það þarf að vera hægt að skipta á milli þess hvort skjárinn sýnir hita eða raka stig með takka.
    - Vantar

##### Bjargir
- [dht 11 upplysingar](https://github.com/VESM2VT/Efni/blob/main/Skynjarar/dht11.md)
- [dht 11 tutorial](https://lastminuteengineers.com/dht11-module-arduino-tutorial/)
- [Timasetningar](https://github.com/VESM2VT/Efni/blob/main/Kennsluefni/Timasetning.md)
- [Seven segment display tutorial](https://lastminuteengineers.com/seven-segment-arduino-tutorial/)
