#include "input_13.h"

#include <algorithm>
#include <iostream>

struct Map
{
    const size_t width;
    const size_t height;

    Map(size_t x, size_t y) : width(x), height(y), map((y + 1) * (x + 1), 0) {}

    int &get(size_t x, size_t y)
    {
        return map.at(width * y + x);
    }

    size_t countDots() const
    {
        return std::count_if(std::begin(map), std::end(map), [](const int x)
                             { return x != 0; });
    }

    Map &operator=(const Map &rhs)
    {
        const_cast<size_t &>(height) = rhs.height;
        const_cast<size_t &>(width) = rhs.width;
        map = rhs.map;
        return *this;
    }

private:
    std::vector<int> map;
};

Map parseMap(const Coordinates &coordinates)
{
    size_t max_x = (*std::max_element(std::begin(coordinates), std::end(coordinates), [](const Coordinate &a, const Coordinate &b)
                                      { return a.first < b.first; }))
                       .first;
    size_t max_y = (*std::max_element(std::begin(coordinates), std::end(coordinates), [](const Coordinate &a, const Coordinate &b)
                                      { return a.second < b.second; }))
                       .second;

    Map map = Map(max_x, max_y);

    for (auto [x, y] : coordinates)
    {
        map.get(x, y) = true;
    }

    return map;
}

int main(int, char **)
{
    Map map = parseMap(coordinates);

    for (auto fold : folds)
    {
        const size_t old_x = map.width;
        const size_t old_y = map.height;

        const size_t new_x = fold.first == 'x' ? fold.second : old_x;
        const size_t new_y = fold.first == 'y' ? fold.second : old_y;

        Map newMap(new_x, new_y);
        for (size_t y = 0; y < old_y; ++y)
        {
            if (fold.first == 'y' && y == new_y)
            {
                continue;
            }

            size_t set_y = (y < new_y ? y : new_y - (y - new_y));
            for (size_t x = 0; x < old_x; ++x)
            {
                if (fold.first == 'x' && x == new_x)
                {
                    continue;
                }
                size_t set_x = (x < new_x ? x : new_x - (x - new_x));
                newMap.get(set_x, set_y) |= map.get(x, y);
            }
        }
        map = newMap;

        std::cout << "There are " << map.countDots() << " dots visible" << std::endl;
    }

    for (size_t y = 0; y < map.height; ++y)
    {
        for (size_t x = 0; x < map.width; ++x)
        {
            std::cout << (map.get(x, y) ? '*' : ' ');
        }
        std::cout << std::endl;
    }
    // Shows "ZKAUCFUC"
}
