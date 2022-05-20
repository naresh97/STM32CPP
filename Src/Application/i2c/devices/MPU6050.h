//
// Created by naresh on 19/05/22.
//

#ifndef HELLONUCLEO_SRC_APPLICATION_I2C_DEVICES_MPU6050_H
#define HELLONUCLEO_SRC_APPLICATION_I2C_DEVICES_MPU6050_H

static const int WhoamiRegister = 0x75;
static const int WhoamiResponse = 0x72;
static const int PowerOnRegister = 0x6b;
static const int AccelReadRegister = 0x3b;
static const int AccelReadLength = 6;
static const double AccelConversionFactor = 16384.0;
static const int GyroReadRegister = 0x43;
static const int GyroReadLength = 6;
static const double GyroConversionFactor = 131.0;

#include "../I2CDevice.h"
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
};

#endif // HELLONUCLEO_SRC_APPLICATION_I2C_DEVICES_MPU6050_H
