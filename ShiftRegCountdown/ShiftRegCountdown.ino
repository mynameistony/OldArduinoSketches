int latchPin = 8;
int clockPin = 2;
int dataPin = 3;
int number[] = {
  222, 130, 62, 174, 226, 236, 252, 134, 254, 238};//0 to 9 values to display on 7seg display
long t;
long interval = 1000;
int count = 0;
void setup() {
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  long now = millis();
       if (now > t) {
      t = now + interval;    
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, number[count]);  
    digitalWrite(latchPin, HIGH);
    count++;
    if (count >9){
      count = 0;
    }
    Serial.println(count);
     } 
}

