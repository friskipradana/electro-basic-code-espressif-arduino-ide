/*
  Wiring :
  Sensor ========> Arduino
  + / VCC    =>     5V
  - / Gnd    =>     Gnd
  S / Signal =>     A0

*/

#define pinSensor A0  // mendefinisikan pin 2 sebagai pin yang berhubungan dengan sensor
int sensorValue = 0; // variable untuk menampung nilai baca dari sensor dalam bentuk integer
float tinggiAir = 0; // variabel untuk menampung ketinggian air
float sensorVoltage = 0; // untuk menampung nilai ketinggian air


int nilaiMax = 1023; // nilai "sensorValue" saat sensor terendam penuh kedalam air, bisa dirubah sesuai sensor dan jenis air yang anda pakai
float panjangSensor = 4.0 ; // 4.0 cm, bisa dirubah, menyesuikan dengan panjang sensor yang kalian gunakan

//        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
//        |||||||||| Variabel di Atas Bisa Dirubah ||||||||||



void setup() {
  Serial.begin(9600); // mengatur boudrate komunikasi serial antara arduino dengan PC
  Serial.println("Pembacaan Ketinggian Air");
  delay(500);
}

void loop() {
  sensorValue = analogRead(pinSensor); // membaca tengan dari sensor dalam bentuk integer
  tinggiAir = sensorValue * panjangSensor / nilaiMax;
  sensorVoltage = sensorValue * 5.0 / 1023;

  // print data ke serial monitor
  Serial.print("Sensor Value = ");
  Serial.println(sensorValue);
  Serial.print("Sensor Voltage = ");
  Serial.println(sensorVoltage);
  Serial.print("Tinggi Air = ");
  Serial.println(tinggiAir);
  Serial.println();
  delay(1000);
}
