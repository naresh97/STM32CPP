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

class i2cDevice {
  uint8_t address;
  I2C_HandleTypeDef i2CHandle;
  int i2cTimeout = HAL_MAX_DELAY;

public:
  explicit i2cDevice(I2C_HandleTypeDef i2CHandle, uint8_t address);
  virtual void initialize(uint8_t whoamiRegister, int whoamiResponse);
  virtual std::vector<uint8_t> read(uint8_t registerAddress,
                                    int readBytesLength);
  virtual void write(uint8_t registerAddress, std::vector<uint8_t> data);
};

#endif // HELLONUCLEO_I2CDEVICE_H
