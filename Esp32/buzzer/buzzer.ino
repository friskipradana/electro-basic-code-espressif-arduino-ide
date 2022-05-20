const int BUZZER_PIN = 21; // GIOP21 pin connected to Buzzer's pin

void setup() {
  Serial.begin(9600);                // initialize serial
  pinMode(BUZZER_PIN, OUTPUT);       // set ESP32 pin to output mode
}

void loop() {
  analogWrite(BUZZER_PIN, 20); // turn on
  delay(1000);
  analogWrite(BUZZER_PIN, 0);  // turn off
  delay(1000);
}
