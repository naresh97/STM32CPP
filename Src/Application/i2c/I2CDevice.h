//
// Created by naresh on 19/05/22.
//

#ifndef HELLONUCLEO_I2CDEVICE_H
#define HELLONUCLEO_I2CDEVICE_H

extern "C" {
#include "stm32f4xx_hal.h"
};

#include <cstdint>
#include <exception>
#include <stdexcept>
#include <string>
#include <vector>

class I2CDevice {
  int I2CTimeout = HAL_MAX_DELAY;

protected:
  I2C_HandleTypeDef I2CHandle;

  uint8_t Address;

public:
  explicit I2CDevice(I2C_HandleTypeDef i2CHandle, uint8_t address);
  virtual void Initialize(uint8_t whoamiRegister, int whoamiResponse);
  virtual std::vector<uint8_t> Read(uint8_t registerAddress,
                                    int readBytesLength);
  virtual void Write(uint8_t registerAddress, std::vector<uint8_t> data);
  virtual std::vector<uint8_t> ScanForDevices();
};

#endif // HELLONUCLEO_I2CDEVICE_H
