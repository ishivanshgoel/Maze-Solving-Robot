#include<Arduino.h>

int lth=5;  // threshold distance for left sensor
int fth=5;  // threshold distance for front sensor

float distance_left,distance_front;  // left and front distance
float duration_left,duration_front; // 

int turning_speed= 100;  // bot speed for taking left or right turn



///  Doubt::  while taking turn speed of both left and right tyres should be same?? 


// detecting walls
bool leftwall=false;
bool rightwall=false;
bool frontwall=false;

// pin declaration for ultrasonic sensors
int left_trigger=13;   // trigger pin for left sensor
int left_echo=12;     // echo pin for left sensor
int front_trigger=11;     // trigger pin for front sensor
int front_echo=10;   // echo pin for frontsensors
///////////////////////////////////////////////////////////////////////////////////////////

// pin declaration for motor driver of left motor

int enA=7;   // speed control pin for left motor
int in1=6;
int in2=5;  // direction change


// pin declaration for motor driver of right motor

int enB=3;
int in3=2;
int in4=1;


void readsensor(){
// calculation of distance from right wall
    duration_left=pulseIn(left_echo,HIGH);
    distance_left=((duration_left)/float(2))*(0.034);   // distance from left wall

// calculation of distance from front wall
    duration_front=pulseIn(front_echo,HIGH);
    distance_front=((duration_front)/float(2))*(0.034); // distance from front wall
}
void checkwall(){

/* if(no left wall)  ---->   setdirection(1)  turn left
        if ()                   setdirection(2)   turn right
                                setdirection(3)    move forward
*/


}

void setdirection(int dir){
    /*  if (dir==1)  turn_left();
            if (dir==2)  turn_right();
      */

}

void turn_left(){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);     // to move left tyre in anticlock wise direction
    digitalWrite(in3,HIGH);       // to move right tyre in clock wise direction 
    digitalWrite(in4,LOW);

     delay(50);

for(int speed_in1=0,speed_in3=0;speed_in1<=turning_speed,speed_in3<=turning_speed;speed_in1++,speed_in3++){

    analogWrite(enA,speed_in1);
    analogWrite(enB,speed_in3);
    delay(20);
}

void turn_right(){
    
}



void setup(){
    pinMode(left_trigger,OUTPUT);   // sets trigger pin for left sensor
    pinMode(front_trigger,OUTPUT);    // sets trigger pin for front sensor
    pinMode(left_echo,INPUT);     // sets echo pin for left sendor
    pinMode(front_echo,INPUT);      // sets echo pin for front sensor
        
        
    //set all the motor control pins to output
    pinMode(enA,OUTPUT);
    pinMode(in1,OUTPUT);
    pinMode(in2,OUTPUT);
    pinMode(enB,OUTPUT);
    pinMode(in3,OUTPUT);
    pinMode(in4,OUTPUT);


    Serial.begin(9600); // starts the serial communication
}

void loop(){
    readsensor();
    delay(200);
    checkwall();
    delay(200);
   

}