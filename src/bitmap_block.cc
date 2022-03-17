#include "bitmap_block.h"

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <sstream>

namespace ascii_art_converter {

BitmapBlock::BitmapBlock(SimdView contents) :
		contents_(contents) {
}

char BitmapBlock::ClosestAsciiCharacter(
		const std::vector<AsciiBlock> ascii_blocks) const {
	uint64_t min_distance = UINT64_MAX;
	auto closest_ascii_block_it = ascii_blocks.begin();

	for (auto block_it = ascii_blocks.begin(); block_it != ascii_blocks.end();
			block_it++) {
		uint64_t distance_to_current = block_it->Distance(contents_);

		if (distance_to_current < min_distance) {
			min_distance = distance_to_current;
			closest_ascii_block_it = block_it;
		}
	}

	return closest_ascii_block_it->Character();
}

BitmapBlock::~BitmapBlock() {
}

}  // namespace ascii_art_converter
