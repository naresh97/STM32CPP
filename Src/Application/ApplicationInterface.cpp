//
// Created by naresh on 18/05/22.
//

#include "ApplicationInterface.h"

ApplicationInterface::ApplicationInterface(UART_HandleTypeDef uartHandle,
                                           I2C_HandleTypeDef i2CHandle)
    : ApplicationLogger(uartHandle), UartHandle(uartHandle),
      I2CHandle(i2CHandle) {}

void ApplicationInterface::Delay(int milliseconds) { HAL_Delay(milliseconds); }