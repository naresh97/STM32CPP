//
// Created by naresh on 18/05/22.
//

#include "application.h"

#include <sstream>
void application::applicationLoop() {
  applicationLogger.clear();

  auto accel = gyro.readAcceleration();
  auto gyrodata = gyro.readGyroscope();

  std::stringstream ss;
  ss << "X: " << accel.x << ",  Y: " << accel.y << ", Z: " << accel.z;
  ss << "\r\n";
  ss << "X: " << gyrodata.x << ",  Y: " << gyrodata.y << ", Z: " << gyrodata.z;
  applicationLogger.log(ss.str());

  delay(100);
}

void application::applicationSetup() {}

application::application(UART_HandleTypeDef uartHandle,
                         I2C_HandleTypeDef i2CHandle)
    : applicationInterface(uartHandle, i2CHandle),
      gyro(i2CHandle, (0x68 << 1)) {
  applicationLogger.info("Application setup initiated.");

  try {
    gyro.initialize();
  } catch (std::runtime_error &e) {
    applicationLogger.error(e.what());
  }
}
