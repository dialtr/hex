// Copyright (C) 2026 The hex authors. All rights reserved.
#include "hex/stream.h"

#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

#include "absl/status/status.h"
#include "absl/status/statusor.h"
#include "gtest/gtest.h"
#include "tools/cpp/runfiles/runfiles.h"

using std::cerr;
using std::cout;
using std::endl;

using bazel::tools::cpp::runfiles::Runfiles;

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
  EXPECT_TRUE(stream->EndOfStream());
}

TEST(StreamTest, FileReadTest) {
  std::string error;
  std::unique_ptr<Runfiles> runfiles(Runfiles::CreateForTest(&error));
  EXPECT_TRUE(runfiles != nullptr);
  const std::string path = runfiles->Rlocation("hex/hex/testdata/abc.txt");
  auto result = Stream::OpenFile(path.c_str());
  EXPECT_TRUE(result.ok());
  auto stream = result.value();

  const char a = stream->Next();
  EXPECT_EQ('a', a);
  char n = stream->Next();
  EXPECT_EQ('\n', n);

  const char b = stream->Next();
  EXPECT_EQ('b', b);
  n = stream->Next();
  EXPECT_EQ('\n', n);

  const char c = stream->Next();
  EXPECT_EQ('c', c);

  Position pos = stream->CurrentPosition();

  const size_t kExpectedOffset = 5;
  const size_t kExpectedLine = 3;
  const size_t kExpectedColumn = 2;
  EXPECT_EQ(kExpectedOffset, pos.offset);
  EXPECT_EQ(kExpectedLine, pos.line);
  EXPECT_EQ(kExpectedColumn, pos.column);
}
