#ifndef ASCII_ART_CONVERTER_SRC_ASCII_BLOCKS_FACTORY
#define ASCII_ART_CONVERTER_SRC_ASCII_BLOCKS_FACTORY

#include <cstdint>
#include <vector>

#include "ascii_block.h"

namespace ascii_art_converter {

class AsciiBlocksFactory {
 public:
  AsciiBlocksFactory();
  virtual ~AsciiBlocksFactory();

  const std::vector<AsciiBlock>& CreateAsciiBlocks(uint16_t block_width_in_pix,
                                                   uint16_t block_height_in_pix,
                                                   size_t font_size);

 private:
  std::vector<AsciiBlock> ascii_blocks_;
};

}  // namespace ascii_art_converter

#endif  // ASCII_ART_CONVERTER_SRC_ASCII_BLOCKS_FACTORY
