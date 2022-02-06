#include<Wire.h>

#define Led1 9     // green led
#define Led2 3     // red led
#define Address 1  //slave id
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
 
void Led_fun(int Temp_cel)    // switches led state based on temp readings
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
  int Temp_cel=Wire.read();
  Led_fun(Temp_cel);
  delay(100);
}