
#include "TetrisGame.hpp"
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"
#include <random>
#include "iostream"


using namespace threepp;


TetrisGame::TetrisGame(): _borderGroup(Group::create()), _current_tetrino(randomTetrino()) {
    renderedGroup = _current_tetrino.getGroup();

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

Tetrino TetrisGame::getTetrinoCopy() {
    return _current_tetrino;
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
        _boardGrid.at(pos.x - 1).at(pos.y) = true;      // creates new blocks in new position
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

//    for (auto pos : positions) {
//        if (pos.y <= 1) {
//            return;
//        }
//    }

    for (auto pos : positions) {
        _boardGrid.at(pos.y).at(pos.x) = false;
    }

    for (auto pos : positions) {
        if ((pos.y == 1) || (_boardGrid.at(pos.y - 1).at(pos.x))) {
            std::cout<< "99"<< std::endl;
            for (auto pos : positions) {
                _boardGrid.at(pos.y).at(pos.x) = true;
            }
            _current_tetrino = randomTetrino();
//            sceneHandler->getScene()->add(getTetrinoGroup());
//            renderedGroup = _current_tetrino.getGroup();
            newTetrinoSceneFunction(_current_tetrino);
            return;
        }
    }

    for (auto pos : positions) {
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

    std::cout<< positions.at(0).x << "||"<< positions.at(0).y <<std::endl;
}

void TetrisGame::rotateTetrino() {

    auto positions = _current_tetrino.getPositions();
    auto orientation = _current_tetrino.getOrientation();
    std::array<Vector3, 4> newPos;
    std::array<Vector2, 4> offsets;

    switch (_current_tetrino.getShape()) {
        case I: {
            rotateI(orientation, offsets);
        } break;

        case J: {
            rotateJ(orientation, offsets);
        } break;

        case L: {
            rotateL(orientation, offsets);
        } break;

        case S: {
            rotateS(orientation, offsets);
        } break;

        case Z: {
            rotateZ(orientation, offsets);
        } break;

        case T: {
            rotateT(orientation, offsets);
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

void TetrisGame::rotateI(Orientation orientation, std::array<Vector2, 4> &offsets) {

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
}

void TetrisGame::rotateJ(Orientation orientation, std::array<Vector2, 4> &offsets) {

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
}

void TetrisGame::rotateL(Orientation orientation, std::array<Vector2, 4> &offsets) {

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
}

void TetrisGame::rotateS(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {0, -2};
            offsets.at(1) = {1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, 1};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-2, 0};
            offsets.at(1) = {-1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, -1};

            _current_tetrino.setOrientation(Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {0, 2};
            offsets.at(1) = {-1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, -1};

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {2, 0};
            offsets.at(1) = {1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, 1};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }
}

void TetrisGame::rotateZ(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {2, 0};
            offsets.at(1) = {1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, -1};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {0, -2};
            offsets.at(1) = {-1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, 1};

            _current_tetrino.setOrientation(Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-2, 0};
            offsets.at(1) = {-1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, 1};

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {0, 2};
            offsets.at(1) = {1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, -1};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }
}

void TetrisGame::rotateT(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {0, 0};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, 1};

            _current_tetrino.setOrientation(Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {0, 0};

            _current_tetrino.setOrientation(Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {0, 0};
            offsets.at(1) = {1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {0, 0};

            _current_tetrino.setOrientation(Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {-1, -1};
            offsets.at(1) = {-1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, -1};

            _current_tetrino.setOrientation(Orientation::UP);

        } break;
    }
}

Tetrino TetrisGame::randomTetrino() {
    // random number generator code copied from ...
    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_int_distribution<std::mt19937_64::result_type> randomNumber(0, 6);

    auto shape = static_cast<Shapes> (randomNumber(rng));

    return {shape, {0, 10, 0}, randomColor()};
}

Color TetrisGame::randomColor() {
    std::array<Color, 7> colors = {Color::hotpink, Color::orange, Color::mediumseagreen, Color::deepskyblue, Color::springgreen, Color::blueviolet, Color::gold};

    std::random_device dev;
    std::mt19937_64 rng(dev());
    std::uniform_int_distribution<std::mt19937_64::result_type> randomNumber(0, 6);

    return colors[randomNumber(rng)];
}
