// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/read_utility.h"

#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "absl/status/status.h"

TEST(ReadUtilityTest, ReadStartByte_FindsStartByte) {
  std::stringstream line("    :");
  absl::Status status;
  status = hex::ReadStartByte(line);
  EXPECT_EQ(absl::OkStatus(), status);
}
