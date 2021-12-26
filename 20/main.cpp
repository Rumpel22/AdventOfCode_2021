#include "input_20.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>

std::vector<bool> parseString(const std::string &string)
{
    std::vector<bool> bits;
    std::transform(std::begin(string), std::end(string), std::back_insert_iterator(bits), [](char c)
                   { return c == '#'; });
    return bits;
}

bool getPixel(const std::vector<std::vector<bool>> &image, int row, int col, bool unknownPixel)
{
    if (row < 0 || row >= image.size())
    {
        return unknownPixel;
    }
    if (col < 0 || col >= image[row].size())
    {
        return unknownPixel;
    }
    return image[row][col];
}

std::vector<std::vector<bool>> applyAlgorithm(const std::vector<std::vector<bool>> &image, const std::vector<bool> &algorithm, bool unknownPixel)
{
    std::vector<std::vector<bool>> newImage;
    for (int row = -1; row <= static_cast<int>(image.size()); ++row)
    {
        std::vector<bool> newRow;
        for (int col = -1; col <= static_cast<int>(image[0].size()); ++col)
        {
            unsigned int number = 0;
            number = (number << 1) + getPixel(image, row - 1, col - 1, unknownPixel);
            number = (number << 1) + getPixel(image, row - 1, col, unknownPixel);
            number = (number << 1) + getPixel(image, row - 1, col + 1, unknownPixel);
            number = (number << 1) + getPixel(image, row, col - 1, unknownPixel);
            number = (number << 1) + getPixel(image, row, col, unknownPixel);
            number = (number << 1) + getPixel(image, row, col + 1, unknownPixel);
            number = (number << 1) + getPixel(image, row + 1, col - 1, unknownPixel);
            number = (number << 1) + getPixel(image, row + 1, col, unknownPixel);
            number = (number << 1) + getPixel(image, row + 1, col + 1, unknownPixel);

            newRow.push_back(algorithm[number]);
        }
        newImage.push_back(newRow);
    }
    return newImage;
}

int main(int, char **)
{
    std::vector<bool> bitEnhancement = parseString(enhancement);
    std::vector<std::vector<bool>> bitImage;
    std::transform(std::begin(image), std::end(image), std::back_insert_iterator(bitImage), [](const std::string &row)
                   { return parseString(row); });

    for (int i = 0; i < 50; ++i)
    {
        bitImage = applyAlgorithm(bitImage, bitEnhancement, i % 2 != 0);
    }

    size_t lightPixels = std::accumulate(std::begin(bitImage), std::end(bitImage), size_t(0), [](size_t sum, const std::vector<bool> &row)
                                         { return sum + std::count_if(std::begin(row), std::end(row), [](bool b)
                                                                      { return b; }); });
    std::cout << "There are " << lightPixels << " pixels lit in the image." << std::endl;
}