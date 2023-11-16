
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
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -3, 0}, color));

            position0 = {0, 0};
            position1 = {0, -1};
            position2 = {0, -2};
            position3 = {0, -3};

        } break;

        case Shapes::J: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -2, 0}, color));

            position0 = {0, 0};
            position1 = {0, -1};
            position2 = {0, -2};
            position3 = {-1, -2};

        } break;

        case Shapes::O: {
            _group->add(ThreeppHelper::createBox({-1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));

            position0 = {-1, 0};
            position1 = {0, -1};
            position2 = {-1, -1};
            position3 = {0, -1};

        } break;

        case Shapes::S: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -1, 0}, color));

            position0 = {0, 0};
            position1 = {1, -1};
            position2 = {0, -1};
            position3 = {-1, -1};

        } break;

        case Shapes::Z: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({1, -1, 0}, color));

            position0 = {0, 0};
            position1 = {-1, 0};
            position2 = {0, -1};
            position3 = {1, -1};

        } break;

        case Shapes::L: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({1, -2, 0}, color));

            position0 = {0, 0};
            position1 = {0, -1};
            position2 = {0, -2};
            position3 = {1, -2};

        } break;

        case Shapes::T: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, 0, 0}, color));

            position0 = {0, 0};
            position1 = {0, -1};
            position2 = {1, 0};
            position3 = {-1, 0};

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
