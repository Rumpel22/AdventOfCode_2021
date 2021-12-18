#include "input_17.h"

#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

std::pair<bool, int> tryTrajetory(int v_x, int v_y)
{
    int x = 0;
    int y = 0;
    int max_y = 0;

    if (v_y >= 0)
    {
        int nb_steps = v_y * 2 + 1;
        int v_x_new = std::max(0, v_x - nb_steps);
        x = v_x * (v_x + 1) / 2 - v_x_new * (v_x_new + 1) / 2;
        v_x = v_x_new;

        max_y = (v_y) * (v_y + 1) / 2;
        v_y = (-v_y) - 1;
    }
    while (true)
    {
        x += v_x;
        if (v_x > 0)
        {
            --v_x;
        }
        else if (v_x < 0)
        {
            ++v_x;
        }

        y += v_y;
        --v_y;
        if (x >= targetArea.x_min && x <= targetArea.x_max && y >= targetArea.y_min && y <= targetArea.y_max)
        {
            return {true, max_y};
        }
        if (x > targetArea.x_max || y < targetArea.y_min)
        {
            return {false, 0};
        }
    }
}

int getV_x_min()
{
    return static_cast<int>(std::ceil((std::sqrt(1 + 8 * targetArea.x_min) - 1) / 2));
}

int main(int, char **)
{
    int max_y = 0;
    size_t nbPairs = 0;

    for (int v_x = getV_x_min(); v_x <= targetArea.x_max; ++v_x)
    {
        for (int v_y = targetArea.y_min; v_y < (-targetArea.y_min); ++v_y)
        {
            std::pair<bool, int> result = tryTrajetory(v_x, v_y);
            if (result.first)
            {
                ++nbPairs;
                max_y = std::max(max_y, result.second);
            }
        }
    }

    std::cout << "The maximum height is " << max_y << std::endl;
    std::cout << "There are " << nbPairs << " different velocities matching the target area." << std::endl;
}