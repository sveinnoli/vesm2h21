String strengur = "okay"; 
void setup() {
  Serial.begin(9600); 
}

void loop() {
  if(Serial.available() > 0 ) { 
    strengur = Serial.readString();
    strengur.toUpperCase();
    Serial.println(strengur);
  }
}
