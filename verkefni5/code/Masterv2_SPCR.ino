// SPI MASTER (ARDUINO)
// SPI COMMUNICATION BETWEEN TWO ARDUINO
// CIRCUIT DIGEST
// Upphaflegi kóðinn er frá https://circuitdigest.com/microcontroller-projects/arduino-spi-communication-tutorial

#include <SPI.h>                             //Library for SPI 

const int LED = 2;
const int ipbutton = 7;
int buttonvalue;
int x;

void setup (void) {
  Serial.begin(9600);                   //Starts Serial Communication at Baud Rate 115200

  pinMode(ipbutton, INPUT_PULLUP);               //Sets pin 2 as input
  pinMode(LED, OUTPUT);                   //Sets pin 7 as Output

  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV8);    //Sets clock for SPI communication at 8 (16/8=2Mhz)
  digitalWrite(SS, HIGH);                 // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop(void) {
  byte Mastersend, Mastereceive;

  buttonvalue = digitalRead(ipbutton);   //Reads the status of the pin 2

  if (buttonvalue == LOW) {             //Logic for Setting x value (To be sent to slave) depending upon input from pin 2
    x = 1;
  } else {
    x = 0;
  }

  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master

  Mastersend = x;
  Mastereceive = SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
}
