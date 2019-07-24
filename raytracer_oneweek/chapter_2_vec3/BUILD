
cc_library(
    name = "vec3",
    hdrs = ["vec3.h"],
    srcs = ["vec3.cc"],
    copts = [
      "-Werror",
      "-std=c++11",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "vec3_test",
    deps = [
        "vec3",
    ],
    copts = [
      "-Werror",
      "-std=c++11",
    ],
    srcs = ["vec3_test.cc"],
)