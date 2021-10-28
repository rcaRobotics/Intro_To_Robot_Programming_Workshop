#include <Pololu3piPlus32U4.h>

using namespace Pololu3piPlus32U4;

//declare objects - the hardware pieces we are going to use
Buzzer buzzer;
Motors motors;
ButtonA buttonA;
BumpSensors bumpSensors;

//declare variables for a maximum speed and a slower speed
int maxSpeed = 80;
int slowSpeed = 40;

void setup()
{
  Serial.begin(9600);
  bumpSensors.calibrate();

   while(!buttonA.isPressed())
   {
    //stays there until i press the button
   }
}


void loop()
{
  bumpSensors.read();

  if(bumpSensors.rightIsPressed())
  {
    Serial.println("right is Pressed");
    
  }

  if (bumpSensors.leftIsPressed())
  {
    Serial.println("left is Pressed");
  }

  else
  {
    motors.setSpeeds(slowSpeed,slowSpeed);
  }

  
 
 /*     ledRed(1); //red LED is on
      ledGreen(0); //green LED is off
      motors.setSpeeds(maxSpeed, maxSpeed); //the robot moves forward for 1 second with max speed
      delay(1000);
      motors.setSpeeds(maxSpeed, -100); //turn right
      delay(200);
      motors.setSpeeds(maxSpeed, maxSpeed); //move forward
      delay(1000);
      motors.setSpeeds(-maxSpeed, maxSpeed); //turn left
      delay(200);
      motors.setSpeeds(-slowSpeed, -slowSpeed); //move backwards with slow speed for 1 second
      delay(1000); 
      */  
}
