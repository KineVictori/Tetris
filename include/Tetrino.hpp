
#ifndef EXAM_TETRIS_TETRINO_HPP
#define EXAM_TETRIS_TETRINO_HPP

#include <threepp/threepp.hpp>
#include <array>
#include "TetrinoEnum.hpp"

using namespace threepp;


class Tetrino {

public:
    Tetrino(Shapes shape, const Vector3& pos, const Color& color);
    std::shared_ptr<Group> getGroup ();
    std::array<Vector2, 4> getPositions();

private:
    std::shared_ptr<Group> _group;

    Vector2 position0;
    Vector2 position1;
    Vector2 position2;
    Vector2 position3;
};


#endif//EXAM_TETRIS_TETRINO_HPP
