//Board DOIT ESP32 DEVKIT V1

#include "BluetoothSerial.h" 
#define LED_BUILTIN 2 

BluetoothSerial ESP_BT; //Object for Bluetooth

int incoming;


void setup() {
  Serial.begin(9600); //Start Serial monitor in 9600
  ESP_BT.begin("ESP32_LED_Control"); //Name of your Bluetooth Signal
  Serial.println("Bluetooth Device is Ready to Pair");

  pinMode (LED_BUILTIN, OUTPUT);//Specify that LED pin is output
}

void loop() {
  
  if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming); 
    

    if (incoming == 49)
        {
        digitalWrite(LED_BUILTIN, HIGH);
        ESP_BT.println("LED turned ON");
        }
        
    if (incoming == 48)
        {
        digitalWrite(LED_BUILTIN, LOW);
        ESP_BT.println("LED turned OFF");
        }     

        if (incoming == 70)
        {
        ESP_BT.println("huruf F :");
        
          ESP_BT.print("Decimal Receive : ");
        ESP_BT.println(incoming);
        } 
  }
  delay(20);
}
