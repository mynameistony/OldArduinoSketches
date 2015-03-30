#include "pitches.h"
int button = 2;
int off = 13;
int on = 12;
int speaker = 8;
int melody[] = {
  NOTE_C4, NOTE_G3,NOTE_G3, NOTE_A3, NOTE_G3,0, NOTE_B3, NOTE_C4};
int noteDurations[] = {
  4, 8, 8, 4,4,4,4,4 };


void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP);
  pinMode(on, OUTPUT);
  pinMode(off, OUTPUT);
  pinMode(speaker, OUTPUT);
} 
 void loop() {
  int state = digitalRead(button);
  Serial.println(state);
  delay(5);
  
  if (state == 1) {
    digitalWrite(on,HIGH);
  }
  else{
    digitalWrite(on,LOW);
  }
  
  if (state == 0) {
    digitalWrite(off,HIGH);
  }
  else{
    digitalWrite(off,LOW);
  }
  
  if (state == 0) {
    for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[thisNote];
    tone(8, melody[thisNote],noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    }}}
    
