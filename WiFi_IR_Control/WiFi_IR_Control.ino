#include <SPI.h>
#include <WiFi.h>
#include <IRremote.h>

#define Address      0x4004     
#define Power        0x538BC81
#define vUP          0x5000401
#define vDown        0x5008481
#define pause        0x8000
#define guide        0x5000
#define cancel       0x4800
#define info         0x0000
#define left         0x7000
#define right        0x6000
#define menu         0x2C00

char ssid[] = "home network";      //  your network SSID (name)

IRsend irsend;


int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);      // initialize serial communication
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true);        // don't continue
  } 

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Connecting to: ");
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

            client.print("<font size='20'><a href=\"/STEREO\">STEREO CONTROL</a><br>");
            client.print("<a href=\"/DVR\">DVR CONTROL</a><br>");              
            
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
        
        
        if (currentLine.endsWith("GET /DVR")) { 
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");  
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");  
            
            digitalWrite(5,1);
        }
          if (currentLine.endsWith("GET /INFO")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(info,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");             
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }       
 
           if (currentLine.endsWith("GET /LEFT")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(left,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");             
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }   
            
          if (currentLine.endsWith("GET /RIGHT")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(right,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");             
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }         
      
          if (currentLine.endsWith("GET /MENU")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(menu,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");             
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }   

        if (currentLine.endsWith("GET /UP")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(0x6800,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");             
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }        

        if (currentLine.endsWith("GET /DOWN")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(0x7800,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");             
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }

        if (currentLine.endsWith("GET /SELECT")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(0x4000,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");              
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }            
            
            if (currentLine.endsWith("GET /PAUSE")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(pause,16);
              }
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>");              
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }

        if (currentLine.endsWith("GET /GUIDE")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(guide,16);
              }           
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>"); 
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");              }        

        if (currentLine.endsWith("GET /CANCEL")) { 
              for (int count = 0; count < 5; count++){
              irsend.sendDISH(cancel,16);
              }        
            client.print("<font size='20'><a href=\"/PAUSE\">Pause</a><br>");
            client.print("<a href=\"/GUIDE\">Guide</a><br>");
            client.print("<a href=\"/CANCEL\">Cancel</a><br>"); 
            client.print("<a href=\"/UP\">Channel Up</a><br>");          
            client.print("<a href=\"/DOWN\">Channel Down</a><br>");          
            client.print("<a href=\"/SELECT\">Select</a><br>"); 
            client.print("<a href=\"/INFO\">Info</a><br>");  
            client.print("<a href=\"/LEFT\">Left</a><br>");  
            client.print("<a href=\"/RIGHT\">Right</a><br>");  
            client.print("<a href=\"/MENU\">Menu</a><br>");            }
 
        if (currentLine.endsWith("GET /STEREO")) { 
            client.print("<font size='20'><a href=\"/POWER\">Toggle Power</a><br>");
            client.print("<a href=\"/VUP\">Volume Up</a><br>");
            client.print("<a href=\"/VDOWN\">Volume Down</a><br>");
            digitalWrite(5,1);
        }

         if (currentLine.endsWith("GET /POWER")) {
               irsend.sendPanasonic(Address,Power);
            client.print("<font size='20'><a href=\"/POWER\">Toggle Power</a><br>");
            client.print("<a href=\"/VUP\">Volume Up</a><br>");
            client.print("<a href=\"/VDOWN\">Volume Down</a><br>");               
         }
         if (currentLine.endsWith("GET /VUP")) {
           for (int count = 0; count < 6; count++){
               irsend.sendPanasonic(Address,vUP);
               delay(100);
               irsend.sendPanasonic(Address,vUP);      
         }
            client.print("<font size='20'><a href=\"/POWER\">Toggle Power</a><br>");
            client.print("<a href=\"/VUP\">Volume Up</a><br>");
            client.print("<a href=\"/VDOWN\">Volume Down</a><br>");
          }
         if (currentLine.endsWith("GET /VDOWN")) {
           for (int count = 0; count < 6; count++){
               irsend.sendPanasonic(Address,vDown);
               delay(100);
               irsend.sendPanasonic(Address,vDown);
               
         }
            client.print("<font size='20'><a href=\"/POWER\">Toggle Power</a><br>");
            client.print("<a href=\"/VUP\">Volume Up</a><br>");
            client.print("<a href=\"/VDOWN\">Volume Down</a><br>");
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

