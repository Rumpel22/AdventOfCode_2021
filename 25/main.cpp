#include "input_25.h"

#include <iostream>

using boolMap = std::vector<std::vector<bool>>;

boolMap getBoolMap(const std::vector<std::string> &input, char c)
{
    boolMap map;
    for (const auto &line : input)
    {
        map.push_back({});
        auto &current = map.back();
        for (const char ch : line)
        {
            current.push_back(c == ch);
        }
    }
    return map;
}

boolMap move(const boolMap &movers, const boolMap &standingStill, bool goingEast)
{
    boolMap newSituation = boolMap(movers.size(), std::vector<bool>(movers[0].size(), false));
    for (size_t y = 0; y < movers.size(); ++y)
    {
        size_t newY = goingEast ? y : ((y + 1) % movers.size());
        for (size_t x = 0; x < movers[0].size(); ++x)
        {
            if (!movers[y][x])
            {
                continue;
            }
            size_t newX = goingEast ? ((x + 1) % movers[0].size()) : x;
            if (!movers[newY][newX] && !standingStill[newY][newX])
            {
                newSituation[newY][newX] = true;
            }
            else
            {
                newSituation[y][x] = true;
            }
        }
    }
    return newSituation;
}

int main(int, char **)
{
    boolMap south = getBoolMap(input, 'v');
    boolMap east = getBoolMap(input, '>');

    unsigned long long counter = 0;
    while (true)
    {
        ++counter;

        auto newEast = move(east, south, true);
        auto newSouth = move(south, newEast, false);
        if (newEast == east && newSouth == south)
        {
            break;
        }
        east = std::move(newEast);
        south = std::move(newSouth);
    }
    std::cout << "There is a full stop after " << counter << " iterations." << std::endl;
}
