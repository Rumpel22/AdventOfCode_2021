#include "input_2.h"

#include <assert.h>
#include <iostream>

int main(int, char **)
{
    int depth_1 = 0;
    int position_1 = 0;

    int depth_2 = 0;
    int position_2 = 0;
    int aim_2 = 0;
    for (const auto &move : movements)
    {
        switch (move.first)
        {
        case forward:
            position_1 += move.second;
            position_2 += move.second;
            depth_2 += aim_2 * move.second;
            break;
        case up:
            depth_1 -= move.second;
            aim_2 -= move.second;
            break;
        case down:
            depth_1 += move.second;
            aim_2 += move.second;
            break;
        default:
            assert(false && "Should never happen");
        }
    }
    std::cout << "Position: " << position_1 << '\n'
              << "Depth: " << depth_1 << '\n'
              << "Product: " << position_1 * depth_1 << "\n\n"
              << "Position: " << position_2 << '\n'
              << "Depth: " << depth_2 << '\n'
              << "Product: " << position_2 * depth_2 << std::endl;
}
