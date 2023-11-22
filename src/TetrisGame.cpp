
#include "TetrisGame.hpp"
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"
#include <random>


using namespace threepp;

                                                                            //randomTetrino()
TetrisGame::TetrisGame(): _borderGroup(Group::create()), _current_tetrino(Shapes::L, {0, 10, 0}, Color::orange) {

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
        _boardGrid.at(pos.x - 1).at(pos.y) = true;
    }

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.x -= 1;
        newPos.at(i) = tmp;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::moveRight() {
    auto positions = _current_tetrino.getPositions();

    for (auto pos : positions) {
        if (pos.x >= 16) {
            return;
        }
    }

    for (auto pos : positions) {
        _boardGrid.at(pos.x).at(pos.y) = false;
        _boardGrid.at(pos.x + 1).at(pos.y) = true;
    }

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.x += 1;
        newPos.at(i) = tmp;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
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

        case J: {
            rotateJ();
        } break;

        case L: {
            rotateL();
        } break;

        case S: {
            rotateS();
        } break;

        case Z: {
            rotateZ();
        } break;

        case T: {
            rotateT();
        } break;
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
            _boardGrid.at(pos0.y - 1 ).at(pos0.x + 2) = true;

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

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 1).at(pos0.x - 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y - 1).at(pos2.x + 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y - 2).at(pos3.x + 2) = true;

            newPos.at(0) = {pos0.x - 1, pos0.y + 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x + 1, pos2.y - 1, 0};
            newPos.at(3) = {pos3.x + 2, pos3.y - 2, 0};

            _current_tetrino.setOrientation(Orientation::DOWN);

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

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT:{
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 2).at(pos0.x + 1) = true;

            auto pos1 = positions.at(1);
            _boardGrid.at(pos1.y).at(pos1.x) = false;
            _boardGrid.at(pos1.y + 1).at(pos1.x) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y).at(pos2.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y - 1).at(pos3.x - 2) = true;

            newPos.at(0) = {pos0.x + 1, pos0.y + 2, 0};
            newPos.at(1) = {pos1.x, pos1.y + 1, 0};
            newPos.at(2) = {pos2.x - 1, pos2.y, 0};
            newPos.at(3) = {pos3.x - 2, pos3.y - 1, 0};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::rotateJ() {
    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();

    std::array<Vector3, 4> newPos;
    switch (orientation) {

        case UP: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y - 1).at(pos0.x + 1) = true;

            auto pos1 = positions.at(1);
            _boardGrid.at(pos1.y).at(pos1.x) = false;
            _boardGrid.at(pos1.y).at(pos1.x) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y + 1).at(pos2.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y + 2).at(pos3.x) = true;

            newPos.at(0) = {pos0.x + 1, pos0.y - 1, 0};
            newPos.at(1) = {pos1.x, pos1.y, 0};
            newPos.at(2) = {pos2.x - 1, pos2.y + 1, 0};
            newPos.at(3) = {pos3.x, pos3.y + 2, 0};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y - 1).at(pos0.x - 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y + 1).at(pos2.x + 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y).at(pos3.x + 2) = true;

            newPos.at(0) = {pos0.x - 1, pos0.y - 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x + 1, pos2.y + 1, 0};
            newPos.at(3) = {pos3.x + 2, pos3.y, 0};

            _current_tetrino.setOrientation(Orientation::DOWN);
        } break;

        case DOWN: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 1).at(pos0.x - 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y - 1).at(pos2.x + 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y - 2).at(pos3.x) = true;

            newPos.at(0) = {pos0.x - 1, pos0.y + 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x + 1, pos2.y - 1, 0};
            newPos.at(3) = {pos3.x, pos3.y - 2, 0};

            _current_tetrino.setOrientation(Orientation::LEFT);
        } break;

        case LEFT: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 1).at(pos0.x + 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y - 1).at(pos2.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y).at(pos3.x - 2) = true;

            newPos.at(0) = {pos0.x + 1, pos0.y + 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x - 1, pos2.y - 1, 0};
            newPos.at(3) = {pos3.x - 2, pos3.y, 0};

            _current_tetrino.setOrientation(Orientation::UP);
        } break;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::rotateL() {
    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();

    std::array<Vector3, 4> newPos;
    switch (orientation) {

        case UP: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y - 1).at(pos0.x + 1) = true;

            auto pos1 = positions.at(1);
            _boardGrid.at(pos1.y).at(pos1.x) = false;
            _boardGrid.at(pos1.y).at(pos1.x) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y + 1).at(pos2.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y).at(pos3.x - 2) = true;

            newPos.at(0) = {pos0.x + 1, pos0.y - 1, 0};
            newPos.at(1) = {pos1.x, pos1.y, 0};
            newPos.at(2) = {pos2.x - 1, pos2.y + 1, 0};
            newPos.at(3) = {pos3.x - 2, pos3.y, 0};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y - 1).at(pos0.x - 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y + 1).at(pos2.x + 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y + 2).at(pos3.x) = true;

            newPos.at(0) = {pos0.x - 1, pos0.y - 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x + 1, pos2.y + 1, 0};
            newPos.at(3) = {pos3.x, pos3.y + 2, 0};

            _current_tetrino.setOrientation(Orientation::DOWN);
        } break;

        case DOWN: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 1).at(pos0.x - 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y - 1).at(pos2.x + 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y).at(pos3.x + 2) = true;

            newPos.at(0) = {pos0.x - 1, pos0.y + 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x + 1, pos2.y - 1, 0};
            newPos.at(3) = {pos3.x + 2, pos3.y, 0};

            _current_tetrino.setOrientation(Orientation::LEFT);
        } break;

        case LEFT: {
            auto pos0 = positions.at(0);
            _boardGrid.at(pos0.y).at(pos0.x) = false;
            _boardGrid.at(pos0.y + 1).at(pos0.x + 1) = true;

            auto pos2 = positions.at(2);
            _boardGrid.at(pos2.y).at(pos2.x) = false;
            _boardGrid.at(pos2.y - 1).at(pos2.x - 1) = true;

            auto pos3 = positions.at(3);
            _boardGrid.at(pos3.y).at(pos3.x) = false;
            _boardGrid.at(pos3.y - 2).at(pos3.x) = true;

            newPos.at(0) = {pos0.x + 1, pos0.y + 1, 0};
            newPos.at(1) = {positions.at(1).x, positions.at(1).y, 0};
            newPos.at(2) = {pos2.x - 1, pos2.y - 1, 0};
            newPos.at(3) = {pos3.x, pos3.y - 2, 0};

            _current_tetrino.setOrientation(Orientation::UP);
        } break;
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::rotateS() {

}

void TetrisGame::rotateZ() {

}

void TetrisGame::rotateT() {

}

Tetrino TetrisGame::randomTetrino() {
    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_int_distribution<std::mt19937_64::result_type> random(0, 6);

    auto shape = static_cast<Shapes> (random(rng));

    return {shape, {0, 10, 0}, Color::orange};
}
