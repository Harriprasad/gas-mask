void setup()
{
Serial.begin(9600); //Set serial baud rate to 9600 bps
}

void loop()
{
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

delay(1000);
}