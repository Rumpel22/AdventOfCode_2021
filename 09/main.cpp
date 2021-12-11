#include "input_9.h"

#include <algorithm>
#include <array>
#include <numeric>
#include <iostream>
#include <set>
#include <stack>

struct Point
{
    size_t x;
    size_t y;
    int value;

    bool operator<(const Point &rhs) const
    {
        if (x < rhs.x)
        {
            return true;
        }
        return (x == rhs.x && y < rhs.y);
    }
};

std::vector<Point> getNeighbours(Point p, const Map &map)
{
    std::vector<Point> points;
    const size_t &x = p.x;
    const size_t &y = p.y;
    if (y > 0)
    {
        points.emplace_back(Point{x, y - 1, map[y - 1][x]});
    }
    if (y < (map.size() - 1))
    {
        points.emplace_back(Point{x, y + 1, map[y + 1][x]});
    }
    if (x > 0)
    {
        points.emplace_back(Point{x - 1, y, map[y][x - 1]});
    }
    if (x < (map[y].size() - 1))
    {
        points.emplace_back(Point{x + 1, y, map[y][x + 1]});
    }
    return points;
}

int main(int, char **)
{
    std::vector<Point> lowPoints;
    for (size_t y = 0; y < map.size(); ++y)
    {
        for (size_t x = 0; x < map[y].size(); ++x)
        {
            Point point{x, y, map[y][x]};
            auto neighbours = getNeighbours(Point{x, y}, map);
            if (
                std::all_of(std::begin(neighbours), std::end(neighbours), [&point](Point p)
                            { return map[p.y][p.x] > point.value; }))
            {
                lowPoints.push_back(point);
            }
        }
    }
    unsigned int sum = std::accumulate(std::begin(lowPoints), std::end(lowPoints), 0u, [](unsigned int sum, const Point &point)
                                       { return sum + point.value; });
    unsigned int riskLevelSum = sum + static_cast<unsigned int>(lowPoints.size());
    std::cout << "Sum of risk levels: " << riskLevelSum << std::endl;

    std::vector<size_t> basinSizes;
    for (auto point : lowPoints)
    {
        std::set<Point> basin;
        std::stack<Point> candidates;
        candidates.push(point);
        while (!candidates.empty())
        {
            auto candidate = candidates.top();
            candidates.pop();
            auto [iter, newOne] = basin.insert(candidate);
            if (newOne)
            {
                auto neighbours = getNeighbours(candidate, map);
                for (auto newCandidate : neighbours)
                {
                    if (newCandidate.value > candidate.value && newCandidate.value < 9)
                    {
                        candidates.push(newCandidate);
                    }
                }
            }
        }
        basinSizes.push_back(basin.size());
    }
    std::sort(std::begin(basinSizes), std::end(basinSizes), std::greater<size_t>());
    size_t product = basinSizes[0] * basinSizes[1] * basinSizes[2];
    std::cout << "Product of 3 largest basin sizes: " << product << std::endl;
}
