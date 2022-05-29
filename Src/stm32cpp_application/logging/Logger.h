//
// Created by naresh on 18/05/22.
//

#ifndef STM32CPP_LOGGER_H
#define STM32CPP_LOGGER_H

#include "HAL.h"

#include <string>

class Logger {
  UART_HandleTypeDef UartHandle;
  int Counter = 0;

public:
  explicit Logger(UART_HandleTypeDef uartHandle);
  void Log(const std::string &message, const std::string &prefix = "");

  void Info(const std::string &message) { Log(message, "[INFO] "); }
  void Error(const std::string &message) { Log(message, "[ERROR] "); }

  void SendBytes(uint8_t *bytes, size_t length);

  void Clear();
};

#endif // STM32CP_LOGGER_H
