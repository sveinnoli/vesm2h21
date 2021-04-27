//Include Libraries
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
#define led 5

//create an RF24 object
RF24 radio(9, 8);  // CE, CSN

  
//address through which two modules communicate.
const byte address[6] = "00001";

void setup()
{
  while (!Serial);
    Serial.begin(9600);
  
  radio.begin();
  radio.setChannel(106);
  radio.setPALevel(RF24_PA_MIN);
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    char text[32] = {0};
    radio.read(&text, sizeof(text));
    Serial.println(text);
    flashLed();
    delay(100);
  } else {
    flashLed();
  
  }
}
void flashLed()

{

for (int i = 0; i < 5; i++)

{

digitalWrite(led, HIGH);

delay(200);

digitalWrite(led, LOW);

delay(200);

}}
