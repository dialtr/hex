// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_READ_UTILITY_H_
#define HEX_READ_UTILITY_H_

#include <cstdint>
#include <istream>

#include "absl/status/status.h"
#include "absl/status/statusor.h"

namespace hex {

// Read characters from the stream until the start character ':' is read.
// Returns absl::OkStatus() on success.
// Returns absl::ResourceExhaustedError() if EOF is reached before the
//   the char is found.
absl::Status ReadStartByte(std::istream& input);

}  // namespace hex

#endif  // HEX_READ_UTILITY_H_
