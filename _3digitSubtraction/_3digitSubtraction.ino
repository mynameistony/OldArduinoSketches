int dig1;
int dig2;
int dig3;
int dig4;
int dig5;
int dig6;

int add1;
int add2;

int ans;

int ansdig1;
int ansdig2;
int ansdig3;
int ansdig4;

void setup(){
  Serial.begin(9600);
}

void loop(){
  dig1=random(10);
  dig2=random(10);
  dig3=random(10);
  dig4=random(10);
  dig5=random(10);
  dig6=random(10);
  
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

  
  Serial.print(dig1);
  Serial.print(dig2);
  Serial.print(dig3);
  Serial.print(" - ");
  Serial.print(dig4);
  Serial.print(dig5);
  Serial.print(dig6);
  Serial.print(" = ");
  Serial.print(ans); 
 
 if (add1>add2){
  Serial.print("\t ");     
  Serial.print("\t ");  
  Serial.print(ansdig1);
}
 if (add1<add2){   
  Serial.print("\t - ");  
}
  Serial.print("\t ");
  Serial.print(ansdig2);
  Serial.print("\t ");
  Serial.print(ansdig3);
  Serial.print("\t ");
  Serial.println(ansdig4);  
}
