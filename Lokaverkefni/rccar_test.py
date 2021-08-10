import random
import math
import time
analog_max = 1024
# Divide by 4 to convert 10 bit singla into 8 bit signal for PWM
# True = Forward, False = Backwards
def loop(iterations=1):
    for x in range(0,iterations):
        setSpeed = 0
        setDirection = True
        analog_x = (math.floor((analog_max*random.random())/4))
        analog_y = (math.floor((analog_max*random.random())/4))

        #Forward + left
        if analog_y > 128 and analog_x < 128:
            print('Forward + left')
            setDirection = True
        #Forward + right
        elif analog_y > 128 and analog_x > 128:
            print('Forward + right')
            setDirection = True
        #Stopped and have wheels facing left or right
        elif analog_y == 128 and analog_x < 128 or analog_x == 128 and analog_y == 128 or analog_x > 128 and analog_y == 128:
            print("Stopped")
        #Backwards + left
        elif analog_y < 128 and analog_x < 128:
            print("Backwards + left")
            setDirection = False
        #Backwards+right
        elif analog_y < 128 and analog_x > 128:
            print("Backwards + right")
            setDirection = False

        setspeed = analog_x


        print('Speed: {speed} ({currspeed} of {maxspeed})\nX: {x}\nY:{y}\nDirection: {direction}\n'.format(
            speed=str(round(analog_x/256, 2)*100) + "%", 
            x=analog_x, y=analog_y, 
            direction=setDirection, 
            currspeed=analog_x, 
            maxspeed=int(analog_max/4)
            ))

        time.sleep(1)
loop(10)

#Lets create a class instead*
