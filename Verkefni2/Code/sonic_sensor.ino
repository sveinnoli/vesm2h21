/*
  VCC tengist í 5V
  Trig tengist í digital pinna.
  Echo tegist í digital pinna.
  Gnd tengist í GND.
*/

const int TrigPin = 9; 
const int EchoPin = 10; 
float fjarlaegd; // fjarlægð þess sem mælt er

void setup() {
  Serial.begin(9600); 

  pinMode(TrigPin,OUTPUT);
  pinMode(EchoPin,INPUT);
}

void loop () {

  // sendir út púlsar
  digitalWrite(TrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(TrigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(TrigPin,LOW);

  // mælt hvað púlsarnir voru lengi að berast til baka
  fjarlaegd = pulseIn(EchoPin,HIGH)/58.2; // deilt með 58 til að breyta í cm

  if(fjarlaegd < 0) { // fjarlægð getur ekki verið mínustala
    fjarlaegd = 0;
  } else if (fjarlaegd > 400) {
    Serial.print("Out of range\n");
  } else {
      Serial.print(fjarlaegd);
  Serial.print(" Cm\n");
  }


}
