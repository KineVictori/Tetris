
#ifndef EXAM_TETRIS_TETRISGAME_HPP
#define EXAM_TETRIS_TETRISGAME_HPP

#include "Enums.hpp"
#include "Tetrino.hpp"
#include <threepp/threepp.hpp>

using namespace threepp;


class TetrisGame {

public:
    TetrisGame();
    std::shared_ptr<Group> getBorderGroup ();
    std::shared_ptr<Group> getTetrinoGroup ();

    void moveLeft();
    void moveRight();
    void moveDown();

    void rotateI(Orientation orientation, std::array<Vector2, 4> &offsets);
    void rotateJ(Orientation orientation, std::array<Vector2, 4> &offsets);
    void rotateL(Orientation orientation, std::array<Vector2, 4> &offsets);
    void rotateS(Orientation orientation, std::array<Vector2, 4> &offsets);
    void rotateZ(Orientation orientation, std::array<Vector2, 4> &offsets);
    void rotateT(Orientation orientation, std::array<Vector2, 4> &offsets);

    void rotateTetrino();
    Tetrino randomTetrino();

private:
    std::shared_ptr<Group> _borderGroup;
    Tetrino _current_tetrino;

    std::array<std::array<bool, 17>, 24> _boardGrid = {false};

};


#endif//EXAM_TETRIS_TETRISGAME_HPP
