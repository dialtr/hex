// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_POSITION_H_
#define HEX_POSITION_H_

#include <cstddef>
#include <string>

namespace hex {

// Position in a stream, tracking file offset, line and column.
struct Position {
  size_t offset = 0;
  size_t line = 1;
  size_t column = 1;

  // Implement comparison.
  auto operator<=>(const Position&) const = default;
};

// Update a position given a character. Rules are:
//   1. Always advance the offset.
//   2. If 'ch' is a '\r', reset "carriage" to column 1.
//   3. If 'ch' is a '\n', reset "carriage" to column 1, advance line.
//   4. If 'ch' is any other character, advance the column.
void UpdatePosition(Position* position, char ch);

}  // namespace hex

#endif  // HEX_POSITION_H_
