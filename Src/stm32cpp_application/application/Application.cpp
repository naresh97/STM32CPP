//
// Created by naresh on 18/05/22.
//

#include "Application.h"

#include "../communications/protobuf/hd44780_lcd/Hd44780PbApi.h"
#include "../devices/HD44780.h"

#include <cmath>
#include <sstream>
#include <utility>
void Application::ApplicationLoop() {
  auto accel = Gyro.ReadAcceleration();
  auto [x, y, z] = accel;

  auto rescaler = Math::Rescaler<double>({-1, 1}, {0, 180});

  auto angle = rescaler(y);

  //  lcd1.ClearDisplay();
  std::stringstream ss;
  ss << "angle: " << static_cast<int>(std::lround(angle));
  Lcd1.MoveCursor(0, 0);
  Lcd1.WriteText(ss.str());
  HAL_Delay(200);

  Servo1.GoToAngle(static_cast<int>(angle));
  UartComm.ProcessingLoop();
}

Application::Application(UART_HandleTypeDef &uartHandle,
                         I2C_HandleTypeDef &i2CHandle,
                         TIM_HandleTypeDef &timerHandle)
    : ApplicationInterface(uartHandle), Gyro(i2CHandle, (0x68 << 1)),
      Servo1(timerHandle, {60, 253}, {0, 180}), Lcd1(i2CHandle, 0x3f << 1),
      UartComm(uartHandle) {

  Gyro.Initialize();

  UartComm.InitializeReceive();
  UartMessageCallback = UartComm.GetMessageEventCallback();
  UartMessageCallback.Subscribe([&](std::vector<uint8_t> message) {
    Hd44780PbApi::ParseMessage(std::move(message), Lcd1);
  });
}
