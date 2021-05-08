#include <nRF24L01.h>
#include <RF24.h>
#include "Coordinate.h"

//MPU6050
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

Coordinate coordinate(0, 0, true, 1);
// Init joystick pins
const int joystick_x = A0;
const int joystick_y = A1;
const int joystick_button = 2;

// Init joystick variables
int x_axis = 0;
int y_axis = 0;
int joystick_button_state = 0;

//Joystick x and y axis offset
int x_axis_center_offset = 266; // 256+10 center+offset
int y_axis_center_offset = 249; // 256-7  center-offset

//Joystick direction max value factoring offset
int x_axis_right_max_value = 245;
int x_axis_left_max_value = 265;
int y_axis_forward_max_value = 249;
int y_axis_backwards_max_value = 262;

//Motor settings
uint8_t motorcontrols[4] = {};
uint8_t motor_maxspeed = 200;

//Init MPU6050 pins
const int mpu6050_button = 5;

// MPU6050 Button
int mpu6050_button_state = HIGH;
int mpu6050_last_button_state = HIGH;
int mpu6050_current_button_state = 1;
boolean mpu6050_on = false; //Start with mpu6050 off by default

// Debounce for MPU6050
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

//MPU6050 axis controls
uint8_t mpu6050_x_axis = 0; 
uint8_t mpu6050_y_axis = 0;
float mpu6050_max_value = 9.8;

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void mpu6050_init(void){
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
}

void mpu6050_config(void) {
  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void RF24_init(void) {
  radio.begin();
  radio.setChannel(106);
  radio.setPALevel(RF24_PA_MIN);
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();  
}

void set_pinmode(void) {
  //Joystick pinmode
  pinMode(joystick_x, INPUT);
  pinMode(joystick_y, INPUT);
  pinMode(joystick_button, INPUT_PULLUP); 

  //MPU6050 button pinmode
  pinMode(mpu6050_button, INPUT_PULLUP);  
}

//Joystick directions
bool joystick_direction_backwards(int y_axis) {
  if (y_axis > y_axis_center_offset) {
    return true;  
  }
  return false;
}

bool joystick_direction_forward(int y_axis) {
  if (y_axis <= y_axis_center_offset) {
    return true;  
  }  
  return false;
}

bool joystick_direction_right(int x_axis) {
  if (x_axis >= x_axis_center_offset) {
    return true;
  }  
  return false; 
}

bool joystick_direction_left(int x_axis) {
  if (x_axis < x_axis_center_offset) {
    return true;  
  }  
  return false;
}

void setup()
{
  //Configure pinmode
  set_pinmode();
  
  //Initialize RF24
  RF24_init();

  //Init Serial
  Serial.begin(115200);

  //Init mpu6050
  mpu6050_init();

  //Configure the MPU6050
  mpu6050_config();


}
void loop()
{
  mpu6050_current_button_state = digitalRead(mpu6050_button);
  coordinate.debug();

  int myarr[3];
  int *p = coordinate.ret_array(myarr);




// Checks if mpu6050 has been turned on
  if (mpu6050_on){
    //MPU 6050 sensors
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    coordinate.update_data(a.acceleration.x, a.acceleration.y);

    Serial.print("Acceleration X: ");
    Serial.print(a.acceleration.x);
    Serial.print(", Y: ");
    Serial.print(a.acceleration.y);
    Serial.print(", Z: ");
    Serial.print(a.acceleration.z);
    Serial.println(" m/s^2");

    Serial.print("Rotation X: ");
    Serial.print(g.gyro.x);
    Serial.print(", Y: ");
    Serial.print(g.gyro.y);
    Serial.print(", Z: ");
    Serial.print(g.gyro.z);
    Serial.println(" rad/s");

    //Going Left
    if (a.acceleration.x >= 0) {
      mpu6050_x_axis = map(a.acceleration.x*100, 0, mpu6050_max_value*100, 0, motor_maxspeed);
      motorcontrols[1] = mpu6050_x_axis;
      motorcontrols[3] = 2;
    //Going Right
    } else if (a.acceleration.x < 0) {
      mpu6050_x_axis = map((a.acceleration.x)*-1*100, 0, mpu6050_max_value*100, 0, motor_maxspeed);
      motorcontrols[1] = mpu6050_x_axis;
      motorcontrols[3] = 1;
    }
    //Going Backwards
    if (a.acceleration.y >= 0) {
      mpu6050_y_axis = map(a.acceleration.y*100, 0, mpu6050_max_value*100, 0, motor_maxspeed);
      motorcontrols[0] = mpu6050_y_axis;
      motorcontrols[2] = 2;
    // Going forward
    } else if (a.acceleration.y < 0) {
        mpu6050_y_axis = map((a.acceleration.y)*-1*100, 0, mpu6050_max_value*100, 0, motor_maxspeed);
        motorcontrols[0] = mpu6050_y_axis;
        motorcontrols[2] = 1; 
    }
  

  //Joystick
  } else if (!mpu6050_on) {
    x_axis = (analogRead(joystick_x)/2)-x_axis_center_offset;
    y_axis = ((analogRead(joystick_y)/2)-y_axis_center_offset)*-1;
    joystick_button_state = digitalRead(joystick_button);
    coordinate.update_data(x_axis, y_axis, joystick_button_state);
    coordinate.get_directions(motorcontrols, 1, 1, 1);
    //Going Backwards
    if (joystick_direction_backwards(y_axis)){
      y_axis = map(y_axis-y_axis_center_offset, 0, y_axis_backwards_max_value, 0, motor_maxspeed);
      motorcontrols[0] = y_axis;
      motorcontrols[2] = 2;
      
  // Going Forward
    } else if (joystick_direction_forward(y_axis)) {
      y_axis = map((y_axis-y_axis_center_offset)*-1, 0, y_axis_forward_max_value, 0, motor_maxspeed);
      motorcontrols[0] = y_axis;
      motorcontrols[2] = 1; 
    } 
    
    // Right
    if (joystick_direction_right(x_axis)){
      x_axis = map(x_axis-x_axis_center_offset, 0, x_axis_right_max_value, 0, motor_maxspeed);
      motorcontrols[1] = x_axis;
      motorcontrols[3] = 1;
      
    // Left
    } else if (joystick_direction_left(x_axis)) {
      Serial.println(x_axis);
      x_axis = map((x_axis-x_axis_center_offset)*-1, 0, x_axis_left_max_value, 0, motor_maxspeed);  
      motorcontrols[1] = x_axis;
      motorcontrols[3] = 2;
    }
  Serial.print("\n");
    
  }
  
  // Noise filtering
  if (mpu6050_button_state != mpu6050_last_button_state) {
    lastDebounceTime = millis();  
  }
  
  // Debounce for MPU6050
  if ((millis() - lastDebounceTime) > debounceDelay) {
    if (mpu6050_current_button_state != mpu6050_button_state) {
      mpu6050_button_state = mpu6050_current_button_state;
      
      // Switch the mpu 6050 ON or OFF
      if (mpu6050_button_state == LOW) {
          mpu6050_on = !mpu6050_on;
          coordinate.set_orientation(3);
      }
    } 
  }
  mpu6050_last_button_state = mpu6050_current_button_state;


  //Send message to receiver
  radio.write(&motorcontrols, sizeof(motorcontrols));
  
  delay(100); //60hz
}
