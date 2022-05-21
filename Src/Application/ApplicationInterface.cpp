//
// Created by naresh on 18/05/22.
//

#include "ApplicationInterface.h"

ApplicationInterface::ApplicationInterface(UART_HandleTypeDef uartHandle)
    : ApplicationLogger(uartHandle) {}

void ApplicationInterface::Delay(int milliseconds) { HAL_Delay(milliseconds); }