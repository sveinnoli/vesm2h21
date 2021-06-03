int Pin_Input = 2;
void setup() {
  //Set the mode of the pin
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);

}

//Start serial communications

void loop() {
  int Sensor_Value = digitalRead(Pin_Input);

  Serial.println(Sensor_Value);

  if(Sensor_Value == LOW) {
    digitalWrite(13, HIGH);  
  }else {
    digitalWrite(13, LOW);  
  }
}
