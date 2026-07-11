// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/stream.h"

#include <cerrno>
#include <cstddef>
#include <fstream>
#include <memory>
#include <string>

#include "absl/log/check.h"
#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "hex/position.h"

namespace hex {

// Open file.
absl::StatusOr<std::shared_ptr<Stream>> Stream::OpenFile(const char* path) {
  DCHECK(path != nullptr) << "Stream::Open(): path was null";
  std::ifstream* stream = new std::ifstream(path);
  if (!stream->is_open()) {
    delete stream;
    return absl::ErrnoToStatus(errno, "failed to  open file stream");
  }
  return std::make_shared<Stream>(stream, Passkey{});
}

// Open as stream on a string.
absl::StatusOr<std::shared_ptr<Stream>> Stream::OpenString(
    const std::string& s) {
  std::stringstream* stream = new std::stringstream(s);
  return std::make_shared<Stream>(stream, Passkey{});
}

// Privileged constructor.
Stream::Stream(std::istream* stream, const Passkey&) : stream_(stream) {}

Stream::~Stream() { delete stream_; }

Position Stream::CurrentPosition() const { return position_; }

char Stream::Peek() {
  const int ch = stream_->peek();
  if (ch == EOF) {
    return '\0';
  }
  UpdatePosition(&position_, ch);
  return static_cast<char>(ch);
}

char Stream::Next() {
  const int ch = stream_->get();
  if (ch == EOF) {
    return '\0';
  }
  UpdatePosition(&position_, ch);
  return static_cast<char>(ch);
}

bool Stream::EndOfStream() { return true; }

}  // namespace hex
