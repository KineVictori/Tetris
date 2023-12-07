
#ifndef EXAM_TETRIS_TETRISGAME_HPP
#define EXAM_TETRIS_TETRISGAME_HPP

#include "Enums.hpp"
#include "Tetrino.hpp"
#include <threepp/threepp.hpp>

using namespace threepp;

class TetrisScene;

class TetrisGame {

public:
    TetrisGame();

    int pointsValue = 0;
    void pointsCalculation(int rowsDeleted);

    std::shared_ptr<Group> getBorderGroup ();

    void moveLeft();
    void moveRight();
    void moveDown(bool allTheWay = false);

    static Orientation rotateI(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateJ(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateL(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateS(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateZ(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateT(Orientation orientation, std::array<Vector2, 4> &offsets);

    bool rotateTetrino();
    static Tetrino randomTetrino();
    static Color randomColor();

    int moveRowDown();

    std::shared_ptr<Group> renderedGroup;
    std::array<std::array<Color, 20>, 28>& getBoard();

private:
    std::shared_ptr<Group> _borderGroup;
    Tetrino _currentTetrino;

    std::vector<std::shared_ptr<Mesh>> _boxes = {};
    std::array<std::array<Color, 20>, 28> _boardGrid;

};


#endif//EXAM_TETRIS_TETRISGAME_HPP
