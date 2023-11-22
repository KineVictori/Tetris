
#include "TetrisGame.hpp"
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"
#include <iostream>

using namespace threepp;


TetrisGame::TetrisGame(): _borderGroup(Group::create()), _current_tetrino({Shapes::I, {0, 10, 0}, Color::orange}) {

    // lower line
    for (int i = 0; i < 17; i++) {
        _borderGroup->add(ThreeppHelper::createBox({static_cast<float>(i), 0, 0}, Color::gray));
    }

    // side lines
    for (int i = 0; i < 24; i++) {
        _borderGroup->add(ThreeppHelper::createBox({0, static_cast<float>(i), 0}, Color::gray));
        _borderGroup->add(ThreeppHelper::createBox({17, static_cast<float>(i), 0}, Color::gray));
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
        if (pos.x <= 0) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.x).at(pos.y) = false;         // removes the positions from the grid array
    }

    if (_current_tetrino.getGroup()->position.x > 1) {
        _current_tetrino.getGroup()->position.x -= 1;
    }
}       // endre på samme måte som down

void TetrisGame::moveRight() {
    auto positions = _current_tetrino.getPositions();

    for (auto pos : positions) {
        if (pos.x >= 16) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.x).at(pos.y) = false;
    }

    if (_current_tetrino.getGroup()->position.x < 16) {
        _current_tetrino.getGroup()->position.x += 1;
    }
}

void TetrisGame::moveDown() {
    auto positions = _current_tetrino.getPositions();

    for (auto pos : positions) {
        if (pos.y <= 1) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.y).at(pos.x) = false;
        _boardGrid.at(pos.y - 1).at(pos.x) = true;
    }

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.y -= 1;
        newPos.at(i) = tmp;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::rotateTetrino() {
    //_current_tetrino.getGroup()->rotateZ(-3.1415926 / 2); // lag ny kode

    switch (_current_tetrino.getShape()) {
        case I: {
            rotateI();
        } break;

        case J:
            break;
        case L:
            break;
        case S:
            break;
        case Z:
            break;
        case T:
            break;
    }
}

void TetrisGame::rotateI() {
    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();

    std::array<Vector3, 4> newPos;
    switch (orientation) {

        case UP: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y -1 ).at(pos0.x + 2) = true;

            auto pos1 = positions.at(1);
            _boardGrid.at(pos1.y).at(pos1.x) = false;
            _boardGrid.at(pos1.y).at(pos1.x + 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y + 1).at(pos2.x) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y + 2).at(pos3.x - 1) = true;

            newPos.at(0) = {pos0.x + 2, pos0.y - 1, 0};
            newPos.at(1) = {pos1.x + 1, pos1.y, 0};
            newPos.at(2) = {pos2.x, pos2.y + 1, 0};
            newPos.at(3) = {pos3.x - 1, pos3.y + 2, 0};

            //fortsett sånn med alle boksene, og så med alle casene

        } break;

        case RIGHT: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.x).at(pos0.x) = false;
            _boardGrid.at(pos0.x - 1).at(pos0.x + 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.x).at(pos2.x) = false;
            _boardGrid.at(pos2.x + 1).at(pos2.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.x).at(pos3.x) = false;
            _boardGrid.at(pos3.x + 2).at(pos3.x - 2) = true;

            newPos.at(0) = {pos0.x + 1, pos0.y - 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x - 1, pos2.y + 1, 0};
            newPos.at(3) = {pos3.x - 2, pos3.y + 2, 0};

        } break;

        case DOWN: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y - 2).at(pos0.x - 2) = true;

            auto pos1 = positions.at(1);
            _boardGrid.at(pos1.y).at(pos1.x) = false;
            _boardGrid.at(pos1.y - 1).at(pos1.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y + 1).at(pos3.x + 1) = true;

            newPos.at(0) = {pos0.x - 2, pos0.y - 2, 0};
            newPos.at(1) = {pos1.x - 1, pos1.y - 1, 0};
            newPos.at(2) = {positions.at(2).x, positions.at(2).y, 0};
            newPos.at(3) = {pos3.x + 1, pos3.y + 1, 0};

        } break;

        case LEFT:{
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 1).at(pos0.x + 2) = true;

            auto pos1 = positions.at(1);
            _boardGrid.at(pos1.y).at(pos1.x) = false;
            _boardGrid.at(pos1.y + 1).at(pos1.x) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y - 1).at(pos2.x + 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y - 1).at(pos3.x - 2) = true;

            newPos.at(0) = {pos0.x + 2, pos0.y + 1, 0};
            newPos.at(1) = {pos1.x, pos1.y + 1, 0};
            newPos.at(2) = {pos2.x + 1, pos2.y - 1, 0};
            newPos.at(3) = {pos3.x - 2, pos3.y - 1, 0};

        } break;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
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