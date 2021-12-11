#include "input_5.h"

#include <iostream>
#include <map>
#include <algorithm>

bool isHorizontal(const Line &line)
{
    return line.p1.y == line.p2.y;
}
bool isVertical(const Line &line)
{
    return line.p1.x == line.p2.x;
}

int main(int, char **)
{
    std::map<Pair, unsigned int> map;

    for (const Line &line : lines)
    {
        Pair p1 = line.p1;
        Pair p2 = line.p2;
        if (isHorizontal(line))
        {
            const int y = p1.y;
            int x1 = p1.x;
            int x2 = p2.x;
            if (x1 > x2)
            {
                std::swap(x1, x2);
            }
            for (int x = x1; x <= x2; ++x)
            {
                map[Pair{x, y}] += 1;
            }
        }
        else if (isVertical(line))
        {
            const int x = p1.x;
            int y1 = p1.y;
            int y2 = p2.y;
            if (y1 > y2)
            {
                std::swap(y1, y2);
            }
            for (int y = y1; y <= y2; ++y)
            {
                map[Pair{x, y}] += 1;
            }
        }
        else
        {
            // it is diagonal
            if (p1.x > p2.x)
            {
                std::swap(p1, p2);
            }
            if (p1.y > p2.y)
            {
                for (int x = p1.x, y = p1.y; x <= p2.x; ++x, --y)
                {
                    map[Pair{x, y}] += 1;
                }
            }
            else
            {
                for (int x = p1.x, y = p1.y; x <= p2.x; ++x, ++y)
                {
                    map[Pair{x, y}] += 1;
                }
            }
        }
    }

    auto points = std::count_if(std::begin(map), std::end(map), [](const std::pair<Pair, unsigned int> &pair)
                                { return pair.second >= 2; });

    std::cout << "Points: " << points << std::endl;
}
