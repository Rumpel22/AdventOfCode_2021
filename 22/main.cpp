#include "input_22.h"

#include <numeric>
#include <iostream>
#include <vector>

struct Cube;
using Cubes = std::vector<Cube>;

struct Cube
{
    std::pair<int, int> x;
    std::pair<int, int> y;
    std::pair<int, int> z;

    size_t Volume() const
    {
        return static_cast<size_t>(x.second - x.first + 1) *
               static_cast<size_t>(y.second - y.first + 1) *
               static_cast<size_t>(z.second - z.first + 1);
    }

    bool intersected(const Cube &cube) const
    {
        return x.second >= cube.x.first && x.first <= cube.x.second &&
               y.second >= cube.y.first && y.first <= cube.y.second &&
               z.second >= cube.z.first && z.first <= cube.z.second;
    }

    Cubes split(const Cube &cube)
    {
        Cubes cubes;
        if (x.first <= cube.x.second && x.second > cube.x.second)
        {
            cubes.push_back({{cube.x.second + 1, x.second}, y, z});
            x.second = cube.x.second;
        }
        if (x.second >= cube.x.first && x.first < cube.x.first)
        {
            cubes.push_back({{x.first, cube.x.first - 1}, y, z});
            x.first = cube.x.first;
        }
        if (y.first <= cube.y.second && y.second > cube.y.second)
        {
            cubes.push_back({x, {cube.y.second + 1, y.second}, z});
            y.second = cube.y.second;
        }
        if (y.second >= cube.y.first && y.first < cube.y.first)
        {
            cubes.push_back({x, {y.first, cube.y.first - 1}, z});
            y.first = cube.y.first;
        }
        if (z.first <= cube.z.second && z.second > cube.z.second)
        {
            cubes.push_back({x, y, {cube.z.second + 1, z.second}});
            z.second = cube.z.second;
        }
        if (z.second >= cube.z.first && z.first < cube.z.first)
        {
            cubes.push_back({x, y, {z.first, cube.z.first - 1}});
            z.first = cube.z.first;
        }
        return cubes;
    }
};

bool isInBounds(const Cube &cube)
{
    //     const Cube boundsCube = {{-50, 50}, {-50, 50}, {-50, 50}};
    //     return boundsCube.intersected(cube);
    return true;
}

int main(int, char **)
{
    Cubes cubes;

    for (const auto &instruction : instructions)
    {
        Cube newCube = {instruction.x, instruction.y, instruction.z};
        if (!isInBounds(newCube))
        {
            continue;
        }
        bool anyIntersected = true;
        while (anyIntersected)
        {
            anyIntersected = false;
            for (auto iter = std::begin(cubes); iter != std::end(cubes); ++iter)
            {
                Cube &cube = *iter;
                if (cube.intersected(newCube))
                {
                    // Split the original cube into smaller ones and delete it afterwards
                    anyIntersected = true;
                    Cubes newCubes = cube.split(newCube);
                    cubes.erase(iter);
                    cubes.insert(std::end(cubes), std::begin(newCubes), std::end(newCubes));
                    break;
                }
            }
        }
        if (instruction.on)
        {
            cubes.push_back(newCube);
        };
    }

    size_t onCubes = std::accumulate(std::begin(cubes), std::end(cubes), size_t(0), [](size_t sum, const Cube &cube)
                                     { return sum + cube.Volume(); });
    std::cout
        << "There are " << onCubes << " cubes on." << std::endl;
}