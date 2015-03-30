#include <Time.h>
//#include "pitches.h"




int latch = 5;
int data = 6;
int clock = 7;

int digit1=8;
int digit2=9;
int digit3=10;
int digit4=12;

int num1;
int num2;
int num3;
int num4;

int number[]={
  32, 55, 12, 6, 19, 66, 64, 39, 0, 2, 255};

int m=0;
int h=0;
int s=0;

int lastbutton1=1;
int lastbutton2=1;
int lastbutton3=1;
int lastbutton4=1;

int snooze;
int lastsnooze;

int d;

int a1=7;
int a2=30;

int delaytime=1;
  void setup(){
  pinMode(0,INPUT_PULLUP);
  pinMode(1,INPUT_PULLUP);  
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  
  pinMode(latch,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clock,OUTPUT);
 
  pinMode(digit1,OUTPUT);
  pinMode(digit2,OUTPUT);
  pinMode(digit3,OUTPUT);
  pinMode(digit4,OUTPUT);   
  }
  
  void loop(){
  int switch1=digitalRead(2);
  int button1=digitalRead(3);
  int button2=digitalRead(4);  
  int button3=digitalRead(0);
  int button4=digitalRead(1);
/*if(d==4){
setTime(h,m,s+.004,1,1,13);
d=0;
}
  if (switch1==1&&button3==0){
    delaytime--;
  if (delaytime<2){
  delaytime=1;}}
  
  if (switch1==1&&button4==0){
    delaytime++;}
  */  
  if(switch1==0){//**************************SET TIME BEGIN**********************
    if (button1 != lastbutton1){
    if (button1 == 0){
    h--;
 if (h<1){
   h=12;}
}
  }    lastbutton1=button1;
  
  if (button2 != lastbutton2){
     if (button2 == 0){
       m--;
  if (m<1){
  m=59;}
}
  }  lastbutton2=button2;

  if (button3 != lastbutton3){
    if (button3 == 0){
    h++;
 if (h>12){
   h=1;}
}
  }    lastbutton3=button3;
  
  if (button4 != lastbutton4){
     if (button4 == 0){
       m++;
  if (m>59){
  m=0;}
}
  }  lastbutton4=button4;
  
   setTime(h,m,s,1,1,13);
   num1=h/10;
   num2=h%10;
   num3=m/10;
   num4=m%10;
goto d;}//**************************SET TIME END*********************



if(switch1==1&&button1==0){//******SECONDS DISPLAY***************
  num1=10;
  num2=10;
  num3=second()/10;
  num4=second()%10;
goto d;}//******************************************************



if (switch1==1&&button2==0){//ALARM SET BEGIN**************  
  
    if (button3 != lastbutton3){
    if (button3 == 0){
    a1++;
 if (a1>12){
   a1=1;}
}
  }    lastbutton3=button3;
  
  if (button4 != lastbutton4){
     if (button4 == 0){
       a2++;
  if (a2>59){
  a2=0;}
}
  }  lastbutton4=button4;


num1=a1/10;
num2=a1%10;
num3=a2/10;
num4=a2%10;

goto d;}//****************************************ALARM SET END*************



/*if (hour()==a1&&minute()==a2&&snooze==0){//**********SKIP TO ALARM**********
   goto alarm;
}*/


num1=hour()/10;
num2=hour()%10;
num3=minute()/10;
num4=minute()%10;

d :
if (num1<1){
  num1=10;}

  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num1]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,1);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);
  
  delay(delaytime);
d++;
 
  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num2]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,1);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);
 
  delay(delaytime);
d++;
  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num3]);
  digitalWrite(latch,1);  

  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,1);
  digitalWrite(digit4,0);

  delay(delaytime);
d++;
   digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num4]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,1);

  delay(delaytime);
d++;
  }
  
/* if(a1==hour()&&a2==minute()&&snooze==0){
  alarm :
  
  for (int count=0; count<5; count++){

  for (int thisNote = 0; thisNote < 8; thisNote++) {
    
    int noteDuration = 1000/noteDurations[thisNote];
    tone(11, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(11);
    }
  snooze++;
lastsnooze=hour();}
 }else
noTone(11);

if (lastsnooze-hour()<0){
  snooze=0;}
   }*/

