// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/stream.h"

#include <cstddef>

namespace hex {

Stream::~Stream() {}

Position Stream::CurrentPosition() const { return Position{}; }

char Stream::Peek() { return '\0'; }

char Stream::Next() { return '\0'; }

}  // namespace hex
