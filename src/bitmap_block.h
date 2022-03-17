#ifndef ASCII_ART_CONVERTER_SRC_BITMAP_BLOCK
#define ASCII_ART_CONVERTER_SRC_BITMAP_BLOCK

#include "common.h"
#include "ascii_block.h"

namespace ascii_art_converter {

class BitmapBlock {
 public:
  BitmapBlock(SimdView contents);
  char ClosestAsciiCharacter(const std::vector<ascii_art_converter::AsciiBlock> ascii_blocks) const;

  virtual ~BitmapBlock();

 private:
  SimdView contents_;
};
}  // namespace ascii_art_converter

#endif  // ASCII_ART_CONVERTER_SRC_BITMAP_BLOCK
