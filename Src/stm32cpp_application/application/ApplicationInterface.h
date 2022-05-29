//
// Created by naresh on 18/05/22.
//

#ifndef STM32CPP_APPLICATIONINTERFACE_H
#define STM32CPP_APPLICATIONINTERFACE_H

#include "../logging/Logger.h"

#include <optional>

class ApplicationInterface {

protected:
  Logger ApplicationLogger;
  static void Delay(int milliseconds = 1000);

public:
  explicit ApplicationInterface(UART_HandleTypeDef uartHandle);
  virtual void ApplicationLoop() = 0;
  Logger GetLogger() { return ApplicationLogger; }
};

#endif // STM32CP_APPLICATIONINTERFACE_H
