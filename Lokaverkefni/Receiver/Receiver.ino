//Include Libraries
#include <nRF24L01.h>
#include <RF24.h>
#include "Motor.h"

//create an RF24 object
RF24 radio(A0, 2);  // CE = A0, CSN = 2

// Motor A connections
int enA = 9;
int in1 = 8;
int in2 = 7;

// Motor B connections
int enB = 3;
int in3 = 5;
int in4 = 4;

//Motor settings
uint8_t motorcontrols[4] = {};

//address through which two modules communicate.
const byte address[6] = "00001";

void radio_init(void) {
  radio.begin();
  radio.setChannel(106);
  radio.setPALevel(RF24_PA_MIN);
  //set the address
  radio.openReadingPipe(0, address);
  
  //Set module as receiver
  radio.startListening();
}

void set_pinmode(void) {
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(A0, OUTPUT);  
}

void motorA_set_speed(uint8_t motor_speed) {
  analogWrite(enA, motor_speed);
 }

void motorB_set_speed(uint8_t motor_speed) {
  analogWrite(enB, motor_speed);
}


void setup()
{
  // Set all the motor control pins to outputs
  set_pinmode();

  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  

  //Initialize Serial
  Serial.begin(115200);
    
  //Initialize radio
  radio_init();
}

void loop()
{
  //Read the data if available in buffer
  if (radio.available())
  {
    radio.read(&motorcontrols, sizeof(motorcontrols));   
   
    Serial.println(motorcontrols[0]);
    Serial.println(motorcontrols[1]);
    Serial.println(motorcontrols[2]);
    Serial.println(motorcontrols[3]);
    
    Serial.print("\n");
    motorA_set_speed(motorcontrols[0]);
    motorB_set_speed(motorcontrols[0]);

 
    
    // Right
    if (motorcontrols[3] == 0 and motorcontrols[1] > 75) {
      // Right + Forward
      if (motorcontrols[2] == 0 and motorcontrols[0] > 50) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);   
      } 
      //Right + Backwards  
      else if (motorcontrols[2] == 1 and motorcontrols[0] > 50) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);       
     }
     //Turning only to the right
     else {
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
          motorA_set_speed(120);
          motorB_set_speed(120);  
      }
    } 

    // Left
    else if (motorcontrols[3] == 1 and motorcontrols[1] > 75) {
      //Left + Forward
      if (motorcontrols[2] == 0 and motorcontrols[0] > 50) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, LOW);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);       
      } 
       //Left + Backwards 
      else if (motorcontrols[2] == 1 and motorcontrols[0] > 50) {
          digitalWrite(in1, LOW);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);        
      } 
      // Turning only to the left
      else {
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);
          motorA_set_speed(120);
          motorB_set_speed(120);  
      }
    }
    
    else {

      //Forward
      if (motorcontrols[2] == 0) {
          digitalWrite(in1, LOW);
          digitalWrite(in2, HIGH);
          digitalWrite(in3, LOW);
          digitalWrite(in4, HIGH);        
      } 
      // Backwards
      else if (motorcontrols[2] == 1) {
          digitalWrite(in1, HIGH);
          digitalWrite(in2, LOW);
          digitalWrite(in3, HIGH);
          digitalWrite(in4, LOW);
      }
    }

     
   
    delay(16.67); //60hz
  } 
}
