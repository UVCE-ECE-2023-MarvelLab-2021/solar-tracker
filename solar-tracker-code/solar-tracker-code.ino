#include "pinsUsed.h"
#include <Servo.h>

Servo myServo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int ldr1_in = 0;
int ldr2_in = 0;
int rad_diff = 0;

void setup() {
  Serial.begin(9600);
  myServo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object
}

void loop() {
  ldr1_in = analogRead(A0); // first ldr output
  ldr2_in = analogRead(A1); // second ldr output

  rad_diff = ldr1_in-ldr2_in; // find the difference between ldr ouputs

  // change servo motor angle if the difference crosses certain threshold
  if(rad_diff>100){
    if(pos>=0){
      pos -=1;
    }
  }
  else if(rad_diff<-100){
    if(pos<=180){
      pos += 1;
    }
  }  
  myServo.write(pos);
  
delay(15);
}
