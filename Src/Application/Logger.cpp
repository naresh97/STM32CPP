//
// Created by naresh on 18/05/22.
//

#include "Logger.h"

#include <chrono>
#include <sstream>

void Logger::Log(const std::string &message, const std::string &prefix) {
  std::stringstream logMessage;
  logMessage << (++Counter) << " - " << prefix << message << "\r\n";
  HAL_UART_Transmit(&UartHandle, (uint8_t *)logMessage.str().c_str(),
                    logMessage.str().size(), HAL_MAX_DELAY);
}

Logger::Logger(UART_HandleTypeDef uartHandle) : UartHandle(uartHandle) {}

void Logger::Clear() {
  std::string logMessage("\x1B[2J\x1B[H");
  HAL_UART_Transmit(&UartHandle, (uint8_t *)logMessage.c_str(),
                    logMessage.size(), HAL_MAX_DELAY);
}
