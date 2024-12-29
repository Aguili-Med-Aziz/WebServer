#include "config.h"

float motorSpeed = 0;
float targetSpeed = 100;  // Target speed (could be set by user input)

void initMotorControl() {
  pinMode(MOTOR_PIN, OUTPUT);
}

void setMotorSpeed(float speed) {
  motorSpeed = speed;
  analogWrite(MOTOR_PIN, motorSpeed);
}

void controlMotorWithPID(float currentSpeed) {
  float error = targetSpeed - currentSpeed;
  float output = PID_KP * error + PID_KI * (error + previousError) + PID_KD * (error - previousError);
  
  setMotorSpeed(output);
  previousError = error;
}
