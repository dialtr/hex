// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/memory_stream.h"

#include <cstddef>
#include <fstream>
#include <memory>
#include <string>

#include "hex/position.h"
#include "hex/stream_interface.h"

namespace hex {

MemoryStream::MemoryStream(const char* buf, size_t len)
    : buf_(buf), len_(len) {}

MemoryStream::~MemoryStream() {}

// Return the current position in the stream.
Position MemoryStream::CurrentPosition() const { return position_; }

// Peek character at the current position without advancing.
char MemoryStream::Peek() {
  if (EndOfStream()) {
    return 0;
  }
  return buf_[position_.offset];
}

// Read character at the current position and advance to the next.
char MemoryStream::Next() {
  if (EndOfStream()) {
    return 0;
  }
  const char c = buf_[position_.offset];
  UpdatePosition(&position_, c);
  return c;
}

// Return 'true' if we've reached the end of the stream.
bool MemoryStream::EndOfStream() { return (position_.offset >= len_); }

}  // namespace hex
