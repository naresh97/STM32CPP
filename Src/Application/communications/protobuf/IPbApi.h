//
// Created by naresh on 29/05/22.
//

#ifndef HELLONUCLEO_IPBAPI_H
#define HELLONUCLEO_IPBAPI_H

#include "pb_decode.h"

#include <cstdint>
#include <vector>

class IPbApi {
public:
  static bool DecodeToByteVector(pb_istream_t *istream, const pb_field_t *,
                                 void **arg) {
    auto *bytesVector = (std::vector<uint8_t> *)(*arg);
    while (istream->bytes_left) {
      uint64_t byte;
      pb_decode_varint(istream, &byte);
      bytesVector->push_back(byte);
    }
    return true;
  };
};

#endif // HELLONUCLEO_IPBAPI_H