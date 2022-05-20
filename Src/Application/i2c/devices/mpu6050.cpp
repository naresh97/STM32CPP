//
// Created by naresh on 19/05/22.
//

#include "mpu6050.h"
mpu6050::mpu6050(const I2C_HandleTypeDef &i2CHandle, uint8_t address)
    : i2cDevice(i2CHandle, address) {}

void mpu6050::initialize() {
  i2cDevice::initialize(WHOAMI_REGISTER, WHOAMI_RESPONSE);
  i2cDevice::write(POWERON_REGISTER, {0});
}
mpu6050::axes mpu6050::readAcceleration() {

  auto accelData = i2cDevice::read(ACCEL_READ_REGISTER, ACCEL_READ_LENGTH);
  mpu6050::axes m{};
  m.x = (int16_t)(accelData[0] << 8 | accelData[1]) / ACCEL_CONVERSION_FACTOR;
  m.y = (int16_t)(accelData[2] << 8 | accelData[3]) / ACCEL_CONVERSION_FACTOR;
  m.z = (int16_t)(accelData[4] << 8 | accelData[5]) / ACCEL_CONVERSION_FACTOR;

  return m;
}
mpu6050::axes mpu6050::readGyroscope() {
  auto gyroData = i2cDevice::read(GYRO_READ_REGISTER, GYRO_READ_LENGTH);
  mpu6050::axes m{};
  m.x = (int16_t)(gyroData[0] << 8 | gyroData[1]) / GYRO_CONVERSION_FACTOR;
  m.y = (int16_t)(gyroData[2] << 8 | gyroData[3]) / GYRO_CONVERSION_FACTOR;
  m.z = (int16_t)(gyroData[4] << 8 | gyroData[5]) / GYRO_CONVERSION_FACTOR;

  return m;
}
