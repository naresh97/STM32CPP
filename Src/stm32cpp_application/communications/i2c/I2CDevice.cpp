//
// Created by naresh on 19/05/22.
//

#include "I2CDevice.h"

#include "../../application/exceptions.h"

I2CDevice::I2CDevice(I2C_HandleTypeDef i2CHandle, uint8_t address)
    : I2CHandle(i2CHandle), Address(address) {}

void I2CDevice::Initialize(uint8_t whoamiRegister, int whoamiResponse) {
  uint8_t check;
  auto status = HAL_I2C_Mem_Read(&I2CHandle, Address, whoamiRegister, 1, &check,
                                 1, I2CTimeout);

  if (status != HAL_OK)
    throw exceptions::i2c::initializationError(
        "Could not Read from I2C Device.");
  if (check != whoamiResponse)
    throw exceptions::i2c::initializationError("Wrong whoami response.");
}
std::vector<uint8_t> I2CDevice::Read(uint8_t registerAddress,
                                     int readBytesLength) {

  uint8_t readBuffer[readBytesLength];
  auto status = HAL_I2C_Mem_Read(&I2CHandle, Address, registerAddress, 1,
                                 readBuffer, readBytesLength, I2CTimeout);

  if (status != HAL_OK)
    throw exceptions::i2c::readError("Could not Read from register.");

  return {readBuffer, readBuffer + readBytesLength};
}
void I2CDevice::Write(uint8_t registerAddress, std::vector<uint8_t> data) {

  if (data.empty())
    throw std::runtime_error("Data vector is empty.");

  auto status = HAL_I2C_Mem_Write(&I2CHandle, Address, registerAddress, 1,
                                  data.data(), data.size(), I2CTimeout);

  if (status != HAL_OK)
    throw std::runtime_error("Could not Write to register.");
}
std::vector<uint8_t> I2CDevice::ScanForDevices() {
  auto devices = std::vector<uint8_t>();
  for (int i = 0x00; i < 0xff; ++i) {
    auto statusReady =
        HAL_I2C_IsDeviceReady(&I2CHandle, i << 1, 5, HAL_MAX_DELAY);

    if (statusReady == HAL_OK)
      devices.push_back(i);
  }
  return devices;
}
