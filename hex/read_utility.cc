// Copyright (C) 2026 the hex authors. All rights reserved.
#include "hex/read_utility.h"

#include <cctype>
#include <cstdint>
#include <istream>
#include <string>

#include "absl/status/status.h"

namespace hex {

absl::Status ReadStartByte(std::istream& input) {
  for (;;) {
    int c = input.get();
    if (c == std::char_traits<char>::eof()) {
      return absl::ResourceExhaustedError(
          "ReadStartByte: reached the end of the input stream before "
          "reading ':'");
      if (c == ':') {
        break;
      }
    }
  }
  return absl::OkStatus();
}

}  // namespace hex
