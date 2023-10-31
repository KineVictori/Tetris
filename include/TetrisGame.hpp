
#ifndef EXAM_TETRIS_TETRISGAME_HPP
#define EXAM_TETRIS_TETRISGAME_HPP

#include "threepp/threepp.hpp"
#include "TetrinoEnum.hpp"
#include "Tetrino.hpp"

using namespace threepp;


class TetrisGame {

public:
    TetrisGame();
    std::shared_ptr<Group> getBorderGroup ();
    std::shared_ptr<Group> getTetrinoGroup ();

private:
    std::shared_ptr<Group> _borderGroup;
    Tetrino _current_tetrino;

    //int gridSize_{};
};


#endif//EXAM_TETRIS_TETRISGAME_HPP
