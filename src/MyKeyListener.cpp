
#include "MyKeyListener.hpp"
#include <threepp/threepp.hpp>

using namespace threepp;

// sets the keys to move the tetrinos
MyKeyListener::MyKeyListener (TetrisGame& tetrisGame): _tetrisGame(tetrisGame) {}

void MyKeyListener::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::D) {            // override? Ask!
        _tetrisGame.moveRight();
    }
    if (evt.key == Key::A) {
        _tetrisGame.moveLeft();
    }
    if (evt.key == Key::S) {
        _tetrisGame.moveDown();
    }
    if (evt.key == Key::W) {
        _tetrisGame.rotateTetrino();
    }
}

void MyKeyListener::onKeyRepeat(KeyEvent evt) {
    if (evt.key == Key::D) {
        _tetrisGame.moveRight();
    }
    if (evt.key == Key::A) {
        _tetrisGame.moveLeft();
    }
    if (evt.key == Key::S) {
        _tetrisGame.moveDown();
    }
}

void setDeltaTime(float dt);
