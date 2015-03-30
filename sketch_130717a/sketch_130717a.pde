import cc.arduino.*;

import processing.net.*; 
Client myClient; 
long dataIn; 
 
void setup() { 
  size(200, 200); 
  // Connect to the local machine at port 5204.
  // This example will not run if you haven't
  // previously started a server on this port.
  myClient = new Client(this, "192.168.1.39", 80); 
} 
 
void draw() { 
  if (myClient.available() > 0) { 
    dataIn = myClient.read(); 
    
    myClient.write("OK");
    
    myClient.clear();
  } 
  println(dataIn); 
} 

