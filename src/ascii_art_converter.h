#ifndef ASCII_ART_CONVERTER_SRC_ASCII_CONVERTER
#define ASCII_ART_CONVERTER_SRC_ASCII_CONVERTER

#include <cstdint>
#include <filesystem>

namespace ascii_art_converter {

void Run(std::filesystem::path input_filename,
         std::filesystem::path output_filename, uint16_t block_width_in_pix,
         uint16_t block_height_in_pix, size_t font_size);

}  // namespace ascii_art_converter

#endif  // ASCII_ART_CONVERTER_SRC_ASCII_CONVERTER
