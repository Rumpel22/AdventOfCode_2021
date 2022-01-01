#include "input_23.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <cassert>
#include <queue>
#include <set>

static const std::array<int, 4> costPerMove = {
    1,    // A
    10,   // B
    100,  // C
    1000, // D
};

enum Antipod
{
    A,
    B,
    C,
    D,
};

// The positions
// "###################################",
// "# 0  1  2  3  4  5  6  7  8  9  10#",
// "#######11####13####15####17########",
// "      #12####14####16####18#  ",
// "      ######################",

using Position = int;
using AntipodIndex = int;

struct Move
{
    AntipodIndex index;
    Position end;
};

struct Situation
{
    // A1, A2, B1, B2, C1, C2, D1, D2
    std::array<Position, 8> antipods;
    unsigned int cost = 0;

    Situation(const std::vector<std::string> &situation_string)
    {
        std::array<int, 4> foundOfType = {0};
        antipods.fill(-1);

        for (int x = 0; x < 4; ++x)
        {
            for (int y = 0; y < 2; ++y)
            {
                int podType = situation_string[y + 2][x * 2 + 3] - 'A';
                antipods[podType * 2 + foundOfType[podType]] = x * 2 + y + 11;
                foundOfType[podType]++;
            }
        }
    }

    // std::array<Antipod, 8> getAntipods() const
    // {
    //     std::array<Antipod, 8> antipods;
    //     auto iter = std::begin(antipods);
    //     for (auto &field : fields)
    //     {
    //         if (field.second != '.')
    //         {
    //             *iter++ = &field;
    //         }
    //     }
    //     assert(iter == std::end(antipods));
    //     return antipods;
    // }

    static bool isRoom(const Position &position)
    {
        return position >= 11;
    }

    static bool isRoom(const Position &position, int room)
    {
        return isRoom(position) && (getRoomNumber(position) == room);
    }

    static int getRoomNumber(const Position &position)
    {
        return (isRoom(position) ? (position - 11) / 2 : -1);
    }

    static bool isHallway(const Position &position)
    {
        return !isRoom(position);
    }

    bool isInOwnRoom(const AntipodIndex &antipod) const
    {
        return isRoom(antipods[antipod], antipod / 2);
    }

    bool isInHallway(const AntipodIndex &antipod) const
    {
        return isHallway(antipods[antipod]);
    }

    bool isFinal() const
    {
        const size_t end = antipods.size();
        for (AntipodIndex i = 0; i < end; ++i)
        {
            if (!isInOwnRoom(i))
            {
                return false;
            }
        }
        return true;
    }

    Antipod getOccupy(Position position) const
    {
        auto iter = std::find(std::begin(antipods), std::end(antipods), position);
        return static_cast<Antipod>(iter == std::end(antipods) ? -1 : std::distance(std::begin(antipods), iter) / 2);
    }

    bool isEmpty(const Position &position) const
    {
        return std::none_of(std::begin(antipods), std::end(antipods), [position](const Position antipodPos)
                            { return antipodPos == position; });
    }

    bool isWayFree(const Position &start, const Position &end) const
    {
        if (start == end)
        {
            return true;
        }
        if (isRoom(start))
        {
            if (getRoomNumber(start) != getRoomNumber(end))
            {
                // Move to other room, in direction of the hallway
                Position newPosition = (start % 2 == 0 ? start - 1 : start - 9);
                return isEmpty(newPosition) && isWayFree(newPosition, end);
            }
            else
            {
                // Move within room
                Position newPosition = (start % 2 == 0 ? start - 1 : start + 1);
                ;
                return isEmpty(newPosition) && isWayFree(newPosition, end);
            }
        }
        if (isHallway(end))
        {
            // Move within hallway
            Position newPosition = start + (end < start ? -1 : 1);
            return isEmpty(newPosition) && isWayFree(newPosition, end);
        }
        if (start + 9 + (end % 2 == 0) == end)
        {
            // Step into room
            Position newPosition = start + 9;
            return isEmpty(newPosition) && isWayFree(newPosition, end);
        }
        // Move in the hallway in the direction of the end room
        Position newPosition = start + (start + 9 >= end ? -1 : 1);
        return isEmpty(newPosition) && isWayFree(newPosition, end);
    }

