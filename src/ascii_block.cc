#include "ascii_block.h"

#include <iostream>
#include <sstream>
#include <cmath>

#include "Simd/SimdFont.hpp"

ascii_art_converter::AsciiBlock::AsciiBlock(char character,
                                            uint16_t width_in_pix,
                                            uint16_t height_in_pix,
                                            size_t font_size)
    : character_(character),
      width_in_pix_(width_in_pix),
      height_in_pix_(height_in_pix), contents_(SimdView(width_in_pix, height_in_pix, SimdView::Gray8)) {

  //Simd::Font font(static_cast<size_t>(round(height_in_pix * 1.33)));
  Simd::Font font(font_size);

  std::stringstream string;
  string << character;

  /*std::cout << "Size of " << character << ":" << font.Measure(string.str()).x << ","
            << font.Measure(string.str()).y << std::endl;*/

  Simd::Pixel::Bgr24 black(0, 0, 0);
  Simd::Pixel::Bgr24 white(255, 255, 255);

  SimdView black_char_on_white_bgd(
      Simd::Point<ptrdiff_t>(width_in_pix, height_in_pix), SimdView::Bgr24);
  Simd::DrawFilledRectangle(
      black_char_on_white_bgd,
      Simd::Rectangle<ptrdiff_t>(0, 0, width_in_pix, height_in_pix), white);

  std::string charToDraw(1, character);
  font.Draw(black_char_on_white_bgd, charToDraw,
            SimdView::MiddleLeft, black);

  Simd::BgrToGray(black_char_on_white_bgd, contents_);

  //std::stringstream filename;
  //filename << "D:\\Users\\RS\\code\\ascii-art-converter\\res\\test_"
  //         << (int)character << ".png ";

  //contents_.Save(filename.str());
}

ascii_art_converter::AsciiBlock::~AsciiBlock() {
  contents_.Clear(); }

uint16_t ascii_art_converter::AsciiBlock::WidthInPix() const {
  return width_in_pix_;
}

uint16_t ascii_art_converter::AsciiBlock::HeightInPix() const {
  return height_in_pix_;
}

char ascii_art_converter::AsciiBlock::Character() const {
  return character_; }

uint64_t ascii_art_converter::AsciiBlock::Distance(const SimdView &to) const {
  assert(to.height == contents_.height && to.width == contents_.width &&
         to.format == contents_.format && to.format == SimdView::Gray8);

  uint64_t distance;

  Simd::AbsDifferenceSum(contents_, to, distance);
  //Simd::SquaredDifferenceSum(contents_, to, distance);

  return distance;
}
