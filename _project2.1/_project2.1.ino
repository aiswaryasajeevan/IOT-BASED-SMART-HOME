//IOT BASED SMART HOME
//AUTHOR:AISWARYA SAJEEVAN


#include <SoftwareSerial.h> //Librarey for serial connection with ESP

SoftwareSerial ESP(2,3); //ESP connected to 12 and 13 pin of arduino

 String wifiname = "Redmi";
  String pass = "12345678"; 
String sendData =  "GET /update?api_key=OME6401TDIPRMQQP&field1=" ;
String output = ""; //Initialize a null string variable 
#define Relay1 10


void setup() 
{
  pinMode(Relay1,OUTPUT);
 
  Serial.begin (9600);
  delay(100);
  ESP.begin(115200);
  ESP.println("AT+CIOBAUD=9600");
  delay(100);
  ESP.begin(9600);
  
  
    ESP_talk("AT",1000);
    ESP_talk("AT+RST",1000);
    ESP_talk("AT+CWMODE=1",5000);
    ESP_talk("AT+CWJAP==\""+ wifiname +"\",\""+ pass +"\"",10000);
    Serial.println("Wifi Connected"); 
    delay(1000);  
     
}

void loop() {

  String cmd = "AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80";   // Establishing TCP connection

 ESP_talk(cmd,1000);
    delay(100); 
    ESP_talk("AT+CIPSEND=76",1000);  
    delay(100);
  output = "";
    ESP_talk(sendData,1000);
    delay(100);

 int incoming_value= int(output.charAt(output.length()-11))-48;
    Serial.print("incoming_value is : ");   
    Serial.println(incoming_value);
    

    if (incoming_value == '1') //light should be on
    {
     
      digitalWrite(Relay1,HIGH);
    }
    if (incoming_value == '0') //light should be off
    {
      
      digitalWrite(Relay1,LOW);
    }
    
}

void ESP_talk(String AT_cmd, const int timeout)
{
  
  Serial.print("Sent: ");
  Serial.print(AT_cmd);
  ESP.println(AT_cmd); //print to ESP through software serial 
  Serial.println("");//Move to next line 
  
  
  long int time = millis();

  output=""; //clear the string
  
  while ( (time + timeout) > millis())
  {
    while (ESP.available())
    {
      char i = ESP.read(); // read one char 
      output += i; //Combine char to string 
    }
  }
  
  Serial.println("Received: ");
  Serial.print(output);
  
}
