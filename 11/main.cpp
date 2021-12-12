#include "input_11.h"

#include <iostream>
#include <set>

int main(int, char **)
{
    size_t flashCount = 0;
    auto field = field_org;
    int step;
    bool alltogether = false;
    for (step = 0; !alltogether; step++)
    {
        for (size_t y = 0; y < field.height; y++)
        {
            for (size_t x = 0; x < field.width; x++)
            {
                field.get(x, y)++;
            }
        }
        std::set<std::pair<size_t, size_t>> flashingOctopuses;
        bool isAnyFlashing = false;
        do
        {
            isAnyFlashing = false;
            for (size_t y = 0; y < field.height; y++)
            {
                for (size_t x = 0; x < field.width; x++)
                {
                    if (field.get(x, y) >= 10 && !flashingOctopuses.contains({x, y}))
                    {
                        auto neighbours = field.getNeighbours(x, y);
                        for (auto neighbour : neighbours)
                        {
                            ++(*neighbour);
                        }
                        flashingOctopuses.insert(std::pair<size_t, size_t>(x, y));
                        isAnyFlashing = true;
                    }
                }
            }
        } while (isAnyFlashing);

        if (step < 100)
        {
            flashCount += flashingOctopuses.size();
        }
        for (auto [x, y] : flashingOctopuses)
        {
            field.get(x, y) = 0;
        }
        if (flashingOctopuses.size() == field.height * field.width)
        {
            alltogether = true;
        }
    }
    std::cout << "Flash count after 100 steps: " << flashCount << std::endl;
    std::cout << "All octopuses flash together in step " << step << std::endl;
}
