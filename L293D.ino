#include "L293D.h"


#define ENABLEPIN_A  5  /* Must be a PWM pin, one of D3,D5,D6,D9,D10,D11 */
#define CONTROLPIN_A 4
#define ENABLEPIN_B  6  /* Must be a PWM pin */
#define CONTROLPIN_B 7

L293D motorA = L293D(ENABLEPIN_A, CONTROLPIN_A);
L293D motorB = L293D(ENABLEPIN_B, CONTROLPIN_B);

void setup() {
  motorA.Stop();
  motorB.Stop();
}

void loop() {
  motorA.SetSpeed(50);  /* Speed is between 0 and 255. Minimum speed is 50. */
  motorB.SetSpeed(50);  /* Speed is between 0 and 255 */

  motorA.Forward();
  motorB.Forward();
  delay(5000);

  /* Turn one side for 5 seconds */
  motorA.SetSpeed(0);
  motorB.SetSpeed(150);
  
  motorA.Forward();
  motorB.Forward();
  delay(5000); 

  /* Turn one side for 5 seconds */
  motorA.SetSpeed(150);
  motorB.SetSpeed(0);

  motorA.Forward();
  motorB.Forward();
  delay(5000); 
  
//  motorA.Reverse();
//  motorB.Reverse();
//  delay(5000);

}
