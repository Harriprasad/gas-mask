#define mq7_pin A2 // mendefinisikan bahwa pin yang digunakan
#include "MQ135.h"
#include <RH_ASK.h>
#include <SPI.h>
const int mq135_pin=5;

int buzzer = 6;
int led_safe=5;
int led_danger=4;

RH_ASK driver;



MQ135 gasSensor_mq135 = MQ135(A5);// untuk membaca sensor adalah pin AO
void setup()
{
Serial.begin(9600);
pinMode(buzzer, OUTPUT);
pinMode(led_safe,OUTPUT );
pinMode(led_danger, OUTPUT);
//digitalWrite(led_safe,LOW);

if (!driver.init())
         Serial.println("init failed");
}


long mq7_RL = 1000; // 1000 Ohm
long mq7_Ro =550; // 500 ohm (SILAHKAN DISESUAIKAN)
void loop()
{
  

  // mq7
int sensorvalue = analogRead (mq7_pin); // membaca nilai ADC dari sensor
float mq7_VRL = sensorvalue*5.00/1024; // mengubah nilai ADC (0-1023) menjadi nilai voltase (0 - 5.00 volt)


float  mq7_Rs = (5.00 *mq7_RL / mq7_VRL) - mq7_RL;


float mq7_ppm = 100 * pow ((mq7_Rs/mq7_Ro), -1.53); // ppm 100* ((rs/ro) ^-1.53);
Serial.print("CO: ");
Serial.print (mq7_ppm);
Serial.println(" ppm");
//delay(500);


//mq135
  float mq135_ppmsignal = gasSensor_mq135.getPPM();

  //float mq135_ppm = map(mq135_ppmsignal,0,1023,400,5000);  
  float mq135_ppm = map(mq135_ppmsignal,0,1023,400,5000);  

  
  

  Serial.print("CO2: ");
Serial.print (mq135_ppm);
Serial.println(" ppm");
  //delay(500);


  //mq136
  float mq136_ppm=0.0;

  //mq4
int mq4_pin=A4;
int mq4_val;
float mq4_ppm;
float mq4_ro;
float mq4_ratio;
float mq4_rs;
mq4_ro=10; //kOhm
int i;
float mq4_RL_VALUE=200;
mq4_val=analogRead(mq4_pin);//Read Gas value from analog 0
//Serial.println 1(val,DEC);//Print the value to serial port
//ppm=1021*pow((1),-2.7887);
//calculate rs/ro

mq4_rs=((mq4_RL_VALUE * (1021 - mq4_val) / mq4_val));
mq4_ratio=mq4_rs/mq4_ro;

//Serial.println 1(RL_VALUE);
//Serial.println 1("\n");

Serial.print("methane:");

mq4_ppm=1021*pow((mq4_ratio),-2.7887);
 
Serial.print(mq4_ppm);
Serial.println(" ppm");
Serial.println("\n");

//delay(3000);










//transmitter
String a="";
 String b="";
 String c="";
String d="";


 String e="";

 a=String(mq135_ppm,2);
 b=String(mq7_ppm,2);
 c=String(mq4_ppm,2);
 d=String(mq136_ppm,2);


   e=a+","+b+","+c+","+d;

  char f[e.length()+1];
  e.toCharArray(f,e.length()+1);

    driver.send((uint8_t *)f, e.length()+1);
    driver.waitPacketSent();
    Serial.println(f);


     //buzzer to arduino pin 9


   // Set buzzer - pin 9 as an output


  digitalWrite(led_safe, HIGH);
  digitalWrite(led_danger, LOW);
 // delay(3000);

  
if (mq7_ppm>35 || mq135_ppm >1500 || mq4_ppm>50 )  
{  
  digitalWrite(led_safe,LOW);
  digitalWrite(led_danger, HIGH);
  //delay(500);
  
  delay(20);
  digitalWrite(buzzer, HIGH);
  //digitalWrite(led_safe, HIGH);
  

  delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(buzzer, LOW);
  //digitalWrite(led_danger,LOW);
  delay(40);

}  
//else{
 // digitalWrite(led_danger,LOW);
//}




    

  


delay(3000);
}










