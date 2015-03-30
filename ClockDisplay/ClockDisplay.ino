#include <Time.h>//Includes time library that defines hour, minute, second etc.

int number[] = {
  222, 130, 62, 174, 226, 236, 252, 134, 254, 238};//String holding numbers that when shifted out will display 0,1,2..etc.
  
int latchPin = 8;//Shift Register 
int clockPin = 2;//Shift Register
int dataPin = 3;//Pin that shifts out the numbers above

int count1;//variable to hold 1st digit
int count2;//variable to hold 2nd digit
int count3;//etc.
int count4;
int count5;
int count6;


void setup(){ //this section runs once on startup
  Serial.begin(9600);//start serial communication with computer for debugging purposes(not neccesary for final projects
  pinMode(latchPin, OUTPUT);//configs. pins as outputs or inputs
  pinMode(clockPin, OUTPUT);//etc
  pinMode(dataPin, OUTPUT);
  pinMode(13,INPUT_PULLUP); 
  pinMode(12,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);  
}

void  loop(){ //this section of code runs over and over and over.
  int switch1 = digitalRead(13);//stores the value (1 or 0) of the input on pin 13 and gives it a name
  int button1 = digitalRead(12);//same as above
  int button2 = digitalRead(11); //same as above

  int pot1 = analogRead(A0);//stores the analog value (0 to 1023) of pin A0 and gives it a name
  int pot2 = analogRead(A1);//same as above
  int pot3 = analogRead(A2);//same
  int pot4 = analogRead(A3);//same
  int pot5 = analogRead(A4);
  int pot6 = analogRead(A5);
  
  count1=map(count1,0,1023,0,9);//
  count2=map(count2,0,1023,0,5);//
  count3=map(count3,0,1023,0,9);//hr digit2
  count4=map(count4,0,1023,0,9);//hr digit1
  count5=map(count5,0,1023,0,5);//
  count6=map(count6,0,1023,0,9);//

int m= count2*10+count1;//converts 2 seperate digits into a 2 digit number. "*" is multiplication
int h= count4*10+count3;//same
int s= count5*10+count6;//variable to store seconds

if (switch1==0){ 
 if(button1==0){
 int day=count4;
 int month= count3;
 int year=13;
 
  
  digitalWrite(latchPin, LOW);//this is to make sure that you can see what numbers you are setting each digit to
  shiftOut(dataPin, clockPin, LSBFIRST, number[count1]);  
  shiftOut(dataPin, clockPin, LSBFIRST, number[count2]);  
  shiftOut(dataPin, clockPin, LSBFIRST, number[count3]);  
  shiftOut(dataPin, clockPin, LSBFIRST, number[count4]);  
  digitalWrite(latchPin, HIGH);//^^^^
  setTime(h,m,s,day,month,year);// sets time
}
}
h=hour();//sets "h" to the hour
m=minute();//sets "m" to the minutes

//since it can only display numbers one digit at a time you must convert them back to seperate digits
count4=h/10;//remember regular division drops the decimal so if h = 12, count4 = 1. if h=6, count4=0
count3=h%10;//the "%" does the "opposite" of division so if h = 12, count3 = 2, if h=6,count3 = 6;
count2=m/10;//same as above but for the minute
count1=m%10;//again same above

if(button1==0){//if the button is pushed display the seconds
  count4=0;//display 0
  count3=0;//display 0 because seconds are only 2 digits
  count2=s/10;//same as before with hour and minute
  count1=s%10;//same as before
}

if (h==9&&m==50){//********ALARM*******if the time is 9:50 light up the LED
  digitalWrite(10,1);
}else//if its not then dont
digitalWrite(10,0);//******ALARM*******

  digitalWrite(latchPin, LOW);//shifts out the numbers to display
  shiftOut(dataPin, clockPin, LSBFIRST, number[count1]);  
  shiftOut(dataPin, clockPin, LSBFIRST, number[count2]);  
  shiftOut(dataPin, clockPin, LSBFIRST, number[count3]);  
  shiftOut(dataPin, clockPin, LSBFIRST, number[count4]);  
  digitalWrite(latchPin, HIGH);
  
  
  Serial.print(hour());//again this is for debugging and is not vital to the program
  Serial.print(":");
  Serial.print(minute());
  Serial.print(":");
  Serial.println(second());

}


