// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/position.h"

#include "absl/log/check.h"

namespace hex {

// Update a position given a character. Rules are:
//   1. Always advance the offset.
//   2. If 'ch' is a '\r', reset "carriage" to column 1.
//   3. If 'ch' is a '\n', reset "carriage" to column 1, advance line.
//   4. If 'ch' is any other character, advance the column.
void UpdatePosition(Position* pos, char ch) {
  DCHECK(pos != nullptr) << "hex::UpdatePosition(): Position pointer was null";
  Position& position(*pos);
  ++position.offset;
  switch (ch) {
    case '\r':
      position.column = 1;
      break;
    case '\n':
      position.column = 1;
      ++position.line;
      break;
    default:
      ++position.column;
      break;
  }
}

}  // namespace hex
