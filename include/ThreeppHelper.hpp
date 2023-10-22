
#ifndef EXAM_TETRIS_THREEPPHELPER_HPP
#define EXAM_TETRIS_THREEPPHELPER_HPP

#include "threepp/threepp.hpp"

using namespace threepp;


class ThreeppHelper {
public:
    // makes it easier to create a box later
    static std::shared_ptr<Mesh> createBox(const Vector3& pos, const Color& color);
};


#endif//EXAM_TETRIS_THREEPPHELPER_HPP
