#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver;


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
      Serial.print("Message: ");
      
      pt = strtok ((char*)buf,",");
      int i=0;

      while (pt != NULL) {
        float a = atof(pt);
        if (i==0)
        {
            mq135=a;
            Serial.println(a);
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
    
    
    Serial.print("carbon dioxide (CO2):");
    Serial.print(mq135);
    Serial.println(" ppm");
    Serial.print("carbon moxide (CO):");
    Serial.print(mq7);
    Serial.println(" ppm");
    Serial.print("methane (Ch4):");
    Serial.print(mq4);
    Serial.println(" ppm");
    Serial.print("hydrogen sulphide (H2S):");
    Serial.print(mq136);
    Serial.println(" ppm");
    Serial.println("\n");}       
    }



    

    delay(3000);
}