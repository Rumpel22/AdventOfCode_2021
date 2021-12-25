#include "input_19.h"

#include <assert.h>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <iterator>

coordinate operator-(const coordinate &a, const coordinate &b)
{
    return {
        std::get<0>(a) - std::get<0>(b),
        std::get<1>(a) - std::get<1>(b),
        std::get<2>(a) - std::get<2>(b),
    };
}
coordinate operator+(const coordinate &a, const coordinate &b)
{
    return {
        std::get<0>(a) + std::get<0>(b),
        std::get<1>(a) + std::get<1>(b),
        std::get<2>(a) + std::get<2>(b),
    };
}

size_t countIdenticalLengths(const std::vector<unsigned int> &a, const std::vector<unsigned int> &b)
{
    return std::accumulate(std::begin(a), std::end(a), size_t(0), [&b](size_t sum, unsigned int x)
                           { return sum + std::count_if(std::begin(b), std::end(b), [x](unsigned int b)
                                                        { return b && b == x; }); });
}

std::vector<std::vector<unsigned int>> lengthsPerSensor(const std::vector<coordinate> &sensor)
{
    std::vector<std::vector<unsigned int>> lengthsPerSensor;
    for (const auto &a : sensor)
    {
        std::vector<unsigned int> lengthsPerBeacon;
        std::transform(std::begin(sensor), std::end(sensor), std::back_insert_iterator(lengthsPerBeacon), [&a](const coordinate &b)
                       {
                           auto [x, y, z] = a - b;
                           return x * x + y * y + z * z;
                       });
        lengthsPerSensor.push_back(lengthsPerBeacon);
    }
    return lengthsPerSensor;
}

std::vector<std::pair<size_t, size_t>> getOverlappingIndexes(const std::vector<std::vector<unsigned int>> &a, const std::vector<std::vector<unsigned int>> &b)
{
    std::vector<std::pair<size_t, size_t>> result;
    for (size_t i = 0; i < a.size(); i++)
    {
        auto &beaconA = a[i];
        for (size_t j = 0; j < b.size(); ++j)
        {
            auto &beaconB = b[j];

            size_t identicalLength = countIdenticalLengths(beaconA, beaconB);
            if (identicalLength >= 11)
            {
                result.emplace_back(i, j);
            }
        }
    }
    return result;
}

void merge(std::vector<coordinate> &sensor0, const std::vector<coordinate> &sensorX)
{
    for (auto &coordinate : sensorX)
    {
        if (std::find(std::begin(sensor0), std::end(sensor0), coordinate) == std::end(sensor0))
        {
            sensor0.push_back(coordinate);
        }
    }
}

int map(const coordinate &beacon, int alignment)
{
    switch (alignment)
    {
    case -1:
        return -std::get<0>(beacon);
    case 1:
        return std::get<0>(beacon);
    case -2:
        return -std::get<1>(beacon);
    case 2:
        return std::get<1>(beacon);
    case -3:
        return -std::get<2>(beacon);
    case 3:
        return std::get<2>(beacon);
    default:
        assert(false && "should never happen");
    }
    return 0;
}

std::tuple<coordinate, std::tuple<int, int, int>> getOrigin(const std::vector<coordinate> &sensor0, const std::vector<coordinate> &sensorX, const std::vector<std::pair<size_t, size_t>> &overlappingBeacons)
{
    int possibilities[] = {-3, -2, -1, 1, 2, 3};
    bool originFound = true;
    coordinate mappedBeacon;
    const coordinate &beacon0 = sensor0[overlappingBeacons[0].first];
    const coordinate &beaconX = sensorX[overlappingBeacons[0].second];
    do
    {
        originFound = true;
        mappedBeacon = {map(beaconX, possibilities[0]),
                        map(beaconX, possibilities[1]),
                        map(beaconX, possibilities[2])};

        for (auto &indexes : overlappingBeacons)
        {
            const coordinate &beaconX = sensorX[indexes.second];
            coordinate x = {map(beaconX, possibilities[0]),
                            map(beaconX, possibilities[1]),
                            map(beaconX, possibilities[2])};
            if (beacon0 - mappedBeacon != sensor0[indexes.first] - x)
            {
                originFound = false;
                break;
            }
        }
    } while (std::next_permutation(std::begin(possibilities), std::end(possibilities)) && !originFound);
    return {beacon0 - mappedBeacon, {possibilities[0], possibilities[1], possibilities[2]}};
}

std::tuple<coordinate, std::vector<coordinate>> mapTo0(size_t sensorIndex, const std::vector<std::pair<size_t, size_t>> &overlappingBeacons)
{
    const std::vector<coordinate> &sensor0 = beacons[0];
    const std::vector<coordinate> &sensorX = beacons[sensorIndex];

    auto [originX, usedValueIndexes] = getOrigin(sensor0, sensorX, overlappingBeacons);

    std::vector<coordinate> mapped(sensorX.size());
    std::transform(std::begin(sensorX), std::end(sensorX), std::begin(mapped), [&originX, usedValueIndexes](const coordinate &c)
                   {
                       return coordinate{
                                  map(c, std::get<0>(usedValueIndexes)),
                                  map(c, std::get<1>(usedValueIndexes)),
                                  map(c, std::get<2>(usedValueIndexes)),
                              } +
                              originX;
                   });
    return {originX, mapped};
}

int main(int, char **)
{
    std::vector<std::vector<std::vector<unsigned int>>> allLengths;
    for (auto &sensor : beacons)
    {
        allLengths.push_back(lengthsPerSensor(sensor));
    }

    std::vector<size_t> toMerge(beacons.size() - 1);
    std::iota(std::begin(toMerge), std::end(toMerge), 1);
    std::vector<coordinate> sensors;
    while (!toMerge.empty())
    {
        auto sensor0Lengths = allLengths[0];
        for (auto sensorIndex = std::begin(toMerge); sensorIndex != std::end(toMerge); ++sensorIndex)
        {
            auto beaconIndexes = getOverlappingIndexes(sensor0Lengths, allLengths[*sensorIndex]);
            if (beaconIndexes.size() >= 12)
            {
                auto [sensor, mappedCoordinates] = mapTo0(*sensorIndex, beaconIndexes);
                sensors.push_back(sensor);
                merge(beacons[0], mappedCoordinates);
                allLengths[0] = lengthsPerSensor(beacons[0]);
                toMerge.erase(sensorIndex);
                break;
            }
        }
    }

    std::cout << "There are " << allLengths[0].size() << " individual beacons." << std::endl;

    int maxDistance = std::numeric_limits<int>::min();
    for (const coordinate &a : sensors)
    {
        for (const coordinate &b : sensors)
        {
            auto vector = a - b;
            int distance = std::get<0>(vector) + std::get<1>(vector) + std::get<2>(vector);
            if (distance > maxDistance)
            {
                maxDistance = distance;
            }
        }
    }
    std::cout << "The max Manhatten Distance between two sensors is " << maxDistance << std::endl;
}