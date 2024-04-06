
#define pinSensor A2 // mendefinisikan bahwa pin yang digunakan
// untuk membaca sensor adalah pin AO
void setup()
{
Serial.begin(9600);
}
long RL = 1000; // 1000 Ohm
long Ro =550; // 500 ohm (SILAHKAN DISESUAIKAN)
void loop()
{
int sensorvalue = analogRead (pinSensor); // membaca nilai ADC dari sensor
float VRL = sensorvalue*5.00/1024; // mengubah nilai ADC (0-1023) menjadi nilai voltase (0 - 5.00 volt)


float  Rs = (5.00 *RL / VRL) - RL;


float ppm = 100 * pow ((Rs/Ro), -1.53); // ppm 100* ((rs/ro) ^-1.53);
Serial.print("CO: ");
Serial.print (ppm);
Serial.println(" ppm");
delay(2000);
}