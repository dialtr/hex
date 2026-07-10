// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_STREAM_INTERFACE_H_
#define HEX_STREAM_INTERFACE_H_

#include <cstddef>

namespace hex {

// Position in a stream, tracking file offset, line and column.
struct Position {
  size_t offset;
  size_t line;
  size_t column;
};

// Character stream interface.
class StreamInterface {
 public:
  virtual ~StreamInterface() {}

  // Return the current position in the stream.
  virtual Position CurrentPosition() const = 0;

  // Peek the next character from the stream without advancing the position.
  virtual char Peek() = 0;

  // Read the next character from the stream, advancing the position.
  virtual char Next() = 0;

  // Returns true if the end of the stream has been reached.
  virtual bool EndOfStream() = 0;
};

}  // namespace hex

#endif  // HEX_STREAM_INTERFACE_H_
