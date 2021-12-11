#include "input_3.h"

#include <vector>
#include <bitset>
#include <iostream>
#include <algorithm>

int main(int, char **)
{
    std::vector<int> bitCounts(size);
    for (int number : data)
    {
        for (int i = 0; i < size; ++i)
        {
            bitCounts[i] += (number & 0x1 ? 1 : -1);
            number >>= 1;
        }
    }
    std::bitset<size> gamma;
    for (int i = 0; i < bitCounts.size(); i++)
    {
        gamma[i] = bitCounts[i] >= 0;
    }
    std::bitset<size> epsilon = gamma;
    epsilon.flip();
    std::cout << "Gamma: " << gamma.to_ulong() << '\n'
              << "Epsilon: " << epsilon.to_ulong() << '\n'
              << "Product: " << gamma.to_ulong() * epsilon.to_ulong() << std::endl;

    std::vector<int> oxygenCandidates(std::begin(data), std::end(data));
    std::sort(std::begin(oxygenCandidates), std::end(oxygenCandidates));

    int oxygenBit = size - 1;
    int border = (1 << oxygenBit);
    while (oxygenCandidates.size() > 1)
    {
        oxygenBit--;

        auto pivotElement = oxygenCandidates.begin();
        while (*pivotElement < border)
        {
            ++pivotElement;
        }
        if (static_cast<size_t>(std::distance(oxygenCandidates.begin(), pivotElement)) > oxygenCandidates.size() / 2)
        {
            oxygenCandidates.erase(pivotElement, oxygenCandidates.end());
            border -= (1 << oxygenBit);
        }
        else
        {
            oxygenCandidates.erase(oxygenCandidates.begin(), pivotElement);
            border += (1 << oxygenBit);
        }
    }
    const int oxygenGeneratorRating = oxygenCandidates[0];
    //-----------------
    std::vector<int> co2ScrubberCandidates(std::begin(data), std::end(data));
    std::sort(std::begin(co2ScrubberCandidates), std::end(co2ScrubberCandidates));

    int co2Bit = size - 1;
    border = (1 << co2Bit);
    while (co2ScrubberCandidates.size() > 1)
    {
        co2Bit--;

        auto pivotElement = co2ScrubberCandidates.begin();
        while (*pivotElement < border)
        {
            ++pivotElement;
        }
        if (static_cast<size_t>(std::distance(co2ScrubberCandidates.begin(), pivotElement)) <= co2ScrubberCandidates.size() / 2)
        {
            co2ScrubberCandidates.erase(pivotElement, co2ScrubberCandidates.end());
            border -= (1 << co2Bit);
        }
        else
        {
            co2ScrubberCandidates.erase(co2ScrubberCandidates.begin(), pivotElement);
            border += (1 << co2Bit);
        }
    }
    const int co2ScrubberRating = co2ScrubberCandidates[0];

    std::cout << "Oxygen Generator Rating: " << oxygenGeneratorRating << '\n'
              << "CO2 Scrubber Rating: " << co2ScrubberRating << '\n'
              << "Product: " << oxygenGeneratorRating * co2ScrubberRating << std::endl;
}
