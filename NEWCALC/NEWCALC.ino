int latch = 7;
int clock = 5;
int data = 6;

int prevtime;
int time=3000;

int number[] = {
  2,118,24,48,100,33,1,114,0,32};

long dig1;
long dig2;
long dig3;
long dig4;

unsigned int count1;
unsigned int count2;


long ans;

float subAns3;

  
void setup() {
  Serial.begin(9600);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data, OUTPUT);
  pinMode(2,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {

  int button3 = digitalRead(3);
  int button1 = digitalRead(2);
  int button2 = digitalRead(4);

  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);

  count1=map(pot1,0,1023,0,99);
  count2=map(pot2,0,1023,0,99);



Serial.print(button1);
Serial.print("    ");
Serial.print(button2);
Serial.print("    ");
Serial.print(button3);
Serial.print("    ");
Serial.print(count1);
Serial.print("    ");
Serial.println(count2);

 


dig1=count1/10;
dig2=count1%10;
dig3=count2/10;
dig4=count2%10;


if(button1==1&&button2==0&&button3==1){
  add();
}

if(button1==1&&button2==1&&button3==0){
  subtract();
}

if(button1==0&&button2==0&&button3==1){
  multiply();
}

if(button1==0&&button2==1&&button3==0){
  divide();
}

breakdown();

if (button1&&button2&&button3==1){  
dig1=count1/10;
dig2=count1%10;
dig3=count2/10;
dig4=count2%10;

}  
show();




}

void show(){
//DIGIT 1***************
digitalWrite(8,1);
digitalWrite(9,0);
digitalWrite(10,0);
digitalWrite(11,0);
  
digitalWrite(latch,0);
shiftOut(data, clock, LSBFIRST, number[dig1]);
digitalWrite(latch,1);

//delay(5);
//***********************
//DIGIT 2***************
digitalWrite(8,0);
digitalWrite(9,1);
digitalWrite(10,0);
digitalWrite(11,0);
  
digitalWrite(latch,0);
shiftOut(data, clock, LSBFIRST, number[dig2]);
digitalWrite(latch,1);

//delay(5);
//***********************

//DIGIT 3***************
digitalWrite(8,0);
digitalWrite(9,0);
digitalWrite(10,1);
digitalWrite(11,0);
  
digitalWrite(latch,0);
shiftOut(data, clock, LSBFIRST, number[dig3]);
digitalWrite(latch,1);

//delay(5);
//***********************

//DIGIT 4***************
digitalWrite(8,0);
digitalWrite(9,0);
digitalWrite(10,0);
digitalWrite(11,1);
  
digitalWrite(latch,0);
shiftOut(data, clock, LSBFIRST, number[dig4]);
digitalWrite(latch,1);

//delay(5);
//***********************
}

void breakdown(){
dig1=ans/1000;
dig2=(ans%1000)/100;
dig3=ans%(dig1*1000+dig2*100)/10;
dig4=ans%(dig1*1000+dig2*100+dig3*10);
}

void add(){
  ans=count1+count2;
}
void subtract(){
  ans=count1-count2;
}
void multiply(){
  ans=count1*count2;
}
void divide(){
  ans=count1/count2;
}






