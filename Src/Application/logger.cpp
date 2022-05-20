//
// Created by naresh on 18/05/22.
//

#include "logger.h"

#include <chrono>
#include <sstream>

void logger::log(const std::string &message, const std::string &prefix) {
  std::stringstream logMessage;
  logMessage << (++counter) << " - " << prefix << message << "\r\n";
  HAL_UART_Transmit(&uartHandle, (uint8_t *)logMessage.str().c_str(),
                    logMessage.str().size(), HAL_MAX_DELAY);
}

logger::logger(UART_HandleTypeDef uartHandle) : uartHandle(uartHandle) {}

void logger::clear() {
  std::string logMessage("\x1B[2J\x1B[H");
  HAL_UART_Transmit(&uartHandle, (uint8_t *)logMessage.c_str(),
                    logMessage.size(), HAL_MAX_DELAY);
}
