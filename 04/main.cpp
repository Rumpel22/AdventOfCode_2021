#include "input_4.h"

#include <algorithm>
#include <iostream>
#include <numeric>

bool isWinningRow(const std::array<int, 25> &card, int rowIndex)
{
    return std::all_of(std::begin(card) + 5 * rowIndex, std::begin(card) + 5 * (rowIndex + 1), [](int field)
                       { return field == -1; });
}

bool isWinningCol(const std::array<int, 25> &card, int colIndex)
{
    bool isWinner = true;
    for (int i = 0; i < 5; i++)
    {
        isWinner &= (card[i * 5 + colIndex] == -1);
    }
    return isWinner;
}

bool isCardWinner(const std::array<int, 25> &card)
{
    bool isWinner = false;
    for (int row = 0; row < 5; ++row)
    {
        isWinner |= isWinningRow(card, row);
    }
    for (int col = 0; col < 5; ++col)
    {
        isWinner |= isWinningCol(card, col);
    }
    return isWinner;
}

int findWinningCard(const std::vector<std::array<int, 25>> &cards)
{
    auto iter = std::find_if(std::begin(cards), std::end(cards), isCardWinner);
    if (iter != std::end(cards))
    {
        return std::distance(std::begin(cards), iter);
    }
    return -1;
}

int main(int, char **)
{
    std::vector<std::array<int, 25>> cards = orgCards;
    int winningCardIndex = -1;
    int winningCardScore = 0;
    for (int draw : draws)
    {
        for (size_t cardIndex = 0; cardIndex < cards.size(); ++cardIndex)
        {
            auto &card = cards[cardIndex];
            for (int i = 0; i < card.size(); ++i)
            {
                if (card[i] == draw)
                {
                    card[i] = -1;
                }
            }
        }
        // === PART I ===
        // winningCardIndex = findWinningCard(cards);
        // if (winningCardIndex != -1)
        // {
        //     const auto &card = cards[winningCardIndex];
        //     winningCardScore = draw * std::accumulate(std::begin(card), std::end(card), 0, [](int sum, int value)
        //                                               { return sum + (value != -1 ? value : 0); });
        //     break;
        // }

        // === PART II ===
        if (cards.size() > 1)
        {
            cards.erase(std::remove_if(std::begin(cards), std::end(cards), isCardWinner), std::end(cards));
        }
        else
        {
            const auto &card = cards[0];
            if (isCardWinner(card))
            {
                winningCardScore = draw * std::accumulate(std::begin(card), std::end(card), 0, [](int sum, int value)
                                                          { return sum + (value != -1 ? value : 0); });
                break;
            }
        }
    }

    std::cout << "Winning card score: " << winningCardScore << '\n';
    //           << "CO2 Scrubber Rating: " << co2ScrubberRating << '\n'
    //           << "Product: " << oxygenGeneratorRating * co2ScrubberRating << std::endl;
}
