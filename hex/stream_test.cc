// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/stream.h"

#include <gtest/gtest.h>

#include <cstddef>
#include <memory>
#include <sstream>
#include <string>

#include "absl/status/status.h"
#include "absl/status/statusor.h"

using hex::Position;
using hex::Stream;

TEST(StreamTest, EmptyStringReturnsEndOfStream) {
  auto result = Stream::OpenString("");
  EXPECT_TRUE(result.ok());
  auto stream = result.value();
  EXPECT_TRUE(stream->EndOfStream());
}

TEST(StreamTest, PeekDoesNotAdvanceStream) {
  auto result = Stream::OpenString("ab");
  EXPECT_TRUE(result.ok());
  auto stream = result.value();
  const char p1 = stream->Peek();
  EXPECT_EQ('a', p1);
  const char p2 = stream->Peek();
  EXPECT_EQ('a', p2);
}

TEST(StreamTest, NextAdvancesStream) {
  auto result = Stream::OpenString("ab");
  EXPECT_TRUE(result.ok());
  auto stream = result.value();
  const char p1 = stream->Next();
  EXPECT_EQ('a', p1);
  const char p2 = stream->Next();
  EXPECT_EQ('b', p2);
  Position pos = stream->CurrentPosition();
  const size_t kExpectedOffset = 2;
  const size_t kExpectedLine = 1;
  const size_t kExpectedColumn = 3;
  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);
}
