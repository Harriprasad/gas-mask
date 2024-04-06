#include "MQ135.h"
const int ANALOGPIN=5;
MQ135 gasSensor = MQ135(ANALOGPIN);
void setup(){
  Serial.begin(9600);      // sets the serial port to 9600
}
void loop(){
  float ppm = gasSensor.getPPM();

  float abppm = map(ppm,0,1023,400,5000);  
  Serial.println(abppm);
  
  delay(1000);
}