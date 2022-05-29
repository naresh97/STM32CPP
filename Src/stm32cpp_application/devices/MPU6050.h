//
// Created by naresh on 19/05/22.
//

#ifndef STM32CPP_SRC_APPLICATION_I2C_DEVICES_MPU6050_H
#define STM32CPP_SRC_APPLICATION_I2C_DEVICES_MPU6050_H

#include "../communications/i2c/I2CDevice.h"
static const int WhoamiRegister = 0x75;
static const int WhoamiResponse = 0x72;
static const int PowerOnRegister = 0x6b;
static const int AccelReadRegister = 0x3b;
static const int AccelReadLength = 6;
static const double AccelConversionFactor = 16384.0;
static const int GyroReadRegister = 0x43;
static const int GyroReadLength = 6;
static const double GyroConversionFactor = 131.0;
static const int TempReadRegister = 0x41;
static const int TempReadLength = 2;

class MPU6050 : public I2CDevice {
public:
  struct axes {
    double X;
    double Y;
    double Z;
  };

  MPU6050(const I2C_HandleTypeDef &i2CHandle, uint8_t address);
  void Initialize();
  axes ReadAcceleration();
  axes ReadGyroscope();
  double ReadTemperature();
};

#endif // STM32CP_SRC_APPLICATION_I2C_DEVICES_MPU6050_H
