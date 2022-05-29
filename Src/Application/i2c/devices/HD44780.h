//
// Created by naresh on 23/05/22.
//

#ifndef HELLONUCLEO_HD44780_H
#define HELLONUCLEO_HD44780_H

static const int Initialize8BitData = 0b00110000;
static const int Initialize4BitData = 0b00100000;
static const int Configure4BitData2Lines8bitFont = 0b00101000;
static const int EntryMode = 0b00000110;

#include "../I2CDevice.h"

/**
 * Interacts with the HD44780 LCD device
 * Implements I2CDevice
 */
class HD44780 : public I2CDevice {
public:
  enum class Direction {
    LEFT,
    RIGHT,
  };

private:
  /**
   * Sends initialization instructions
   * Refer to Datasheet: Initializing by Instruction pg. 45-46
   */
  void Initialize();
  static std::vector<uint8_t> GenerateInstructionBytes(uint8_t rs, uint8_t rw,
                                                       uint8_t data);
  void SendInstructionBytes(uint8_t rs, uint8_t rw, uint8_t data);

public:
  HD44780(const I2C_HandleTypeDef &i2CHandle, uint8_t address);

  void MoveCursor(int row, int column);
  void WriteText(char character);
  void WriteText(const std::string &characters);
  void ConfigureDisplay(bool displayOn, bool showCursor = true,
                        bool blinkCursor = true);
  void ShiftDisplay(Direction direction, int steps = 1);
  void ClearDisplay();
};

#endif // HELLONUCLEO_HD44780_H
