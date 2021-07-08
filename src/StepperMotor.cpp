#include "StepperMotor.h"
#include "AccelStepper.h"
#include "Arduino.h"
#include "ArduinoJson.h"

StepperMotor::StepperMotor(uint8_t interface /* = AccelStepper::FULL4WIRE*/, uint8_t pin1 /* = MOTOR_PIN1*/,
                           uint8_t pin2 /* = MOTOR_PIN2*/, uint8_t pin3 /* = MOTOR_PIN3*/,
                           uint8_t pin4 /* = MOTOR_PIN4*/, bool enable /* = true*/, float maxSpeed /*= MAX_SPEED*/,
                           float acceleration /*= ACCELERATION*/, float speed /*= SPEED*/)
    : mStepper(interface, pin1, pin2, pin3, pin4, enable) {
  mStepper.setMaxSpeed(maxSpeed);          // set the max motor speed
  mStepper.setAcceleration(acceleration);  // set the acceleration
  mStepper.setSpeed(speed);                // set the current speed
  Close();
}

void StepperMotor::Consume(const char* topic, const CleanAIR::MessageJson& message) {
  const char* command = message["command"];

  if (strcmp("OPEN", command) == 0) {
    Open();
  } else if (strcmp("CLOSE", command) == 0) {
    Close();
  } else {
    Serial.println(F("Unknown command!"));
  }
}

void StepperMotor::Loop() { mStepper.run(); }

StepperMotor::STATE StepperMotor::GetState() const { return mState; }

void StepperMotor::Open() {
  const auto degrees = static_cast<float>(STATE::OPEN);
  mStepper.stop();
  mStepper.moveTo(DegreesToSteps(degrees));
  mState = STATE::OPEN;
}

void StepperMotor::Close() {
  const auto degrees = static_cast<float>(STATE::CLOSE);
  mStepper.stop();
  mStepper.moveTo(DegreesToSteps(degrees));
  mState = STATE::CLOSE;
}

float StepperMotor::DegreesToSteps(const float deg) { return (STEPS_PER_REVOLUTION / DEGREES_PER_REVOLUTION) * deg; }
