int sensorpin = 0;                 // analog pin used to connect the sharp sensor
int val = 0;                 // variable to store the values from sensor(initially zero)
void setup()
{
  Serial.begin(9600);
  pinMode(11, OUTPUT);// starts the serial monitor
}
 
void loop()
{
 
  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  Serial.println(val);
  if(val<600)
  {
    analogWrite(11, 50);delay(200);analogWrite(11, 0);delay(200);
      
  }
  else
  {
    analogWrite(11, LOW);
  }
  delay(100);                    // wait for this much time before printing next value
}
