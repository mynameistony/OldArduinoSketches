#include <Servo.h> 
#include <SPI.h>
#include <WiFi.h>

Servo leftmotor;  // create servo object to control a servo 
Servo rightmotor;  // create servo object to control a servo 
Servo claw;  // create servo object to control a servo 
Servo arm;  // create servo object to control a servo 


char ssid[] = "vanfleet";      //  your network SSID (name) 
char key[] = "computer4";

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);      // initialize serial communication
  leftmotor.attach(9);
  rightmotor.attach(3);
  arm.attach(5);
  claw.attach(6);
  
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true);        // don't continue
  } 

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Attempting to connect to Network named: ");
    Serial.println(ssid);                   // print the network name (SSID);

    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid);
    // wait 10 seconds for connection:
    delay(10000);
  } 
  server.begin();                           // start the web server on port 80
  printWifiStatus();                        // you're connected now, so print out the status
}


void loop() {
  WiFiClient client = server.available();   // listen for incoming clients

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {  
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:    
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("<a href=\"/OPEN\">OPEN CLAW</a><br>");
            client.print("<a href=\"/CLOSE\">CLOSE CLAW</a><br>");
            client.print("<a href=\"/FORWARD\">FORWARD</a><br>");
            client.print("<a href=\"/BACKWARD\">BACKWARD</a><br>");
            client.print("<a href=\"/ARMUP\">ARM UP</a><br>");
            client.print("<a href=\"/ARMDOWN\">ARN DOWN</a><br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;         
          } 
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }     
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /OPEN")) {
          openclaw();           
        }
        if (currentLine.endsWith("GET /CLOSE")) {
          closeclaw();            
        }
        if (currentLine.endsWith("GET /FORWARD")) {         
          forward();
        }
        if (currentLine.endsWith("GET /BACKWARD")) {
          backward();
        }
         if (currentLine.endsWith("GET /ARMUP")) {
          armup();
        }       
         if (currentLine.endsWith("GET /ARMDOWN")) {
          armdown();
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
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
  // print where to go in a browser:
  Serial.print("To see this page in action, open a browser to http://");
  Serial.println(ip);
}

void openclaw(){
claw.write(20);
delay(500);
claw.write(90);
}

void closeclaw(){
claw.write(160);
delay(500);
claw.write(90);
}

void forward(){
  leftmotor.write(160);
  rightmotor.write(20);
  delay(750);
  leftmotor.write(90);
  rightmotor.write(90);
}

void backward(){
  leftmotor.write(20);
  rightmotor.write(160);
  delay(750);
  leftmotor.write(90);
  rightmotor.write(90);  
}

void armup(){
  arm.write(160);
  delay(500);
  arm.write(0);  
}

void armdown(){
  arm.write(20);
  delay(500);
  arm.write(0);  
}



  
