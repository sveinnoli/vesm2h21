# Remote controlled car

---

## Myndbönd og kóði
1. Kóði fyrir Fjarstýringuna
 - [Transmitter - fjarstýring](https://github.com/sveinnoli/vesm2h21/blob/main/Lokaverkefni/transmitter/transmitter.ino)
 - [Transmitter - Library.h - Coordinates](https://github.com/sveinnoli/vesm2h21/blob/main/Lokaverkefni/transmitter/Coordinate.h)
 - [Transmitter - library.cpp - Coordinates](https://github.com/sveinnoli/vesm2h21/blob/main/Lokaverkefni/transmitter/Coordinate.cpp)
2. Kóði fyrir bíllinn
 - [Receiver - Bíll](https://github.com/sveinnoli/vesm2h21/blob/main/Lokaverkefni/Receiver/Receiver.ino)

Getur hunsað library í bílnum, var ekki notað vegna tímaskertununi.

Það er library sem ég nota í fjarstýringunna til að einfalda virkni hennar kallað Coordinates. getur checka þær út í library.h, library.cpp linkonum


[Myndband af virkni fyrir árekstarvörn og joystick sem sýnir beygjur hraðabreytingar og fleira](https://www.youtube.com/watch?v=5d1p1xOrTkY&feature=youtu.be&ab_channel=Icgxstriker)

[Myndband af virkni fyrir mpu6050](https://youtu.be/6eQ2Ym2_j-E)

---
## Tengingar

### Joystick
```
VCC  - 5V
GND  - GND
VRX  - A0
VRY  - A1
SW   - D2
```

### NRF24
```
VCC  - 5V
GND  - GND
CE   - D9
CSN  - D8
SCK  - D13
MOSI - D11
MISO - D12
```

### MPU6050
```
VCC - 3.3V
GND - GND
SCL - A5
XDA - A4
```

### Motor driver
```
ENA - 3 

IN4 - 4

IN3 - 5

IN2 - 7

IN1 - 8

ENB - 9
```
---

## Steering

### 1. Joystick
Núllstöðvar:
- X-ás: 266 
- Y-ás: 249

Þegar Joytick analog gildin eru mælt er byrjað að deila þeim með 2 svo er notað hálft af því til að mæla hverja átt fyrir hvern ás sem gefur okkur 512/2 = 256 til að mæla hraðann áfram, til baka, vinstri og hægri. Núllstöðvarnar eru samt ekki nákvæmlega 256 líklega vegna framleiðanda villu en eru tölurnar sem eru greiddar fyrir ofan.

#### Offsets fyrir x-ás og y-ás

##### X-ás (Vinstri og hægri)
```
Right: 266-511 Total(245)

Center: 266

Left: 266-0 Total(266)
```
Right er 21 minni en Left þannig það þarf að annaðhvort breyta bæði í prósentar einíngar fyrir max gildi eða setja offset til að koma báðum tölum inn í gildi sem eru 8 bits.

##### Y-ás: (Áfram og til baka)
```
forward: 249-0 Total(249)

Center: 249

back: 249-511 Total(262)
```

Forward er 11 minni en Back þannig það þarf að annaðhvort að breyta bæði í prósentar einíngar fyrir max gildi eða setja offset til að koma báðum tölum inn í gildi sem eru 8 bits.

Til að breyta þessum tölum yfir í prósentar einíngu fyrir max_speed notum við map() fallið t.d. map(x gildi, 0, 255, 0, max_speed)
Þetta breytir öllum gildum yfir 0-255 yfir í 0 til hraðan sem við ákveðum sem max hraða. Þar sem joystickið er ekki með nákvæmlega 256 tölur fyrir hvern ás líklega vegna framleiðanda galla er þetta mjög þægilegt.

### 2. MPU 6050

Til að nota MPU6050 til að stjórna fjarstýringu þarf að taka inn acceleration á X, Y ásinum. 
Hérna er tafla sem heldur upp á hvaða átt er verið að snúa í eftir hvort X og Y gildi eru í + eða -
```
Forward:   Y er -
Backwards: Y er +
Left:      X er +
Right:     X er -
```
Þarf að leiðretta áttirnar þar sem MPU6050 verður að beina í serstaka átt þegar hún verður í fjarstýringunni þannig:
```
Forward:   X er -
Backwards: X er +
Right:     Y er +
Left:      Y er -
```

### 3. Motor Driver
Conditions for turning off motors, going forward and backwards.
```
OFF:
IN1: LOW
IN2: LOW

Backwards:
IN1:HIGH
IN2:LOW  

Forward:
IN1: LOW
IN2: HIGH

OFF:
IN1: HIGH
IN2: HIGH
```

Til að stýra bíllnum í sér átt þurfa pinnarnir að vera stiltir eins og eftirfarandi:
```
Hægri:
IN1=LOW, IN2=HIGH
IN3=HIGH, IN4=LOW

Vinstri:
IN1=HIGH, IN2=LOW
IN3=LOW, IN4=HIGH
```

Það er líka hægt að hafa bæði dekkin snúa í sama átt en hafa dekkin á það hlið sem er verið að snúa í vera með mun minni PWM set í það en anstæða hliðin sem er verið að snúa í.

MotorA(Left): IN1, IN2

MotorB(Right): IN3, IN4

---

## Millifærsla
```
Motorcontrol[] = 
{
 0 = y_axis
 1 = x_axis
 2 = [0 = forward | 1 = backwards]
 3 = [0 = right | 1 = left]
}
```

## Dagbók
#### 28/04 - 03/05
Tengdi og setti bílinn saman.

#### 03/05 - 04/05
Tengdi fjarstýringu við brauðborð og Setti up NRF tengin við bílinn og náði að millifæra array frá fjarstýringunni til bíllsins og náði einfaldu keyrslu (áfram og til baka).

#### 05/05
Náði að setja inn fulla keyrslu, áfram, vinstri, hægri og til baka með bæði MPU6050 og joystickið. Þarf enþá að refinea það til að ná nákvæmari og betri hreyfingar.

#### 06/05 - 09/05
Búði til 'Coordinate' library sem getur tekið við analog gildum og gildi sem nýta sér hnitakerfið eins og MPU6050 og breytir þeim í hraða og átt fyrir mótorina. Til að koma við hvernig joystickið og mpuið snýr þegar það er sett í fjarstýringuna gerði ég fall sem getur snúið við vígrum í 90, 180 og 270° clockwise til að koma við að það skiptir ekki máli hvernig það snýr.

#### 09/05 - 10/05
Bætti við árekstrarvörn

#### 10/05 - 12/05 
Lóðaði saman fjarstýringuna og náði almenilega virkni.

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
