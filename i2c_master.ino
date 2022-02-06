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
  int V_analog=analogRead(TempPin); // voltage output ranges from 0 to 1023
  int V_range=map(V_analog,0,1023,0,255); //voltage output mapped to range from 0 to 255 
  Wire.beginTransmission(Address);
  Wire.write(V_range);
  Wire.endTransmission();
  delay(1000);
}