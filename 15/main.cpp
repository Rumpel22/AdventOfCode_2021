#include "input_15.h"

#include <algorithm>
#include <iostream>

unsigned int getRisk(size_t x, size_t y)
{
    unsigned int xFactor = x / risks[0].size();
    unsigned int yFactor = y / risks.size();
    unsigned int orgRisk = risks[y % risks.size()][x % risks[0].size()];
    unsigned int risk = orgRisk + xFactor + yFactor;
    if (risk > 9)
    {
        risk -= 9;
    }
    return risk;
}

struct Field
{
    size_t x;
    size_t y;

    auto operator<=>(const Field &) const = default;
};

void insert(std::vector<std::vector<unsigned int>> &frontier, const Field &field, unsigned int prevRisk)
{
    unsigned int &risk = frontier[field.y][field.x];
    if (risk == std::numeric_limits<unsigned int>::max())
    {
        return;
    }

    unsigned int fieldRisk = getRisk(field.x, field.y);
    if (risk == 0)
    {
        risk = prevRisk + fieldRisk;
    }
    else
    {
        risk = std::min(risk, prevRisk + fieldRisk);
    }
}

int main(int, char **)
{
    const size_t map_height = risks.size() * 5;
    const size_t map_width = risks[0].size() * 5;
    const Field endPosition = {map_width - 1, map_height - 1};

    std::vector<std::vector<unsigned int>> frontier(map_height, std::vector<unsigned int>(map_width, 0));
    Field currentPosition = {0, 0};
    while (currentPosition != endPosition)
    {
        unsigned int currentRisk = frontier[currentPosition.y][currentPosition.x];
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
        frontier[currentPosition.y][currentPosition.x] = std::numeric_limits<unsigned int>::max();

        unsigned int minRisk = std::numeric_limits<unsigned int>::max();
        for (size_t y = 0; y < map_height; ++y)
        {
            for (size_t x = 0; x < map_width; ++x)
            {
                if (frontier[y][x] < minRisk && frontier[y][x] != 0)
                {
                    minRisk = frontier[y][x];
                    currentPosition = {x, y};
                }
            }
        }
    }
    std::cout << "Total risk at the end: " << frontier[currentPosition.y][currentPosition.x] << std::endl;
}
