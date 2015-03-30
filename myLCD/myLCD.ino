#include <SoftwareSerial.h>

#include <myLCD.h>

myLCD myLCD(6,7);

void setup()
{
  Serial.begin(9600);
  myLCD.clearScreen();
  myLCD.backlightOn();

}

void loop()
{
  
  myLCD.setPosition(1,5);
  Serial.write("Hello?"); 
  
  myLCD.setPosition(2,5);
  Serial.write("FUCK YEAH");
  
  
}
