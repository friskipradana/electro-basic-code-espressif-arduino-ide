int red_light_pin = 15;
int green_light_pin = 4;
int blue_light_pin = 5;
const int ledChannel = 0;

const int freq = 5000;
const int resolution = 8;
void setup() {
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(red_light_pin, ledChannel);
  ledcAttachPin(green_light_pin, ledChannel);
  ledcAttachPin(blue_light_pin, ledChannel);

}


void loop() {


  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

  // decrease the LED brightness
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    // changing the LED brightness with PWM
    ledcWrite(ledChannel, dutyCycle);
    delay(15);
  }

}
