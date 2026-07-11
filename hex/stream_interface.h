// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_STREAM_INTERFACE_H_
#define HEX_STREAM_INTERFACE_H_

#include <cstddef>
#include <string>

#include "hex/position.h"

namespace hex {

// Character stream interface.
class StreamInterface {
 public:
  virtual ~StreamInterface() {}

  // Return the current position (offset, line, column) of stream.
  // A subsequent call to Peek() or Next() will return the character
  // that resides at this position.
  virtual Position CurrentPosition() const = 0;

  // Peek the character at the current position without advancing.
  virtual char Peek() = 0;

  // Read the character at the current position and advance to the next.
  virtual char Next() = 0;

  // Returns true if the end of the stream has been reached.
  virtual bool EndOfStream() = 0;
};

}  // namespace hex

#endif  // HEX_STREAM_INTERFACE_H_
