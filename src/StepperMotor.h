#pragma once
#include "AccelStepper.h"
#include "Definitions.h"
#include "MessageConsumer.h"

class StepperMotor : public CleanAIR::MessageConsumer {
 public:
  enum class STATE { OPEN = OPENED_DEGREES, CLOSE = CLOSED_DEGREES };

  StepperMotor(uint8_t interface = AccelStepper::HALF4WIRE, uint8_t pin1 = MOTOR_PIN1, uint8_t pin2 = MOTOR_PIN2,
               uint8_t pin3 = MOTOR_PIN3, uint8_t pin4 = MOTOR_PIN4, bool enable = true, float maxSpeed = MAX_SPEED,
               float acceleration = ACCELERATION, float speed = SPEED);
  void Consume(const char* topic, const CleanAIR::MessageJson& message) override;
  void Loop() override;
  void Open();
  void Close();
  STATE GetState() const;

 private:
  AccelStepper mStepper;
  STATE mState;

  /*
   * Converts degrees to steps
   *
   * 28BYJ-48 motor has 5.625 degrees per step
   * 360 degrees / 5.625 = 64 steps per revolution
   *
   * Example with DegreesToSteps(45):
   * (64 / 5.625) * 45 = 512 steps
   */
  float DegreesToSteps(const float deg);
};
