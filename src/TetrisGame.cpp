
#include "TetrisGame.hpp"
#include "threepp/threepp.hpp"
#include "ThreeppHelper.hpp"

using namespace threepp;

//int size = game
//grid

TetrisGame::TetrisGame(): _borderGroup(Group::create()), _current_tetrino({shapes::T, {0, 10, 0}, Color::orange}) {

    // lower line
    for (int i = -8; i < 9; i++) {
        _borderGroup->add(ThreeppHelper::createBox({static_cast<float>(i), -11, 0}, Color::gray));
    }

    // side lines
    for (int i = -10; i < 14; i++) {
        _borderGroup->add(ThreeppHelper::createBox({8, static_cast<float>(i), 0}, Color::gray));
        _borderGroup->add(ThreeppHelper::createBox({-8, static_cast<float>(i), 0}, Color::gray));
    }

}

std::shared_ptr<Group> TetrisGame::getBorderGroup() {
    return _borderGroup;
}

std::shared_ptr<Group> TetrisGame::getTetrinoGroup() {
    return _current_tetrino.getGroup();
}

//explicit TetrisGame(int gridSize)
//    : gridSize_(gridSize),
//      snake_(gridSize / 2, gridSize / 2) {
//
//    reset();
//}
//
//[[nodiscard]] int gridSize() const {
//    return gridSize_;
//}
//
//if (checkBorderCollision(nextMove) || snake_.checkSelfCollision(nextMove)) {
//    running_ = false;
//    return;
//}
//
//// check border collision
//[[nodiscard]] bool checkBorderCollision(const Vector2& pos) const {
//    auto size = static_cast<float>(gridSize_);
//    if (pos.x < 0 || pos.x >= size) return true;
//    if (pos.y < 0 || pos.y >= size) return true;
//
//    return false;
//}