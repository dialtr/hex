// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/memory_stream.h"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "gtest/gtest.h"

using std::cerr;
using std::cout;
using std::endl;

using hex::MemoryStream;
using hex::Position;

TEST(MemoryStreamTest, EmptyStringReturnsEndOfStream) {
  const char data[1] = {0};
  MemoryStream stream(data, 0);
  EXPECT_TRUE(stream.EndOfStream());
}

TEST(MemoryStreamTest, PeekDoesNotAdvanceStream) {
  const char* data = "ab";
  MemoryStream stream(data, 2);
  const char p1 = stream.Peek();

  EXPECT_EQ('a', p1);
  const char p2 = stream.Peek();
  EXPECT_EQ('a', p2);
}

TEST(MemoryStreamTest, PeekDoesNotAdvancePosition) {
  const char data[] = {'a', 'b'};
  MemoryStream stream(data, 2);
  const Position p1 = stream.CurrentPosition();
  const char a = stream.Peek();
  EXPECT_EQ('a', a);
  const Position p2 = stream.CurrentPosition();
  EXPECT_EQ(p1, p2);
}

TEST(MemoryStreamTest, NextAdvancesStream) {
  const char data[] = {'a', 'b'};
  MemoryStream stream(data, 2);

  const char p1 = stream.Next();
  EXPECT_EQ('a', p1);

  const char p2 = stream.Next();
  EXPECT_EQ('b', p2);

  Position pos = stream.CurrentPosition();

  const size_t kExpectedOffset = 2;
  const size_t kExpectedLine = 1;
  const size_t kExpectedColumn = 3;
  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);

  EXPECT_TRUE(stream.EndOfStream());
}
