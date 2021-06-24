/*------ Arduino Line Follower Code----- */
#include <NewPing.h>

/*-------definning Inputs------*/
#define LS 3      // left sensor
#define RS 2      // right sensor

/*-------definning Outputs------*/
#define LM1 4       // left motor
#define LM2 5       // left motor
#define RM1 7       // right motor
#define RM2 6       // right motor

#define TRIGGER_PIN  9 // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     10  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

#define rightFarSensor     A0
#define rightNearSensor    A1
#define leftFarSensor      A2
#define leftNearSensor     A3

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

int leftNearReading;
int leftFarReading;
int rightNearReading;
int rightFarReading;

#define led 13

int left = 0;
int right = 0;

int fadeAmount = 5;
int startspeed = 50;
int maxspeed  = 100;
int motorspeed = startspeed;
unsigned long distance = 0;
int objectDetected = 0;

void setup()
{
  Serial.begin(9600);
  
  pinMode(LS, INPUT);
  pinMode(RS, INPUT);
  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

}

void loop1()
{
    //forward();
    reverse();

    distance = sonar.ping_cm();

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" Speed: ");
    Serial.println(motorspeed);
}


void loop()
{
  left = digitalRead(LS);
  right = digitalRead(RS);

  distance = sonar.ping_cm();

   Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" Speed: ");
    Serial.println(motorspeed);
    
  if ((distance > 0) && (distance < 25)) {
     motorspeed = startspeed;
     reverse();

      delay(1000);

      objectDetected = 1;
      
  } else if (objectDetected) {

      if (random(0,10) < 5) {
          turn_left();
          delay(1500);
      } else {
          turn_right();
          delay(1500);
      }
      
      objectDetected = 0;
      
  } else {

      forward();
   
      if (motorspeed < maxspeed)
        motorspeed += fadeAmount;
   
   }

    delay(1000);
    
  return;
  
  if (left && right)     // Move Forward
  {
    forward();

  } else if (!left && right)     // Turn right
  {
    turn_right();

  } else if (left && !right)     // turn left
  {
    turn_left();
  } else {
    reverse();
  }

  readSensors();
//  delay(50);

}

void readSensors()
{
  
  leftNearReading    = analogRead(leftNearSensor);
  leftFarReading     = analogRead(leftFarSensor);
  rightNearReading   = analogRead(rightNearSensor);
  rightFarReading    = analogRead(rightFarSensor);  

  Serial.print(leftNearReading);
  Serial.print(" ");
  
  Serial.print(leftFarReading);
  Serial.print(" ");
  
  Serial.print(rightNearReading);
  Serial.print(" ");
  
  Serial.println(rightFarReading);
}

void stop()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
//    digitalWrite(led, LOW);
}

void reverse()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, HIGH);
//    digitalWrite(led, LOW);
}

void forward()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
//    digitalWrite(led, LOW);
}
void turn_right()
{
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
//    digitalWrite(led, LOW);
}

void turn_left()
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
//    digitalWrite(led, LOW);
}
