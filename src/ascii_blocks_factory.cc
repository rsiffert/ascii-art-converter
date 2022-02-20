#include "ascii_blocks_factory.h"

namespace ascii_art_converter {

AsciiBlocksFactory::AsciiBlocksFactory() : ascii_blocks_() {}

const std::vector<AsciiBlock>& AsciiBlocksFactory::CreateAsciiBlocks(
    uint16_t block_width_in_pix, uint16_t block_height_in_pix,
    size_t font_size) {
  ascii_blocks_.clear();

  for (char ascii_char = ' '; ascii_char <= '~'; ascii_char++) {
    AsciiBlock ascii_block(ascii_char, block_width_in_pix, block_height_in_pix,
                           font_size);
    ascii_blocks_.push_back(ascii_block);
  }
  return ascii_blocks_;
}

AsciiBlocksFactory::~AsciiBlocksFactory() {}

}  // namespace ascii_art_converter
