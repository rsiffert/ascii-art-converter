cc_binary(
  name = "ascii_art_converter",
  srcs = [
          "inc/ascii_block.h",
          "src/ascii_block.cc",
          "inc/ascii_blocks_factory.h",
          "src/ascii_blocks_factory.cc",
          "inc/bitmap_block.h",
          "src/bitmap_block.cc",
          "inc/bitmap_image.h",
          "src/bitmap_image.cc",
          "src/main.cc"
         ],
  deps = ["@simd//:simd"],
  includes = ["inc"],
  linkstatic = False,
  copts = select({
              "@bazel_tools//src/conditions:windows": ["/std:c++17"],
              "//conditions:default": []
          })
)