
#include "Tetrino.hpp"
#include <threepp/threepp.hpp>
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
        } break;

        case Shapes::J: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -2, 0}, color));
        } break;

        case Shapes::O: {
            _group->add(ThreeppHelper::createBox({-1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
        } break;

        case Shapes::S: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -1, 0}, color));
        } break;

        case Shapes::Z: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({1, -1, 0}, color));
        } break;

        case Shapes::L: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({1, -2, 0}, color));
        } break;

        case Shapes::T: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({1, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, 0, 0}, color));
        } break;
    }
}

std::shared_ptr<Group> Tetrino::getGroup() {
    return _group;
}