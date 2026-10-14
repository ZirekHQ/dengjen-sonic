# Sonic is a library for speeding up or slowing down speech without changing
# the pitch.
package(
    default_applicable_licenses = ["//third_party/sonic:license"],
)

licenses(["notice"])

cc_library(
    name = "genwave_lib",
    srcs = ["genwave.c"],
    hdrs = ["genwave.h"],
    copts = [
        "-D GOOGLE_BUILD",
    ],
    deps = ["//third_party/sonic:sonic_internal_lib_fftw"],
)

cc_test(
    name = "sonic_unit_test",
    srcs = [
        "chord_pitch_test.c",
        "input_clamping_test.c",
        "pitch_position_test.c",
        "slowdown_flush_test.c",
        "sonic_api_test.c",
        "sonic_unit_test.cc",
        "stream_resize_test.c",
        "tests.h",
    ],
    copts = [
        "-D GOOGLE_BUILD",
    ],
    deps = [
        ":genwave_lib",
        "//testing/base/public:gunit_main",
        "//third_party/sonic:sonic_classic_lib_fftw",
    ],
)
