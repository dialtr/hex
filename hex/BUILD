load("@rules_cc//cc:defs.bzl", "cc_test", "cc_library", "cc_binary")

cc_library(
  name = "read_utility",
  hdrs = [ "read_utility.h" ],
  srcs = [ "read_utility.cc" ],
  deps = [
    "@abseil-cpp//absl/status:status",
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/strings",
    "@abseil-cpp//absl/log:check",
  ],
)

cc_library(
  name = "record",
  hdrs = [ "record.h" ],
  srcs = [ "record.cc" ],
  deps = [
    "@abseil-cpp//absl/status:status",
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/strings",
    "@abseil-cpp//absl/log:check",
  ],
)

cc_library(
  name = "position",
  hdrs = [ "position.h" ],
  srcs = [ "position.cc" ],
  deps = [
    "@abseil-cpp//absl/log:check",
  ],
)

cc_library(
  name = "stream",
  hdrs = [
    "stream.h",
    "stream_interface.h",
  ],
  srcs = [
    "stream.cc"
  ],
  deps = [
    "@abseil-cpp//absl/log:check",
    "@abseil-cpp//absl/status:status",
    "@abseil-cpp//absl/status:statusor",
    ":position",
  ],
)

cc_library(
  visibility = [ "//visibility:public" ],
  name = "hex",
  deps = [
    "@abseil-cpp//absl/status:status",
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/strings",
    "@abseil-cpp//absl/log:check",
    ":read_utility",
    ":record",
  ],
)

cc_test(
  name = "position_test",
  srcs = ["position_test.cc"],
  deps = [
    ":position",
    "@googletest//:gtest_main",
  ],
  timeout = "short",
)

cc_test(
  name = "read_utility_test",
  srcs = ["read_utility_test.cc"],
  deps = [
    ":read_utility",
    "@googletest//:gtest_main",
  ],
  timeout = "short",
)

cc_test(
  name = "record_test",
  srcs = ["record_test.cc"],
  deps = [
    ":record",
    "@googletest//:gtest_main",
  ],
  timeout = "short",
)

cc_test(
  name = "stream_test",
  srcs = ["stream_test.cc"],
  data = [
    "testdata/abc.txt"
  ],
  deps = [
    ":position",
    ":stream",
    "@googletest//:gtest_main",
    "@bazel_tools//tools/cpp/runfiles",
  ],
  timeout = "short",
)

