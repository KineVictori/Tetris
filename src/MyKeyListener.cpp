
#include "MyKeyListener.hpp"
#include <threepp/threepp.hpp>

using namespace threepp;

// sets the keys to move the boxes
MyKeyListener::MyKeyListener (TetrisGame& TetrisGame): TetrisGame_(TetrisGame) {}

void MyKeyListener::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::D) {            // override? Ask!
        TetrisGame_.moveRight();
    }
    if (evt.key == Key::A) {
        TetrisGame_.moveLeft();
    }
    if (evt.key == Key::S) {
        TetrisGame_.moveDown();
    }
    if (evt.key == Key::W) {            // rotate later
        TetrisGame_.rotateTetrino();
    }
}

void MyKeyListener::onKeyRepeat(KeyEvent evt) {
    if (evt.key == Key::D) {
        TetrisGame_.moveRight();
    }
    if (evt.key == Key::A) {
        TetrisGame_.moveLeft();
    }
    if (evt.key == Key::S) {
        TetrisGame_.moveDown();
    }
}

void setDeltaTime(float dt);
