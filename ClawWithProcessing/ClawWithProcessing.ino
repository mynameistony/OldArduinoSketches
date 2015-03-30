#include <SPI.h>
#include <WiFi.h>
#include <Servo.h>


char ssid[] = "home network"; //  your network SSID (name) 
char pass[] = "secretPassword";    // your network password (use for WPA, or use as key for WEP)

Servo leftmotor;
Servo rightmotor;
Servo arm;
Servo claw;

char input;

int status = WL_IDLE_STATUS;
// if you don't want to use DNS (and reduce your sketch size)
// use the numeric IP instead of the name for the server:
IPAddress server(192,168,254,10);  // numeric IP for Google (no DNS)
//char server[] = "www.google.com";    // name address for Google (using DNS)

// Initialize the Ethernet client library
// with the IP address and port of the server 
// that you want to connect to (port 80 is default for HTTP):
WiFiClient client;

void setup() {
 
leftmotor.attach(9);
rightmotor.attach(6);
arm.attach(5);
claw.attach(4);

  Serial.begin(9600); 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    // don't continue:
    while(true);
  } 
  
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Connecting: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid);
  
    // wait 10 seconds for connection:
    delay(10000);
  } 
  Serial.println("Connected to wifi");
  printWifiStatus();
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 5204)) {
    Serial.println("connected to server");
  }
}

void loop() {
  // if there are incoming bytes available 
  // from the server, read them and print them:
  while (client.available()) {
    input = client.read();
    
    if(input<=180){
      leftmotor.write(input);
      rightmotor.write(input);
    }
    
    if(input==190){
      leftmotor.write(160);
      rightmotor.write(0);
    }
    if(input==191){
      leftmotor.write(0);
      rightmotor.write(160); 
    }
    if(input==200){
      claw.write(160);
      delay(50);190
      claw.write(0);
    }
    if(input==201){
      claw.write(20);
      delay(50);
      claw.write(0);
    }
    if(input==210){
      arm.write(160);
      delay(50);
      arm.write(0);
    }
    if(input==211){
      arm.write(20);
      delay(50);
      arm.write(0);
    }
      
}


Serial.println(input, DEC);

}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}





