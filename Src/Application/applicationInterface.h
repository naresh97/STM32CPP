//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_APPLICATIONINTERFACE_H
#define HELLONUCLEO_APPLICATIONINTERFACE_H

#include "logger.h"

#include <optional>

class applicationInterface {

protected:
  logger applicationLogger;
  static void delay(int milliseconds = 1000);
  UART_HandleTypeDef uartHandle;
  I2C_HandleTypeDef i2CHandle;

public:
  applicationInterface(UART_HandleTypeDef uartHandle,
                       I2C_HandleTypeDef i2CHandle);
  virtual void applicationLoop() = 0;
  virtual void applicationSetup() = 0;
  logger getLogger() { return applicationLogger; }
};

#endif // HELLONUCLEO_APPLICATIONINTERFACE_H
