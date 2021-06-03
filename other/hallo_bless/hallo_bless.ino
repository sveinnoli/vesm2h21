char stafur = 0; 

void setup() {
  Serial.begin(9600); // byrja á að stilla hraðann á serial tengingunni
}

void loop() {
  if(Serial.available() > 0) { 
    stafur = Serial.read(); 
  }
  if(stafur == 'h') {
    Serial.println("hallo");
  } else if (stafur == 'b') {
    Serial.println("Bless");
  }
}
