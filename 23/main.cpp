#include "input_23.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <optional>

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
// "#######12####14####16####18########",
// "      #22####24####26####28#  ",
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
    std::array<Position, 4 * antipodsPerType> antipods;
    int cost = 0;

    auto operator<=>(const Situation &rhs) const = default;

    Situation(const std::vector<std::string> &situation_string)
    {
        std::array<int, 4> foundOfType = {0};
        antipods.fill(-1);

        for (int x = 0; x < 4; ++x)
        {
            for (int y = 0; y < antipodsPerType; ++y)
            {
                int podType = situation_string[y + 2][x * 2 + 3] - 'A';
                antipods[podType * antipodsPerType + foundOfType[podType]] = (y + 1) * 10 + (x + 1) * 2;
                foundOfType[podType]++;
            }
        }
    }

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
        return (isRoom(position) ? ((position % 10) / 2 - 1) : -1);
    }

    static Situation applyMove(const Situation &situation, const Move &move)
    {
        Situation newSituation(situation);
        const Position start = situation.antipods[move.index];
        newSituation.antipods[move.index] = move.end;
        newSituation.cost += Situation::countMoves(start, move.end) * costPerMove[move.index / antipodsPerType];
        return newSituation;
    }

    bool isInOwnRoom(const AntipodIndex &antipod) const
    {
        return isRoom(antipods[antipod], antipod / antipodsPerType);
    }

    bool isFinal() const
    {
        const size_t end = antipods.size();
        for (AntipodIndex i = 0; i < end; ++i)
        {
            Position position = antipods[i];
            int antipodType = i / 4;
            if (position < 11 || (position % 10 != (antipodType + 1) * 2))
            {
                return false;
            }
        }
        return true;
    }

    Antipod getOccupy(Position position) const
    {
        auto iter = std::find(std::begin(antipods), std::end(antipods), position);
        return static_cast<Antipod>(iter == std::end(antipods) ? -1 : std::distance(std::begin(antipods), iter) / antipodsPerType);
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
            // Move vertical in room
            Position newPosition = start;
            newPosition += (start % 10 == end % 10 ? 10 : -10);
            return isEmpty(newPosition) && isWayFree(newPosition, end);
        }
        if (start % 10 == end % 10)
        {
            // Step into room
            Position newPosition = start + 10;
            return isEmpty(newPosition) && isWayFree(newPosition, end);
        }
        // Move in the hallway in the direction of the end room
        Position newPosition = start + (start >= end % 10 ? -1 : 1);
        if (end == 10)
        {
            newPosition += 2;
        }
        return isEmpty(newPosition) && isWayFree(newPosition, end);
    }

    static int countMoves(Position start, Position end)
    {
        int count = 0;
        while (start > 10)
        {
            count++;
            start -= 10;
        }
        while (end > 10)
        {
            count++;
            end -= 10;
        }
        count += std::abs(start - end);
        return count;
    }

    bool reachedFinal(AntipodIndex antipodIndex) const
    {
        if (isInOwnRoom(antipodIndex))
        {
            Position position = antipods[antipodIndex];
            Antipod type = static_cast<Antipod>(antipodIndex / antipodsPerType);
            for (; position < (antipodsPerType + 1) * 10; position += 10)
            {
                int occupy = getOccupy(position);
                if (occupy != type)
                {
                    return false;
                }
            }
            return true;
        }
        return false;
    }

    std::optional<Move> getGoGoals() const
    {
        for (int room = 0; room < antipods.size() / antipodsPerType; ++room)
        {
            for (int spot = antipodsPerType; spot > 0; --spot)
            {
                int spotIndex = (room + 1) * 2 + spot * 10;
                Antipod occupy = getOccupy(spotIndex);
                if (occupy == room)
                {
                    // Field already occupied by correct antipod
                    continue;
                }
                if (occupy != -1)
                {
                    // Field occupied with wrong antipod => room cannot be filled
                    break;
                }
                // Spot in room is empty (and all spots above, too)
                for (int antipod = 0; antipod < antipodsPerType; antipod++)
                {
                    AntipodIndex index = room * antipodsPerType + antipod;
                    Position position = antipods[index];
                    if (position <= 10 || position % 10 != (room + 1) * 2)
                    {
                        if (isWayFree(position, spotIndex))
                        {
                            return Move{index, spotIndex};
                        }
                    }
                }
            }
        }
        return std::nullopt;
    }

    std::vector<Move> getCheapestMoves() const
    {
        std::vector<Move> moves;
        for (int antipodType = 0; antipodType < 4; ++antipodType)
        {
            for (int antipod = 0; antipod < antipodsPerType; ++antipod)
            {
                AntipodIndex index = antipodType * antipodsPerType + antipod;
                Position start = antipods[index];
                if (start <= 10)
                {
                    // start must be in room
                    continue;
                }
                if (reachedFinal(index))
                {
                    continue;
                }

                for (int hallwayPos = 1; hallwayPos <= 9; hallwayPos += 2)
                {
                    if (isWayFree(start, hallwayPos))
                    {
                        moves.emplace_back(index, hallwayPos);
                    }
                }
                if (isWayFree(start, 0))
                {
                    moves.emplace_back(index, 0);
                }
                if (isWayFree(start, 10))
                {
                    moves.emplace_back(index, 10);
                }
            }
        }

        return moves;
    }

    int solve() const
    {
        if (isFinal())
        {
            return cost;
        }
        std::optional<Move> goToGoal = getGoGoals();
        if (goToGoal.has_value())
        {
            Situation newSituation = applyMove(*this, goToGoal.value());
            return newSituation.solve();
        }

        std::vector<Move> moves = getCheapestMoves();
        int minimumCost = std::numeric_limits<int>::max();
        for (Move move : moves)
        {
            Situation newSituation = applyMove(*this, move);
            minimumCost = std::min(minimumCost, newSituation.solve());
        }
        return minimumCost;
    }
};

int main(int, char **)
{
    Situation situation(situation_string);
    int cost = situation.solve();

    std::cout << "The most energy efficient solution uses " << cost << " energy." << std::endl;
}
