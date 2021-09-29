#include <Pololu3piPlus32U4.h>

using namespace Pololu3piPlus32U4;

//declare objects - the hardware pieces we are going to use
Buzzer buzzer;
Motors motors;
ButtonA buttonA;

//declare variables for a maximum speed and a slower speed
int maxSpeed = 80;
int slowSpeed = 40;



void setup()
{

  /*
   * How to use the buzzer
   * 'a' - 'g': specify the notes that will be played
   * 1-2000: specify the duration of the note
   * For example c16: C note played as a 1/16th the length of a whole note          
   *
   */
   delay(100); //a small delay before the buzzer play the notes
   buzzer.play("a8b8c8");

}

void loop()
{

  /*  
   *  Use a button to move the robot.
   *  If buttonA is pressed then the robot move following a sequence of movements
   *  and the red LED is on.
   *  The robot runs this sequence of movements 2 times using a for loop.
   *  When no button is pressed or the sequence of movements ends the robot stop moving and 
   *  the green LED is on.
   *  
   *  We will use:
   *
   *  If Statement
   *  -------------------------
   *  if (condition)
   *  {
   *   //statement(s)
   *  }
   *  
   *  The if statement checks the condition inside the parentheses and executes the block of code under the if
   *  statement if the condition is TRUE.
   *  If the condition is FALSE then the block of code inside the else statement will be executed.
   *  
   *  For Loop
   *  ---------------------------
   *  for (initialization; condition; increment)
   *  {
   *    //statement(s)
   *  }
   *  
   *  The for statement is used to repeat a block of code enclosed in curly brackets.
   *  An increment counter('i' in our code below) is used to increment and terminate the loop.
   *  
   *  initialization: is executed only once
   *  condition: the condition is evaluated, if it is TRUE then the block of code inside the for loop is executed
   *             if it is FALSE then the for loop is terminated
   *  increment: executed each time through the loop when the condition is TRUE, in the code below we increment 'i' 
   *             by 1 each time
   *  
   */
  
  if (buttonA.isPressed()) //when button is pressed
  {
    for (int i=0; i<2; i++)
    {
      ledRed(1); //red LED is on
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
    }
    
  }
  else //when button is not Pressed
  {
    ledRed(0); //red LED is off
    ledGreen(1); //green LED is on
    motors.setSpeeds(0,0); //robot stop moving
  } 
}
