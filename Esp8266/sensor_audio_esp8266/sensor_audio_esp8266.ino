int Led = 5; //Definisi Led pada pin 13 (default)
int OutputAO = 13; //Definisi pin 2 sebagai keluaran sensor
int val = 0; //val sebagai buffer data

void setup() {
  //Inisialisasi I/O
  pinMode(Led, OUTPUT);
  pinMode(OutputAO, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Membaca sinyal keluaran dari sensor berupa logika 1 atau 0
  val = digitalRead(OutputAO);
  Serial.println(val);
  delay(100);
  if (val == HIGH) {
    //Jika berlogika 1 maka LED akan menyala
    digitalWrite(Led, HIGH);
    delay(1000);
  }
  else
  {
    //jika berlogika 0 maka LED akan mati
    digitalWrite(Led, LOW);
  }

}
