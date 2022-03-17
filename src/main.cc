#include <iostream>
#include <sstream>
#include <vector>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include <filesystem>

#include "ascii_art_converter.h"

using namespace ascii_art_converter;

static void PrintUsage() {
	std::cout << "Usage: ascii_art_converter <input_file> <output_file>";
}

constexpr int kInFileArgPos = 1;
constexpr int kOutFileArgPos = 2;

bool ArgumentsAreCorrect(int argc, char *argv[]) {
	return argc == 3
			&& std::filesystem::exists(
					std::filesystem::path(argv[kInFileArgPos]));
}

int main(int argc, char *argv[]) {
	constexpr uint16_t kBlockWidthInPix = 2;
	constexpr uint16_t kBlockHeightInPix = 3;
	constexpr size_t kFontSize = 5;

	if (ArgumentsAreCorrect(argc, argv)) {
		std::filesystem::path input_filename(argv[kInFileArgPos]);
		std::filesystem::path output_filename(argv[kOutFileArgPos]);

		Run(input_filename, output_filename, kBlockWidthInPix, kBlockHeightInPix, kFontSize);

		return EXIT_SUCCESS;

	} else {
		PrintUsage();
		return EXIT_FAILURE;
	}
}
