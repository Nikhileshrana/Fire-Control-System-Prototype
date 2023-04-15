void setup() 
{
  pinMode(16,OUTPUT);
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(4,OUTPUT);
}


void loop() 
{
  float sensor_value;
  sensor_value = analogRead(A0);
  sensor_value = ((sensor_value - 273)/10)+8;
  Serial.print("Temperature Reading = ");
  Serial.print(sensor_value);
  Serial.print("\n");
  delay(400);



  if(sensor_value > 37)
  {
    digitalWrite(5,LOW);   //Green Light
    digitalWrite(16,HIGH); //Red Light
    for(int i=500;i<1000;i++)
    {
      tone(4,i);
    }
    digitalWrite(4,LOW);
    delay(100);
  }
  else
  {
    digitalWrite(16,LOW); //Red Light
    digitalWrite(5,HIGH); //Green Light
    delay(100);
  }

}
