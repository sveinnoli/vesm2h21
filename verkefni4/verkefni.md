## 4.1 Rafþéttar og tranistorar (1%)

1. Hver er munurinn á rafhlöðu og rafþétti?
    - Rafhlaða geymir rafmagnið sitt efnisfræðilega og gefur út stöðugt voltage og getur geymt talsvert meira rafmagn en capacitor.
      meðan capacitor tekur rafmagn frá rafrás og geymir rafmagnið ef of mikið er að koma í gegn og hleypur rafmagn í gegn ef of lítið rafmagn er að fara í gegn til að                 gefa hreynan straum sem gefur alltaf sama straum en getur ekki geymt mikið rafmagn í einu..
1. Hvað gerir transistor?
   - Svar: Það hleypur rafmagn í gegn ef Base pinnin er að fá smá rafmagn í sig, annars er rafrásinn sem transistor er tengdur við milli Collector og Emitter lokaður.
     Hann er mjög svipaður og takki sem hleypur straum í gegn ef er ýtt á takkan.
2. Hvað heita lappirnar á transistor?
   - Svar: Collector, Base og Emitter

---

## 4.2 Servo Motors (2%)
- [Hlekkur á kóða - Sweep](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni4/4.2_Servo_motor/Code/Sweep.ino)

![Servo_SWEEP](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni4/4.2_Servo_motor/myndir/Servo.jpg)

- [Hlekkur á kóða - Potentiometer](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni4/4.2_Servo_motor/Code/potentometer.ino)

![Servo_potentometer](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni4/4.2_Servo_motor/myndir/Servo_potento.jpg)

1. Afhverju er heppilegt að nota rafþéttir með servo motor?
    - Svar: til að vernda arduinoið, þar sem servo motorinn getur dragið mjög mikið rafmagn í einu þegar það er verið að t.d. ræsa arduinoinu eða tengja það í usb með mótorinn               tengdann. Ef það er ekki rafþéttir tengd á milli þá getur það valdið að arduinoið resettar.
2. Hvað snýst servo motor margar gráður þegar hár púls (e. pulse) varir í 1.5 millisekúndur?
    - Svar: Það snýst 90°

---

## 4.3. DC Motors (1%)
- [Hlekkur á kóða](https://github.com/sveinnoli/vesm2h21/tree/main/verkefni4/4.3_DC_Motors/code)

![DC_Motor](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni4/4.3_DC_Motors/DC_motor.jpg)

1. Afhverju þurfum við að nota PWM pinna til að stýra DC mótor?
   - Svar: PWM skilar 10bita gildi sem er milli 0-1023 sem getur verið notað sem prósentar eining til að stjórna hraða mótorsins.
2. Afhverju þurfum við að nota viðnám, transistor og diode með DC mótor í _Lesson 13. DC Motors_?
   - Svar: 
        - Transistorinn kemur við að við skemmum ekki digital pinana á arduinoinu þar sem það getur tekin inn smá rafmagn frá digital pinonum og svo gefið mótorinum mikið                  rafmagn í einu. Það stjórnar líka hvort rafmagn getur farið á milli pinnana "Collector" og "Emitter" ef það er smá rafmagn að fara í base connectionið.
        - Diode er notuð til að stjórna rafmagnsflæði þar sem það leyfur einungis rafmagn að flæða í eina átt. Þegar er slökkt á mótorinum gefur það mikið neikvætt                        rafmagnsflæði sem getur skemmt arduinoið, þetta kemur við að arduinoið er ekki eyðilagt.
        - Viðnámið er tengd við pwm pinna og base pinnan á transitorinum sem stjórnar hvort transistorinn er opinn eða lokaður til að stjórna flæði rafmagns í rafrásinni

3. Hvernig er stýrimótor (e. servo motor) ólíkur hefðbundnum DC mótor?
   - Svar:  
        - Servo er með þrjá víra Power, Ground, Control en DC er aðeins með Power og Ground
        - Servo mótorinn getur aðeins snúið 180° en dc motorinn getur snúið endalaust 
        - Servo er oft notað fyrir robot hendi og hluti sem þarf að snúa nákvæmlega en hægt og dc er notað fyrir hluti sem þurfa mikla snúníngu

---

## 4.4. H-Bridge (1%)

1. Hvað er hægt að gera með L293D?
   - Svar: Þar sem L293D er Motor driver sem getur outputtað milli 5-36V, það er hægt að tengja það við micro controller eins og Arduino og tengja það svo við Motor og nota                controllerin til að stjórna Voltage ouput í mótorinn til að geta stjórnað hraðanum á mótorinum, L293D er mjög æskilegt í því að það kemur við að það þarfnast ekki                díoður og ýmsar varnir þannig að mótorinn eyðileggur ekki Micro controllerinn. Það getur líka driveað relay, solenoids og bipolar stepping motors, o.fl.
2. Hver er munurinn á L293 or L293D?
   - Svar: L293 er ekki með inbyggða Díoðu en L293D er með inbyggða díoðu. en L293 getur outputað current up að 1A en L293D getur einungis outputtað 600mA og L293 output ræður              við 2A en L293D getur aðeins rætt við 1.2A í outputtinu.

---

## 4.5. DC motor reversing (2%)

[Hlekkur á myndband](https://youtu.be/fMw-L9e_4-E)

[Hlekkur á kóða](https://github.com/sveinnoli/vesm2h21/blob/main/verkefni4/4.5_Motor_reversing/Motor_reverse.ino)


1. Hvað gerir kóðinn?

        ```cpp
        void setMotor(int speed, boolean reverse) {
            analogWrite(enablePin, speed);
            digitalWrite(in1Pin, !reverse);
            digitalWrite(in2Pin, reverse);
        }
        ```
    - Svar:
1. L293D er með tvo +V pinna (8 and 16), útskýrðu þá.
    - Svar:

