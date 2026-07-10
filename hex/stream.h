// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_STREAM_H_
#define HEX_STREAM_H_

#include <cstddef>

#include "hex/stream_interface.h"

namespace hex {

class Stream : public StreamInterface {
 public:
  ~Stream() override;

  // Return the current position in the stream.
  Position CurrentPosition() const override;

  // Peek the next character from the stream without advancing the position.
  char Peek() override;

  // Read the next character from the stream, advancing the position.
  char Next() override;

  // Return 'true' if we've reached the end of the stream.
  bool EndOfStream() override;
};

}  // namespace hex

#endif  // HEX_STREAM_H_
