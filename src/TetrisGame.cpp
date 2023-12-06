
#include "TetrisGame.hpp"
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"
#include <random>
#include "iostream"


using namespace threepp;


TetrisGame::TetrisGame(): _borderGroup(Group::create()), _currentTetrino(randomTetrino()) {
    renderedGroup = _currentTetrino.getGroup();

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
    return _currentTetrino.getGroup();
}

Tetrino TetrisGame::getCurrentTetrino() {
    return _currentTetrino;
}

// points
void TetrisGame::pointsCalculation(int rowsDeleted) {
    pointsValue += rowsDeleted * 1200;
}

bool TetrisGame::getBlock(int x, int y, Color color) {
    return _boardGrid.at(y).at(x);
}

void TetrisGame::addBlock(int x, int y, bool invisible, Color color) {
    _boardGrid.at(y).at(x) = true;

    if (invisible)
        return;

    auto box = ThreeppHelper::createBox({static_cast<float>(x), static_cast<float>(y), 0}, color);
    _borderGroup->add(box);
    _boxes.push_back(box);
}

void TetrisGame::delBlock(int x, int y, bool invisible) {
    _boardGrid.at(y).at(x) = false;

    if (invisible)
        return;

    std::shared_ptr<Mesh> box;
    for (int i = 0 ; i < _boxes.size() ; i++) {
        auto _box = _boxes[i];
        if (_box->position.x == static_cast<float>(x) && _box->position.y == static_cast<float>(y)) {
            box = _box;
            break;
        }
    }

    _borderGroup->remove(*box);
}

// controls for MyKeyListener
void TetrisGame::moveLeft() {
    auto positions = _currentTetrino.getPositions();

    for (auto pos : positions) {
        if (pos.x <= 1) {
            return;
        }
    }

    for (auto pos : positions) {
        delBlock(pos.x, pos.y, true);       // removes the positions from the grid array
    }

    for (auto pos : positions) {                      // if tetrino crashes, don't move sideways
        if (_boardGrid.at(pos.y).at(pos.x - 1)) {
            for (auto pos : positions) {
                addBlock(pos.x, pos.y, true);
            }
            return;
        }
    }

    for (auto pos : positions) {
        addBlock(pos.x - 1, pos.y, true);       // creates new blocks in new position
    }

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.x -= 1;
        newPos.at(i) = tmp;
    }

    _currentTetrino.setPositions(newPos);
    _currentTetrino.updateGroup();
}

void TetrisGame::moveRight() {
    auto positions = _currentTetrino.getPositions();

    for (auto pos : positions) {
        if (pos.x >= 16) {
            return;
        }
    }

    for (auto pos : positions) {
        delBlock(pos.x, pos.y, true);
    }

    for (auto pos : positions) {
        if (_boardGrid.at(pos.y).at(pos.x + 1)) {

            for (auto pos : positions) {
                addBlock(pos.x, pos.y, true);
            }
            return;
        }
    }

    for (auto pos : positions) {
        addBlock(pos.x + 1, pos.y, true);
    }

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.x += 1;
        newPos.at(i) = tmp;
    }

    _currentTetrino.setPositions(newPos);
    _currentTetrino.updateGroup();
}

void TetrisGame::moveDown() {
    auto positions = _currentTetrino.getPositions();

    for (auto pos : positions) {
        delBlock(pos.x, pos.y, true);
    }

    for (auto pos : positions) {                      // if tetrino crashes downwards, stop it and send new tetrino
        if ((pos.y == 1) || (_boardGrid.at(pos.y - 1).at(pos.x))) {
            std::cout<< "129"<< std::endl;
            for (auto pos : positions) {
                addBlock(pos.x, pos.y, false, _currentTetrino.color);
            }
            removeTetrinoSceneFunction(_currentTetrino);
            _currentTetrino = randomTetrino();
            newTetrinoSceneFunction(_currentTetrino);

            pointsValue += 100;

            int rowsDeleted = moveRowDown();

            //moveRowDown();
            pointsCalculation(rowsDeleted);
            return;
        }
    }

    for (auto pos : positions) {
        addBlock(pos.x, pos.y - 1, true);
    }

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.y -= 1;
        newPos.at(i) = tmp;
    }

    _currentTetrino.setPositions(newPos);
    _currentTetrino.updateGroup();

    std::cout<< positions.at(0).x << "||"<< positions.at(0).y <<std::endl;

}

// remove full rows and move the others down
int TetrisGame::moveRowDown() {

    int lowestFullRow = -1;
    for (int i = 0 ; i < 22 ; i++) {
        auto row = _boardGrid.at(i);

        bool full = true;
        for (int x = 1 ; x < 17 ; x++) { // Kanskje 1 og 16, kanskje 17
            if (! row.at(x)) {full = false;}
        }

        if (full) {
            lowestFullRow = i;
            break;
        }
    }

    if (lowestFullRow != -1) {

        for (int y = lowestFullRow ; y < 20 ; y++) { // Kanskje 22 eller 23

            for (int x = 1 ; x < 17 ; x++) { // Kanskje 1 og 16, kanskje 17

                auto blockAbove = getBlock(x, y + 1);
                if (blockAbove) {
                    addBlock(x, y, false, _currentTetrino.color);
                }
                else {
                    delBlock(x, y);
                }
            }
        }
        return 1 + moveRowDown();
    }
    return 0;
}

