//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_APPLICATION_H
#define HELLONUCLEO_APPLICATION_H

#include "ApplicationInterface.h"
#include "i2c/devices/MPU6050.h"
#include "Servo.h"

#include <list>

class Application : public ApplicationInterface {
  MPU6050 Gyro;
  Servo Servo1;
  std::list<long> angleBuffer = std::list<long>(20);

public:
  explicit Application(UART_HandleTypeDef uartHandle,
                       I2C_HandleTypeDef i2CHandle,
                       TIM_HandleTypeDef timerHandle);

  void ApplicationLoop() override;
  void ApplicationSetup() override;
};

#endif // HELLONUCLEO_APPLICATION_H
