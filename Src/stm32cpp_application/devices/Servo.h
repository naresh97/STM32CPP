//
// Created by naresh on 21/05/22.
//

#ifndef STM32CPP_SERVO_H
#define STM32CPP_SERVO_H

#include "../math/Rescaler.h"

#include <HAL.h>
#include <tuple>

class Servo {
  TIM_HandleTypeDef TimerHandle;
  Math::Rescaler<int> AngleDutyRescaler;

public:
  explicit Servo(TIM_HandleTypeDef timerHandle, std::tuple<int, int> dutyRange,
                 std::tuple<int, int> angleRange);
  void GoToAngle(int angle) const;
};

#endif // STM32CPP_SERVO_H
