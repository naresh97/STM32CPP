//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_APPLICATION_H
#define HELLONUCLEO_APPLICATION_H

#include "ApplicationInterface.h"
#include "i2c/devices/MPU6050.h"

class Application : public ApplicationInterface {
  MPU6050 Gyro;

public:
  explicit Application(UART_HandleTypeDef uartHandle,
                       I2C_HandleTypeDef i2CHandle);

  void ApplicationLoop() override;
  void ApplicationSetup() override;
};

#endif // HELLONUCLEO_APPLICATION_H
