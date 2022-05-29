//
// Created by naresh on 27/05/22.
//

#include "UART.h"
UART::UART(UART_HandleTypeDef &uartHandle) : UartHandle(uartHandle) {}
void UART::InitializeReceive() {
  HAL_UART_MspInit(&UartHandle);
  HAL_UART_Receive_DMA(&UartHandle, ReceiveBuffer, sizeof(ReceiveBuffer));
  __HAL_UART_ENABLE_IT(&UartHandle, UART_IT_IDLE);
}
void UART::InterruptCallback(UART_HandleTypeDef *handle) {
  ProcessReceiveBuffer();
}

void UART::ProcessReceiveBuffer() {
  int dmaBufferWritePosition =
      uartReceiveBufferSize -
      static_cast<int>(UartHandle.hdmarx->Instance->NDTR);
  if (dmaBufferWritePosition != OldDmaWritePosition) {
    if (dmaBufferWritePosition > OldDmaWritePosition) {
      MessageBuffer.insert(MessageBuffer.end(),
                           &ReceiveBuffer[OldDmaWritePosition],
                           &ReceiveBuffer[dmaBufferWritePosition]);
    } else {
      MessageBuffer.insert(MessageBuffer.end(),
                           &ReceiveBuffer[OldDmaWritePosition],
                           &ReceiveBuffer[uartReceiveBufferSize]);
      if (dmaBufferWritePosition > 0)
        MessageBuffer.insert(MessageBuffer.end(), &ReceiveBuffer[0],
                             &ReceiveBuffer[dmaBufferWritePosition]);
    }
    OldDmaWritePosition = dmaBufferWritePosition;
  }
}
void UART::ProcessingLoop() {

  if (!MessageBuffer.empty()) {
    uint8_t processingByte = MessageBuffer[0];
    if (processingByte == messageEndByte) {
      MessageComplete();
      MessageBuffer.clear();
    } else {
      ProcessedMessage.push_back(processingByte);
      MessageBuffer.pop_front();
    }
  }

  if (ProcessedMessage.size() > messageBufferSize)
    ProcessedMessage.clear();
}
void UART::MessageComplete() {
  MessageEventCallback.PushMessage(ProcessedMessage);
  ProcessedMessage.clear();
}
EventCallback<std::vector<uint8_t>> UART::GetMessageEventCallback() {
  return MessageEventCallback;
}
