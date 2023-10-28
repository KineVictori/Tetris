
#include "TetrisGame.hpp"
#include "threepp/threepp.hpp"
#include "ThreeppHelper.hpp"

using namespace threepp;

TetrisGame::TetrisGame(): _group(Group::create()) {}

void TetrisGame::Border(const threepp::Vector3& pos, const threepp::Color& color) {          // hvor pos

    // lower line
    for (int i = -10; i < 11; i++) {
        _group->add(ThreeppHelper::createBox({static_cast<float>(i), -14, 0}, color));
    }

    // side lines
    for (int i = -13; i < 17; i++) {
        _group->add(ThreeppHelper::createBox({10, static_cast<float>(i), 0}, color));
        _group->add(ThreeppHelper::createBox({-10, static_cast<float>(i), 0}, color));
    }
}

std::shared_ptr<Group> TetrisGame::getGroup() {             // hvor bruk
    return _group;
}