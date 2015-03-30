#include <myLCD.h>
#include <SPI.h>
#include <WiFi.h>

char ssid[] = "Tolens WiFi"; //  your network SSID (name) 
char title[] ={10000};

int status = WL_IDLE_STATUS;
char server[] = "www.reddit.com";    // name address for Google (using DNS)

WiFiClient client;
myLCD myLCD;

void setup() {
  Serial.begin(9600); 
  myLCD.backlightOn();
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
  Serial.println("Done");
  printWifiStatus();

  Serial.println("\nConnect to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 80)) {
    Serial.println("connecting to server");
    // Make a HTTP request:
    client.println("GET /r/todayilearned/new.rss HTTP/1.1");
    client.println("Host:www.reddit.com");
    client.println("Connection: close");
    client.println();
  }
}

void loop() {
  while (client.available()) 
  {

    for(int posts=0;posts<5;posts++){

      if(client.find("<item>")==1)
      {     

        if(client.find("<title>")==1)
        {          
          //while(client.find("</title>")==0)
          for(int t=0;t<300;t++)
            {      
              
            char c = client.read();
            title[t] = c;
            
            if(c=='/')
            {
              break;
            }
            Serial.write(c);
                        
          }
        }
      }
    }
  }   




  // if the server's disconnected, stop the client:
  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting from server.");
    client.stop();

    // do nothing forevermore:
    while(true);
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
}







