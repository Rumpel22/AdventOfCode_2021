#include "input_21.h"
#include <iostream>
#include <map>

struct DeterministicDice
{
    unsigned int getNextThreeRolls()
    {
        unsigned int result = 0;
        for (int i = 0; i < 3; ++i)
        {
            result += nextRoll++;
            if (nextRoll > 100)
            {
                nextRoll = 1;
            }
            nbRolls++;
        }
        return result;
    }

    unsigned int getNbRolls() const
    {
        return nbRolls;
    }

private:
    unsigned int nextRoll = 1;
    unsigned int nbRolls = 0;
};

struct Universe
{
    unsigned int player1;
    unsigned int player2;
    unsigned int score1 = 0;
    unsigned int score2 = 0;
    bool nextPlayer1 = true;

    auto operator<=>(const Universe &) const = default;
};

using Multiverse = std::map<Universe, unsigned long long>;

Multiverse getNextUniverses(Universe universe)
{
    Multiverse multiverse;
    for (int i = 1; i <= 3; ++i)
    {
        for (int j = 1; j <= 3; ++j)
        {
            for (int k = 1; k <= 3; ++k)
            {
                Universe nextUniverse = universe;
                unsigned int &player = (universe.nextPlayer1 ? nextUniverse.player1 : nextUniverse.player2);
                unsigned int &score = (universe.nextPlayer1 ? nextUniverse.score1 : nextUniverse.score2);
                nextUniverse.nextPlayer1 = !universe.nextPlayer1;
                player += i + j + k;
                player = ((player - 1) % 10) + 1;
                score += player;
                multiverse[nextUniverse]++;
            }
        }
    }
    return multiverse;
}

int main(int, char **)
{
    /*     unsigned int player1Scores = 0;
    unsigned int player2Scores = 0;
    DeterministicDice dice;
    bool turn = true;
    while (player1Scores < 1000 && player2Scores < 1000)
    {
        unsigned int &player = (turn ? player1 : player2);
        unsigned int &score = (turn ? player1Scores : player2Scores);
        turn = !turn;

        unsigned int roll = dice.getNextThreeRolls();
        player += roll;
        player = ((player - 1) % 10) + 1;
        score += player;
    }

    unsigned int nbRolls = dice.getNbRolls();
    unsigned int losingPlayerScore = (player1Scores < 1000 ? player1Scores : player2Scores);
    std::cout << "The product of number of rolls and the score of the losing player is " << nbRolls * losingPlayerScore << std::endl;
 */
    Multiverse multiverse;
    multiverse[{player1, player2}] = 1;
    unsigned long long winsPlayer1 = 0;
    unsigned long long winsPlayer2 = 0;
    while (!multiverse.empty())
    {
        Multiverse nextMultiverse;
        for (auto [universe, count] : multiverse)
        {
            Multiverse newUniverses = getNextUniverses(universe);

            for (auto [newUniverse, newCount] : newUniverses)
            {
                if (newUniverse.score1 >= 21)
                {
                    winsPlayer1 += newCount * count;
                }
                else if (newUniverse.score2 >= 21)
                {
                    winsPlayer2 += newCount * count;
                }
                else
                {
                    nextMultiverse[newUniverse] += newCount * count;
                }
            }
        }

        multiverse = std::move(nextMultiverse);
    };
    std::cout << "Player 1 wins " << winsPlayer1 << " times, player 2 wins " << winsPlayer2 << " times.\n";
    std::cout << "Player" << (winsPlayer1 > winsPlayer2 ? '1' : '2') << " wins more" << std::endl;
}