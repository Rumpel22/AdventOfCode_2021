#include "input_7.h"

#include <iostream>
#include <algorithm>
#include <numeric>

int main(int, char **)
{
    std::vector<int> positions = positions_org;
    std::sort(positions.begin(), positions.end());
    int linear_value = 0;
    auto left = positions.begin();
    auto right = positions.rbegin();
    while (left < right.base())
    {
        linear_value += (*right - *left);
        ++right;
        ++left;
    }

    std::cout << "With linear fuel consumption: " << linear_value << std::endl;

    const double exact_x = std::accumulate(positions.begin(), positions.end(), 0.0) / positions.size();
    const int upper_x = static_cast<int>(std::ceil(exact_x));
    const int lower_x = static_cast<int>(std::floor(exact_x));

    int upper_value = 0;
    int lower_value = 0;
    std::cout << "Exact x = " << exact_x << std::endl;
    for (auto position : positions)
    {
        const int upper_difference = std::abs(position - static_cast<int>(upper_x));
        const int lower_difference = std::abs(position - static_cast<int>(lower_x));
        upper_value += (upper_difference * (upper_difference + 1) / 2);
        lower_value += (lower_difference * (lower_difference + 1) / 2);
    }
    const int exp_x = upper_value < lower_value ? upper_x : lower_x;
    const int exp_value = upper_value < lower_value ? upper_value : lower_value;
    std::cout << "Used x-position: " << exp_x << '\n'
              << "With exponential fuel consumption: " << exp_value << std::endl;
}
