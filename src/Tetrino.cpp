
#include "Tetrino.hpp"
#include "threepp/threepp.hpp"
#include "ThreeppHelper.hpp"
#include "TetrinoEnum.hpp"

using namespace threepp;

// creates the boxes

Tetrino::Tetrino(shapes shape, const threepp::Vector3& pos, const threepp::Color& color): _group(Group::create()) {
    auto box0 = ThreeppHelper::createBox(pos, color);

    //switch statement for shape
    switch (shape) {

        case shapes::I: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -3, 0}, color));
        } break;

        case shapes::J: {
            _group->add(ThreeppHelper::createBox({0, 0, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -1, 0}, color));
            _group->add(ThreeppHelper::createBox({0, -2, 0}, color));
            _group->add(ThreeppHelper::createBox({-1, -2, 0}, color));
        } break;
    }




    //    auto group = Group::create();
    //    group->add(createBox({-1, 0, 0}, Color::orange));
    //    group->add(createBox({1, 0, 0}, Color::yellow));
    //    scene->add(group);
}

std::shared_ptr<Group> Tetrino::getGroup() {
    return _group;
}