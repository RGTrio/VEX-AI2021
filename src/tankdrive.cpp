#include "vex.h"
#include "robotMap.h"

using namespace vex;

motor Motor_Left_1(LEFT_MOTOR1);
motor Motor_Left_2(LEFT_MOTOR2);
motor Motor_Right_1(RIGHT_MOTOR1);
motor Motor_Right_2(RIGHT_MOTOR2);
double kP = 1.0;
double kP2 = 1.0;
double TURNING_BUFFER = 5.0;
double DISTANCE_BUFFER = 5.0;
void move_left_side(double speed) {
  Motor_Left_1.setVelocity(speed, velocityUnits::pct);
  Motor_Left_2.setVelocity(speed, velocityUnits::pct);
}


void move_right_side(double speed) {
  Motor_Right_1.setVelocity(speed, velocityUnits::pct);
  Motor_Right_2.setVelocity(speed, velocityUnits::pct);
}

void left_turn(double speed){
  Motor_Left_1.setVelocity(-speed, velocityUnits::pct);
  Motor_Left_2.setVelocity(-speed, velocityUnits::pct);

  Motor_Right_1.setVelocity(speed, velocityUnits::pct);
  Motor_Right_2.setVelocity(speed, velocityUnits::pct);
}

void right_turn(double speed){
  Motor_Left_1.setVelocity(speed, velocityUnits::pct);
  Motor_Left_2.setVelocity(speed, velocityUnits::pct);

  Motor_Right_1.setVelocity(-speed, velocityUnits::pct);
  Motor_Right_2.setVelocity(-speed, velocityUnits::pct);
}

double turn_speed(double heading, double target){
  double rightError = target - heading;
  double leftError = 360 - heading;
  if (rightError > leftError)
  {
    return min(rightError*kP, 100.0));
  }
  if (leftError > rightError)
  {
    return -min(leftError*kP, 100.0));
  }
}

bool move_speed(double dist, double target){
  double error = target - dist;
  return min((error * kP2), 100);
  
}

bool move(double dist, double targetDist, double heading, double targetHeading)
{

}
