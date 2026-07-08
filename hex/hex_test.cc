// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/hex.h"

#include <gtest/gtest.h>

TEST(toolkit, Add) {
  int result = Add(1, 2);
  EXPECT_EQ(result, 3);
}
