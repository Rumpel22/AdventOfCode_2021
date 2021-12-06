#include "input_6.h"

#include <iostream>

int main(int, char **)
{
    for (unsigned int day = 1; day <= 80; day++)
    {
        std::vector<int> newFishes;
        for (auto &fish : lanternFishes)
        {
            if (fish == 0)
            {
                fish = 6;
                newFishes.push_back(8);
            }
            else
            {
                fish--;
            }
        }
        lanternFishes.insert(lanternFishes.end(), newFishes.begin(), newFishes.end());

        if (day == 80 || day == 256)
        {
            std::cout << "Lanternfishes after " << day << " days: " << lanternFishes.size() << std::endl;
        }
    }
}
