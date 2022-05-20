//
// Created by naresh on 19/05/22.
//

#ifndef HELLONUCLEO_EXCEPTIONS_H
#define HELLONUCLEO_EXCEPTIONS_H

#include <stdexcept>
namespace exceptions::i2c {

class initializationError : public std::runtime_error {
public:
  explicit initializationError(const std::string &message) noexcept
      : std::runtime_error(message) {}
};

class readError : public std::runtime_error {
public:
  explicit readError(const std::string &message) noexcept
      : std::runtime_error(message) {}
};

} // namespace exceptions::i2c

#endif // HELLONUCLEO_EXCEPTIONS_H
