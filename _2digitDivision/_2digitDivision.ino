int dig1;
int dig2;
int dig3;
int dig4;

long ansdig1;
long ansdig2;
long ansdig3;
long ansdig4;

long ans;

float subAns1;
float subAns2;
float subAns3;
float subAns4;
void setup(){
  Serial.begin(9600);
}
void loop(){
  dig1=random(10);
  dig2=random(10);
  dig3=random(10);
  dig4=random(10);
 
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
  
  Serial.print(subAns1); 
  Serial.print(" / ");
  Serial.print(subAns2);
  Serial.print(" = ");
  Serial.print(subAns4);


  Serial.print("\t d1= ");  
  Serial.print(ansdig1);
  Serial.print(".");
  Serial.print("\t d2= ");
  Serial.print(ansdig2);
  Serial.print("\t d3= ");
  Serial.print(ansdig3);
  Serial.print("\t d4= ");
  Serial.println(ansdig4);  
  
}
