#ifndef ASCII_ART_CONVERTER_SRC_BITMAP_IMAGE
#define ASCII_ART_CONVERTER_SRC_BITMAP_IMAGE

#include <filesystem>
#include <map>
#include <vector>

#include "Simd/SimdView.hpp"
#include "ascii_block.h"
#include "bitmap_block.h"

namespace ascii_art_converter {

class BitmapImage {
 public:
  BitmapImage(std::filesystem::path path);

  void ConvertToAscii(const std::vector<AsciiBlock>& ref_ascii_blocks,
                      const std::filesystem::path& output_filename);

  virtual ~BitmapImage();

 private:
  typedef uint64_t row_idx;
  typedef uint64_t col_idx;
  typedef std::pair<row_idx, col_idx> BlockCoordinate; 
  typedef std::map<BlockCoordinate, BitmapBlock> BitmapBlockMap;
  typedef std::map<BlockCoordinate, char> AsciiCharMap;

  SimdView full_img_;
  BitmapBlockMap bitmap_blocks_;
  AsciiCharMap ascii_blocks_;
  const std::vector<AsciiBlock> *ref_ascii_blocks_;

  void Blockify();
  void ConvertBlocksToAsciiBlocks();
  void DumpAsciiBlocksAsImage();
  void DumpAsciiBlocksAsTxt(const std::filesystem::path& output_filename);
};
}  // namespace ascii_art_converter

#endif  // ASCII_ART_CONVERTER_SRC_BITMAP_IMAGE
