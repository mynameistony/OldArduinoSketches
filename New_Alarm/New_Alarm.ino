
#include <SoftwareSerial.h>

SoftwareSerial lcd(10, 11); // RX, TX
boolean lightIsOn = false;

void setup()  
{
  Serial.begin(9600);  
  lcd.begin(9600);
  
  ClearLCD();

  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(5,INPUT_PULLUP);
  pinMode(6,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
}

void loop() // run over and over
{
  int switch1 = digitalRead(2);
  int up = digitalRead(3); 
  int down = digitalRead(4);
  int left = digitalRead(5);
  int right = digitalRead(6);
  int button1 = digitalRead(7);
  int button2 = digitalRead(8);

  checkLight();

 int secs = millis()/1000;
 int mins = secs/60;
 int hrs = mins/60;

 setPos(1,1);
 lcd.print("Time Running:");
 setPos(2,1);
 lcd.print("Hr:");
lcd.print(hrs);
lcd.print("Min:");
lcd.print(mins);
lcd.print("Sec:");
lcd.print(secs);
}


void testButtons(){
  int switch1 = digitalRead(2);
  int up = digitalRead(3); 
  int down = digitalRead(4);
  int left = digitalRead(5);
  int right = digitalRead(6);
  int button1 = digitalRead(7);
  int button2 = digitalRead(8);

  setPos(1,1);  
  lcd.print(switch1);
  lcd.print(up);
  lcd.print(down);
  lcd.print(left);
  lcd.print(right);
  lcd.print(button1);
  lcd.print(button2);
   
}
void ClearLCD(){
  lcd.write(12);
  delay(5);
}

void lightOn(){
  lcd.write(17);
  lightIsOn = true; 
 
}

void lightOff(){
  lcd.write(18);
  lightIsOn = false;
}

void checkLight(){
  int switch1 = digitalRead(2);
  
  if(lightIsOn == false && switch1 == 1){
    
    lightOn();
  }
  
  if(lightIsOn == true && switch1 == 0){
    
    lightOff();
  }
   
}

void setPos(int row, int col){
  
 row-=1;
 col-=1;
 int num = 128;
 
 if(row == 1)
   num+=20;
   
 num += col;
 
 lcd.write(num);
  
}

