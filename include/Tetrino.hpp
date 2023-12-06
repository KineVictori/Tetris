
#ifndef EXAM_TETRIS_TETRINO_HPP
#define EXAM_TETRIS_TETRINO_HPP

#include "Enums.hpp"
#include <array>
#include <threepp/threepp.hpp>

using namespace threepp;


class Tetrino {

public:
    Tetrino(Shapes shape, const Vector3& pos, const Color& color);

    void setPositions(std::array<Vector3, 4> newPos);
    void setOrientation(Orientation orientation);

    std::array<Vector3, 4> getPositions();
    Orientation getOrientation();
    std::shared_ptr<Group> getGroup();
    Shapes getShape();

    void updateGroup();

private:
    std::shared_ptr<Group> _group;
    Shapes _shape;
    Orientation _orientation;

    std::shared_ptr<Mesh> _box0;
    std::shared_ptr<Mesh> _box1;
    std::shared_ptr<Mesh> _box2;
    std::shared_ptr<Mesh> _box3;

    Vector3 position0;
    Vector3 position1;
    Vector3 position2;
    Vector3 position3;
};


#endif//EXAM_TETRIS_TETRINO_HPP
