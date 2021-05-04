# Remote controlled car

---

## Components
### Motor Driver

MotorA: Vinstri

MotorB: Hægri

### MPU 6050

### Joystick

### Arduino Nano

### Arduino Uno

### Ultrasonic Sensor



---

## Connections
### Motor Driver

> ENA: Purple - 3
> 
> IN4: Blue - 4
> 
> IN3: green - 5
> 
> IN2: yellow - 7
> 
> IN1: orange - 8
> 
> ENB: red - 9

---

## Steering

### 1. Joystick
Núllstöðvar:
- X-ás: 533 
- Y-ás: 498

Núllstöðvar eru ekki nákvæmlega 2^10/2 = 512 líklega vegna framleiðanda villu, en eru í staðinn á tölunum sem eru greiddar fyrir ofan.
Þegar er verið að reikna hraða þarf að taka delta af x-ás til að geta sagt hvé hratt er verið að fara áfram og til baka. Dæmi:
> Mælt joystickið og er gefið 700 á X-ás, við tökum delta af því og fáum 700-533 = 167, við breytum þessu svo í prósentareiningu fyrir hámarks hraðann sem við stilum fyrirfram.
> Þar sem 533 er núllstöðvan fyrir X-ásinum til að geta breytt þessu í prósentareiningu tökum við 533 af 1024, svo 1024-533 = 491
> svo finnum við prósentareininguna, 167/491 = 34%. Ef við erum með 200 sem max hraða fáum við 200*0.34 = 68 sem hraðan frá þessari mælingu. 

En það er ekki hægt að nota 68 þar sem frictionið leyfir ekki dekkjonum að keyra sig áfram frá kjurru stöðu ef það fær gildi sem er minni en 70-75. Þannig lausnin er, er að byrja á milli 75-100 og læggi sig svo niður í 68 þar sem það er hægt að keyra á 68 ef dekkin eru þegar á hreyfingu þar sem friction hefur mun minni áhrif ef það er þegar á hreyfingu.

Líka er hægt að bæta við minspeed sem segir ef þú færð tölu minni en 75 settu hana sem 75. Þetta takmarkar samt nákvæmari hreyfingar.

#### Offsets fyrir x-ás og y-ás

##### X-ás (Vinstri og hægri)
Right: 267-511 Total(244)

Center: 266

Left: 265-0 Total(265)

Right er 21 minni en Left þannig það þarf að annaðhvort breytu bæði í prósentar einíngar eða setja offset til að koma báðum tölum inn í gildi sem eru 8 bits.



##### Y-ás: (Áfram og til baka)
forward: 250-0 Total(250)

Center: 249

back: 250-511 Total(261)


Forward er 11 minni en Back þannig það þarf að annaðhvort breytu bæði í prósentar einíngar eða setja offset til að koma báðum tölum inn í gildi sem eru 8 bits.

#### NOTE:
 - Gildin eru ekki einmit 9 bits en í staðin 2^9-1 þar sem Joystickið gefur út gildi sem er 10 bits eða 0-1023 og tölur sem eru deilaðar eru rúnuð í lægsta heiltölu t.d.
 1023/2 = 511.5 Þannig það mun rúna það niður í 511. Ef ég vil offseta bæði X-ás og Y-ás þarf ég að hafa í huga að hæðsta gildin verður þá að vera 255 fyrir hvern ás.



### Motor Driver
Conditions for turning off motors, going forward and backwards.
 
OFF:
> IN1: LOW
> 
> IN2: LOW

Backwards:
> IN1:HIGH
>
>  IN2:LOW  

Forward:
> IN1: LOW
> 
> IN2: HIGH

OFF:
>IN1: HIGH
>
>IN2: HIGH


Til að stýra bíllnum í sér átt þurfa pinnarnir að vera stiltir eins og eftirfarandi:

Hægri:
> IN1=LOW, IN2=HIGH
> 
> IN3=HIGH, IN4=LOW

Vinstri:
> IN1=HIGH, IN2=LOW
> 
> IN3=LOW, IN4=HIGH

### MPU 6050

---

## Ýttri upplýsingar

### Hnitakerfi:

I   : x+ y+ (Áfram og til hægri)

II  : x- y+ (Áfram og til vinstri)

III : x- y- (Til baka og til vinstri)

IIII: x+ y- (Til baka og til hægri) 

ef x = 0 og y = 0 er ekki verið að hreyfa bílinn
ef x = 0 og y = + eða - er verið að keyra áfram eða afturabak
ef x = + eða - og y = 0 er verið að snúa bílnum í annaðhvort vinstri eða hægri án þess að færa sig

---
