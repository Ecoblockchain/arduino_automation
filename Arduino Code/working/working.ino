#include <SPI.h>

#include <Client.h>
#include <Ethernet.h>
#include <Server.h>
#include <Udp.h>

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };  
byte ip[] = { 192, 168, 1, 166 };
byte gateway[] = { 196,168, 1, 1 };
byte subnet[] = {255, 255, 255, 0};


EthernetServer server(23);

void setup() 
{   
  Serial.begin(9600);
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
  delay(1000);
  Serial.println("Setup complete");
  
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  
}

void loop ()
{

EthernetClient client = server.available();

if (client) {
  Serial.println("jacked in");
  
    // an http request ends with a blank line
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.print(c);
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
      }
    }
    
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("jacked out");
  }
}


