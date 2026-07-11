// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/read_utility.h"

#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "absl/status/status.h"

TEST(ReadUtilityTest, ReadStartByte_FindsStartByte) {
  std::stringstream line("    :x");
  const absl::Status status = hex::ReadStartByte(line);
  EXPECT_EQ(absl::OkStatus(), status);
  const char next = line.get();
  // Make sure the ':' was consumed, but no further.
  EXPECT_EQ('x', next);
}

TEST(ReadUtilityTest, ReadStartByte_ReturnsResourceExhausted) {
  std::stringstream line("    ");
  const absl::Status status = hex::ReadStartByte(line);
  EXPECT_EQ(absl::StatusCode::kResourceExhausted, status.code());
}
