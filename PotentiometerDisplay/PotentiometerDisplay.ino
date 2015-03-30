int latchPin = 8;
int clockPin = 2;
int dataPin = 3;
int number[] = {
  222, 130, 62, 174, 226, 236, 252, 134, 254, 238};//0 to 9 values to display on 7seg display
int ans;
int ansdig1;
int ansdig2;
int ansdig3;
int ansdig4;

int pot1;
int pot2;
int pot3;
int pot4;

int count1;
int count2;
int count3;
int count4;

void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(13,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
}

void loop() {
  
  
 int pot1 = analogRead(A0);
 int pot2 = analogRead(A1);
 int pot3 = analogRead(A2);
 int pot4 = analogRead(A3);
 
 int switch1 = digitalRead(13);
 int button1 = digitalRead(12);
 int button2 = digitalRead(11);

 count1=map(pot1,0,1023,0,10);
 count2=map(pot2,0,1023,0,10);
 count3=map(pot3,0,1023,0,10);
 count4=map(pot4,0,1023,0,10);
 

 
 int numb = count4*1000+count3*100+count2*10+count1;
 
 if (switch1==1){
   if (button1==0){
     ans=numb*2;
       ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
  
  count1=ansdig4;
  count2=ansdig3;
  count3=ansdig2;
  count4=ansdig1;
}
   
   if (button2==0){
     ans=numb*5;
       ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
  
  count1=ansdig4;
  count2=ansdig3;
  count3=ansdig2;
  count4=ansdig1;
}
}

 if (switch1==0){
   if (button1==0){
     ans=numb*numb;
       ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
  
  count1=ansdig4;
  count2=ansdig3;
  count3=ansdig2;
  count4=ansdig1;
}
  
   if (button2==0){
     ans=numb*numb*numb;
       ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);
  
  count1=ansdig4;
  count2=ansdig3;
  count3=ansdig2;
  count4=ansdig1;
}

 }

    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, number[count1]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[count2]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[count3]);  
    shiftOut(dataPin, clockPin, LSBFIRST, number[count4]);  
    digitalWrite(latchPin, HIGH);
  }   



     