    bool canMove(const Position &start, const Position &end, Antipod antipod) const
    {
        if (start == end)
        {
            // illegal move
            return false;
        }
        if (isHallway(start) && isHallway(end))
        {
            // no move within hallway
            return false;
        }
        if (!isWayFree(start, end))
        {
            // way is not free
            return false;
        }
        if (!isRoom(end, antipod) && !isHallway(end))
        {
            // Move only in own room or hallway
            return false;
        }
        if (isRoom(start, antipod))
        {
            if (start % 2 == 0)
            {
                // Don't move if already at the bottom
                return false;
            }
            // start in own room
            if (isEmpty(start + start % 2) && end != (start + start % 2))
            {
                // Don't step out from own room if second place is free (=> move down!)
                return false;
            }
            if (antipods[antipod * 2] == start + 1 || antipods[antipod * 2 + 1] == start + 1)
            {
                // Don't step out of room if both places are covered with correct antipod
                return false;
            }
            // Move out of room to let the second antipod pass by
        }
        if (isRoom(end) && getOccupy(end + end % 2) != antipod && getOccupy(end + end % 2) != -1)
        {
            // Don't step in occupied room
            return false;
        }
        if (isRoom(start) && end == start - 9 - (start % 2 == 0))
        {
            // Don't stop on the field directly outside the starting room
            return false;
        }
        return true;
    }

    static int countMoves(const Position &start, const Position &end)
    {
        int result = 0;
        if (isHallway(start))
        {
            result += std::abs(start - (end - 9 - (end % 2 == 0))) + (1 + (end % 2 == 0));
        }
        else if (isHallway(end))
        {
            result += std::abs(end - (start - 9 - (start % 2 == 0))) + (1 + (start % 2 == 0));
        }
        else
        {
            result += 1 + (start % 2 == 0);
            result += 1 + (end % 2 == 0);
            int x1 = (start - 9) - (start % 2 == 0);
            int x2 = (end - 9) - (end % 2 == 0);
            result += std::abs(x1 - x2);
        }
        return result;
    }

    std::vector<Move> getNextMoves() const
    {
        std::vector<Move> nextMoves;
        for (AntipodIndex antipod = 0; antipod < antipods.size(); ++antipod)
        {
            const Position &start = antipods[antipod];
            for (Position end = 0; end < 19; ++end)
            {
                if (canMove(start, end, static_cast<Antipod>(antipod / 2)))
                {
                    nextMoves.emplace_back(antipod, end);
                }
            }
        }
        return nextMoves;
    }
};

auto cost_compare = [](const Situation &a, const Situation &b)
{ return a.cost < b.cost; };

auto situation_compare = [](const Situation &a, const Situation &b)
{ return a.antipods < b.antipods; }; // We want the smallest costs on top

int main(int, char **)
{
    Situation situation(situation_string);
    std::vector<Situation> possibleSituations;
    std::set<Situation, decltype(situation_compare)> visitedSituations;

    while (!situation.isFinal())
    {
        visitedSituations.insert(situation);
        std::vector<Move> nextMoves = situation.getNextMoves();
        for (const Move &nextMove : nextMoves)
        {
            Situation nextSituation(situation);
            const Position &start = nextSituation.antipods[nextMove.index];
            const Position &end = nextMove.end;
            Antipod antipod = nextSituation.getOccupy(start);

            nextSituation.cost += costPerMove.at(antipod) * Situation::countMoves(start, end);
            nextSituation.antipods[nextMove.index] = end;

            auto iter = std::find_if(std::begin(possibleSituations), std::end(possibleSituations), [&nextSituation](const Situation &situation)
                                     { return nextSituation.antipods == situation.antipods; });
            if (iter == std::end(possibleSituations))
            {
                if (!visitedSituations.contains(nextSituation))
                {
                    possibleSituations.push_back(nextSituation);
                }
            }
            else
            {
                (*iter).cost = std::min(nextSituation.cost, (*iter).cost);
            }
        }
        auto iter = std::min_element(std::begin(possibleSituations), std::end(possibleSituations), cost_compare);
        situation = *iter;
        possibleSituations.erase(iter);
    }

    std::cout << "The most energy efficient solution uses " << situation.cost << " energy" << std::endl;
}
