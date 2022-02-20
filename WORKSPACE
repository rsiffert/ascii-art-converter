load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "simd",
  url = "https://github.com/ermig1979/Simd/releases/download/v4.9.105/simd.4.9.105.zip",
  sha256 = "80c725fde30eb249c101dc96ef3750875c273fe9c98868b92452efe1fc636296",
  build_file = "//deps:BUILD.simd",
  strip_prefix = "simd"
)

http_archive(
  name = "FreeImage",
  url = "https://sourceforge.net/projects/freeimage/files/Source%20Distribution/3.18.0/FreeImage3180.zip",
  sha256 = "f41379682f9ada94ea7b34fe86bf9ee00935a3147be41b6569c9605a53e438fd",
  build_file = "//deps:BUILD.FreeImage",
  strip_prefix = "FreeImage"
)
