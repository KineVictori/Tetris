
#ifndef EXAM_TETRIS_ENUMS_HPP
#define EXAM_TETRIS_ENUMS_HPP

#include <threepp/threepp.hpp>

using namespace threepp;

enum Shapes {
    O = 0,
    I = 1,
    J = 2,
    L = 3,
    S = 4,
    Z = 5,
    T = 6
};

enum Orientation {
    UP = 0,
    RIGHT = 1,
    DOWN = 2,
    LEFT = 3
};

enum Col {
    Color::pink = 0,
    Color::purple = 1,
    Color::blue = 2,
    Color::green = 3,
    Color::red = 4,
    Color::yellow = 5,
    Color::orange = 6
};

#endif//EXAM_TETRIS_ENUMS_HPP
