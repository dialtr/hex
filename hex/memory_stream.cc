// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/memory_stream.h"

#include <cstddef>
#include <fstream>
#include <memory>
#include <string>

#include "hex/position.h"
#include "hex/stream_interface.h"

namespace hex {

MemoryStream::MemoryStream(void* buf, size_t len)
    : buf_(reinterpret_cast<char*>(buf)), len_(len) {}

MemoryStream::~MemoryStream() {}

// Return the current position in the stream.
Position MemoryStream::CurrentPosition() const { return Position{}; }

// Peek character at the current position without advancing.
char MemoryStream::Peek() { return 0; }

// Read character at the current position and advance to the next.
char MemoryStream::Next() { return 0; }

// Return 'true' if we've reached the end of the stream.
bool MemoryStream::EndOfStream() { return true; }

/*
 private:
  char* buf_;
  size_t len_;
  Position position_;
};
*/

}  // namespace hex
