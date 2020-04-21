# IOT-BASED-SMART-HOME
IOT based smart home using thingspeak and IFTTT.Setup a Google assistant applet from IFTTT to trigger a web request which will update a field in ThingSpeak cloud. Then read the data from ThingSpeak cloud using arduino to control the appliances in your home from anywhere in the world. Ex:- From your mobile phone, if you say- “ok google” Turn on the light” from anywhere, it should turn on the light in your home. 

Components required
1)	Arduino Uno with cable 
2)	Esp8266(Wi-Fi module) 
3)	5v Relay two channel 
4)	230v bulb along with holder 
5)	Wires 
6)	Jumper cables

To communicate with the Google Assitant on our mobile phone I have used IFTTT services,which configure the assistant to listen for a particular command
The commands given are
1.turn the light off
2.turn the light on
THE esp8266 can read information from internet only through API calls ,so i used Thingspeak platform .Basically voice command is given to the Google assistant changes the value of this field using API calls and sends this value to Arduino using serial communication.The arduino then performs the required action tike toggling a relay based on the value received.
