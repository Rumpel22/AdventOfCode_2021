#include "input_13.h"

#include <algorithm>
#include <iostream>

using Map = std::vector<std::vector<bool>>;

Map parseMap(const Coordinates &coordinates)
{
    size_t max_x = (*std::max_element(std::begin(coordinates), std::end(coordinates), [](const Coordinate &a, const Coordinate &b)
                                      { return a.first < b.first; }))
                       .first;
    size_t max_y = (*std::max_element(std::begin(coordinates), std::end(coordinates), [](const Coordinate &a, const Coordinate &b)
                                      { return a.second < b.second; }))
                       .second;

    Map map = std::vector(max_y + 1, std::vector(max_x + 1, false));

    for (auto [x, y] : coordinates)
    {
        map[y][x] = true;
    }

    return map;
}

size_t countDots(const Map &map)
{
    size_t count = 0;
    for (const auto &row : map)
    {
        for (const auto &field : row)
        {
            if (field)
            {
                ++count;
            }
        }
    }
    return count;
}

int main(int, char **)
{
    Map map = parseMap(coordinates);

    for (auto fold : folds)
    {
        const size_t old_x = map[0].size();
        const size_t old_y = map.size();

        const size_t new_x = fold.first == 'x' ? fold.second : old_x;
        const size_t new_y = fold.first == 'y' ? fold.second : old_y;

        Map newMap = std::vector(new_y, std::vector(new_x, false));
        for (size_t y = 0; y < old_y; ++y)
        {
            if (fold.first == 'y' && y == new_y)
            {
                continue;
            }
            for (size_t x = 0; x < old_x; ++x)
            {
                if (fold.first == 'x' && x == new_x)
                {
                    continue;
                }
                size_t set_x = (x < new_x ? x : new_x - (x - new_x));
                size_t set_y = (y < new_y ? y : new_y - (y - new_y));
                newMap[set_y][set_x] = (newMap[set_y][set_x] | map[y][x]);
            }
        }
        map = newMap;

        std::cout << "There are " << countDots(map) << " dots visible" << std::endl;
    }

    for (size_t y = 0; y < map.size(); ++y)
    {
        for (size_t x = 0; x < map[0].size(); ++x)
        {
            std::cout << (map[y][x] ? '*' : ' ');
        }
        std::cout << std::endl;
    }
    // Shows "ZKAUCFUC"
}
