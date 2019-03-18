/*
LDR*ARDUINO
LBPS(light based parking system)
*/

int ldr[9]={0,1,2,3,4,5,6,7};
int lightState[10];

void setup()
{
  pinMode(ldr[1],INPUT);
  pinMode(ldr[2],INPUT);
  
  Serial.begin(96000);
  Serial.println("arduino is ready ");

}

void loop()
{
  int i;
  for(i=0;i<2;i++)
  {
    lightState[i] = analogRead(ldr[i]);
  }
  
  //lightState = map(lightState,0,969,0,255);
  seekreq();//check for request
  
  delay(1000);
}

void seekreq()
{
  while(1)
  {
    if(Serial.available()>0)
       {
         String a;
         a=Serial.readString();
         if(a=="request" || a=="Request"|| a=="REQUEST")
         {
           Serial.println("ldr reading");
           int i;
  			for(i=0;i<2;i++)
		  {
              	Serial.println(lightState[i]);
            }
         }
         else
         {
           Serial.println("invalid input");
           delay(100);
           break;
         }
       }
       else
       break;
  }
}
