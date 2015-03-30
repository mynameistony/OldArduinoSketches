//You should be able to just copy and paste all this text into a sketch and upload and it should work, if theres problem, message me//

#include "pitches.h"//Look up arduino tone library and download from website
/*
Alternately, create new tab labeled "pitches.h" w/o the quotes
and copy and paste the following into it:
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_C5  523
#define NOTE_A4  440
#define NOTE_AS4 466

These are the only notes you need
*/
int button = 2;
int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int speaker = 8;
int line1[] = {//Notes for 1st line
NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4};
int line2[] = {//Notes for 2nd line...etc
  NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4};
int line3[] = {
  NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4, NOTE_E4, NOTE_D4};
  //Notice that theres 7 instead of 6 notes in this line
int line4[] = {
  NOTE_A4, NOTE_A4, NOTE_AS4, NOTE_F4, NOTE_G4, NOTE_F4};
int line1Dur[] = {//duration of notes in 1st line 8=eighth note, 4=quarter note...etc
  8,8,4,4,4,2};
int line2Dur[] = {
  8,8,4,4,4,2};
int line3Dur[] = {//Notice that theres 7 instead of 6
  8,8,4,4,4,4,2};
int line4Dur[] = {
  8,8,4,4,4,2};
  
int ledsequence[] = {//this order is arbitrary and you can change it
  led1, led2, led2, led3, led2, led4, led1,};


void setup() {
  Serial.begin(9600);
  pinMode(button, INPUT_PULLUP); //Wire button to 5v, then straight to pin
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(speaker, OUTPUT);
} 
 void loop() 
 {
  int state = digitalRead(button);//Variable for button state
  Serial.println(state);
  delay(5);
  
  

  
  if (state == 0) //If buttons pushed
  { 
    // LINE1
    for (int thisNote = 0; thisNote < 6; thisNote++) {//Count "thisNote" to 5
     
    int noteDuration = 1000/line1Dur[thisNote];//Defines note duration based on the values above
    
    int pause = noteDuration * 1.10;//Changing this value changes pause between notes
    
    tone(speaker, line1[thisNote],noteDuration);//Plays tone based on "thisNote" value
    digitalWrite(ledsequence[thisNote],HIGH);//Light LED for as long the note plays
    delay(pause);//pause between notes
    digitalWrite(ledsequence[thisNote],LOW);//turn off LED before next note
    delay(100);
  } 
  //LINE2
  for (int thisNote = 0; thisNote < 6; thisNote++) {//Same as before, but different notes
     
    int noteDuration = 1000/line2Dur[thisNote];
    
    int pause = noteDuration * 1.10;
    
    tone(speaker, line2[thisNote],noteDuration);
    digitalWrite(ledsequence[thisNote],HIGH);
    delay(pause);
    digitalWrite(ledsequence[thisNote],LOW);
    delay(100);
  }  
  //LINE3
  for (int thisNote = 0; thisNote < 7; thisNote++) {//Same as before however it counts to 6
  //because there are 7 notes instead of 6
     
    int noteDuration = 1000/line3Dur[thisNote];
    
    int pause = noteDuration * 1.10;
    
    tone(speaker, line3[thisNote],noteDuration);
    digitalWrite(ledsequence[thisNote],HIGH);
    delay(pause);
    digitalWrite(ledsequence[thisNote],LOW);
    delay(100);
  }  
  //LINE4
  for (int thisNote = 0; thisNote < 6; thisNote++) {
     
    int noteDuration = 1000/line4Dur[thisNote];
    
    int pause = noteDuration * 1.10;
    
    tone(speaker, line4[thisNote],noteDuration);
    digitalWrite(ledsequence[thisNote],HIGH);
    delay(pause);
    digitalWrite(ledsequence[thisNote],LOW);
    delay(100);}
  }
 }
