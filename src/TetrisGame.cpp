
#include "TetrisGame.hpp"
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"

using namespace threepp;


TetrisGame::TetrisGame(): _borderGroup(Group::create()), _current_tetrino({Shapes::T, {0, 10, 0}, Color::orange}) {

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

// controls for MyKeyListener
void TetrisGame::moveLeft() {
    auto positions = _current_tetrino.getPositions();

    for (auto pos : positions) {
        if (pos.x >= 6) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.x).at(pos.y) = false;         // removes the positions from the grid array
    }

    if (_current_tetrino.getGroup()->position.x > -6) {
        _current_tetrino.getGroup()->position.x -= 1;
    }
}

void TetrisGame::moveRight() {
    auto positions = _current_tetrino.getPositions();

    for (auto pos : positions) {
        if (pos.x >= 6) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.x).at(pos.y) = false;
    }

    if (_current_tetrino.getGroup()->position.x < 6) {
        _current_tetrino.getGroup()->position.x += 1;
    }
}

void TetrisGame::moveDown() {
    auto positions = _current_tetrino.getPositions();

    for (auto pos : positions) {
        if (pos.y <= -9) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.x).at(pos.y) = false;
    }

    if (_current_tetrino.getGroup()->position.y > -9) {
        _current_tetrino.getGroup()->position.y -= 1;
    }
}

void TetrisGame::rotateTetrino() {
    _current_tetrino.getGroup()->rotateZ(-3.1415926 / 2); // lag ny kode
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