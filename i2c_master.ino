#include<Wire.h>
#define TempPin 0
#define Address 1

void setup()
{ Serial.begin(9600);
  Wire.begin();
  pinMode(TempPin, INPUT);
}

void loop()
{
  int V_range=analogRead(TempPin); // voltage output mapped from 0 to 1024
  float Vout=((V_range)*(5000.0/1024.0)); //voltage output given by sensor in millivolts
  int Temp_cel=((Vout-500.0)/10.0);  //voltage to temp in celcius conversion
  Wire.beginTransmission(Address);
  Wire.write(Temp_cel);
  Wire.endTransmission();
  delay(1000);
}