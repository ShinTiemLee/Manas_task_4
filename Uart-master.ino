#define potPin 1

void setup()
{
  pinMode(potPin,INPUT);
  Serial.begin(9600);
}

void loop()
{
  int val=analogRead(potPin);
  val=map(val,0,1023,0,255);
  /*char cval[3];
  for (int i=2;i>=0;i--)
  {
    cval[i]=(val%10)+'0';
    val=val/10;
  }
  Serial.write(cval);
  Serial.println(cval);
  delay(1000);*/
  if (val>=(255/2))
    Serial.write("yes.");
  else
    Serial.write("no.");
  delay(5000);
}