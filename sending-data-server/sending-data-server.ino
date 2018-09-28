

// For the server part, see the corresponing node.js project in github:
// nodemcutest
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>


const char* ssid     = "Newinti-Student";
const char* password = "iicp@penng";

//-- Declare your pins here --     

 
void setup() 
{
    Serial.begin(9600);
    
    //-- Set your pinMode here --   
}
 
void loop() 
{      
  if(WiFi.status() != WL_CONNECTED ){
    Serial.println("Wifi not connected...");
    WiFi.begin(ssid, password); 
  } 
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  } 

  Serial.print("Connected to: "); Serial.println(WiFi.SSID());
  Serial.print("Your IP: "); Serial.println(WiFi.localIP());

  int value = getSensorDistance();
  
  HTTPClient http;

  String datatosend = "/?sensor=" + String(value);
  Serial.print("Sensor value: "); Serial.println(datatosend);

  //-- Change the IP address below to your server's IP --
  http.begin("192.168.1.101", 3000, datatosend);
  int httpCode = http.GET();
  
  if(httpCode > 0){
    Serial.printf("GET code: %d\n", httpCode);
    if(httpCode == HTTP_CODE_OK){
      String response = http.getString();
      Serial.println(response);
    }
  } else {
    Serial.printf("GET failed: error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
  delay(10000);
}

int getSensorDistance()
{
  //-- Put your code for reading sensor data here --
}
