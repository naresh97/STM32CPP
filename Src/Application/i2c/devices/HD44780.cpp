//
// Created by naresh on 23/05/22.
//

#include "HD44780.h"
HD44780::HD44780(const I2C_HandleTypeDef &i2CHandle, uint8_t address)
    : I2CDevice(i2CHandle, address) {
  Initialize();
}
void HD44780::Initialize() {
  HAL_Delay(50);
  SendInstructionBytes(0, 0, Initialize8BitData);
  HAL_Delay(5);
  SendInstructionBytes(0, 0, Initialize8BitData);
  HAL_Delay(1);
  SendInstructionBytes(0, 0, Initialize8BitData);
  HAL_Delay(10);
  SendInstructionBytes(0, 0, Initialize4BitData);
  HAL_Delay(10);
  SendInstructionBytes(0, 0, Configure4BitData2Lines8bitFont);
  HAL_Delay(5);
  ConfigureDisplay(false);
  HAL_Delay(5);
  ClearDisplay();
  HAL_Delay(5);
  SendInstructionBytes(0, 0, EntryMode);
  HAL_Delay(5);
  ConfigureDisplay(true);
}
std::vector<uint8_t> HD44780::GenerateInstructionBytes(uint8_t rs, uint8_t rw,
                                                       uint8_t data) {
  uint8_t bytes[4];
  uint8_t upperNibble = (data & 0b11110000);
  uint8_t lowerNibble = (data << 4) & 0b11110000;

  uint8_t headerHigh = (0b11 << 2) | (rw << 1) | rs;
  uint8_t headerLow = (headerHigh & 0b1011);

  bytes[0] = (upperNibble | headerHigh);
  bytes[1] = (upperNibble | headerLow);
  bytes[2] = (lowerNibble | headerHigh);
  bytes[3] = (lowerNibble | headerLow);

  return {bytes, bytes + sizeof(bytes)};
}
void HD44780::SendInstructionBytes(uint8_t rs, uint8_t rw, uint8_t data) {
  auto d = GenerateInstructionBytes(rs, rw, data);
  HAL_Delay(10);
  HAL_I2C_Master_Transmit(&I2CHandle, Address, d.data(), d.size(),
                          HAL_MAX_DELAY);
}
void HD44780::ClearDisplay() {
  SendInstructionBytes(0, 0, 0b00000001);
  SendInstructionBytes(0, 0, 0b00000010);
}
void HD44780::ConfigureDisplay(bool displayOn, bool showCursor,
                               bool blinkCursor) {
  // 00001(D)(C)(B) - D: Display On, C: Cursor On, B: Blinking
  char instruction = 0b1000;
  instruction = instruction | ((displayOn ? 1 : 0) << 2) |
                ((showCursor ? 1 : 0) << 1) | (blinkCursor ? 1 : 0);
  SendInstructionBytes(0, 0, instruction);
}
void HD44780::WriteText(char character) {
  SendInstructionBytes(1, 0, character);
}
void HD44780::WriteText(const std::string &characters) {
  for (char c : characters) {
    WriteText(c);
  }
}
void HD44780::ShiftDisplay(HD44780::Direction direction, int steps) {
  // 0001(S/C)(R/L)00
  char instruction = 0b11000;
  instruction = instruction | ((direction == Direction::RIGHT ? 1 : 0) << 2);
  for (int i = 0; i < steps; i++) {
    SendInstructionBytes(0, 0, instruction);
  }
}
void HD44780::MoveCursor(int row, int column) {
  char base = (row == 0 ? 0x00 : 0x40);
  base += column;
  base = 0b10000000 | base;
  SendInstructionBytes(0, 0, base);
}
