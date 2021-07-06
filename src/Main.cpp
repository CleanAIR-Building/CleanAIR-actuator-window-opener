#include "Arduino.h"
#include "CleanAIRDevice.h"
#include "Definitions.h"
#include "StepperMotor.h"

StepperMotor stepperMotor;

void setup() {
  Serial.begin(BAUDRATE);
  CleanAIR::SetConsumer(&stepperMotor);
  CleanAIR::LoadConfiguration(CONFIG_FILE);
  CleanAIR::ConnectToWifi();
  CleanAIR::ConnectToMQTT();
  CleanAIR::ConnectToTopic();
  CleanAIR::InitializeHeartBeat(HEARTBEAT);
}

void loop() { CleanAIR::Loop(); }
