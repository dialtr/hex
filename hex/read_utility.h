// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_READ_UTILITY_H_
#define HEX_READ_UTILITY_H_

#include <cstdint>
#include <istream>

#include "absl/status/status.h"
#include "absl/status/statusor.h"

namespace hex {

// Convert a hex character (0..9, A..F, a..f) to a nybble.
//
// Returns nybble in the low bits of a uint8_t on success.
// Returns absl::InvalidArgumentError if a non hex char is read.
absl::StatusOr<uint8_t> HexCharToNybble(char c);

// Read characters from the stream until the start character ':' is read.
//
// Returns absl::OkStatus() on success.
// Returns absl::ResourceExhaustedError() if EOF is reached before the
//   the char is found.
absl::Status ReadStartByte(std::istream& input);

// Read two hex chars from the stream in succession that encode a single
// uint8_t (byte)
//
// Returns uint8_t on success.
// Returns absl::InvalidArgumentError if a non-hex char is read.
// Returns absl::ResourceExhaustedError if EOF is reached.
absl::StatusOr<uint8_t> ReadHexByte(std::istream& input);

// Read all whitespace including carriage return / newline.
//
// Returns absl::OkStatus on success.
// Returns absl::ResourceExhausted if EOF is reached.
absl::Status ReadEndOfLine(std::istream& input);

}  // namespace hex

#endif  // HEX_READ_UTILITY_H_
