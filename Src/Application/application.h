//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_APPLICATION_H
#define HELLONUCLEO_APPLICATION_H

#include "applicationInterface.h"
#include "i2c/devices/mpu6050.h"

class application : public applicationInterface {
  mpu6050 gyro;

public:
  explicit application(UART_HandleTypeDef uartHandle,
                       I2C_HandleTypeDef i2CHandle);

  void applicationLoop() override;
  void applicationSetup() override;
};

#endif // HELLONUCLEO_APPLICATION_H
