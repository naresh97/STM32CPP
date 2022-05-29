//
// Created by naresh on 27/05/22.
//

#ifndef STM32CPP_UART_H
#define STM32CPP_UART_H

#include "../../application/callbacks/EventCallback.h"
#include "HAL.h"

#include <deque>
#include <functional>
#include <vector>

static const int uartReceiveBufferSize = 128;
static const int messageBufferSize = 128;
static const int messageEndByte = 0xff;

class UART {
  UART_HandleTypeDef UartHandle;
  uint8_t ReceiveBuffer[uartReceiveBufferSize]{};

  std::deque<uint8_t> MessageBuffer{};
  std::vector<uint8_t> ProcessedMessage{};

  int OldDmaWritePosition{};

  EventCallback<std::vector<uint8_t>> MessageEventCallback;

private:
  void ProcessReceiveBuffer();
  void MessageComplete();

public:
  explicit UART(UART_HandleTypeDef &uartHandle);
  void InitializeReceive();
  void InterruptCallback(UART_HandleTypeDef *handle);
  void ProcessingLoop();
  EventCallback<std::vector<uint8_t>> GetMessageEventCallback();
};

#endif // STM32CPP_UART_H
