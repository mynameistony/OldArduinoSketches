#include <Time.h>
int PM;
int val1;
int val2;

int p;

int x;
int y;

int alarmbutton;
int timebutton;
int datebutton;
int lighton;
int lightoff;

int months;
int weekdays;
int days;
int hours;
int minutes;
int seconds;

int e=211;
int q=212;
int h=213;

int A=220;
int C=223;
int D=225;
int E=227;
int F=228;
int G=230;

int alarmminute;
int alarmhour;
void setup(){
Serial.begin(9600);

Serial.write(12);

Serial.write(248);
Serial.write(0);
Serial.write(17);
Serial.write(14);
Serial.write(10);
Serial.write(21);
Serial.write(10);
Serial.write(4);
Serial.write(0);


pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(5,INPUT_PULLUP);
pinMode(6,INPUT_PULLUP);

}

void loop(){
  alarmbutton=digitalRead(2);
  datebutton=digitalRead(3);
  timebutton=digitalRead(6);
  lighton=digitalRead(5);
 


if(second()==30){
  backlightOff();
}

if(alarmbutton==0){
  ALARMSET();
}

if(timebutton==0){
  TIMESET();
}

if (datebutton==0){
  DATESET();
}

if(hours==alarmhour&&minutes==alarmminute==1&&alarmbutton==1&&timebutton==1){
  ALARM(); 
}

 if (lighton==0){
  backlightOn();
 }


hours=hourFormat12();
minutes=minute();
seconds=second();
days=day();
weekdays=weekday();
months=month();



setposition(1,1);


Serial.print(hours);
Serial.write(":");
if(minutes<10){
  Serial.write("0");
}
Serial.print(minutes);

if(isAM()==1){
  Serial.write("AM");
}else Serial.write("PM");

setposition(1,9);
Serial.write(0);

Serial.print(alarmhour);
Serial.write(":");
if(alarmminute<10){
  Serial.write("0");
}
Serial.print(alarmminute);





setposition(2,1);
if(weekdays==1){
  Serial.write("Sun");
}
if(weekdays==2){
  Serial.write("Mon");
}
if(weekdays==3){
  Serial.write("Tues");
}
if(weekdays==4){
  Serial.write("Weds");
}
if(weekdays==5){
  Serial.write("Thur");
}
if(weekdays==6){
  Serial.write("Fri");
}
if(weekdays==7){
  Serial.write("Sat");
}
Serial.write(" ");
Serial.print(months);
Serial.write("/");
Serial.print(days);
Serial.write("/2013");



}


void backlightOn(){
  Serial.write(12);
  Serial.write(17);
}

void backlightOff(){
  Serial.write(12);
  Serial.write(18);
}
void clearScreen(){
  Serial.write(12);
}
  
void TIMESET(){
val1=map(analogRead(A0),0,1023,0,23);
val2=map(analogRead(A1),0,1023,0,59);
  
  setTime(val1,val2,0,days,months,13);
  } 

void DATESET(){
val1=map(analogRead(A1),0,1023,1,31);
val2=map(analogRead(A0),0,1023,1,12);
  setTime(hour(),minutes,seconds,val1,val2,13);
  
}

void ALARMSET(){
val1=map(analogRead(A0),0,1023,0,12);
val2=map(analogRead(A1),0,1023,0,59);


   alarmhour=val1;
   alarmminute=val2;
}

void ALARM(){  
Serial.write(215);

Serial.write(e);
Serial.write(C);

}

void setposition(int r, int c){
 constrain(c,1,16);
 constrain(r,1,2);
 if(r==1){
    p=c+127;
 } else
   p=c+147;
 
 
 Serial.write(p);
}

  
  
/*
Value of 128-143 puts in 1st row
""148-163 puts in 2nd row
*/
