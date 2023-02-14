/*
 * IoT ESP8266 Based Mood Lamp (RGB LED) Controller Program
 * https://circuits4you.com
 */
 
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

//SSID and Password of your WiFi router
const char* ssid = "led";
const char* password = "45454545";

ESP8266WebServer server(80);

//LED Connections
const int RedLED=15;     //D8  GPIO15
const int GreenLED=12;  //D6  GPIO12
const int BlueLED=13;    //D7  GPIO13

String setcolor="#ff00ff"; //Set color for HTML

const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<title>Mood Lamp (RGB LED Color) Controller</title>
</head>
<body style="background:@@color@@;">

<center>
    Mood Lamp (RGB LED Color) Controller<br><br><br>
  <form method="post" action="/form">
      Color:
      <input type="color" name="color" value="@@color@@">
      <button type="submit" name="state" value="stop">SET</button>
  </form>
<br><br><br>
<a href="https://circuits4you.com">Circuits4you.com</a><br>
</center>
</body>
</html>
)=====";

//=======================================================================
//                    handles main page
//=======================================================================
void handleRoot() {
  String p = MAIN_page;  
  p.replace("@@color@@",setcolor);    //Set page background color and selected color
  server.send(200, "text/html", p);    
}

//=======================================================================
//                    Handle Set Color
//=======================================================================
void handleForm() {
  String color = server.arg("color");
  //form?color=%23ff0000
  setcolor = color; //Store actual color set for updating in HTML
  Serial.println(color);

  //See what we have recived
  //We get #RRGGBB in hex string

  // Get rid of '#' and convert it to integer, Long as we have three 8-bit i.e. 24-bit values
  long number = (int) strtol( &color[1], NULL, 16);

  //Split them up into r, g, b values
  long r = number >> 16;
  long g = (number >> 8) & 0xFF;
  long b = number & 0xFF;
  
  //PWM Correction
  r = r * 4; 
  g = g * 4;
  b = b * 4;
//for ULN2003 or Common Cathode RGB LED not needed
/*
  r = 1024 - r;
  g = 1024 - g;
  b = 1024 - b;
*/
  //ESP supports analogWrite All IOs are PWM
  analogWrite(RedLED,r);
  analogWrite(GreenLED,g);
  analogWrite(BlueLED,b);

  server.sendHeader("Location", "/");
  server.send(302, "text/plain", "Updated-- Press Back Button");
 
  delay(500);  
}
//=======================================================================
//                    SETUP
//=======================================================================
void setup(){
  Serial.begin(115200);   //Start serial connection  
  
  pinMode(RedLED,OUTPUT);
  pinMode(GreenLED,OUTPUT);
  pinMode(BlueLED,OUTPUT);
  
    WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");
  
  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  //If connection successful show IP address in serial monitor
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());  //IP address assigned to your ESP
  
  server.on("/", handleRoot);  //Associate handler function to path
  server.on("/form",handleForm);
    
  server.begin();                           //Start server
  Serial.println("HTTP server started");
}
//=======================================================================
//                    LOOP
//=======================================================================
void loop(){
  server.handleClient();
}
