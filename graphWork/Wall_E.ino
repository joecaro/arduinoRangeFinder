// Do not remove the include below
#include "Wall_E.h"
#include "NewPing.h"
#include "rgb_lcd.h"
#include <Wire.h>
  
float time = .4;
int timeMilliseconds = time * 1000;
const int TouchPin=2;
int mode = 1; //mode 0 is distance



#define TRIGGER_PIN  8  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     7  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 300
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
rgb_lcd lcd;

void setup(){
    Serial.begin(115200); 
    pinMode(TouchPin, INPUT);
    lcd.begin(16, 2);
    lcd.setRGB(255, 255, 20);
    lcd.write("Hello, Handsome!");
    delay(2000);
    lcd.clear();    
}

void loop(){  
    if (mode == 0){
     unsigned int pingTime = sonar.ping();
     float distance1 = calculatePingDistance(pingTime);{
        if (distance1>=150)
          distance1=150;
     }
     lcd.print(distance1);
    }
    else{
      unsigned int pingTime = sonar.ping();
      float distance1 = calculatePingDistance(pingTime);    
      delay(timeMilliseconds);
	
      pingTime = sonar.ping();
      float distance2 = calculatePingDistance(pingTime);
      if (distance2-distance1 >= 40 ){
        distance2 = distance1 + 40;
      }
      if (distance2 >= 150){
        distance2=150;
      }
      
 	
      float velocity = calculateAvgVelocity(distance1, distance2, time);
      Serial.print(distance1);
      Serial.print(",");
      Serial.print(distance2);
      Serial.print(",");
      Serial.println(velocity);
      printVelocity(velocity, lcd);
    }
    
    delay(500);
    lcd.clear();
   
    int sensorValue = digitalRead(TouchPin);
    if(sensorValue==1){
        delay(1000);
        changeMode(); 
    }
   
}

void changeMode(){
    if (mode == 0) { 
        mode = 1;
    }
    else {
        mode = 0;
    }
}
