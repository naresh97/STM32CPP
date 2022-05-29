//
// Created by naresh on 21/05/22.
//

#include "Servo.h"

#include <cmath>
Servo::Servo(TIM_HandleTypeDef timerHandle, std::tuple<int, int> dutyRange,
             std::tuple<int, int> angleRange)
    : TimerHandle(timerHandle), AngleDutyRescaler(angleRange, dutyRange) {
  HAL_TIM_PWM_Start(&timerHandle, TIM_CHANNEL_2);
}
void Servo::GoToAngle(int angle) const {
  TimerHandle.Instance->CCR2 = std::lround(AngleDutyRescaler.Rescale(angle));
}
