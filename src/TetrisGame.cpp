
#include "TetrisGame.hpp"
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"
#include <random>


using namespace threepp;

                                                                            //randomTetrino()
TetrisGame::TetrisGame(): _borderGroup(Group::create()), _current_tetrino(Shapes::J, {0, 10, 0}, Color::orange) {

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
        if (pos.x <= 1) {
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

//    for (int ix = 0; ix < 4; ix++)
//    {
//        auto pos = positions.at(ix);
//        auto off = offsets.at(ix);
//
//        _boardGrid.at(pos.y).at(pos.x) = false;
//        _boardGrid.at(pos.y + off.y).at(pos.x + off.x) = true;
//
//        newPos.at(ix) = {pos.x + off.x, pos.y + off.y, 0};
//    }
}

void TetrisGame::rotateI() {
    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();

    std::array<Vector3, 4> newPos;
    std::array<Vector2, 4> offsets;

    switch (orientation) {

        case UP: {
            offsets.at(0) = {2, -1};
            offsets.at(1) = {1, 0};
            offsets.at(2) = {0, 1};
            offsets.at(3) = {-1, 2};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, -1};
            offsets.at(3) = {2, -2};

            _current_tetrino.setOrientation(Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-2, -2};
            offsets.at(1) = {-1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, 1};

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT:{
            offsets.at(0) = {1, 2};
            offsets.at(1) = {0, 1};
            offsets.at(2) = {-1, 0};
            offsets.at(3) = {-2, -1};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }
    for (int ix = 0; ix < 4; ix++)
    {
        auto pos = positions.at(ix);
        auto off = offsets.at(ix);

        _boardGrid.at(pos.y).at(pos.x) = false;
        _boardGrid.at(pos.y + off.y).at(pos.x + off.x) = true;

        newPos.at(ix) = {pos.x + off.x, pos.y + off.y, 0};
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::rotateJ() {
    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();

    std::array<Vector3, 4> newPos;
    std::array<Vector2, 4> offsets;

    switch (orientation) {

        case UP: {
            offsets.at(0) = {1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, 1};
            offsets.at(3) = {0, 2};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, 1};
            offsets.at(3) = {2, 0};

            _current_tetrino.setOrientation(Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, -1};
            offsets.at(3) = {0, -2};

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, -1};
            offsets.at(3) = {-2, 0};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }
    for (int ix = 0; ix < 4; ix++)
    {
        auto pos = positions.at(ix);
        auto off = offsets.at(ix);

        _boardGrid.at(pos.y).at(pos.x) = false;
        _boardGrid.at(pos.y + off.y).at(pos.x + off.x) = true;

        newPos.at(ix) = {pos.x + off.x, pos.y + off.y, 0};
    }

    _current_tetrino.setPositions(newPos);
    _current_tetrino.updateGroup();
}

void TetrisGame::rotateL() {
    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();

    std::array<Vector3, 4> newPos;
    std::array<Vector2, 4> offsets;

    switch (orientation) {

        case UP: {
            offsets.at(0) = {1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, 1};
            offsets.at(3) = {-2, 0};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, 1};
            offsets.at(3) = {0, 2};

            _current_tetrino.setOrientation(Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, -1};
            offsets.at(3) = {2, 0};

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, -1};
            offsets.at(3) = {0, -2};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }
    for (int ix = 0; ix < 4; ix++)
    {
        auto pos = positions.at(ix);
        auto off = offsets.at(ix);

        _boardGrid.at(pos.y).at(pos.x) = false;
        _boardGrid.at(pos.y + off.y).at(pos.x + off.x) = true;

        newPos.at(ix) = {pos.x + off.x, pos.y + off.y, 0};
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
