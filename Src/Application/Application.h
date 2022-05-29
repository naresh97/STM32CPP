//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_APPLICATION_H
#define HELLONUCLEO_APPLICATION_H

#include "ApplicationInterface.h"
#include "communications/UART.h"
#include "i2c/devices/HD44780.h"
#include "i2c/devices/MPU6050.h"
#include "Servo.h"

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

#endif // HELLONUCLEO_APPLICATION_H
