A simple ASCII art converter which main purpose is to experiment with Bazel.

# Dependencies

* Bazel build tool: https://bazel.build
* C++ compiler:
  * Visual C++ on Windows - tested with Visual Studio 2019 Build Tools 
  * GCC on Linux

# How-tos

## Build
With bazel in the PATH from the root directory:
bazel build --enable_platform_specific_config ascii_art_converter

## Run
With bazel in the PATH from the root directory:
bazel run --enable_platform_specific_config ascii_art_converter -- <input_image> <output_file>

Example with the provided test image: bazel run --enable_platform_specific_config ascii_art_converter -- [ascii_converter_path]/res/toronto.jpg [ascii_converter_path]/res/toronto.txt

**Note: On Windows you may have to set the BAZEL_VC environment variable to the *VC* folder inside of the Visual Studio Build Tools**

