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

## Tengingar
### Motor Driver
!BÆTA VIÐ TÖFLU

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


### Motor Driver
Conditions for turning off motors, going forward and backwards.

MotorA(Left): IN1, IN2

MotorB(Right): IN3, IN4

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

### MPU 6050

---

## Millifærsla

```
Motorcontrol[] = 
{
 0 = y_axis
 1 = x_axis
 2 = [1 = forward, 2 = backwards]
 3 = [1 = right, 2 = left]
}
```

## Dagbók

#### 03/05 - 05/05
Setti up NRF tengin við bílinn og náði að millifæra array frá fjarstýringunni til bíllsins og náði einföldu keyrslu (áfram og til baka).


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
