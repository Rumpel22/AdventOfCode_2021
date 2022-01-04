#pragma once

#include <string>
#include <vector>

constexpr int antipodsPerType = 4;
// constexpr int antipodsPerType = 2;

const std::vector<std::string> situation_string = {
    // "#############",
    // "#...........#",
    // "###A#C#B#D###",
    // "  #A#B#C#D#  ",
    // "  #########  ",

    // "#############",
    // "#...........#",
    // "###B#C#B#D###",
    // "  #A#D#C#A#  ",
    // "  #########  ",

    // "#############",
    // "#...........#",
    // "###D#A#D#C###",
    // "  #C#A#B#B#  ",
    // "  #########  ",

    // "#############",
    // "#...........#",
    // "###B#C#B#D###",
    // "  #D#C#B#A#  ",
    // "  #D#B#A#C#  ",
    // "  #A#D#C#A#  ",
    // "  #########  ",

    "#############",
    "#...........#",
    "###D#A#D#C###",
    "  #D#C#B#A#  ",
    "  #D#B#A#C#  ",
    "  #C#A#B#B#  ",
    "  #########  ",

};
