#include "input_20.h"

#include <algorithm>
#include <array>
#include <iostream>

struct Image
{
    Image(size_t height, size_t width, bool unknown) : height(height),
                                                       width(width),
                                                       data(height * width, false),
                                                       unknownPixel(unknown)
    {
    }

    Image(const std::vector<std::string> &image, bool unknown) : height(image.size()),
                                                                 width(image[0].size()),
                                                                 unknownPixel(unknown)
    {
        data.reserve(height * width);
        for (const auto &row : image)
        {
            for (const auto &c : row)
            {
                data.push_back(c == '#');
            }
        }
    }

    bool get(size_t x, size_t y) const
    {
        if (x < 0 || x >= width)
        {
            return unknownPixel;
        }
        if (y < 0 || y >= height)
        {
            return unknownPixel;
        }
        return data[y * width + x];
    }

    void set(size_t x, size_t y, bool value)
    {
        data[y * width + x] = value;
    }

    size_t lightPixels() const
    {
        return std::count_if(std::begin(data), std::end(data), [](bool b)
                             { return b; });
    }
    size_t height;
    size_t width;
    bool unknownPixel;

private:
    std::vector<bool> data;
};

using Algorithm = std::array<bool, 512>;

template <size_t size>
std::array<bool, size> parseString(const std::string &string)
{
    std::array<bool, size> bits;
    std::transform(std::begin(string), std::end(string), std::begin(bits), [](char c)
                   { return c == '#'; });
    return bits;
}

Image applyAlgorithm(const Image &image, const Algorithm &algorithm)
{
    Image newImage(image.height + 2, image.width + 2, algorithm[0] && !image.unknownPixel);
    for (int row = -1; row <= static_cast<int>(image.height); ++row)
    {
        for (int col = -1; col <= static_cast<int>(image.width); ++col)
        {
            unsigned int number = 0;
            number = (number << 1) + image.get(col - 1, row - 1);
            number = (number << 1) + image.get(col, row - 1);
            number = (number << 1) + image.get(col + 1, row - 1);
            number = (number << 1) + image.get(col - 1, row);
            number = (number << 1) + image.get(col, row);
            number = (number << 1) + image.get(col + 1, row);
            number = (number << 1) + image.get(col - 1, row + 1);
            number = (number << 1) + image.get(col, row + 1);
            number = (number << 1) + image.get(col + 1, row + 1);

            newImage.set(col + 1, row + 1, algorithm[number]);
        }
    }
    return newImage;
}

int main(int, char **)
{
    const auto bitEnhancement = parseString<512>(enhancement);
    Image bitImage(image, false);

    for (int i = 0; i < 50; ++i)
    {
        bitImage = applyAlgorithm(bitImage, bitEnhancement);
    }

    size_t lightPixels = bitImage.lightPixels();
    std::cout << "There are " << lightPixels << " pixels lit in the image." << std::endl;
}