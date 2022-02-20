#include "bitmap_block.h"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>

namespace ascii_art_converter {

BitmapBlock::BitmapBlock(SimdView contents) : contents_(contents) {
  //std::stringstream filename;
  //filename << "D:\\Users\\RS\\code\\ascii-art-converter\\res\\block_" << rand()
  //         << ".png ";

  //contents_.Save(filename.str());
}

char BitmapBlock::ClosestAsciiCharacter(
    const std::vector<AsciiBlock> ascii_blocks) const {
  uint64_t min_distance = UINT64_MAX;
  auto closest_ascii_block_it = ascii_blocks.begin();

  for (auto block_it = ascii_blocks.begin(); block_it != ascii_blocks.end();
       block_it++) {
    uint64_t distance_to_current = block_it->Distance(contents_);

    /*std::cout << "Distance " << distance_to_current << " for "
              << block_it->Character() << std::endl;*/

    if (distance_to_current < min_distance) {
      min_distance = distance_to_current;
      closest_ascii_block_it = block_it;
    }
  }

  return closest_ascii_block_it->Character();
}

BitmapBlock::~BitmapBlock() {}

}  // namespace ascii_art_converter