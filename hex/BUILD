load("@rules_cc//cc:defs.bzl", "cc_test", "cc_library", "cc_binary")

cc_library(
  visibility = [ "//visibility:public" ],
  name = "hex",
  hdrs = [
    "hex.h"
  ],
  srcs = [
    "hex.cc"
  ],
  deps = [
    "@abseil-cpp//absl/status:statusor",
    "@abseil-cpp//absl/strings",
    "@abseil-cpp//absl/log:check",
  ],
)

cc_test(
  name = "hex_test",
  srcs = ["hex_test.cc"],
  deps = [
    ":libhex",
    "@googletest//:gtest_main",
  ],
)

