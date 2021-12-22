#include "input_18.h"

#include <iostream>
#include <sstream>
#include <string>
#include <utility>

std::pair<unsigned int, unsigned int> extractPair(std::string &number, size_t pos)
{
    size_t comma;
    unsigned int left = std::stoul(number.substr(pos + 1), &comma);
    size_t rightStart = pos + comma + 2;
    unsigned int right = std::stoul(number.substr(rightStart), &comma);
    number.replace(pos, rightStart + comma + 1 - pos, 1, '0');
    return {left, right};
}

bool explode(std::string &number)
{
    size_t count = 0;
    for (size_t pos = 0; pos < number.size(); ++pos)
    {
        if (number[pos] == '[')
        {
            count++;
            if (count > 4)
            {
                std::pair<unsigned int, unsigned int> pair = extractPair(number, pos);

                size_t rightPosBegin = number.find_first_of("0123456789", pos + 1);
                if (rightPosBegin != std::string::npos)
                {
                    size_t rightPosEnd;
                    unsigned int right = std::stoul(number.substr(rightPosBegin), &rightPosEnd);
                    number.replace(rightPosBegin, rightPosEnd, std::to_string(right + pair.second));
                }

                size_t leftPosEnd = number.find_last_of("0123456789", pos - 1);
                if (leftPosEnd != std::string::npos)
                {
                    size_t leftPosBegin = leftPosEnd;
                    while (std::isdigit(number[leftPosBegin]))
                    {
                        --leftPosBegin;
                    }
                    unsigned int left = std::stoul(number.substr(leftPosBegin + 1));
                    number.replace(leftPosBegin + 1, leftPosEnd - leftPosBegin, std::to_string(left + pair.first));
                }

                return true;
            }
        }
        else if (number[pos] == ']')
        {
            count--;
        }
    }
    return false;
}

bool split(std::string &number)
{
    for (size_t pos = 0; pos < number.size(); ++pos)
    {
        if (std::isdigit(number[pos]) && std::isdigit(number[pos + 1]))
        {
            size_t end;
            unsigned int n = std::stoul(number.substr(pos), &end);
            unsigned int newLeft = n / 2;
            unsigned int newRight = (n + 1) / 2;

            number.replace(pos, end, "[" + std::to_string(newLeft) + "," + std::to_string(newRight) + "]");
            return true;
        }
    }

    return false;
}

std::string add(const std::string_view &a, const std::string_view &b)
{
    std::ostringstream str;
    str << '[' << a << "," << b << ']';
    std::string result = str.str();
    while (true)
    {
        if (explode(result))
        {
            continue;
        }
        if (split(result))
        {
            continue;
        }
        return result;
    }
}

unsigned int magnitude(std::string &number)
{
    for (size_t pos = 1; pos < number.size(); ++pos)
    {
        if (number[pos] == '[')
        {
            std::string n = number.substr(pos);
            unsigned int mag = magnitude(n);
            n.replace(0, 1, std::to_string(mag));
            number.replace(pos, number.size(), n);
        }
        else if (number[pos] == ']')
        {
            auto pair = extractPair(number, 0);
            return 3 * pair.first + 2 * pair.second;
        }
    }
    return 0;
}

int main(int, char **)
{
    std::string result(numbers[0].data(), numbers[0].size());
    for (size_t numberIndex = 1; numberIndex < numbers.size(); numberIndex++)
    {
        result = add(result, numbers[numberIndex]);
    }

    unsigned int mag = magnitude(result);
    std::cout << "The magnitude of the final result is " << mag << std::endl;

    unsigned int maxDiff = 0;
    for (size_t i = 0; i < numbers.size(); ++i)
    {
        for (size_t j = i + 1; j < numbers.size(); ++j)
        {
            std::string sum = add(numbers[i], numbers[j]);
            unsigned int mag = magnitude(sum);
            maxDiff = std::max(maxDiff, mag);
        }
    }
    std::cout << "The max magnitude between two summands is " << maxDiff << std::endl;
}