#include "input_14.h"
#include <algorithm>
#include <iostream>

int main(int, char **)
{
    std::string polymer = polymer_template;
    for (unsigned int i = 0; i < 40; ++i)
    {
        for (size_t pos = 0; pos < polymer.size() - 1; ++pos)
        {
            char c1 = polymer[pos];
            char c2 = polymer[pos + 1];
            if (insertions.contains({c1, c2}))
            {
                char insert = insertions.at({c1, c2});
                polymer.insert(pos + 1, 1, insert);
                pos++;
            }
        }
    }
    std::map<char, size_t> charCount;
    for (char c : polymer)
    {
        charCount[c]++;
    }

    auto minmax = std::minmax_element(std::begin(charCount), std::end(charCount), [](const std::pair<char, size_t> &a, const std::pair<char, size_t> &b)
                                      { return a.second < b.second; });
    size_t min = (*minmax.first).second;
    size_t max = (*minmax.second).second;
    std::cout << "Difference is " << (max - min) << std::endl;
}
