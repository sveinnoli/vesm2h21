#include <SPI.h>

void setup (void)
{
  Serial.begin(9600);
  digitalWrite(SS, HIGH);
  SPI.begin ();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop (void)
{
  char c;

  // enable Slave Select
  digitalWrite(SS, LOW);    // SS is pin 10

  // send test string
  for (const char * p = "Sveinn Oli\n" ; c = *p; p++) {
    SPI.transfer (c);
    Serial.print(c);
  }

  // disable Slave Select
  digitalWrite(SS, HIGH);

  delay (1000);
}
