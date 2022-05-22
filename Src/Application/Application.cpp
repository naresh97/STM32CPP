//
// Created by naresh on 18/05/22.
//

#include "Application.h"

#include "communications/protobuf/mpu6050.pb.h"
#include "pb_encode.h"

#include <algorithm>
#include <numeric>
#include <sstream>
void Application::ApplicationLoop() {
  auto accel = Gyro.ReadAcceleration();
  auto [x, y, z] = accel;

  auto rescaler = Math::Rescaler<double>({-1, 1}, {180, 0});

  auto angle = rescaler(y);

  angleBuffer.pop_front();
  angleBuffer.push_back(angle);
  auto avg =
      std::reduce(angleBuffer.begin(), angleBuffer.end()) / angleBuffer.size();

  Servo1.GoToAngle(static_cast<int>(angle));

  AccelData testMessage{.x = x, .y = y, .z = z};
  uint8_t buffer[128];
  auto stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
  pb_encode(&stream, AccelData_fields, &testMessage);

  ApplicationLogger.SendBytes(buffer, stream.bytes_written);
}

void Application::ApplicationSetup() {}

Application::Application(UART_HandleTypeDef uartHandle,
                         I2C_HandleTypeDef i2CHandle,
                         TIM_HandleTypeDef timerHandle)
    : ApplicationInterface(uartHandle), Gyro(i2CHandle, (0x68 << 1)),
      Servo1(timerHandle, {60, 253}, {0, 180}) {
  //  ApplicationLogger.Info("Application setup initiated.");

  try {
    Gyro.Initialize();
  } catch (std::runtime_error &e) {
    ApplicationLogger.Error(e.what());
  }
}
