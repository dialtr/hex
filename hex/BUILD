load("@rules_cc//cc:defs.bzl", "cc_test", "cc_library", "cc_binary")

cc_library(
  name = "record",
  hdrs = [ "record.h" ],
  srcs = [ "record.cc" ],
  deps = [
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/strings",
    "@abseil-cpp//absl/log:check",
  ],
)

cc_library(
  visibility = [ "//visibility:public" ],
  name = "hex",
  deps = [
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/strings",
    "@abseil-cpp//absl/log:check",
    ":record",
  ],
)

cc_test(
  name = "record_test",
  srcs = ["record_test.cc"],
  deps = [
    ":record",
    "@googletest//:gtest_main",
  ],
)

