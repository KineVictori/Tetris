
#ifndef EXAM_TETRIS_MYKEYLISTENER_HPP
#define EXAM_TETRIS_MYKEYLISTENER_HPP

#include <threepp/threepp.hpp>
#include "TetrisGame.hpp"

using namespace threepp;


// sets the keys to control the boxes
class MyKeyListener: public KeyListener {

    public:
        explicit MyKeyListener(TetrisGame &tetrisGame);

        void onKeyPressed(KeyEvent evt) override;

        void onKeyRepeat(KeyEvent evt) override;

        //void setDeltaTime(float dt);

    private:
        //float dt_{0};
        TetrisGame &_tetrisGame;
};


#endif//EXAM_TETRIS_MYKEYLISTENER_HPP
