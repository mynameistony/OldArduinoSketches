#include <NewPing.h>

#define TRIGGER_PIN  3  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     4  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 60 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int latch = 5;
int data = 6;
int clock = 7;

int digit1=8;
int digit2=9;
int digit3=10;
int digit4=12;
int number[]={
  32, 55, 12, 6, 19, 66, 64, 39, 0, 2, 255};

int lastButtonState=0;
int diststate=0;
int count=0;
int lastcount;
void setup() {
  Serial.begin(9600);
  pinMode(2,INPUT_PULLUP);

  pinMode(latch,OUTPUT);
  pinMode(data,OUTPUT);
  pinMode(clock,OUTPUT);

  pinMode(digit1,OUTPUT);
  pinMode(digit2,OUTPUT);
  pinMode(digit3,OUTPUT);
  pinMode(digit4,OUTPUT);  

  pinMode(10,OUTPUT);
}
void loop() {
  int switch1=digitalRead(2);
  delay(35);                   
  unsigned int uS = sonar.ping();
  int distcm = uS/ US_ROUNDTRIP_CM;
  int distin = distcm*.39;

  int brightness = map(distcm,3,50,0,255);
  
 // if(distcm>30|distcm==0){
 //   brightness=0;
 // }
  if(distcm>0)
  {
    analogWrite(10,brightness);
  }
  
  
Serial.print(lastcount);
Serial.println(count);

  


  



  int num1=distcm/10;
  int num2=distcm%10;

  int num3=distin/10;
  int num4=distin%10;

  if (switch1==0){
    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, number[num1]);
    digitalWrite(latch,1);  

    digitalWrite(digit1,1);
    digitalWrite(digit2,0);
  //  digitalWrite(digit3,0);
    digitalWrite(digit4,0);

    //delay(4);  

    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, number[num2]);
    digitalWrite(latch,1);  

    digitalWrite(digit1,0);
    digitalWrite(digit2,1);
 //   digitalWrite(digit3,0);
    digitalWrite(digit4,0);

    //delay(4);  

    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, 255);
    digitalWrite(latch,1);  

    digitalWrite(digit1,0);
    digitalWrite(digit2,0);
 //   digitalWrite(digit3,1);
    digitalWrite(digit4,0);

    //delay(4);

    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, 220);
    digitalWrite(latch,1);

    digitalWrite(digit1,0);
    digitalWrite(digit2,0);
  //  digitalWrite(digit3,0);
    digitalWrite(digit4,1);

    //delay(4);

  }
  if(switch1==1){


    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, number[num3]);
    digitalWrite(latch,1);  

    digitalWrite(digit1,1);
    digitalWrite(digit2,0);
  //  digitalWrite(digit3,0);
    digitalWrite(digit4,0);

    //delay(4);  

    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, number[num4]);
    digitalWrite(latch,1);  

    digitalWrite(digit1,0);
    digitalWrite(digit2,1);
  //  digitalWrite(digit3,0);
    digitalWrite(digit4,0);

    //delay(4);  

    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, 255);
    digitalWrite(latch,1);  

    digitalWrite(digit1,0);
    digitalWrite(digit2,0);
  //  digitalWrite(digit3,1);
    digitalWrite(digit4,0);

    //delay(4);

    digitalWrite(latch,0);
    shiftOut(data, clock, LSBFIRST, 213);
    digitalWrite(latch,1);

    digitalWrite(digit1,0);
    digitalWrite(digit2,0);
  //  digitalWrite(digit3,0);
    digitalWrite(digit4,1);

    //delay(4);
  }



}



