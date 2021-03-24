/*
Adafruit Arduino - Lesson 3. RGB LED
*/
 
int redPin = 11;
int greenPin = 10;
int bluePin = 9;
const int ldrPin = A0;

int rgbBrightness;
float ldrPercentage;
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(ldrPin, INPUT);
}
 
void loop()
{
  float ldrStatus = analogRead(ldrPin);
  ldrPercentage = ldrStatus/400;
  if (ldrPercentage > 1) {
    ldrPercentage = 1; 
  }
  rgbBrightness = 255*ldrPercentage;
  setColor(rgbBrightness, rgbBrightness, rgbBrightness);  
  delay(1000);
  
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
