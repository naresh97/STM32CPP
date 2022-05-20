//
// Created by naresh on 18/05/22.
//

#ifndef HELLONUCLEO_LOGGER_H
#define HELLONUCLEO_LOGGER_H

extern "C" {
#include "stm32f4xx_hal.h"
};

#include <string>

class logger {
  UART_HandleTypeDef uartHandle;
  int counter = 0;

public:
  explicit logger(UART_HandleTypeDef uartHandle);
  void log(const std::string &message, const std::string &prefix = "");

  void info(const std::string &message) { log(message, "[INFO] "); }
  void error(const std::string &message) { log(message, "[ERROR] "); }

  void clear();
};

#endif // HELLONUCLEO_LOGGER_H
