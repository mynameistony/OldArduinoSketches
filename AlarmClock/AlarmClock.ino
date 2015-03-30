#include <Time.h>
#include "pitches.h"

int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};

int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };

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
  32, 55, 12, 6, 19, 66, 64, 39, 0, 2};

int m;
int h;
int s;

int lastbutton1=1;
int lastbutton2=1;
int lastbutton3=1;
int lastbutton4=1;


int d=0;

int t=100;

int a1=7;
int a2=0;

int d1;
int m1;

int snooze=0;

int lastsnooze;
void setup(){
  Serial.begin(9600);
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
  s=0;



  


if (switch1==0){
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
  
   setTime(h,m,s,m1,d1,13);
}
b :
if(d==250){
  h=hour();
  m=minute();
  s=second();
 
 setTime(h,m,s+1,m1,d1,13);
}
if (switch1==1&&button4==0){
goto y;}  

if (switch1==1&&button2==0){
goto z;}

if (switch1==1&&button1==0&&button2==1){

  num1=second()/10;
  num2=second()%10;
  
  digitalWrite(latch,0);
  shiftOut(data,clock,LSBFIRST,number[num1]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,1);
  digitalWrite(digit4,0);
  
  delay(4);
  d++;

  digitalWrite(latch,0);
  shiftOut(data,clock,LSBFIRST,number[num2]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,1);

  delay(4);
  d++;


button1=digitalRead(3);

if(button1==0&&button2==1){
goto b;}else{
goto a;
}

a :

h=hour();

if(h>12){
  h=1;}
    num1=h/10;
    num2=h%10;
    num3=minute()/10;
    num4=minute()%10;
    
  
if (num1>0){

  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num1]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,1);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);

delay(4);
d++;}

 
  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num2]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,1);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);

delay(4);
d++;
  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num3]);
  digitalWrite(latch,1);  

  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,1);
  digitalWrite(digit4,0);
 
 delay(4);
 d++; 
   digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num4]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,1);
 
 delay(4);
d++;
 
z :
if (switch1==1&&button2==0){
  
    if (button3 != lastbutton3){
    if (button3 == 0){
    a1++;
 if (a1>12){
   a1=1;}
}
  }    lastbutton3=button3;
  
  if (button1 != lastbutton1){
     if (button1 == 0){
       a2++;
  if (a2>59){
  a2=0;}
}
  }  lastbutton1=button1;


num1=a1/10;
num2=a1%10;
num3=a2/10;
num4=a2%10;

if (num1>0){
  digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num1]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,1);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);
 
 delay(4);
d++;
 
}
   digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num2]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,2);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);
 
 delay(4);
d++;

   digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num3]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,1);
  digitalWrite(digit4,0);
 
 delay(4);
d++;

   digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num4]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,1);
 
 delay(4);
d++;
}
if (hour()-lastsnooze==1){
  snooze=0;
}

if (hour()==a1&&minute()==a2){
if(snooze>0){goto snooze;
}
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    int noteDuration = 1000/noteDurations[thisNote];
    tone(11, melody[thisNote],noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(11);
 if(button1==0|button2==0|button3==0|button4==0){
      snooze++;
      lastsnooze=hour();
      goto snooze;
    }
  }

  
}else snooze :noTone(11);


y :
if(switch1==1&&button4==0){

  if (button1 != lastbutton1){
    if (button1 == 0){
    m1++;
 if (m1>12){
   m1=1;}
}
  }    lastbutton1=button1;
  
  if (button2 != lastbutton2){
     if (button2 == 0){
       d1++;
  if (d1>31){
  d1=1;}
}
  }  lastbutton2=button2;
 
 num1=m1/10;
 num2=m1%10;
 num3=d1/10;
 num4=d1%10;
    
if (num1>0){

  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num1]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,1);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);
  
  delay(4);
d++;
}
 
  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num2]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,1);
  digitalWrite(digit3,0);
  digitalWrite(digit4,0);
 
  delay(4);
d++;

  digitalWrite(latch,0);
  shiftOut(data, clock, LSBFIRST, number[num3]);
  digitalWrite(latch,1);  

  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,1);
  digitalWrite(digit4,0);

  delay(4);
d++;

   digitalWrite(latch,0);
   shiftOut(data, clock, LSBFIRST, number[num4]);
  digitalWrite(latch,1);
  
  digitalWrite(digit1,0);
  digitalWrite(digit2,0);
  digitalWrite(digit3,0);
  digitalWrite(digit4,1);

  delay(4);
d++;
 
}    
}
  }
