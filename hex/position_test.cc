// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/position.h"

#include <cstddef>

#include "gtest/gtest.h"

TEST(PositionTest, Constructor) {
  hex::Position pos;
  const size_t kExpectedOffset = 0;
  const size_t kExpectedLine = 1;
  const size_t kExpectedColumn = 1;
  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);
}

TEST(PositionTest, UpdateStandardChar) {
  hex::Position pos;
  const size_t kExpectedOffset = 1;
  const size_t kExpectedLine = 1;
  const size_t kExpectedColumn = 2;
  hex::UpdatePosition(&pos, 'x');
  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);
}

TEST(PositionTest, UpdateCarriageReturn) {
  // Set up a position with some initial non-zero values.
  hex::Position pos;
  pos.offset = 100;
  pos.line = 10;
  pos.column = 5;

  hex::UpdatePosition(&pos, '\r');

  const size_t kExpectedOffset = 101;
  const size_t kExpectedLine = 10;
  const size_t kExpectedColumn = 1;

  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);
}

TEST(PositionTest, UpdateCarriageNewline) {
  // Set up a position with some initial non-zero values.
  hex::Position pos;
  pos.offset = 100;
  pos.line = 10;
  pos.column = 5;

  hex::UpdatePosition(&pos, '\n');

  const size_t kExpectedOffset = 101;
  const size_t kExpectedLine = 11;
  const size_t kExpectedColumn = 1;

  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);
}
