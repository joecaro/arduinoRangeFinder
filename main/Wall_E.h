#ifndef _Wall_E_H_
#define _Wall_E_H_
#include "Arduino.h"
//add your includes for the project Wall_E here
#include "NewPing.h"
#include "rgb_lcd.h"
#include "inttypes.h"

//end of add your includes here
#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
} // extern "C"
#endif
//add your function definitions for the project Wall_E here
/*
 * takes pingTime, calculates the distance in cm by dividing pingTime by 57
 * (57uS for sound to travel 2cm)
 * returns distance as distanceincm
 */

float calculatePingDistance(float pingTime){
  float distanceInCm = pingTime/US_ROUNDTRIP_CM;
  return distanceInCm;
}

/*
 * takes distance1 and distance2 and subtracts them to find the change in cm
 * divides the change in distance by the change in time to find velocity
 * returns velocity
 */
float calculateAvgVelocity(float distance1, float distance2, float time){
  float deltaDistance = distance2-distance1;
  float velocity = deltaDistance/time;
  return velocity;
}

void printVelocity(float velocity, rgb_lcd lcd){
        lcd.print(velocity);
  lcd.write("cm/s");
}



//Do not add code below this line
#endif /* _Wall_E_H_ */
