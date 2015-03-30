// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------

#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

long previousMillis = 0;
long interval = 50; 

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(9600); // Open serial monitor at 115200 baud to see ping results.
}

void loop() {
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;  
    unsigned int uS = sonar.ping(); 
    unsigned int distance = uS / US_ROUNDTRIP_CM;
    int note=map(distance,0,100,0,700);
    analogWrite(6, note);
    
   Serial.print("Ping: ");
  Serial.print(distance);
  Serial.println("cm");
 
  }
}
