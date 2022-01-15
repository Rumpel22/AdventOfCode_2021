#include "input_25.h"

#include <iostream>

struct Map
{
    std::vector<bool> fields;
    const size_t height;
    const size_t width;

    Map(const std::vector<std::string> &input, char c) : height(input.size()),
                                                         width(input[0].size())
    {
        fields.reserve(height * width);
        for (const auto &line : input)
        {
            for (const char ch : line)
            {
                fields.push_back(c == ch);
            }
        }
    }
};

bool move(Map &movers, const Map &standingStill, bool goingEast)
{
    auto newFields = std::vector(movers.fields.size(), false);
    bool moved = false;

    for (size_t y = 0; y < movers.height; ++y)
    {
        const size_t newY = goingEast ? y : ((y + 1) % movers.height);
        const size_t newOffset = newY * movers.width;
        const size_t offset = y * movers.width;
        for (size_t x = 0; x < movers.width; ++x)
        {
            const size_t index = offset + x;
            if (!movers.fields[index])
            {
                continue;
            }

            const size_t newX = goingEast ? ((x + 1) % movers.width) : x;
            const size_t newIndex = newOffset + newX;
            if (!movers.fields[newIndex] && !standingStill.fields[newIndex])
            {
                newFields[newIndex] = true;
                moved = true;
            }
            else
            {
                newFields[index] = true;
            }
        }
    }
    movers.fields = std::move(newFields);
    return moved;
}

int main(int, char **)
{
    Map south(input, 'v');
    Map east(input, '>');

    unsigned long long counter = 0;
    while (true)
    {
        ++counter;

        bool moved = false;
        moved |= move(east, south, true);
        moved |= move(south, east, false);
        if (!moved)
        {
            break;
        }
    }
    std::cout << "There is a full stop after " << counter << " iterations." << std::endl;
}
