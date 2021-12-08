#include "input_8.h"

#include <iostream>
#include <algorithm>

int main(int, char **)
{
    unsigned int searched_digits = 0;
    for (const auto &line : lines)
    {
        const auto &output = line.second;
        searched_digits += std::count_if(output.begin(), output.end(), [](const char *digit)
                                         {
                                             size_t digitLength = strlen(digit);
                                             return digitLength == 2 || digitLength == 3 || digitLength == 4 || digitLength == 7;
                                         });
    }
    std::cout << "Number of searched digits: " << searched_digits << std::endl;
}
