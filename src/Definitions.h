#pragma once

#define BAUDRATE 115200
#define CONFIG_FILE "/Config.json"
#define HEARTBEAT 5000

#define MOTOR_PIN1 D1  // IN1 pin on the ULN2003A driver to pin D1 on NodeMCU board
#define MOTOR_PIN2 D3  // IN2 pin on the ULN2003A driver to pin D3 on NodeMCU board
#define MOTOR_PIN3 D2  // IN3 pin on the ULN2003A driver to pin D2 on NodeMCU board
#define MOTOR_PIN4 D4  // IN4 pin on the ULN2003A driver to pin D4 on NodeMCU board

#define MAX_SPEED 1000.0
#define ACCELERATION 100.0
#define SPEED 200.0

#define STEPS_PER_REVOLUTION 64
#define DEGREES_PER_REVOLUTION 5.625

#define CLOSED_DEGREES 0
#define OPENED_DEGREES 180
