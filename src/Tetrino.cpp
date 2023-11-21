
#include "Tetrino.hpp"
#include <threepp/threepp.hpp>
#include <array>
#include "ThreeppHelper.hpp"
#include "TetrinoEnum.hpp"

using namespace threepp;

// creates the boxes

Tetrino::Tetrino(Shapes shape, const threepp::Vector3& pos, const threepp::Color& color): _group(Group::create()) {
    auto box0 = ThreeppHelper::createBox(pos, color);

    //switch statement for shape
    switch (shape) {

        case Shapes::I: {
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 21, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 20, 0}, color));

            position0 = {9, 23};
            position1 = {9, 22};
            position2 = {9, 21};
            position3 = {9, 20};

        } break;

        case Shapes::J: {
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 21, 0}, color));
            _group->add(ThreeppHelper::createBox({8, 21, 0}, color));

            position0 = {9, 23};
            position1 = {9, 22};
            position2 = {9, 21};
            position3 = {8, 21};

        } break;

        case Shapes::O: {
            _group->add(ThreeppHelper::createBox({8, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({8, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));

            position0 = {8, 23};
            position1 = {9, 23};
            position2 = {8, 22};
            position3 = {9, 22};

        } break;

        case Shapes::S: {
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({10, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({8, 22, 0}, color));

            position0 = {9, 23};
            position1 = {10, 23};
            position2 = {9, 22};
            position3 = {8, 22};

        } break;

        case Shapes::Z: {
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({8, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({10, 22, 0}, color));

            position0 = {9, 23};
            position1 = {8, 23};
            position2 = {9, 22};
            position3 = {10, 22};

        } break;

        case Shapes::L: {
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 21, 0}, color));
            _group->add(ThreeppHelper::createBox({10, 21, 0}, color));

            position0 = {9, 23};
            position1 = {9, 22};
            position2 = {9, 21};
            position3 = {10, 21};

        } break;

        case Shapes::T: {
            _group->add(ThreeppHelper::createBox({9, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({9, 22, 0}, color));
            _group->add(ThreeppHelper::createBox({10, 23, 0}, color));
            _group->add(ThreeppHelper::createBox({8, 23, 0}, color));

            position0 = {9, 23};
            position1 = {9, 22};
            position2 = {10, 23};
            position3 = {8, 23};

        } break;
    }
}

std::shared_ptr<Group> Tetrino::getGroup() {
    return _group;
}

std::array<Vector2, 4> Tetrino::getPositions() {
    std::array<Vector2, 4> totalPos = {position0, position1, position2, position3};
    return totalPos;
}
