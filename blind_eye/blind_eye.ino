#include <SoftwareSerial.h>  

int bluetoothTx =3;  //rx of bluetooth to pin 3
int bluetoothRx =2; 
SoftwareSerial bluetooth(bluetoothRx, bluetoothTx);

  const int TrigPin = 9; //Trigger connected to PIN 7   
  const int EchoPin = 8; //Echo connected yo PIN 8   
  const int bluetooth_power=10;
  
  int buz=5; //Buzzer to PIN 4 

  long pd=0;
  long duration,sum,cm;
 // Not actualy used but needed to compile

  void setup() {   
  Serial.begin(9600); 
  pinMode(bluetooth_power,OUTPUT);
  digitalWrite(bluetooth_power,HIGH);
  bluetooth.begin(9600);

  
  pinMode(buz, OUTPUT);   
  pinMode(TrigPin, OUTPUT);  
  pinMode(EchoPin, INPUT);
  
  delay(2000);
  bluetooth.println("hello!!");   
  delay(1000);
  bluetooth.println("Welcome to blind eye");
  delay(1500);
  bluetooth.println("I am your friendly assistant");
  delay(2000);
  bluetooth.println("Note. the speed of vibrator is proportional to the distance around  you");
  delay(3000);
  bluetooth.println("Happy travelling");
  delay(1500);
  }   
  
  void loop()   
  {     
  sum=0;
     for (int i=0;i<15;i++)
    {
    digitalWrite(TrigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(TrigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TrigPin, LOW);
    duration = pulseIn(EchoPin, HIGH);
    sum=sum+duration;
    }
  
  duration = sum/15;   
  cm = microsecondsToCentimeters(duration); 

if(cm>0 && cm<2000)
{
   if((pd-cm)>200 && (pd-cm)<2000)
   {
     bluetooth.println("fast approaching object");
   //  delay(1000);
   }
  else if(cm<=30 && cm>0)   
  {     
  analogWrite(buz,490);
  bluetooth.println("You are too near to an object");
 /*   if((pd-cm)>800 && (pd-cm)<2000)
  {
    bluetooth.println("fast approaching object detected");
  }
 // delay(100);*/
  }
  else if(cm<=100 && cm>30)   
  {     
  analogWrite(buz,150);
  bluetooth.println("obstacle ahead");
  //delay(1000);
  }
  else if(100<cm && cm<=130)
  {
    analogWrite(buz,76);
    bluetooth.println("object at 1 meter distance");
    //delay(1000);
  }
  else
  {
    analogWrite(buz,10);
    bluetooth.println("All Ok");
    //delay(1000);
  }
}
 
  Serial.print(cm);    
  Serial.print("cm");   
  Serial.println(); 
  pd=cm;  
  delay(2000);
  digitalWrite(buz,LOW);  
  }   

  long microsecondsToCentimeters(long microseconds)   
  {   
  return microseconds / 29.4 / 2;   
  }   
  
