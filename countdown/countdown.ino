int button = 0;
const int f = 3;
const int g = 2;
const int e = 6;
const int d = 7;
const int c = 8;
const int b = 13;
const int a = 12;

void setup () {
  Serial.begin(9600);
  pinMode(3, OUTPUT);//F-TL
  pinMode(2, OUTPUT);//G-M
  pinMode(6, OUTPUT);//E-BL
  pinMode(7, OUTPUT);//D-B
  pinMode(8, OUTPUT);//C-BR
  pinMode(13, OUTPUT);//B-TR
  pinMode(12, OUTPUT);//A-T
  pinMode(0,INPUT_PULLUP);
}

void loop () {
  Serial.println(button);
  button = digitalRead(0);
  if (button == 0){
  
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  delay(1000);}
  //9
  
  if (button == 0){
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  delay(1000);}
  //8
  
  if (button == 0){
  digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  delay(1000);}
  //7
  
  if (button == 0){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,1);
  delay(1000);}
  //6
  if (button == 0){
  digitalWrite(a,1);
  digitalWrite(b,0);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  delay(1000);}
  //5
  if (button == 0){
    digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,1);
  digitalWrite(g,1);
  delay(1000);}
  //4
  
  if (button == 0){
    digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,1);
  delay(1000);}
  //3
  if (button == 0){
    digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,0);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,0);
  digitalWrite(g,1);
  delay(1000);}
  //2
 if (button == 0){
   digitalWrite(a,0);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,0);
  digitalWrite(e,0);
  digitalWrite(f,0);
  digitalWrite(g,0);
  delay(1000);}
  //1
 if (button == 0){
   digitalWrite(a,1);
  digitalWrite(b,1);
  digitalWrite(c,1);
  digitalWrite(d,1);
  digitalWrite(e,1);
  digitalWrite(f,1);
  digitalWrite(g,0);
  delay(1000);  }
  //0
}

  
  
