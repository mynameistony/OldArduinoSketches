int latch1 = 7;
int latch2 = 13;
int clock = 5;
int data1 = 6;
int data2 = 12;

int numberdec[] = {
  32, 55, 12, 5, 19, 65, 64, 39, 0, 1, 232};
int number[] = {
  160, 183, 140, 133, 147, 193, 192, 167, 128, 129, 223};

long ansdig1;
long ansdig2;
long ansdig3;
long ansdig4;

int count1;
int count2;
int count3;
int count4;
int count5;
int count6;

long ans;

float subAns3;

void setup() {
  Serial.begin(9600);
  pinMode(latch1, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(data1, OUTPUT);
  pinMode(latch2, OUTPUT);
  pinMode(data2, OUTPUT);
  pinMode(11,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(9,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
}

void loop() {


  int pot1 = analogRead(A0);
  int pot2 = analogRead(A1);
  int pot3 = analogRead(A2);
  int pot4 = analogRead(A3);
  int pot5 = analogRead(A4);
  int pot6 = analogRead(A5);

  int switch1 = digitalRead(10);//change?
  int button1 = digitalRead(11);//change?
  int button2 = digitalRead(8);//change?

  count1=map(pot1,0,1023,0,9);
  count2=map(pot2,0,1023,0,9);
  count3=map(pot3,0,1023,0,9);
  count4=map(pot4,0,1023,0,9);
  count5=map(pot5,0,1023,0,9);
  count6=map(pot6,0,1023,0,9);

  if(switch1==1){
    count1=0;
    count4=0;
  }


  float numb1 = count1*100+count2*10+count3;
  float numb2 = count4*100+count5*10+count6;

  if (switch1==1){
  
    if (button1==0){//MULTIPLICATION
      ans=numb1*numb2;

      ansdig1=ans/1000;
      ansdig2=(ans%1000)/100;
      ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
      ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);

    }

    if (button2==0){//DIVISION
      subAns3 = numb1/numb2;

      ans = subAns3*1000;
      if(ans>9999){
        ans=ans/10;
      }

      ansdig1=ans/1000;
      ansdig2=(ans%1000)/100;
      ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
      ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);

    }   
  }
  if (switch1==0){
    if (button1==0){//ADDITION
      ans=numb1+numb2;


      ansdig1=ans/1000;
      ansdig2=(ans%1000)/100;
      ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
      ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);

    }  
    if (button2==0){

      ans=numb1-numb2;

      ansdig1=ans/1000;
      ansdig2=(ans%1000)/100;
      ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
      ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);

      ansdig4=abs(ansdig4);
      ansdig3=abs(ansdig3);
      ansdig2=abs(ansdig2);
      ansdig1=abs(ansdig1);

  }
  }

  if (switch1==1){
    count1=0;
    count4=0;
  }
  

  
 
  //DIGIT1
  digitalWrite(latch1,0);
   shiftOut(data1, clock, LSBFIRST, number[count4]);
   shiftOut(data1, clock, LSBFIRST, number[count3]);
  digitalWrite(latch1,1);
   
  digitalWrite(latch2,0);
  if(switch1==1&&button2==0&&subAns3>10){
      shiftOut(data2, clock, LSBFIRST, numberdec[ansdig2]);
    }else
   shiftOut(data2, clock, LSBFIRST, number[ansdig2]);//ANSDIGIT2
  digitalWrite(latch2,1);
    
 digitalWrite(9,0);
 digitalWrite(4,1);
 digitalWrite(3,0);
 digitalWrite(2,0);
   
   delay(6);
   //DIGIT2

   
   
   digitalWrite(latch1,0);
 shiftOut(data1, clock, LSBFIRST, number[count5]);//DIGIT2
 shiftOut(data1, clock, LSBFIRST, number[count1]);
   digitalWrite(latch1,1);
   
   digitalWrite(latch2,0);      
 shiftOut(data2, clock, LSBFIRST, number[ansdig4]);//ANSDIGIT2
   digitalWrite(latch2,1);
   
 digitalWrite(9,0);
 digitalWrite(2,1);
 digitalWrite(3,0);
 digitalWrite(4,0);
  
    delay(6);

 //DIGIT3
   digitalWrite(latch1,0);
 shiftOut(data1, clock, LSBFIRST, number[count6]);//DIGIT3
 shiftOut(data1, clock, LSBFIRST, number[count2]);
   digitalWrite(latch1,1);
  
   
   digitalWrite(latch2,0);
 shiftOut(data2, clock, LSBFIRST, number[ansdig3]);//ANSDIGIT3
   digitalWrite(latch2,1);
  
 digitalWrite(9,0);
 digitalWrite(4,0);
 digitalWrite(3,1);
 digitalWrite(2,0);
 
    delay(6);

 //ANSDIGIT4
if(switch1==0&&button2==0&&numb1<numb2){//NEGATIVE
  ansdig1=10;
}

   digitalWrite(latch2,0);      
   if(switch1==1&&button2==0&&subAns3<10){
      shiftOut(data2, clock, LSBFIRST, numberdec[ansdig1]);
    }else
 shiftOut(data2, clock, LSBFIRST, number[ansdig1]);//ANSDIGIT4
   digitalWrite(latch2,1);
   
 digitalWrite(9,1);
 digitalWrite(4,0);
 digitalWrite(3,0);
 digitalWrite(2,0);

   delay(6);

}





