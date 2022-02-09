#define ledPin 5
String val;

void setup()
{
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,0);
  Serial.begin(9600);
}

void loop()
{  
  /* if(Serial.available()>=4)
  {
   val=Serial.readStringUntil('z');
   Serial.println(val);
   delay(1000);
  } */
  if(Serial.available()>0)
  {val=Serial.readStringUntil('.');
   Serial.println(val);}
  if (val=="yes")
  {
   for(int i =10;i<=255;i++)
   {analogWrite(ledPin,i);
    delay(5);}
   for(int i =255;i>=0;i--)
   {analogWrite(ledPin,i);
    delay(5);}
  }
  delay(20);
}

