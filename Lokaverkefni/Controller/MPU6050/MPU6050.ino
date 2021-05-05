#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

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


void mpu6050_init(void){
  if (!mpu.begin()) {
    Serial.println("Failed to find MPU6050 chip");
    while (1) {
      delay(10);
    }
  }
}

void mpu6050_setup(void) {
  // set accelerometer range to +-8G
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);

  // set gyro range to +- 500 deg/s
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);

  // set filter bandwidth to 21 Hz
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}


void setup(void) {
  pinMode(mpu6050_button, INPUT_PULLUP);
  
  Serial.begin(115200);

  // Try to initialize!
  mpu6050_init();

  // Setup the MPU6050
  mpu6050_setup();

  delay(100);
}

void loop() {
  /* Get new sensor events with the readings */
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  mpu6050_current_button_state = digitalRead(mpu6050_button);

// Checks if mpu6050 has been turned on
  if (mpu6050_on){
    // Here the data will be transmitted to the Master
    Serial.print(a.acceleration.x);
    Serial.print(",");
    Serial.print(a.acceleration.y);
    Serial.print(",");
    Serial.print(a.acceleration.z);
    Serial.print(", ");
    Serial.print(g.gyro.x);
    Serial.print(",");
    Serial.print(g.gyro.y);
    Serial.print(",");
    Serial.print(g.gyro.z);
    Serial.println("");
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
      }
    } 
  }
  mpu6050_last_button_state = mpu6050_current_button_state;
  delay(500);
}
