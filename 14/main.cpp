#include "input_14.h"
#include <algorithm>
#include <iostream>

int main(int, char **)
{
    std::map<std::string, size_t> pairCount;

    for (size_t pos = 0; pos < polymer_template.size() - 1; ++pos)
    {
        pairCount[polymer_template.substr(pos, 2)]++;
    }
    for (unsigned int i = 0; i < 40; i++)
    {
        std::map<std::string, size_t> newPairCount;
        for (auto [pair, size] : pairCount)
        {
            if (insertions.contains(pair))
            {
                char newChar = insertions.at(pair);
                std::string newPair1 = {pair[0], newChar};
                std::string newPair2 = {newChar, pair[1]};
                newPairCount[newPair1] += size;
                newPairCount[newPair2] += size;
            }
            else
            {
                newPairCount[pair] = size;
            }
        }
        pairCount = newPairCount;
    }

    std::map<char, size_t> charCount;
    for (auto [pair, size] : pairCount)
    {
        charCount[pair[0]] += size;
        charCount[pair[1]] += size;
    }

    // First and last characters are just in one pair => increase it, as if they were in two "pairs", too.
    charCount[polymer_template.front()]++;
    charCount[polymer_template.back()]++;

    auto minmax = std::minmax_element(std::begin(charCount), std::end(charCount), [](const std::pair<char, size_t> &a, const std::pair<char, size_t> &b)
                                      { return a.second < b.second; });

    // Each character of the string is in two pairs => divide by two
    size_t min = (*minmax.first).second / 2;
    size_t max = (*minmax.second).second / 2;
    std::cout << "Difference is " << (max - min) << std::endl;
}
