

void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
   char str[]="400,300,200,100";
  char *pt;
  int b[10];
 int mq135=0;
 int mq136=0;
 int mq137=0;
 int mq138=0;
  pt = strtok (str,",");
  int i=0;
    while (pt != NULL) {
        int a = atoi(pt);
        if (i==0)
        {
            mq135=a;
        }
        if (i==1)
        {
            mq136=a;
        }
        if (i==2)
        {
            mq137=a;
        }
        if (i==3)
        {
            mq138=a;
        }
            
        
        
        //printf("%d",b[i]);
         
        i++;
        //printf("%d\n", a);
        pt = strtok (NULL, ",");
    }
    
    
    Serial.println(mq135);
    Serial.println(mq136);
    Serial.println(mq137);
    Serial.println(mq138);
    delay(3000);
    
    


 

}