platform(
    name = "linux-x86_64",
    constraint_values = [
        "@platforms//os:linux",
        "@platforms//cpu:x86_64"
    ]
)

platform(
    name = "windows-x86_64",
    constraint_values = [
        "@platforms//os:windows",
        "@platforms//cpu:x86_64"
    ]
)

cc_binary(
  name = "ascii_art_converter",
  srcs = [
          "src/ascii_block.h",
          "src/ascii_block.cc",
          "src/ascii_blocks_factory.h",
          "src/ascii_blocks_factory.cc",
          "src/common.h",
          "src/bitmap_block.h",
          "src/bitmap_block.cc",
          "src/bitmap_image.h",
          "src/bitmap_image.cc",
          "src/ascii_art_converter.h",
          "src/ascii_art_converter.cc",
          "src/main.cc"
         ],
  deps = ["@simd//:simd"],
  copts = select ({
  			"@platforms//os:windows":
  				[
  					"/std:c++17"
				],
			"@platforms//os:linux":
				[
					"-std=c++17",
					"-m64"
				],
			"//conditions:default": []
  		}),
  linkstatic = False
)