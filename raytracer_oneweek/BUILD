package(
    default_visibility = ["//visibility:public"],
)

cc_library(
    name = "vec3",
    hdrs = ["include/vec3.h"],
    srcs = ["src/vec3.cc"],
    copts = [
      "-Werror",
      "-std=c++11",
    ],
    visibility = ["//visibility:public"],
)

cc_test(
    name = "vec3_test",
    deps = [
        ":vec3",
    ],
    copts = [
      "-Werror",
      "-std=c++11",
    ],
    srcs = ["src/vec3_test.cc"],
)

cc_binary(
    name = "generate-ppm",
    srcs = ["src/generate-ppm.cc"],
)
