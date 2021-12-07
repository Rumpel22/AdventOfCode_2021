#include "input_6.h"

#include <iostream>
#include <array>
#include <numeric>

using FishCounterPerAge = std::array<unsigned long long, 9>;

int main(int, char **)
{
    FishCounterPerAge fishesPerAge = {};
    for (const int fish : lanternFishes)
    {
        fishesPerAge[fish]++;
    }

    for (unsigned int day = 1; day <= 256; day++)
    {
        FishCounterPerAge fishesPerAge_new = {};
        for (int i = 1; i <= 8; i++)
        {
            fishesPerAge_new[i - 1] = fishesPerAge[i];
        }
        fishesPerAge_new[6] += fishesPerAge[0];
        fishesPerAge_new[8] = fishesPerAge[0];

        fishesPerAge = fishesPerAge_new;
        if (day == 80 || day == 256)
        {
            unsigned long long nbFishes = std::accumulate(fishesPerAge.begin(), fishesPerAge.end(), 0ull);
            std::cout << "Lanternfishes after " << day << " days: " << nbFishes << std::endl;
        }
    }
}
