
#include "Tetrino.hpp"
#include "Enums.hpp"
#include "ThreeppHelper.hpp"
#include <array>
#include <threepp/threepp.hpp>

using namespace threepp;

// creates the boxes

Tetrino::Tetrino(Shapes shape, const threepp::Vector3& pos, const threepp::Color& color)
    : _group(Group::create()), _shape(shape), _orientation(Orientation::UP), color(color) {

    //switch statement for shape
    switch (shape) {

        case Shapes::I: {

            position0 = {9, 23, 0};
            position1 = {9, 22, 0};
            position2 = {9, 21, 0};
            position3 = {9, 20, 0};

        } break;

        case Shapes::J: {

            position0 = {9, 23, 0};
            position1 = {9, 22, 0};
            position2 = {9, 21, 0};
            position3 = {8, 21, 0};

        } break;

        case Shapes::O: {

            position0 = {8, 23, 0};
            position1 = {9, 23, 0};
            position2 = {8, 22, 0};
            position3 = {9, 22, 0};

        } break;

        case Shapes::S: {

            position0 = {10, 23, 0};
            position1 = {9, 23, 0};
            position2 = {9, 22, 0};
            position3 = {8, 22, 0};

        } break;

        case Shapes::Z: {

            position0 = {8, 23, 0};
            position1 = {9, 23, 0};
            position2 = {9, 22, 0};
            position3 = {10, 22, 0};

        } break;

        case Shapes::L: {

            position0 = {9, 23, 0};
            position1 = {9, 22, 0};
            position2 = {9, 21, 0};
            position3 = {10, 21, 0};

        } break;

        case Shapes::T: {

            position0 = {9, 22, 0};
            position1 = {8, 23, 0};
            position2 = {9, 23, 0};
            position3 = {10, 23, 0};

        } break;
    }

    _box0 = ThreeppHelper::createBox(position0, color);
    _box1 = ThreeppHelper::createBox(position1, color);
    _box2 = ThreeppHelper::createBox(position2, color);
    _box3 = ThreeppHelper::createBox(position3, color);

    _group->add(_box0);
    _group->add(_box1);
    _group->add(_box2);
    _group->add(_box3);
}

void Tetrino::updateGroup() {
    _box0->position.copy(position0);
    _box1->position.copy(position1);
    _box2->position.copy(position2);
    _box3->position.copy(position3);
}

std::shared_ptr<Group> Tetrino::getGroup() {
    return _group;
}

std::array<Vector3, 4> Tetrino::getPositions() {
    std::array<Vector3, 4> totalPos = {position0, position1, position2, position3};
    return totalPos;
}

Shapes Tetrino::getShape() {
    return _shape;
}

Orientation Tetrino::getOrientation() {
    return _orientation;
}

void Tetrino::setOrientation(Orientation orientation) {
    _orientation = orientation;
}

void Tetrino::setPositions(std::array<Vector3, 4> newPos) {
    position0 = newPos.at(0);
    position1 = newPos.at(1);
    position2 = newPos.at(2);
    position3 = newPos.at(3);
}
