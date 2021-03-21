/*
Segment display model: 5011AS
Common Cathode
A, B, C, D, E, F, G, PD

*/
#include "SevSeg.h"
SevSeg sevseg; 
const int buttonPin = 10;     // the number of the pushbutton pin
// variables will change:
int buttonState;         // variable for reading the pushbutton status

//Debounce
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
int debounceDelay = 50;
int currentButtonState;
int lastButtonState = LOW;

void setup(){
    byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {3, 2, 8, 7, 6, 4, 5, 9};
    bool resistorsOnSegments = true;
 
    sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
  
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT_PULLUP);

}  

void loop()
{
  // read the state of the pins:
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
      if (buttonState == HIGH) {
        sevseg.setNumber(random(1,7));
        sevseg.refreshDisplay(); 
      }
    }
  }
  //Update state
  lastButtonState = buttonState;
}
