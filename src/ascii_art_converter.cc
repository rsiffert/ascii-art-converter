#include "ascii_art_converter.h"

#include "Simd/SimdFont.hpp"
#include "Simd/SimdLib.hpp"
#include "ascii_block.h"
#include "ascii_blocks_factory.h"
#include "bitmap_image.h"

namespace ascii_art_converter {

void Run(std::filesystem::path input_filename,
         std::filesystem::path output_filename, uint16_t block_width_in_pix,
         uint16_t block_height_in_pix, size_t font_size) {
  BitmapImage input_image(input_filename);
  AsciiBlocksFactory ascii_blocks_factory;
  const std::vector<AsciiBlock> &ascii_blocks =
      ascii_blocks_factory.CreateAsciiBlocks(block_width_in_pix,
                                             block_height_in_pix, font_size);

  input_image.ConvertToAscii(ascii_blocks, output_filename);
}
}  // namespace ascii_art_converter
