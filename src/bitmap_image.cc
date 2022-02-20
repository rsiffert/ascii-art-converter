#include "bitmap_image.h"

#include <sstream>
#include <iostream>

#include "Simd/SimdLib.hpp"

namespace ascii_art_converter {

BitmapImage::BitmapImage(std::filesystem::path path)
    : full_img_(),
      bitmap_blocks_(),
      ascii_blocks_(),
      ref_ascii_blocks_(nullptr) {
  full_img_.Load(path.string(), SimdView::Gray8);
}

void BitmapImage::Blockify() {
  // TODO handle images with sizes not divisible by the block sizes
  const uint16_t block_height_in_pix = ref_ascii_blocks_->front().HeightInPix();
  const uint16_t block_width_in_pix = ref_ascii_blocks_->front().WidthInPix();

  uint64_t num_vert_blocks = full_img_.height / block_height_in_pix;
  uint64_t num_hor_blocks = full_img_.width / block_width_in_pix;

  for (uint64_t vert_block_idx = 0; vert_block_idx < num_vert_blocks;
       vert_block_idx++) {
    for (uint64_t hor_block_idx = 0; hor_block_idx < num_hor_blocks;
         hor_block_idx++) {
      ptrdiff_t top_pos_in_pix = vert_block_idx * block_height_in_pix;
      ptrdiff_t left_pos_in_pix = hor_block_idx * block_width_in_pix;
      ptrdiff_t right_pos_in_pix = (hor_block_idx + 1) * block_width_in_pix;
      ptrdiff_t bottom_pos_in_pix = (vert_block_idx + 1) * block_height_in_pix;

      bitmap_blocks_.insert(std::pair<BlockCoordinate, BitmapBlock>(
          BlockCoordinate(vert_block_idx, hor_block_idx),
          BitmapBlock(full_img_.Region(left_pos_in_pix, top_pos_in_pix,
                                       right_pos_in_pix, bottom_pos_in_pix))));

      // std::stringstream filename;
      // filename << "D:\\Users\\RS\\code\\ascii-art-converter\\res\\block_"
      //         << vert_block_idx << "_" << hor_block_idx << ".png ";

      // blocks_.back().Save(filename.str());
    }
  }
}

void BitmapImage::ConvertToAscii(
    const std::vector<AsciiBlock>& ref_ascii_blocks, const std::filesystem::path& output_filename) {
  ref_ascii_blocks_ = &ref_ascii_blocks;
  bitmap_blocks_.clear();
  ascii_blocks_.clear();

  Blockify();
  ConvertBlocksToAsciiBlocks();
  DumpAsciiBlocksAsImage();
  DumpAsciiBlocksAsTxt(output_filename);
}

void BitmapImage::DumpAsciiBlocksAsImage() {}

void BitmapImage::DumpAsciiBlocksAsTxt(const std::filesystem::path& output_filename) {
  // TODO make this common
  const uint16_t block_height_in_pix = ref_ascii_blocks_->front().HeightInPix();
  const uint16_t block_width_in_pix = ref_ascii_blocks_->front().WidthInPix();

  uint64_t num_vert_blocks = full_img_.height / block_height_in_pix;
  uint64_t num_hor_blocks = full_img_.width / block_width_in_pix;

  std::ostringstream ascii_blocks_as_txt;

  for (uint64_t row_block_idx = 0; row_block_idx < num_vert_blocks;
       row_block_idx++) {
    for (uint64_t hor_block_idx = 0; hor_block_idx < num_hor_blocks;
         hor_block_idx++) {

      const char character =
          ascii_blocks_.at(BlockCoordinate(row_block_idx, hor_block_idx));

      //std::cout << (int)character << std::endl;

      ascii_blocks_as_txt << character;
    }
    ascii_blocks_as_txt << '\n';
  }

  std::ofstream output_file;
  output_file.open(output_filename,
                   std::ofstream::out);

  output_file << ascii_blocks_as_txt.str() << std::endl;

  output_file.close();
}

void BitmapImage::ConvertBlocksToAsciiBlocks() {
  for (auto block_it = bitmap_blocks_.begin(); block_it != bitmap_blocks_.end();
       block_it++) {
    const char closest_ascii_char =
        block_it->second.ClosestAsciiCharacter(*ref_ascii_blocks_);

    //std::cout << "closest_ascii_char for " << block_it->first.first << "," << block_it->first.second << " is "
    //          << closest_ascii_char << std::endl;

    ascii_blocks_.insert(std::pair<BlockCoordinate, char>(block_it->first, closest_ascii_char));
  }
}

BitmapImage::~BitmapImage() {
  full_img_.Release();
  // TODO clear bitmap blocks?
  /*for (auto block_it = bitmap_blocks_.begin(); block_it !=
    bitmap_blocks_.end(); block_it++) { block_it->Release();
  */
}
}  // namespace ascii_art_converter
