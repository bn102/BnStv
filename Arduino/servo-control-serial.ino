/*
  
  Controlling servos using an Arduino... From a Raspberry Pi
  
*/

#include <Servo.h>

Servo xservo;  // create servo object to control a servo
Servo yservo;  // create servo object to control a servo

int xpin = 0;  // analog pin used to connect the potentiometer
int xval;    // variable to read the value from the analog pin
int ypin = 1;  // analog pin used to connect the potentiometer
int yval;    // variable to read the value from the analog pin

void setup() {
  
  Serial.begin(9600);
  
  xservo.attach(9);  // attaches the servo on pin 9 to the servo object
  yservo.attach(10);  // attaches the servo on pin 9 to the servo object
  
}

void loop() {

  if(Serial.available()){
    String recString="";
    String strArr[2];

    while(Serial.available()) {
      delay(2);
      char sr = Serial.read();
      recString+= sr;
    }

    int stringStart = 0;
    int arrayIndex = 0;

    for (int i=0; i < rxString.length(); i++){
      if(recString.charAt(i) == ',') {
        strArr[arrayIndex] = "";
        strArr[arrayIndex] = recString.substring(stringStart, i);
        stringStart = (i+1);
        arrayIndex++;
      }
    }

  String xposStr = strArr[0];
  String yposStr = strArr[1];
  int xpos = xposStr.toInt();
  int ypos = yposStr.toInt();

  xservo.write(xpos);                  // sets the servo position according to the scaled value
  yservo.write(ypos);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there

  }

}

// Created by Bn102
