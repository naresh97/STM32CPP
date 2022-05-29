//
// Created by naresh on 18/05/22.
//

#ifndef STM32CPP_APPLICATION_H
#define STM32CPP_APPLICATION_H

#include "../communications/uart/UART.h"
#include "../devices/HD44780.h"
#include "../devices/MPU6050.h"
#include "../devices/Servo.h"
#include "ApplicationInterface.h"

#include <list>

class Application : public ApplicationInterface {
  MPU6050 Gyro;
  Servo Servo1;
  HD44780 Lcd1;
  EventCallback<std::vector<uint8_t>> UartMessageCallback;

public:
  UART UartComm;
  explicit Application(UART_HandleTypeDef &uartHandle,
                       I2C_HandleTypeDef &i2CHandle,
                       TIM_HandleTypeDef &timerHandle);

  void ApplicationLoop() override;
};

#endif // STM32CP_APPLICATION_H
