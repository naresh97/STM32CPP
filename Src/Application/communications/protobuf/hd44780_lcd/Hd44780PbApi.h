//
// Created by naresh on 29/05/22.
//

#include "../../../i2c/devices/HD44780.h"
#include "../IPbApi.h"
#include "hd44780_lcd.pb.h"
#include "pb_decode.h"

#include <cstdint>
#include <vector>
#ifndef HELLONUCLEO_HD44780_PBAPI_H
#define HELLONUCLEO_HD44780_PBAPI_H

#endif // HELLONUCLEO_HD44780_PBAPI_H

class Hd44780PbApi : IPbApi {
public:
  static void ParseMessage(std::vector<uint8_t> message, HD44780 &lcd) {
    ApiRequest apiRequest = ApiRequest_init_zero;
    std::vector<uint8_t> apiParamBytes{};
    apiRequest.parameters.arg = &apiParamBytes;
    apiRequest.parameters.funcs.decode = DecodeToByteVector;

    pb_istream_t stream =
        pb_istream_from_buffer(message.data(), message.size());
    pb_decode(&stream, ApiRequest_fields, &apiRequest);

    if (apiRequest.method == ApiRequest_Method_WriteText) {
      WriteText writeText = WriteText_init_zero;
      std::vector<uint8_t> writeTextBytes{};
      writeText.characters.arg = &writeTextBytes;
      writeText.characters.funcs.decode = DecodeToByteVector;
      pb_istream_t paramStream =
          pb_istream_from_buffer(apiParamBytes.data(), apiParamBytes.size());
      pb_decode(&paramStream, WriteText_fields, &writeText);

      std::string writeTexString{};
      for (auto x : writeTextBytes) {
        writeTexString += x;
      }
      lcd.WriteText(writeTexString);
    } else if (apiRequest.method == ApiRequest_Method_ClearDisplay) {
      lcd.ClearDisplay();
    } else if (apiRequest.method == ApiRequest_Method_MoveCursor) {
      MoveCursor moveCursor = MoveCursor_init_zero;
      pb_istream_t paramStream =
          pb_istream_from_buffer(apiParamBytes.data(), apiParamBytes.size());
      pb_decode(&paramStream, MoveCursor_fields, &moveCursor);
      lcd.MoveCursor(moveCursor.row, moveCursor.column);
    } else if (apiRequest.method == ApiRequest_Method_ConfigureDisplay) {
      // TODO: ConfigureDisplay implementation
    } else if (apiRequest.method == ApiRequest_Method_ShiftDisplay) {
      // TODO: ShiftDisplay implementation
    }
  }
};
