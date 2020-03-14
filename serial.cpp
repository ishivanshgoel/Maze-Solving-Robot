#include<Arduino.h>
void setup() {
Serial.begin(9600);
 pinMode(13, OUTPUT); // put your setup code here, to run once:
// initialise the pins of motor
 }
 
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
 if(Serial.available()>0)
   {     
      int data= Serial.read(); // reading the data received from the bluetooth module

      if (data==1) {
        digitalWrite(13, HIGH);
      }
      else if (data==2)  // right
      else if (data==3)  //straight
      else if (data==4)  //pulling
      else if (data==5)  //gripping
      else if (data==6)  //back
      else if (data==7) //throwing
      // Serial.println(data);
   }
}
