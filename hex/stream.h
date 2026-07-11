// Copyright (C) 2026 The hex authors. All rights reserved.
#ifndef HEX_STREAM_H_
#define HEX_STREAM_H_

#include <cstddef>
#include <fstream>
#include <memory>
#include <string>

#include "absl/status/statusor.h"
#include "hex/stream_interface.h"

namespace hex {

class Stream : public StreamInterface {
  struct Passkey {};

 public:
  Stream(std::istream*, const Passkey&);

  // Copy, assignment not allowed.
  Stream(const Stream&) = delete;
  Stream& operator=(const Stream&) = delete;
  Stream(Stream&&) = delete;
  Stream& operator=(Stream&&) = delete;

  // Open a stream given a path to a file, or a string containing chars.
  static absl::StatusOr<std::shared_ptr<Stream>> Open(const char* path);
  static absl::StatusOr<std::shared_ptr<Stream>> Open(const std::string& s);

  ~Stream() override;

  // Return the current position in the stream.
  Position CurrentPosition() const override;

  // Peek character at the current position without advancing.
  char Peek() override;

  // Read character at the current position and advance to the next.
  char Next() override;

  // Return 'true' if we've reached the end of the stream.
  bool EndOfStream() override;

 private:
  std::istream* stream_;
  Position position_;
};

}  // namespace hex

#endif  // HEX_STREAM_H_
