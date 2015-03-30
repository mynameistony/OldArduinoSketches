
#include <SPI.h>
#include <WiFi.h>
int time = millis();
int seconds;
int hours;
int minutes;

unsigned long value;

int data=11;
int latch=8;
int clock=12;

int numbers[]={
  2,118,24,48,100,33,1,114,0,32};
  
char ssid[] = "Tolens WiFi";      //  your network SSID (name) 

int status = WL_IDLE_STATUS;
WiFiServer server(80);

void setup() {
  Serial.begin(9600);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);  // initialize serial communication

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present"); 
    while(true);        // don't continue
  } 

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) { 
    Serial.print("Connecting: ");
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

  int button1 = digitalRead(2);
  int button2 = digitalRead(3);
  int button3 = digitalRead(5);
  
  int analog1 = analogRead(A5);
  int analog2 = analogRead(A4);
 
 analog1=map(analog1,0,1023,0,100);
 analog2=map(analog2,0,1023,0,100);
 
Serial.print(analog1);
Serial.print("     ");
Serial.print(analog2);
Serial.print("     ");
Serial.print(button1);
Serial.print("     ");
Serial.print(button2);
Serial.print("     ");
Serial.println(button3);

  if (client) {                             // if you get a client,
    Serial.println("new client");           // print a message out the serial port
    String currentLine = "";                // make a String to hold incoming data from the client
    while (client.connected()) {            // loop while the client's connected
      if (client.available()) {             // if there's bytes to read from the client,
        char c = client.read();             // read a byte, then
       
        Serial.println(c);                    // print it out the serial monitor
               
            client.print(analog1);
            client.print(analog2);
            client.print(button1);
            client.print(button2);
            client.println(button3);     
            
          
          }
                 break;

}     

      
    }
    // close the connection:
    client.stop();
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
