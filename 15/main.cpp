#include "input_15.h"

#include <algorithm>
#include <iostream>
#include <map>

struct Field
{
    size_t x;
    size_t y;

    auto operator<=>(const Field &rhs) const = default;
};

void insert(std::map<Field, unsigned int> &frontier, const Field &field, unsigned int prevRisk)
{
    if (!frontier.contains(field))
    {
        frontier[field] = std::numeric_limits<unsigned int>::max();
    }
    else if (frontier[field] == std::numeric_limits<unsigned int>::max())
    {
        return;
    }
    frontier.at(field) = std::min(frontier.at(field), prevRisk + risks[field.y][field.x]);
}

int main(int, char **)
{
    const size_t map_height = risks.size();
    const size_t map_width = risks[0].size();
    const Field endPosition = {map_width - 1, map_height - 1};

    std::map<Field, unsigned int> frontier;
    Field currentPosition = {0, 0};
    frontier[currentPosition] = 0;
    while (currentPosition != endPosition)
    {
        unsigned int currentRisk = frontier[currentPosition];
        if (currentPosition.x > 0)
        {
            insert(frontier, {currentPosition.x - 1, currentPosition.y}, currentRisk);
        }
        if (currentPosition.x < map_width - 1)
        {
            insert(frontier, {currentPosition.x + 1, currentPosition.y}, currentRisk);
        }
        if (currentPosition.y > 0)
        {
            insert(frontier, {currentPosition.x, currentPosition.y - 1}, currentRisk);
        }
        if (currentPosition.y < map_height - 1)
        {
            insert(frontier, {currentPosition.x, currentPosition.y + 1}, currentRisk);
        }
        frontier[currentPosition] = std::numeric_limits<unsigned int>::max();

        auto iter = *std::min_element(std::begin(frontier), std::end(frontier), [](const std::pair<Field, size_t> &a, const std::pair<Field, size_t> &b)
                                      { return a.second < b.second; });
        currentPosition = iter.first;
    }
    std::cout << "Total risk at the end: " << frontier[currentPosition] << std::endl;
}
