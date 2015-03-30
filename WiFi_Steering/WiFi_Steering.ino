#include <Servo.h> 
#include <SPI.h>
#include <WiFi.h>

Servo myservo;
int val = 90;
int motor = 0;
char ssid[] = "home network";      //  your network SSID (name) 

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);      // initialize serial communication
  pinMode(9, OUTPUT);      // set the LED pin mode
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 

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
            client.print("Click <a href=\"/RIGHT\">here to go right</a><br>");
            client.print("Click <a href=\"/LEFT\">Click here to go left</a><br>");
            client.print("Click <a href=\"/90\">Click here to straighten up</a><br>");
            client.print("Click <a href=\"/ON\">MOTOR ON</a><br>");
            client.print("Click <a href=\"/OFF\">MOTOR OFF</a><br>");
            
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
        if (currentLine.endsWith("GET /RIGHT")) {
          val = 140;          // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /LEFT")) {
          val = 40;               // GET /L turns the LED off
        }
        if (currentLine.endsWith("GET /90")){
          val = 90;
        }
        if (currentLine.endsWith("GET /ON")){
          motor = 255;
        }
        if (currentLine.endsWith("GET /OFF")){
          motor = 0;
        }
    }
    // close the connection:
    
    myservo.write(val);
    analogWrite(3,motor);
    }
      client.stop();
  Serial.println("client disconnected");
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
