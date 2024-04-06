#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;

int buzzer=7;


void setup()
{
    Serial.begin(9600);	// Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{

  char str[]="";
  char *pt;
  int b[10];

  float mq135=0;
 float mq136=0;
 float mq7=0;
 float mq4=0;
 
 int i=0;

 

    uint8_t buf[50];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {

      
      //int i;
      // Message with a good checksum received, dump it.
      
      
      pt = strtok ((char*)buf,",");
      int i=0;

      while (pt != NULL) {
        float a = atof(pt);
        if (i==0)
        {
            mq135=a;
        }
        if (i==1)
        {
          mq7=a;
            
        }
        if (i==2)
        {
            mq4=a;
        }
        if (i==3)
        {
            mq136=a;
        }
            
        
        
        //printf("%d",b[i]);
         
        i++;
        //printf("%d\n", a);
        pt = strtok (NULL, ",");
    
    
    }  

    if (mq7>35 || mq135 >2000 || mq4>50 )  
{  
  //digitalWrite(led_safe,LOW);
  digitalWrite(buzzer, HIGH);
  //digitalWrite(led_safe, HIGH);
  

  delay(400); // Wait for 1000 millisecond(s)
  digitalWrite(buzzer, LOW);
  delay(40);

}       
    }





    

    delay(3000);
}