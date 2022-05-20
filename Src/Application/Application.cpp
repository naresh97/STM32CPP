//
// Created by naresh on 18/05/22.
//

#include "Application.h"

#include <sstream>
void Application::ApplicationLoop() {
  ApplicationLogger.Clear();

  auto accel = Gyro.ReadAcceleration();
  auto gyrodata = Gyro.ReadGyroscope();

  std::stringstream ss;
  ss << "X: " << accel.X << ",  Y: " << accel.Y << ", Z: " << accel.Z;
  ss << "\r\n";
  ss << "X: " << gyrodata.X << ",  Y: " << gyrodata.Y << ", Z: " << gyrodata.Z;
  ApplicationLogger.Log(ss.str());

  Delay(100);
}

void Application::ApplicationSetup() {}

Application::Application(UART_HandleTypeDef uartHandle,
                         I2C_HandleTypeDef i2CHandle)
    : ApplicationInterface(uartHandle, i2CHandle),
      Gyro(i2CHandle, (0x68 << 1)) {
  ApplicationLogger.Info("Application setup initiated.");

  try {
    Gyro.Initialize();
  } catch (std::runtime_error &e) {
    ApplicationLogger.Error(e.what());
  }
}
