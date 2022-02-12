#include<SPI.h>
#define ledPin 9
volatile byte slaveReceive;
boolean receive;

void setup()
{
 Serial.begin(115200);
 pinMode(ledPin,OUTPUT);
 pinMode(MISO,INPUT); 
 SPCR|=_BV(SPE); 
 SPI.attachInterrupt(); 
 receive=false; 
}

ISR(SPI_STC_vect)
{
 slaveReceive=SPDR;
 receive=true;
}
void loop()
{
 if(receive)
 {
  if(slaveReceive==1)
    digitalWrite(ledPin,HIGH);
  else
    digitalWrite(ledPin,LOW);
 }
  Serial.println(slaveReceive);
  delay(1000);
}