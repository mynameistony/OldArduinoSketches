int latchPin = 8;
int clockPin = 2;
int dataPin = 6;

int button1 = digitalRead(5);  
int button2 = digitalRead(4);  
int switch1 = digitalRead(3);
     
int pot1 = analogRead(A0);
int pot2 = analogRead(A1);
int pot3 = analogRead(A2);
int pot4 = analogRead(A3);
int pot5 = analogRead(A4);
int pot6 = analogRead(A5);

int dig1 = map(pot1,0,1020,0,9);
int dig2 = map(pot2,0,1020,0,9);
int dig3 = map(pot3,0,1020,0,9);
int dig4 = map(pot4,0,1020,0,9);
int dig5 = map(pot5,0,1020,0,9);
int dig6 = map(pot6,0,1020,0,9);  
  
int add1;
int add2;

long ans;

int ansdig1;
int ansdig2;
int ansdig3;
int ansdig4;

float subAns1;
float subAns2;
float subAns3;
float subAns4;

int number[] = {
  252, 96, 218, 242, 102, 182, 190, 224, 254, 246};
  
void setup() {
Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  
} 
  void loop() {
    int button1 = digitalRead(5);  
int button2 = digitalRead(4);  
int switch1 = digitalRead(3);
     
int pot1 = analogRead(A0);
int pot2 = analogRead(A1);
int pot3 = analogRead(A2);
int pot4 = analogRead(A3);
int pot5 = analogRead(A4);
int pot6 = analogRead(A5);

int dig1 = map(pot1,0,1020,0,9);
int dig2 = random(10);//map(pot2,0,1020,0,9);
int dig3 = random(10); //map(pot3,0,1020,0,9);
int dig4 = random(10); //map(pot4,0,1020,0,9);
int dig5 = random(10); //map(pot5,0,1020,0,9);
int dig6 = random(10); //map(pot6,0,1020,0,9);  

 
     digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, number[dig1]);  
   /* shiftOut(dataPin, clockPin, LSBFIRST, number[dig2]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[dig3]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[dig4]);      
    shiftOut(dataPin, clockPin, LSBFIRST, number[dig5]);      
    shiftOut(dataPin, clockPin, LSBFIRST, number[dig6]);      
    shiftOut(dataPin, clockPin, LSBFIRST, number[ansdig1]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[ansdig2]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[ansdig3]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[ansdig4]);    */  
     digitalWrite(latchPin, HIGH);
     
 if (switch1==0){    
    if (button1 == 0){  
  add1=dig1*100+dig2*10+dig3;
  add2=dig4*100+dig5*10+dig6;
  
  ans=add1+add2;
  
  ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
  
}

    if (button2 == 0){
  add1=dig1*100+dig2*10+dig3;
  add2=dig4*100+dig5*10+dig6;
  
  ans=add1-add2;
  
  ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
  
  
    ansdig1=abs(ansdig1);
    ansdig2=abs(ansdig2);
    ansdig3=abs(ansdig3);
    ansdig4=abs(ansdig4);
}
 }
 if (switch1==1){  
    if (button1 == 0){
   
  add1=(dig1*10)+dig2;
  add2=(dig3*10)+dig4;
  
  ans=add1*add2;
  
  ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
}
    if (button2 == 0){
  subAns1 = (dig1*10)+dig2;
  
  subAns2 = (dig3*10)+dig4;
  
  subAns3 = subAns1/subAns2;
  subAns4 = subAns1/subAns2;
  
    subAns3=subAns3*1000;
 
 ans=subAns3; 
 
 if(ans>9999){
   ans=ans/10;
 }
 
  ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
    } 
 }
  Serial.print(dig1);
  Serial.print(dig1);
 if (switch1==0){    
    if (button1 == 0){
  Serial.print("+") ;   
    }      
    if (button2 == 0){
  Serial.print("-");
    }
 }
 if (switch1==1){     
    if (button1 == 0){
  Serial.print("X");
    }      
    if (button2 == 0){
  Serial.print("/");
    }
 }
  
  Serial.print(dig3);
  Serial.print(dig4);
  Serial.print("=");
  Serial.println(ans);

}


  
  
