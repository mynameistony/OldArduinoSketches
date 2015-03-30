int val1;
int val2;

int x;
int y;

int button1;
int button2;
int button3;

void setup(){
Serial.begin(9600);

Serial.write(12);

pinMode(2,INPUT_PULLUP);
pinMode(3,INPUT_PULLUP);
pinMode(4,INPUT_PULLUP);

}

void loop(){
  button1=digitalRead(2);
  button2=digitalRead(3);
  button3=digitalRead(4);
  
  val1=analogRead(A0);
  val2=analogRead(A1);


  Serial.write(128);
  Serial.print(val1);
 
  Serial.write(148);
  Serial.print(val2);
 
  Serial.write(133);
  Serial.print(button1);
  
  Serial.write(135);
  Serial.print(button2);  

  Serial.write(137);
  Serial.print(button3); 
 
 
 if (button2==0){
  backlightOn();
 }

 if (button3==0){
  backlightOff();
 }
 
 if (button1==0){
   clearScreen();
 }
 
 }

void cursorset(int x, int y){
if(y==1){
  x+=128;
}

if(y==2){
  x+=148;
}

Serial.write(x);

}

void backlightOn(){
  Serial.write(17);
}

void backlightOff(){
  Serial.write(18);
}
void clearScreen(){
  Serial.write(12);
}
  
  
  
  
  
  
/*
Value of 128-143 puts in 1st row
""148-163 puts in 2nd row
*/
