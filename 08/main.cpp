#include "input_8.h"

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>
#include <map>

using namespace std;

string sortString(string string)
{
    sort(begin(string), end(string));
    return string;
}

vector<string> findAllWithLength(const auto &input, size_t length)
{
    vector<string> output;
    auto iter = begin(input);
    while (iter != end(input))
    {
        iter = find_if(iter, end(input), [length](const char *string)
                       { return strlen(string) == length; });
        if (iter != end(input))
        {
            output.push_back(sortString(*iter));
            ++iter;
        }
    }
    return output;
}

string findWithLength(const auto &input, size_t length)
{
    auto entries = findAllWithLength(input, length);
    if (!entries.empty())
    {
        return entries[0];
    }
    return {};
}

array<string, 10> getDigits(map<int, char> segments)
{
    array<string, 10> digits;
    digits[0] = {segments[0], segments[1], segments[2], segments[4], segments[5], segments[6]};
    digits[1] = {segments[2], segments[5]};
    digits[2] = {segments[0], segments[2], segments[3], segments[4], segments[6]};
    digits[3] = {segments[0], segments[2], segments[3], segments[5], segments[6]};
    digits[4] = {segments[1], segments[2], segments[3], segments[5]};
    digits[5] = {segments[0], segments[1], segments[3], segments[5], segments[6]};
    digits[6] = {segments[0], segments[1], segments[3], segments[4], segments[5], segments[6]};
    digits[7] = {segments[0], segments[2], segments[5]};
    digits[8] = {segments[0], segments[1], segments[2], segments[3], segments[4], segments[5], segments[6]};
    digits[9] = {segments[0], segments[1], segments[2], segments[3], segments[5], segments[6]};
    for (auto &digit : digits)
    {
        sort(begin(digit), end(digit));
    }
    return digits;
}

unsigned int getValue(output out, const array<string, 10> &digits)
{
    unsigned int value = 0;
    for (string digit : out)
    {
        sort(begin(digit), end(digit));
        for (int i = 0; i < 10; i++)
        {
            if (digits[i] == digit)
            {
                value = 10 * value + i;
                break;
            }
        }
    }
    return value;
}

int main(int, char **)
{
    size_t searched_digits = 0;
    for (const auto &line : lines)
    {
        const auto &output = line.second;
        searched_digits += count_if(begin(output), end(output), [](const char *digit)
                                    {
                                        size_t digitLength = strlen(digit);
                                        return digitLength == 2 || digitLength == 3 || digitLength == 4 || digitLength == 7;
                                    });
    }
    cout << "Number of searched digits: " << searched_digits << endl;

    //-------------
    unsigned long sum = 0;
    for (const auto &[input, output] : lines)
    {
        map<int, char> segments = {};
        string one = findWithLength(input, 2);
        string seven = findWithLength(input, 3);
        // Fill segment 1
        segments[0] = *(mismatch(begin(one), end(one), begin(seven)).second);

        string four = findWithLength(input, 4);
        array<char, 2> seg_2_4 = {};
        set_symmetric_difference(begin(one), end(one), begin(four), end(four), begin(seg_2_4));

        vector<string> six_nine_zero = findAllWithLength(input, 6);
        string eight = findWithLength(input, 7);
        array<char, 3> seg_3_4_5 = {};
        auto iter_1 = set_symmetric_difference(begin(six_nine_zero[0]), end(six_nine_zero[0]), begin(eight), end(eight), begin(seg_3_4_5));
        iter_1 = set_symmetric_difference(begin(six_nine_zero[1]), end(six_nine_zero[1]), begin(eight), end(eight), iter_1);
        set_symmetric_difference(begin(six_nine_zero[2]), end(six_nine_zero[2]), begin(eight), end(eight), iter_1);
        sort(begin(seg_3_4_5), end(seg_3_4_5));
        // Fill segment 4
        set_intersection(begin(seg_2_4), end(seg_2_4), begin(seg_3_4_5), end(seg_3_4_5), &segments[3]);

        vector<string> two_three_five = findAllWithLength(input, 5);
        array<char, 4> temp_seg_1_4_7 = {};
        array<char, 3> seg_1_4_7 = {};
        auto iter_2 = set_intersection(begin(two_three_five[0]), end(two_three_five[0]), begin(two_three_five[1]), end(two_three_five[1]), begin(temp_seg_1_4_7));
        set_intersection(begin(two_three_five[2]), end(two_three_five[2]), begin(temp_seg_1_4_7), iter_2, begin(seg_1_4_7));
        // Fill segment 7
        for (auto value : seg_1_4_7)
        {
            auto iter = find_if(begin(segments), end(segments), [value](pair<int, char> p)
                                { return p.second == value; });
            if (iter == end(segments))
            {
                segments[6] = value;
                break;
            }
        }

        // Fill segment 2
        for (auto value : seg_2_4)
        {
            auto iter = find_if(begin(segments), end(segments), [value](pair<int, char> p)
                                { return p.second == value; });
            if (iter == end(segments))
            {
                segments[1] = value;
                break;
            }
        }

        string five = *find_if(begin(two_three_five), end(two_three_five), [segments](string s)
                               { return s.find(segments.at(1)) != string::npos; });
        // Fill segment 6
        for (auto value : five)
        {
            auto iter = find_if(begin(segments), end(segments), [value](pair<int, char> p)
                                { return p.second == value; });
            if (iter == end(segments))
            {
                segments[5] = value;
                break;
            }
        }

        // Fill segment 3
        segments[2] = one[0] == segments[5] ? one[1] : one[0];

        // Fill segment 5
        for (auto value : "abcdefg")
        {
            auto iter = find_if(begin(segments), end(segments), [value](pair<int, char> p)
                                { return p.second == value; });
            if (iter == end(segments))
            {
                segments[4] = value;
                break;
            }
        }

        auto digits = getDigits(segments);
        sum += getValue(output, digits);
    }
    cout << "Summe: " << sum << endl;
}
