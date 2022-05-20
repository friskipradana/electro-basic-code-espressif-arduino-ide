// Board DOIT ESP32 DEVKIT V1
#include <WiFi.h>

const char* ssid = "your SSID";
const char* password = "your PASSWORD";

void setup() {
  Serial.begin(115200);
  // put your setup code here, to run once:
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Wifi Connected");
  delay(2000);


}

void loop() {
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Status Connection: ");
  Serial.println(WiFi.status());
  // if connection value is 3 it is "connect" but if value 6 "disconnected"
  Serial.print("Connect With Wifi: ");
  Serial.println(ssid);
  long rssi = WiFi.RSSI();
  Serial.print("RSSI: ");
  Serial.print(rssi);
  Serial.println("dBm");
  delay(1000);

}
