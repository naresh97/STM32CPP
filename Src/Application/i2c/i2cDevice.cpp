//
// Created by naresh on 19/05/22.
//

#include "i2cDevice.h"

#include "../exceptions.h"

i2cDevice::i2cDevice(I2C_HandleTypeDef i2CHandle, uint8_t address)
    : i2CHandle(i2CHandle), address(address) {}

void i2cDevice::initialize(uint8_t whoamiRegister, int whoamiResponse) {
  uint8_t check;
  auto status = HAL_I2C_Mem_Read(&i2CHandle, address, whoamiRegister, 1, &check,
                                 1, i2cTimeout);

  if (status != HAL_OK)
    throw exceptions::i2c::initializationError(
        "Could not read from I2C Device.");
  if (check != whoamiResponse)
    throw exceptions::i2c::initializationError("Wrong whoami response.");
}
std::vector<uint8_t> i2cDevice::read(uint8_t registerAddress,
                                     int readBytesLength) {

  uint8_t readBuffer[readBytesLength];
  auto status = HAL_I2C_Mem_Read(&i2CHandle, address, registerAddress, 1,
                                 readBuffer, readBytesLength, i2cTimeout);

  if (status != HAL_OK)
    throw exceptions::i2c::readError("Could not read from register.");

  return {readBuffer, readBuffer + readBytesLength};
}
void i2cDevice::write(uint8_t registerAddress, std::vector<uint8_t> data) {

  if (data.empty())
    throw std::runtime_error("Data vector is empty.");

  auto status = HAL_I2C_Mem_Write(&i2CHandle, address, registerAddress, 1,
                                  data.data(), data.size(), i2cTimeout);

  if (status != HAL_OK)
    throw std::runtime_error("Could not write to register.");
}
