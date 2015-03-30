// Controlling a servo position using a potentiometer (variable resistor) 
// by Michal Rinott <http://people.interaction-ivrea.it/m.rinott> 

#include <Servo.h> 
#include <IRremote.h>

int RECV_PIN = 11; 

Servo myservo;  // create servo object to control a servo 
int val = 130;    // variable to read the value from the analog pin 
int motor = 0;
IRrecv irrecv(RECV_PIN);
decode_results results; 

void setup() 
{ Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  irrecv.enableIRIn();
 } 
 
void loop() {   
  if (irrecv.decode(&results)){
    Serial.print("motor = ");
    Serial.print(motor);
    Serial.print("\t remotevalue = ");
    Serial.println(results.value);
    analogWrite(3,motor);
  
  if (results.value == 89149445){
    motor = 255;}
    
  if (results.value == 83908956){
    motor = 0;}
  
  if (results.value == 83887105){
  val = val - 15;}
  
  if (results.value == 83920001){
  val = val + 15;}
  
  if (results.value == 87556157){
  val = 90;}
 
  myservo.write(val);  // sets the servo position according to the scaled value 
  

irrecv.resume(); // Receive the next value

  }
}


