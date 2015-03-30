#include <SPI.h>
#include <WiFi.h>

char ssid[] = "Meeoowww"; //  your network SSID (name) 
char pass[] = "clarkbowers21";
  
int command=0;

int status = WL_IDLE_STATUS;

long previousMillis = 0;        // will store last time LED was updated

long interval = 500;           // interval at which to blink (milliseconds)

char server[] = "smtp.mail.yahoo.com";    // name address for Google (using DNS)


WiFiClient client;

void setup() {
  //Initialize serial and wait for port to open:
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
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:    
    status = WiFi.begin(ssid,pass);
  
    // wait 10 seconds for connection:
    delay(10000);
  } 
  Serial.println("Connected to wifi");
  printWifiStatus();
  
  Serial.println("\nStarting connection to server...");
  // if you get a connection, report back via serial:
  if (client.connect(server, 587)) {
    Serial.println("connected to server");
  }
  
  delay(1000);
  client.write("HELO spongedude10195@yahoo.com");

}

void loop() {
   
  if (client.available()) {
    char c = client.read();
        
    Serial.write(c);
  } 
     
   unsigned long currentMillis = millis();

   if(currentMillis - previousMillis > interval) {
    previousMillis = currentMillis;  
    client.write("HELP"); 
//    command++;
//    
//    if(command==1){
//      client.print("HELP");
//      Serial.print("command1");
//    }
//    if(command==2){
//      Serial.print("command2");
//    }
//    if(command==3){
//      Serial.print("command3");
//    }
//    if(command==4){
//      Serial.print("command4");
//    }   
      
  }else    
  



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





