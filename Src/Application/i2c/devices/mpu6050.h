//
// Created by naresh on 19/05/22.
//

#ifndef HELLONUCLEO_MPU6050_H
#define HELLONUCLEO_MPU6050_H

static const int WHOAMI_REGISTER = 0x75;
static const int WHOAMI_RESPONSE = 0x72;
static const int POWERON_REGISTER = 0x6b;
static const int ACCEL_READ_REGISTER = 0x3b;
static const int ACCEL_READ_LENGTH = 6;
static const double ACCEL_CONVERSION_FACTOR = 16384.0;
static const int GYRO_READ_REGISTER = 0x43;
static const int GYRO_READ_LENGTH = 6;
static const double GYRO_CONVERSION_FACTOR = 131.0;
#include "../i2cDevice.h"
class mpu6050 : public i2cDevice {
public:
  struct axes {
    double x;
    double y;
    double z;
  };

  mpu6050(const I2C_HandleTypeDef &i2CHandle, uint8_t address);
  void initialize();
  axes readAcceleration();
  axes readGyroscope();
};

#endif // HELLONUCLEO_MPU6050_H
