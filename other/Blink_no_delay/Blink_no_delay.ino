const int ledPin =  LED_BUILTIN; // the number of the LED pin, onboard led, pin 13 
int ledState = LOW;              // ledState used to set the LED, LOW is off

// Generally, you should use "unsigned long" (32 bits) for variables that hold time
// The value will quickly become too large for an int  (16 bits) to store

unsigned long previousMillis = 0;        // will store last time LED was updated
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  pinMode(ledPin, OUTPUT);   // set the digital pin as output:
}

void loop() {

  unsigned long currentMillis = millis();  // return the count of millis since program started to run.

  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;     // save the last time you blinked the LED

    // if the LED is off turn it on and vice-versa:
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);    // set the LED with the ledState of the variable:

  }
}
