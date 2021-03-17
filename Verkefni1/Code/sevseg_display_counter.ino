#include "SevSeg.h"
SevSeg sevseg;

void setup()
{
  //Set to 1 for single digit display
  byte numDigits = 1;

  //defines common pins while using multi-digit display. Left empty as we have a single digit display
  byte digitPins[] = {};

  //Defines arduino pin connections in order: A, B, C, D, E, F, G, DP
  byte segmentPins[] = {3, 2, 8, 7, 6, 4, 5, 9};
  bool resistorsOnSegments = true;

  //Initialize sevseg object. Uncomment second line if you use common cathode 7 segment
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);
  //sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins, resistorsOnSegments);

  sevseg.setBrightness(90);
}


long lastCount = 0;  // the last time the output pin was toggled
long counterDelay = 2000; 
int lastDigit = 0;

void loop()
{ 
  if ( (millis() - lastCount) > counterDelay) {
    sevseg.setNumber(lastDigit);
    sevseg.refreshDisplay();
    
    lastDigit++;
    if (lastDigit > 9){
      lastDigit = 0;
    }
    lastCount = millis();
  }
}
