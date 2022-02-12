#include<SPI.h>
#define buttonPin 2
byte masterSend;

void setup()
{
 Serial.begin(115200);
 SPI.begin();
 SPI.setClockDivider(SPI_CLOCK_DIV8);
 pinMode(buttonPin,INPUT);
 digitalWrite(SS,HIGH); 
}

void loop()
{
 int button_val=digitalRead(buttonPin);
 digitalWrite(SS,LOW); 
 masterSend=button_val; 
 SPI.transfer(masterSend); 
 Serial.println(masterSend); 
 delay(1000); 
}