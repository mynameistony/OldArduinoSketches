#include <myLCD.h>

myLCD myLCD();

void setup()
{
  Serial.begin(9600);
}

void loop()
{ 
  myLCD.backlightOn();
  delay(1000);
  myLCD.backlightOff();
  delay(1000);
  myLCD.backlightOn();
  myLCD.setPosition(1,5);
  Serial.write("HELLO?");
  myLCD.clearScreen();
  Serial.write("FUCK YEah");
  delay(5000);
}
  
