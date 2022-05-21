//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_APPLICATIONINTERFACE_H
#define HELLONUCLEO_APPLICATIONINTERFACE_H

#include "Logger.h"

#include <optional>

class ApplicationInterface {

protected:
  Logger ApplicationLogger;
  static void Delay(int milliseconds = 1000);

public:
  ApplicationInterface(UART_HandleTypeDef uartHandle);
  virtual void ApplicationLoop() = 0;
  virtual void ApplicationSetup() = 0;
  Logger GetLogger() { return ApplicationLogger; }
};

#endif // HELLONUCLEO_APPLICATIONINTERFACE_H
