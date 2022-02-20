#include <iostream>
#include <sstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <filesystem>

#include "Simd/SimdFont.hpp"
#include "Simd/SimdLib.hpp"
#include "ascii_block.h"
#include "ascii_blocks_factory.h"
#include "bitmap_image.h"

using namespace ascii_art_converter;

static void usage() {
  std::cout << "Usage: ascii_art_converter <input_file> <output_file>";
};

constexpr int kInFileArgPos = 1;
constexpr int kOutFileArgPos = 2;

bool arguments_are_correct(int argc, char* argv[]) {
  return argc == 3 &&
         std::filesystem::exists(std::filesystem::path(argv[kInFileArgPos]));
}

int main(int argc, char* argv[]) {
  constexpr uint16_t kBlockWidthInPix = 3;
  constexpr uint16_t kBlockHeightInPix = 5;
  constexpr size_t kFontSize = 4;

  if (arguments_are_correct(argc, argv)) {
    std::filesystem::path input_filename(argv[kInFileArgPos]);
    std::filesystem::path output_filename(argv[kOutFileArgPos]);

    BitmapImage input_image(input_filename);
    AsciiBlocksFactory ascii_blocks_factory;
    const std::vector<AsciiBlock>& ascii_blocks =
        ascii_blocks_factory.CreateAsciiBlocks(kBlockWidthInPix,
                                               kBlockHeightInPix, kFontSize);

    input_image.ConvertToAscii(ascii_blocks, output_filename);

    return EXIT_SUCCESS;

  } else {
    usage();
    return EXIT_FAILURE;
  }
}