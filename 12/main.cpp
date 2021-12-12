#include "input_12.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <string_view>
#include <iterator>

using Map = std::multimap<std::string_view, std::string_view>;
using Path = std::vector<std::string_view>;
using Paths = std::vector<Path>;

Map parse(const std::vector<std::string> &connections)
{
    Map map;
    for (std::string_view connection : connections)
    {
        size_t split = connection.find('-');
        std::string_view n1 = connection.substr(0, split);
        std::string_view n2 = connection.substr(split + 1);
        map.insert(std::pair{n1, n2});
        map.insert(std::pair{n2, n1});
    }
    return map;
}

bool isBig(std::string_view name)
{
    return std::any_of(std::begin(name), std::end(name), std::isupper);
}

bool isSmall(std::string_view name)
{
    return !isBig(name);
}

bool canVisitSmallCave(const Path &path, std::string_view name)
{
    std::map<std::string_view, size_t> visits;
    for (auto cave : path)
    {
        if (isSmall(cave))
        {
            visits[cave]++;
        }
    }
    bool anyVisitedTwice = std::any_of(std::begin(visits), std::end(visits), [](const std::pair<std::string_view, size_t> &p)
                                       { return p.second == 2; });
    return !anyVisitedTwice || visits[name] == 0;
}

bool canVisit(std::string_view name, const Path &path)
{
    return isBig(name) || (name != "start" && canVisitSmallCave(path, name));
}

Paths findPaths(const Map &map, std::string_view current, Path alreadyVisited = {})
{
    alreadyVisited.push_back(current);
    if (current == "end")
    {
        return {alreadyVisited};
    }
    Paths paths;
    auto nexts = map.equal_range(current);
    for (auto iter = nexts.first; iter != nexts.second; ++iter)
    {
        auto next = (*iter).second;
        bool canVisitNext = canVisit(next, alreadyVisited);
        if (canVisitNext)
        {
            auto newPaths = findPaths(map, next, alreadyVisited);
            if (!newPaths.empty())
            {
                paths.insert(paths.end(), std::begin(newPaths), std::end(newPaths));
            }
        }
    }
    return paths;
}

int main(int, char **)
{
    Map map = parse(connections);
    Paths paths = findPaths(map, "start");

    std::cout << "There are " << paths.size() << " paths from start to end." << std::endl;
}
