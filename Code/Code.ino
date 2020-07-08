#include <Servo.h>

Servo Ser1;

int trigPin = 9;
int echoPin = 10;
int servoPin = 11;

int duration;
int distance;
int val = 0;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
Ser1.attach(servoPin);
 
}
void loop() {
digitalWrite(trigPin, HIGH);
delay(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distance= (duration*0.034)/2;
  

if(distance <= 100 && distance >=90 )  
{
 Ser1.write(60);
}
 else if( distance < 90 && distance >= 80)
{
  Ser1.write(120);
 }
else if( distance < 80 && distance >= 70) 
{
  Ser1.write(180);
}
  
else  
{
 Ser1.write(0);
}
  
delay(100);
}
