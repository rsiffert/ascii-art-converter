#ifndef ASCII_ART_CONVERTER_SRC_ASCII_BLOCK
#define ASCII_ART_CONVERTER_SRC_ASCII_BLOCK

#include <cstdint>
#define _USE_MATH_DEFINES
#include <cmath>

#include "Simd/SimdLib.hpp"

#include "common.h"

namespace ascii_art_converter {

class AsciiBlock {
 public:
  AsciiBlock(char character, uint16_t width_in_pix, uint16_t height_in_pix, size_t font_size);
  virtual ~AsciiBlock();

  uint16_t WidthInPix() const;
  uint16_t HeightInPix() const;
  char Character() const;

  uint64_t Distance(const SimdView &to) const;

 private:

  char character_;
  uint16_t width_in_pix_;
  uint16_t height_in_pix_;
  SimdView contents_;
};

}  // namespace ascii_art_converter

#endif  // ASCII_ART_CONVERTER_SRC_ASCII_BLOCK