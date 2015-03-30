#include <SPI.h>
#include <WiFi.h>
int latchPin = 8;
int clockPin = 2;
int dataPin = 3;

int zero = 252;
int one = 96;
int two = 218;
int three = 242;
int four = 102;
int five = 182;
int six = 190;
int seven = 224;
int eight = 254;
int nine = 246;
int alloff = 0;

char ssid[] = "home network";      //  your network SSID (name)

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);      // initialize serial communication
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
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
            client.print("Click <a href=\"/9\">here</a> to display 9<br>");
            client.print("Click <a href=\"/8\">here</a> to display 8<br>");
            client.print("Click <a href=\"/7\">here</a> to display 7<br>");
            client.print("Click <a href=\"/6\">here</a> to display 6<br>");
            client.print("Click <a href=\"/5\">here</a> to display 5<br>");
            client.print("Click <a href=\"/4\">here</a> to display 4<br>");
            client.print("Click <a href=\"/3\">here</a> to display 3<br>");
            client.print("Click <a href=\"/2\">here</a> to display 2<br>");
            client.print("Click <a href=\"/1\">here</a> to display 1<br>");
            client.print("Click <a href=\"/0\">here</a> to display 0<br>"); 
            client.print("Click <a href=\"/OFF\">here</a> to turn off<br>");



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
        if (currentLine.endsWith("GET /9")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, nine);  
    digitalWrite(latchPin, HIGH);
  }
        if (currentLine.endsWith("GET /8")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, eight);  
    digitalWrite(latchPin, HIGH);
  }
        if (currentLine.endsWith("GET /7")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, seven);  
    digitalWrite(latchPin, HIGH);
  }   
        if (currentLine.endsWith("GET /6")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, six);  
    digitalWrite(latchPin, HIGH);
  }
        if (currentLine.endsWith("GET /5")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, five);  
    digitalWrite(latchPin, HIGH);
  }
        if (currentLine.endsWith("GET /4")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, four);  
    digitalWrite(latchPin, HIGH);
  }
        if (currentLine.endsWith("GET /3")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, three);  
    digitalWrite(latchPin, HIGH);
  }
        if (currentLine.endsWith("GET /2")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, two);  
    digitalWrite(latchPin, HIGH);
  }   
        if (currentLine.endsWith("GET /1")) {          
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, one);  
    digitalWrite(latchPin, HIGH);
  }   
        if (currentLine.endsWith("GET /0")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, zero);  
    digitalWrite(latchPin, HIGH);
  }   
        if (currentLine.endsWith("GET /OFF")) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, alloff);  
    digitalWrite(latchPin, HIGH);
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

