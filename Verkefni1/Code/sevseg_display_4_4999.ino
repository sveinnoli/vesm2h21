#include "SevSeg.h"
#include <dht.h>  
SevSeg sevseg; 

#define dhtPin A0    // Defines pin number for DHT11 sensor
#define buttonPin A1 // Defines pin number for button
dht DHT; // Creates a DHT object

//DHT
unsigned long dht_lastUpdate;
int dht_updatePeriod = 2000;
int sensorState = 0; // Temp = 0, Humidity = 1, 2 = skip
int nextSensorState = 1; // Temp = 0, Humidity = 1
int readData;

//Debounce
unsigned long lastDebounceTime = 0;
int debounceDelay = 50;
int currentButtonState;
int buttonState;
int lastButtonState = LOW;


void setup(){
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  bool resistorsOnSegments = true; 
  bool updateWithDelaysIn = true;
  byte hardwareConfig = COMMON_ANODE; 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
  sevseg.setBrightness(90);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop(){
  sevseg.refreshDisplay();
  buttonState = digitalRead(buttonPin); // Reading button state
  
  //Noise filtering
  if (buttonState != lastButtonState) {
    lastDebounceTime = millis();
  }
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    //50Ms has passed since the button was pressed
    if (buttonState != currentButtonState){
      //Checks to see if active button state isn't the same as the reported button state
      currentButtonState = buttonState;
      if (buttonState == LOW) {
        //If current sensor is humidity
        if (nextSensorState == 0) {
            sensorState = 0;
            nextSensorState = 0;
         //If current sensor is temperature
         } else if (nextSensorState == 1) {
            sensorState = 1;
            nextSensorState = 1;
          }
      }
    }
  }
  //Update state
  lastButtonState = buttonState;
    // Find a way to store DHT.temperature and DHT.humidity in a variable to eliminate if statements
    if (sensorState == 0) {
      //Temperature
      sevseg.setNumber(DHT.temperature, 2);
      sensorState = 2;
      nextSensorState = 1;
      dht_lastUpdate = millis();
    } else if (sensorState == 1) {
      //Humidity
      sevseg.setNumber(DHT.humidity, 2);
      sensorState = 2;
      nextSensorState = 0;
      dht_lastUpdate = millis();
    } else {
        //Updates sensor
        if ((millis() - dht_lastUpdate) > dht_updatePeriod) {
          if (nextSensorState == 1) {
             sevseg.setNumber(DHT.temperature, 2);
           } else if (nextSensorState == 0) {
             sevseg.setNumber(DHT.humidity, 2);   
           }
           int readData = DHT.read11(dhtPin);
           dht_lastUpdate = millis();
        }  
    }
  } 
