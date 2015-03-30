int dig1;
int dig2;
int dig3;
int dig4;

int mult1;
int mult2;

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
  
  mult1=(dig1*10)+dig2;
  mult2=(dig3*10)+dig4;
  
  ans=mult1*mult2;
  
  ansdig1=ans/1000;
  ansdig2=(ans%1000)/100;
  ansdig3=ans%(ansdig1*1000+ansdig2*100)/10;
  ansdig4=ans%(ansdig1*1000+ansdig2*100+ansdig3*10);

  Serial.print(dig1);
  Serial.print(dig2);
  Serial.print(" X ");
  Serial.print(dig3);
  Serial.print(dig4);
  Serial.print(" = ");
  Serial.println(ans); 
 
  Serial.print("\t d1= ");  
  Serial.print(ansdig1);
  Serial.print("\t d2= ");
  Serial.print(ansdig2);
  Serial.print("\t d3= ");
  Serial.print(ansdig3);
  Serial.print("\t d4= ");
  Serial.println(ansdig4);  
  
 }
