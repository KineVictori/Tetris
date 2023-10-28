
#ifndef EXAM_TETRIS_TETRISGAME_HPP
#define EXAM_TETRIS_TETRISGAME_HPP

#include "threepp/threepp.hpp"
#include "TetrinoEnum.hpp"

using namespace threepp;


class TetrisGame {

public:
    TetrisGame();
    void Border(const threepp::Vector3& pos, const threepp::Color& color);
    std::shared_ptr<Group> getGroup ();

private:
    std::shared_ptr<Group> _group;
};


#endif//EXAM_TETRIS_TETRISGAME_HPP
