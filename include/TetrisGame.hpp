
#ifndef EXAM_TETRIS_TETRISGAME_HPP
#define EXAM_TETRIS_TETRISGAME_HPP

#include <threepp/threepp.hpp>
#include "TetrinoEnum.hpp"
#include "Tetrino.hpp"

using namespace threepp;


class TetrisGame {

public:
    TetrisGame();
    std::shared_ptr<Group> getBorderGroup ();
    std::shared_ptr<Group> getTetrinoGroup ();

    void moveLeft();
    void moveRight();
    void moveDown();

    void rotateI();
    void rotateJ();
    void rotateL();
    void rotateS();
    void rotateZ();
    void rotateT();

    void rotateTetrino();
    Tetrino randomTetrino();

private:
    std::shared_ptr<Group> _borderGroup;
    Tetrino _current_tetrino;

    std::array<std::array<bool, 17>, 24> _boardGrid = {false};

};


#endif//EXAM_TETRIS_TETRISGAME_HPP
