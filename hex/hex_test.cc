#include <gtest/gtest.h>
#include "hex.h"

TEST(toolkit, Add) {
  int result = Add(1, 2);
  EXPECT_EQ(result, 3);
}

