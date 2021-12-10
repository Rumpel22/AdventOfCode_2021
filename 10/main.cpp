#include "input_10.h"

#include <assert.h>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <stack>

bool isOpeningChar(char c)
{
    return c == '(' || c == '{' || c == '[' || c == '<';
}

char getClosingChar(char c)
{
    switch (c)
    {
    case '(':
        return ')';
    case '[':
        return ']';
    case '{':
        return '}';
    case '<':
        return '>';
    default:
        assert(false);
        return 0;
    }
}

int main(int, char **)
{
    std::vector<char> illegalChars;
    for (const auto &line : lines)
    {
        std::stack<char> chars;
        for (char c : line)
        {
            if (isOpeningChar(c))
            {
                chars.push(c);
            }
            else
            {
                if (c == getClosingChar(chars.top()))
                {
                    chars.pop();
                }
                else
                {
                    illegalChars.push_back(c);
                    break;
                }
            }
        }
    }
    std::vector<unsigned int> points;
    std::transform(std::begin(illegalChars), std::end(illegalChars), std::inserter(points, points.end()), [](char c)
                   {
                       switch (c)
                       {
                       case ')':
                           return 3;
                       case ']':
                           return 57;
                       case '}':
                           return 1197;
                       case '>':
                           return 25137;
                       default:
                           assert(false);
                           return 0;
                       }
                   });
    unsigned int total = std::accumulate(std::begin(points), std::end(points), 0u);
    std::cout << "Total syntax error points: " << total << std::endl;
}
