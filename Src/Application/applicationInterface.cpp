//
// Created by naresh on 18/05/22.
//

#include "applicationInterface.h"

applicationInterface::applicationInterface(UART_HandleTypeDef uartHandle,
                                           I2C_HandleTypeDef i2CHandle)
    : applicationLogger(uartHandle), uartHandle(uartHandle),
      i2CHandle(i2CHandle) {}

void applicationInterface::delay(int milliseconds) { HAL_Delay(milliseconds); }