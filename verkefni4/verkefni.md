## 4.1 Rafþéttar og tranistorar (1%)

1. Hver er munurinn á rafhlöðu og rafþétti?
    - Rafhlaða geymir rafmagnið sitt efnisfræðilega og gefur út stöðugt voltage og getur geymt talsvert meira rafmagn en capacitor.
      meðan capacitor tekur rafmagn frá rafrás og geymir rafmagnið ef of mikið er að koma í gegn og hleypur rafmagn í gegn ef of lítið rafmagn er að fara í gegn til að                 gefa hreynan straum sem gefur alltaf sama straum en getur ekki geymt mikið rafmagn í einu..
1. Hvað gerir transistor?
   - Svar:
2. Hvað heita lappirnar á transistor?
   - Svar:

---

## 4.2 Servo Motors (2%)

- [Hlekkur á myndband - Sweep]()
- [Hlekkur á kóða - Sweep]()
- [Hlekkur á myndband - Potentiometer]()
- [Hlekkur á kóða - Potentiometer]()

1. Afhverju er heppilegt að nota rafþéttir með servo motor?
    - Svar:
2. Hvað snýst servo motor margar gráður þegar hár púls (e. pulse) varir í 1.5 millisekúndur?
    - Svar:

---

## 4.3. DC Motors (1%)

- [Hlekkur á myndband]()
- [Hlekkur á kóða]()

1. Afhverju þurfum við að nota PWM pinna til að stýra DC mótor?
   - Svar: PWM skilar gildi milli 0-1023 sem getur verið notað sem prósentar eining til að stjórna hraða mótorsins.
2. Afhverju þurfum við að nota viðnám, transistor og diode með DC mótor í _Lesson 13. DC Motors_?
   - Svar: - Transistorinn kemur við að við skemmum ekki digital pinana á arduinoinu þar sem það getur tekin inn smá rafmagn frá digital pinonum og svo gefið mótorinum mikið                  rafmagn í einu. Það stjórnar líka hvort rafmagn getur farið á milli pinnana "Collector" og "Emitter" ef það er smá rafmagn að fara í base connectionið.

           - Diode er notuð til að stjórna rafmagnsflæði þar sem það leyfur einungis rafmagn að flæða í eina átt. Þegar er slökkt á mótorinum gefur það mikið neikvætt                        rafmagnsflæði sem getur skemmt arduinoið, þetta kemur við að arduinoið er ekki eyðilagt.

           - Viðnámið er tengd við pwm pinna og base pinnan á transitorinum sem stjórnar hvort transistorinn er opinn eða lokaður til að stjórna flæði rafmagns í rafrásinni

3. Hvernig er stýrimótor (e. servo motor) ólíkur hefðbundnum DC mótor?
   - Svar: 

---

## 4.4. H-Bridge (1%)

1. Hvað er hægt að gera með L293D?
   - Svar:
2. Hver er munurinn á L293 or L293D?
   - Svar:

---

## 4.5. DC motor reversing (2%)

[Hlekkur á myndband]()

[Hlekkur á kóða]()

1. Hvað gerir kóðinn?
    - Svar:
1. L293D er með tvo +V pinna (8 and 16), útskýrðu þá.
    - Svar:

