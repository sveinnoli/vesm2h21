
const int LED=13;
const int button=2;
void setup() {
  pinMode(LED, OUTPUT);           // sets the digital pin 13 as output
  pinMode(button, INPUT_PULLUP);         // sets the button pin 2 as input
  Serial.begin(9600);
}

void loop() {
  int val = digitalRead(button);  //reads the value on digital PIN
  digitalWrite(LED, val);         //write the value on LED
  Serial.println(digitalRead(2));
}
