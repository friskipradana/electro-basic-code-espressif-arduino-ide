#include <Keypad.h>
const byte rows = 4;
const byte cols = 4;
char keys[rows][cols] = {
  {'1', '2', '3', 'C'},
  {'4', '5', '6', '@'},
  {'7', '8', '9', '='},
  {'A', 'N', 'R', '-'}

};
byte rowPins[rows] = {27, 14, 12, 13};
byte colPins[cols] = {26, 25, 33, 32};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, rows, cols);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  char keypressed = keypad.getKey();

  if (keypressed != NO_KEY)

  {

    Serial.print(keypressed);
    delay(100);

  }
}
