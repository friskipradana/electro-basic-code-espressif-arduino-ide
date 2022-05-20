int analogPin = A0; // pin arduino yang terhubung dengan pin S modul sensor tegangan
 
float Vmodul = 0.0; 
float hasil = 0.0;
float R1 = 30000.0; //30k
float R2 = 7500.0; //7500 ohm resistor, 
int value = 0;
 
void setup()
{
   pinMode(analogPin, INPUT);
   Serial.begin(9600);
   Serial.println("mengukur tegangan DC");
   Serial.println("https://www.cronyos.com");
}
 
void loop()
{
   value = analogRead(analogPin);
   Vmodul = (value * 3.2) / 1024.0;
   hasil = Vmodul / (R2/(R1+R2));
 
  Serial.print("Tegangan keluaran modul = ");
  Serial.print(Vmodul,2);
  Serial.print("volt");
  Serial.print(", Hasil pengukuran = ");
  Serial.print(hasil,2);
  Serial.println("volt");
  delay(500);
}
