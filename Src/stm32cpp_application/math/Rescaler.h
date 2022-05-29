//
// Created by naresh on 21/05/22.
//

#ifndef STM32CPP_RESCALER_H
#define STM32CPP_RESCALER_H

#include <tuple>

namespace Math {
template <typename T> class Rescaler {
  double Scaling{};
  double Offset{};

public:
  Rescaler(std::tuple<T, T> fromRange, std::tuple<T, T> toRange);
  double Rescale(T value) const;
  double operator()(T value) const;
};

template <typename T>
Rescaler<T>::Rescaler(std::tuple<T, T> fromRange, std::tuple<T, T> toRange) {
  auto [y1, y2] = toRange;
  auto [x1, x2] = fromRange;
  Scaling = static_cast<double>(y2 - y1) / (x2 - x1);
  Offset = y1 - Scaling * x1;
}
template <typename T> double Rescaler<T>::Rescale(T value) const {
  return value * Scaling + Offset;
}
template <typename T> double Rescaler<T>::operator()(T value) const {
  return Rescale(value);
}

} // namespace Math

#endif // STM32CP_RESCALER_H
