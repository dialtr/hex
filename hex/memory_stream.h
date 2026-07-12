// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_MEMORY_STREAM_H_
#define HEX_MEMORY_STREAM_H_

#include <cstddef>
#include <fstream>
#include <memory>
#include <string>

#include "hex/position.h"
#include "hex/stream_interface.h"

namespace hex {

class MemoryStream : public StreamInterface {
 public:
  MemoryStream(void* buf, size_t len);

  // Copy, assignment not allowed.
  MemoryStream(const MemoryStream&) = delete;
  MemoryStream& operator=(const MemoryStream&) = delete;
  MemoryStream(MemoryStream&&) = delete;
  MemoryStream& operator=(MemoryStream&&) = delete;

  ~MemoryStream() override;

  // Return the current position in the stream.
  Position CurrentPosition() const override;

  // Peek character at the current position without advancing.
  char Peek() override;

  // Read character at the current position and advance to the next.
  char Next() override;

  // Return 'true' if we've reached the end of the stream.
  bool EndOfStream() override;

 private:
  char* buf_;
  size_t len_;
  Position position_;
};

}  // namespace hex

#endif  // HEX_MEMORY_STREAM_H_
