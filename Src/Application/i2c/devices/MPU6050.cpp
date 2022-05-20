//
// Created by naresh on 19/05/22.
//

#include "MPU6050.h"
MPU6050::MPU6050(const I2C_HandleTypeDef &i2CHandle, uint8_t address)
    : I2CDevice(i2CHandle, address) {}

void MPU6050::Initialize() {
  I2CDevice::Initialize(WhoamiRegister, WhoamiResponse);
  I2CDevice::Write(PowerOnRegister, {0});
}
MPU6050::axes MPU6050::ReadAcceleration() {

  auto accelData = I2CDevice::Read(AccelReadRegister, AccelReadLength);
  MPU6050::axes m{};
  m.X = (int16_t)(accelData[0] << 8 | accelData[1]) / AccelConversionFactor;
  m.Y = (int16_t)(accelData[2] << 8 | accelData[3]) / AccelConversionFactor;
  m.Z = (int16_t)(accelData[4] << 8 | accelData[5]) / AccelConversionFactor;

  return m;
}
MPU6050::axes MPU6050::ReadGyroscope() {
  auto gyroData = I2CDevice::Read(GyroReadRegister, GyroReadLength);
  MPU6050::axes m{};
  m.X = (int16_t)(gyroData[0] << 8 | gyroData[1]) / GyroConversionFactor;
  m.Y = (int16_t)(gyroData[2] << 8 | gyroData[3]) / GyroConversionFactor;
  m.Z = (int16_t)(gyroData[4] << 8 | gyroData[5]) / GyroConversionFactor;

  return m;
}
