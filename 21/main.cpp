#include "input_21.h"
#include <iostream>

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

int main(int, char **)
{
    unsigned int player1Scores = 0;
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
}