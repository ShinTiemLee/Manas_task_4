#include<Wire.h>
#define Led1 9
#define Led2 3
#define Address 1
boolean flag=LOW;

void setup()
{ 
  Serial.begin(9600);
  Wire.begin(Address);
  Wire.onReceive(receiveEvent);
  pinMode(Led1, OUTPUT);
  pinMode(Led2,OUTPUT);
  digitalWrite(Led1,flag);
  digitalWrite(Led2,flag);
}

void loop()
{ 
  delay(100);
}
 
void Led_fun(float Temp_cel)
{
  if(Temp_cel<=50)
  {
    digitalWrite(Led1,!flag);
    digitalWrite(Led2,flag);
  }
  else
  {
    digitalWrite(Led1,flag);
    digitalWrite(Led2,!flag); 
  }
  Serial.println(Temp_cel);
  delay(10);
}

void receiveEvent(int howMany)
{
  int V_range=Wire.read();
  float Vout=((V_range)*(5000.0/256.0)); //voltage output given by sensor in millivolts
  float Temp_cel=((Vout-500.0)/10.0);  //voltage to temp in celcius conversion
  Led_fun(Temp_cel);
  delay(100);
}