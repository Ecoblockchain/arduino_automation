This is the code for a automation project I made last winter.  I hooked up an Arduino with an ethernet shield to a relay.  This code allows the user to turn the relay on or off anywhere on the internet.  

I had the Arduino plugged into a space heater in my room.  This way I could keep the temperature of my apartment low.  When I was comming back to my apartment I would turn the space heater on 20 minutes before I got there and my room would be warm and toasty.


STEPS TO MAKE THIS WORK
-Edit the Arduino code.  You should change the "ip address", "port", and "gateway" variables to fit your network.

-Edit "changeit.php" to reflect the values you changed in the arduino code

-Throw the php scripts onto a webserver.

-Now you can turn something on and off remotely.


HOW THIS WORKS
This project is pretty simple.  The arduino waits until a server connects to it.  Once the server connects the arduino will listen for any incoming packets.  When a packet is sent, the arduino will set a variable (the variable is "c" in the code) equal to text in the packet.

Once the server is finished sending the packet, the arduino will execute a chunk of code based off the information in the packet. 


Works with latest version of arduino compiler (1.0.3)





WARNING!!!!!!
Don't run this without settng up some security meausures beforehand.  A simple login script and SSL is what I used.  You don't want people turning your stuff on or off without you knowing.