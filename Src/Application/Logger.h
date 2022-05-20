//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_LOGGER_H
#define HELLONUCLEO_LOGGER_H

extern "C" {
#include "stm32f4xx_hal.h"
};

#include <string>

class Logger {
  UART_HandleTypeDef UartHandle;
  int Counter = 0;

public:
  explicit Logger(UART_HandleTypeDef uartHandle);
  void Log(const std::string &message, const std::string &prefix = "");

  void Info(const std::string &message) { Log(message, "[INFO] "); }
  void Error(const std::string &message) { Log(message, "[ERROR] "); }

  void Clear();
};

#endif // HELLONUCLEO_LOGGER_H
