#include "Wire.h"    // imports the wire library for talking over I2C 


float tempC;  // Variable for holding temp in C
float distance;  // Variable for holding temp in F
float velocity; //Variable for holding pressure reading

void setup(){
Serial.begin(115200); //turn on serial monitor
 //initialize mySensor
}

void loop() {
tempC = 30.0; //  Be sure to declare your variables
distance = tempC*1.8 + 32.; // Convert degrees C to F
velocity=12.0;


Serial.print(distance);
Serial.print(" , ");
Serial.println(velocity);
delay(250); //Pause between readings.
}
