/*
 Arduino JSON Data Server for iOS
 created January 1, 2012
 by M. Heeres
 arduinocontrolapp@gmail.com

 Not all commands currently supported by this code are used by the iOS app.
 Feel free to modify this code but keep in mind the mandatory used syntax when used in combination with the iOS app.
 Any commends or requests regarding this code, in combination with or without the iOS app, is welcome.
*/

#include <SPI.h>
#include <Ethernet.h>
#include <string.h>
//*************************************************** USER EDITABLE AREA ****************************************************//
// MAC address can be anything that is unique within your network.                                                           //
// IP is the address the Arduino Ethernet Card would respond to.  It needs to be an unused address within your network.      //
// Security password, limited to 15 characters, use to prevent unauthorized access. Mandatory!                               //
int macArray[]= {0x00, 0x1E, 0x2A, 0x77, 0x24, 0x02 };
int ipArray[]= {};
int Port = 80;
char secpass[] = "";
// Port 80 is http
//************************************************ END OF USER EDITABLE AREA ************************************************//
//***************************************************************************************************************************//

//********************************* JSON *********************************//
// JSON main //
char JSON_main_pre[]="{\"arduino_io\":{";
char JSON_main_aft[]="}}";
// JSON Analog //
char JSON_analog_pre[]="\"an\":{";
char JSON_analog_aft[]="},";
char JSON_analog_p1[]="\"a";
char JSON_analog_p2[]="\":";
char JSON_analog_a1[]=",";
// JSON Digital //
char JSON_digital_pre[]="\"di\":{";
char JSON_digital_aft[]="}";
char JSON_digital_p1[]="\"d";
char JSON_digital_p2[]="\":";
char JSON_digital_a1[]=",";
//*************************************************************************//

byte mac[]= {macArray[0], macArray[1], macArray[2], macArray[3], macArray[4], macArray[5]};
byte ip[]= {ipArray[0], ipArray[1], ipArray[2], ipArray[3]};

EthernetServer server(Port);

//-- Commands and parameters size --
char pass[15];    // Limits length to 15 characters
char cmd[15];
char port[15];
char action[15];

void setup()
{
  SetupPorts();
  Ethernet.begin(mac, ip);
  server.begin();

  Serial.begin(57600);
//  BootMessage();
}

//-- Port Settings ---
void SetupPorts()
{
  for (int p=0; p<=9 ;p++)
  {
    pinMode(p,OUTPUT); // Define all digital pins ans output; 10,11,12,13 are used by Ethernet Shield.
  }
}

void BootMessage()
{
  Serial.println("****************************************");
  Serial.println("### Arduino JSON Data Server for iOS ###");
  Serial.println("####          by M. Heeres          ####");
  Serial.println("****************************************");
  Serial.print("MAC Adress: \t");
    Serial.print(macArray[0], HEX);Serial.print(":");
    Serial.print(macArray[1], HEX);Serial.print(":");
    Serial.print(macArray[2], HEX);Serial.print(":");
    Serial.print(macArray[3], HEX);Serial.print(":");
    Serial.print(macArray[4], HEX);Serial.print(":");
    Serial.println(macArray[5], HEX);
  Serial.print("IP Adress: \t");
    Serial.print(ipArray[0]);Serial.print(".");
    Serial.print(ipArray[1]);Serial.print(".");
    Serial.print(ipArray[2]);Serial.print(".");
    Serial.println(ipArray[3]);
  Serial.print("Port: \t");Serial.println(Port);
  Serial.println("****************************************");
}

#define bufferMax 128
int bufferSize;
char buffer[bufferMax];

void loop()
{
  EthernetClient client = server.available();
  if (client)
  {
    WaitForRequest(client);
    ParseReceivedRequest();
    PerformRequestedCommands();
    
    client.stop();
  }
}

void WaitForRequest(EthernetClient client) // Sets buffer[] and bufferSize
{
  bufferSize = 0;
  while (client.connected()) {
    if (client.available()) {
      char c = client.read();
      if (c == '\n')
	  {
		client.println("HTTP/1.1 200 OK");
		client.println("Content-Type: text/plain");
		client.println();
        break;
	  }
      else
        if (bufferSize < bufferMax)
          buffer[bufferSize++] = c;
        else
          break;
    }
  } 
}

void ParseReceivedRequest()
{
//  Serial.println("Request");
//  Serial.println(buffer);
  
  //Received buffer contains "GET ?pass= &cmd= &action= HTTP/1.1".  Break it up.
  char* en1;
  char* en2;
  char* en3;
  char* space2;
  char* qm;

  qm      = strstr(buffer, "?pass=") + 6; // Look for questionmark and pass
  en1     = strstr(qm, "&cmd=") + 5; // Look for first en
  en2     = strstr(en1, "&port=") + 6; // second en
  en3     = strstr(en2, "&action=") + 8; // third en
  space2  = strstr(en2, " ") + 1; // space after second en (in case there is no third en)
  if (en3 > space2) en3=en2;
  
  // strncpy does not automatically add terminating zero, but strncat does! So start with blank string and concatenate.
  pass[0]=0;
  cmd[0] = 0;
  port[0] = 0;
  action[0] = 0;
  strncat(pass, qm, en1-qm-5);
  strncat(cmd, en1, en2-en1-6);
  strncat(port, en2, en3-en2-8);
  strncat(action, en3, space2-en3-1);
  
  PrintString("pass","correct");
  PrintString("cmd",cmd);
  PrintString("port",port);
  PrintString("action",action);
}

