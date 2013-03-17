#include <SPI.h>
#include <Ethernet.h>


byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte ip[] = { 192, 168, 1, 166 };
byte gateway[] = { 196,168, 1, 1 };
byte subnet[] = {255, 255, 255, 0};

byte autoServer[] = {192,168,1,000};
EthernetServer server(23);

void setup() 
{   
  Serial.begin(9600);
  EthernetClient client;
  
  //Arm Pin 7.  That's what turns the relay on/off
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  
  //Setup ethernet
  Ethernet.begin(mac, ip, gateway, subnet);
  delay(1000);
  
  //Arduino connects to the Automation Server  
  if (client.connect(autoServer, 80)) {
    Serial.println("connected");
    //make a variable with string for the Host part of the http request.
    //String post = "mac=" + String(192, byte);//Might Be the source of bugs
    client.println("POST /arduino_automation/setup.php HTTP/1.1");
    client.println("Host:" /*+ autoServer)*/);
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Content-Length: 19");
    client.println("mac=12345");
    client.println();
  } else {
    Serial.println("connection failed");
  }
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
    }
  
  
  //Engage server mode.  From here the Arduino will be taking instrutions from the server
  client.stop();
  server.begin();
  delay(1000);

  
  
  

}

void loop () {
  EthernetClient client = server.available();

if (client) {
  Serial.println("jacked in");
  
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
        
        //Execute code based on the package the server sent
        if (c == '1')
        {
         Serial.println("ONN");
         digitalWrite(7, HIGH);
        }
        if (c == '0')
        {
         Serial.println("OFF");
         digitalWrite(7, LOW);
        }
        if (c == '9')//Check the state of Pin 7 and send that to the connected clent
        {
         Serial.println("CHECKSTATUS");
         if (digitalRead(7)== LOW)
           {server.write("OFF");}
         if (digitalRead(7)== HIGH)
           {server.write("ON");}
        }
      }
    }
    
    // give the web browser time to receive the data
    delay(1);
    
    // close the connection:
    client.stop();
    Serial.println("jacked out");
  }
}




