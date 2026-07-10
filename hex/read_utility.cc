// Copyright (C) 2026 the hex authors. All rights reserved.
#include "hex/read_utility.h"

#include <cctype>
#include <cstdint>
#include <istream>
#include <string>

#include "absl/status/status.h"

namespace hex {

// Convert a hex character to a nybble.
absl::StatusOr<uint8_t> HexCharToNybble(char c) {
  switch (toupper(c)) {
    case '0':
      return 0x0;
    case '1':
      return 0x1;
    case '2':
      return 0x2;
    case '3':
      return 0x3;
    case '4':
      return 0x4;
    case '5':
      return 0x5;
    case '6':
      return 0x6;
    case '7':
      return 0x7;
    case '8':
      return 0x8;
    case '9':
      return 0x9;
    case 'A':
      return 0xa;
    case 'B':
      return 0xb;
    case 'C':
      return 0xc;
    case 'D':
      return 0xd;
    case 'E':
      return 0xe;
    case 'F':
      return 0xf;
    default:
      return absl::InvalidArgumentError(
          "HexCharToNybble: input was not a hex character");
  }
}

absl::Status ReadStartByte(std::istream& input) {
  for (;;) {
    int c = input.get();
    if (c == std::char_traits<char>::eof()) {
      return absl::ResourceExhaustedError(
          "ReadStartByte: reached the end of the input stream before "
          "reading ':'");
    } else if (c == ':') {
      break;
    }
  }
  return absl::OkStatus();
}

absl::StatusOr<uint8_t> ReadHexByte(std::istream& input) {
  uint8_t byte = 0;
  for (int i = 0; i < 2; ++i) {
    const int c = input.get();
    if (c == std::char_traits<char>::eof()) {
      return absl::ResourceExhaustedError(
          "ReadHexByte: reached the end of the input stream before "
          "reading a hex character");
    }
    const absl::StatusOr<uint8_t> nybble = HexCharToNybble(c);
    if (!nybble.ok()) {
      return nybble;
    }
    byte <<= 4;
    byte |= nybble.value();
  }
  return byte;
}

}  // namespace hex