void PerformRequestedCommands()
{
  if (strcmp(pass,secpass) == 0 )
  {
    if ( strcmp(cmd,"digitalWrite") == 0 ) RemoteDigitalWrite();
    else if ( strcmp(cmd,"analogRead") == 0 ) JSON_send("analogRead"); //RemoteAnalogRead();
    else if ( strcmp(cmd,"analogReadAll") == 0 ) JSON_send("analogReadAll"); // RemoteAnalogReadAll();
    else if ( strcmp(cmd,"digitalReadAll") == 0 ) JSON_send("digitalReadAll"); // RemoteDigitalReadAll();
    else if ( strcmp(cmd,"ReadAll") == 0 ) JSON_send("ReadAll");
    else if ( strcmp(cmd,"digitalRead") == 0 ) JSON_send("digitalRead"); // RemoteDigitalRead();
    else
    {
      server.print(JSON_main_pre); server.print("\"ERROR\":\"006\""); server.print(JSON_main_aft); // ERROR 006; unknown command
    }
  }
  else
  {
    PrintString("Pass is invallid, supplied password",pass);
    server.print(JSON_main_pre); server.print("\"ERROR\":\"007\""); server.print(JSON_main_aft); // ERROR 007; incorrect password
  }
}

void RemoteDigitalWrite()
{
  int digitalPin = atoi(port);
  if (strcmp(action,"s") == 0)
  {
    digitalWrite(digitalPin, !digitalRead(digitalPin));
      //-- Send debug message to serial port --
    Serial.println("RemoteDigitalWrite with s");
    PrintNumber("digitalPin", digitalPin);
    PrintNumber("digitalState", digitalRead(digitalPin));
  }
  else
  {
    int digitalState = action[0] - '0'; // action should be either 1 or 0
    digitalWrite(digitalPin, digitalState);
      //-- Send debug message to serial port --
    Serial.println("RemoteDigitalWrite without s");
    PrintNumber("digitalPin", digitalPin);
    PrintNumber("digitalState", digitalState);
  }
  JSON_send("digitalRead");
}

void JSON_send(char* cmd)
{
  server.print(JSON_main_pre);
  // ************************* //
    if (cmd=="digitalReadAll")
    {
      server.print(JSON_digital_pre);
      for (int i=0; i<=9; i++)
      {
        int digitalPin = i;
        int digitalSate = digitalRead(digitalPin);
        server.print(JSON_digital_p1); server.print(digitalPin); server.print(JSON_digital_p2); server.print(digitalSate); server.print(JSON_digital_a1);
      }
      server.print(JSON_digital_aft);
    }
    else if (cmd=="analogReadAll")
    {
      server.print(JSON_analog_pre);
      for (int i=0; i<=5; i++)
      {
        int analogPin = i;
        int analogValue = analogRead(analogPin);
        server.print(JSON_analog_p1); server.print(analogPin); server.print(JSON_analog_p2); server.print(analogValue); server.print(JSON_analog_a1);
      }
      server.println(JSON_analog_aft);
    }
    else if (cmd=="ReadAll")
    {
      server.print(JSON_analog_pre);
      for (int i=0; i<=4; i++)
      {
        int analogPin = i;
        int analogValue = analogRead(analogPin);
        server.print(JSON_analog_p1); server.print(analogPin); server.print(JSON_analog_p2); server.print(analogValue); server.print(JSON_analog_a1);
      }
      int analogPin = 5;
      int analogValue = analogRead(analogPin);
      server.print(JSON_analog_p1); server.print(analogPin); server.print(JSON_analog_p2); server.print(analogValue);
      server.print(JSON_analog_aft);
      server.print(JSON_digital_pre);
      for (int i=0; i<=8; i++)
      {
        int digitalPin = i;
//        char* digitalState = "\"n\"";
//        if (digitalRead(digitalPin)==HIGH) digitalState = "\"y\"";
        int digitalState = digitalRead(digitalPin);
        server.print(JSON_digital_p1); server.print(digitalPin); server.print(JSON_digital_p2); server.print(digitalState); server.print(JSON_digital_a1);
      }
      int digitalPin = 9;
//      char* digitalState = "\"n\"";
//      if (digitalRead(digitalPin)==HIGH) digitalState = "\"y\"";
      int digitalState = digitalRead(digitalPin);
      server.print(JSON_digital_p1); server.print(digitalPin); server.print(JSON_digital_p2); server.print(digitalState);
      server.print(JSON_digital_aft);
    }
    else if (cmd=="digitalRead")
    {
      server.print(JSON_digital_pre);
      int digitalPin = port[0] - '0'; // port should be one digit analog port
//      char* digitalState = "\"n\"";
//      if (digitalRead(digitalPin)==HIGH) digitalState = "\"y\"";
      int digitalState = digitalRead(digitalPin);
      server.print(JSON_digital_p1); server.print(digitalPin); server.print(JSON_digital_p2); server.print(digitalState);
      server.print(JSON_digital_aft);
    }
    else if (cmd=="analogRead")
    {
      server.print(JSON_analog_pre);
      int analogPin = port[0] - '0'; // port should be one digit analog port
      int analogValue = analogRead(analogPin);
      server.print(JSON_analog_p1); server.print(analogPin); server.print(JSON_analog_p2); server.print(analogValue);
      server.print(JSON_analog_aft);
    }
  // ************************ //
  server.print(JSON_main_aft);
}

void PrintString(char* label, char* str)
{
  Serial.print(label);
  Serial.print("=");
  Serial.println(str);
}

void PrintNumber(char* label, int number)
{
  Serial.print(label);
  Serial.print("=");
  Serial.println(number, DEC);
}