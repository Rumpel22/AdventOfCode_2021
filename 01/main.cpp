#include "input_1.h"

#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>

int main(int, char **)
{
    std::vector<int> differences;
    std::adjacent_difference(std::begin(depths), std::end(depths), std::back_inserter(differences));
    std::cout << std::count_if(std::next(std::begin(differences)), std::end(differences), [](int a)
                               { return a > 0; })
              << std::endl;

    std::vector<int> sums;
    for (auto iter = std::begin(depths); iter < std::end(depths) - 2; iter++)
    {
        sums.emplace_back(*iter + *(iter + 1) + *(iter + 2));
    }

    differences.clear();
    std::adjacent_difference(std::begin(sums), std::end(sums), std::back_inserter(differences));
    std::cout << std::count_if(std::next(std::begin(differences)), std::end(differences), [](int a)
                               { return a > 0; })
              << std::endl;
}