// rotation for the different tetrino shapes
bool TetrisGame::rotateTetrino() {

    auto positions = _currentTetrino.getPositions();
    auto orientation = _currentTetrino.getOrientation();
    Orientation newOrientation;
    std::array<Vector3, 4> newPos;
    std::array<Vector2, 4> offsets;

    switch (_currentTetrino.getShape()) {
        case I: {
            newOrientation = rotateI(orientation, offsets);
        } break;

        case J: {
            newOrientation = rotateJ(orientation, offsets);
        } break;

        case L: {
            newOrientation = rotateL(orientation, offsets);
        } break;

        case S: {
            newOrientation = rotateS(orientation, offsets);
        } break;

        case Z: {
            newOrientation = rotateZ(orientation, offsets);
        } break;

        case T: {
            newOrientation = rotateT(orientation, offsets);
        } break;
    }

    float collideOffset = 0;
    bool willCollide = false;
    for (int ix = 0; ix < 4; ix++) {
        auto pos = positions.at(ix);
        auto off = offsets.at(ix);

        float leftBorderWall = 0.0;
        float rightBorderWall = 17.0;

        if (pos.x >= rightBorderWall || pos.x <= leftBorderWall /* || getBlock(pos.x, pos.y) collides with itself, fixable by not updating grid when moving*/) {
            willCollide = true;

            if (pos.x >= rightBorderWall) {
                float diff = rightBorderWall - pos.x - 1;
                if (diff < collideOffset) {
                    collideOffset = diff;
                }
            }
            if (pos.x <= leftBorderWall) {
                float diff = leftBorderWall - pos.x + 1;
                if (diff > collideOffset) {
                    collideOffset = diff;
                }
            }
        }
    }

    for (int ix = 0; ix < 4; ix++)
    {
        auto pos = positions.at(ix);
        auto off = offsets.at(ix);
        int newPosX = pos.x + off.x + collideOffset;
        int newPosY = pos.y + off.y;

        delBlock(pos.x, pos.y, true);
        addBlock(newPosX, newPosY, true);

        newPos.at(ix) = {static_cast<float>(newPosX), static_cast<float>(newPosY), 0};
    }

    _currentTetrino.setPositions(newPos);
    _currentTetrino.updateGroup();
    _currentTetrino.setOrientation(newOrientation);

    return true;
}

Orientation TetrisGame::rotateI(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {2, -1};
            offsets.at(1) = {1, 0};
            offsets.at(2) = {0, 1};
            offsets.at(3) = {-1, 2};

            return (Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, -1};
            offsets.at(3) = {2, -2};

            return (Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-2, -2};
            offsets.at(1) = {-1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, 1};

            return (Orientation::LEFT);

        } break;

        case LEFT:{
            offsets.at(0) = {1, 2};
            offsets.at(1) = {0, 1};
            offsets.at(2) = {-1, 0};
            offsets.at(3) = {-2, -1};

            return (Orientation::UP);

        } break;
    }
}

Orientation TetrisGame::rotateJ(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, 1};
            offsets.at(3) = {0, 2};

            return (Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, 1};
            offsets.at(3) = {2, 0};

            return (Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, -1};
            offsets.at(3) = {0, -2};

            return (Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, -1};
            offsets.at(3) = {-2, 0};

            return (Orientation::UP);

        } break;
    }
}

Orientation TetrisGame::rotateL(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, 1};
            offsets.at(3) = {-2, 0};

            return (Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-1, -1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, 1};
            offsets.at(3) = {0, 2};

            return (Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {1, -1};
            offsets.at(3) = {2, 0};

            return (Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {-1, -1};
            offsets.at(3) = {0, -2};

            return (Orientation::UP);

        } break;
    }
}

Orientation TetrisGame::rotateS(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {0, -2};
            offsets.at(1) = {1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, 1};

            return (Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {-2, 0};
            offsets.at(1) = {-1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, -1};

            return (Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {0, 2};
            offsets.at(1) = {-1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, -1};

            return (Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {2, 0};
            offsets.at(1) = {1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, 1};

            return (Orientation::UP);

        } break;
    }
}

Orientation TetrisGame::rotateZ(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {2, 0};
            offsets.at(1) = {1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, -1};

            return (Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {0, -2};
            offsets.at(1) = {-1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, 1};

            return (Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {-2, 0};
            offsets.at(1) = {-1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, 1};

            return (Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {0, 2};
            offsets.at(1) = {1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, -1};

            return (Orientation::UP);

        } break;
    }
}

Orientation TetrisGame::rotateT(Orientation orientation, std::array<Vector2, 4> &offsets) {

    switch (orientation) {

        case UP: {
            offsets.at(0) = {0, 0};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {-1, 1};

            return (Orientation::RIGHT);

        } break;

        case RIGHT: {
            offsets.at(0) = {1, 1};
            offsets.at(1) = {0, 0};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {0, 0};

            return (Orientation::DOWN);

        } break;

        case DOWN: {
            offsets.at(0) = {0, 0};
            offsets.at(1) = {1, -1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {0, 0};

            return (Orientation::LEFT);

        } break;

        case LEFT: {
            offsets.at(0) = {-1, -1};
            offsets.at(1) = {-1, 1};
            offsets.at(2) = {0, 0};
            offsets.at(3) = {1, -1};

            return (Orientation::UP);

        } break;
    }
}

// random shape and color
Tetrino TetrisGame::randomTetrino() {
    // random number generator code copied from Cornstalks on StackOverflow
    std::random_device dev;         // sett alle 3 statisk
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
