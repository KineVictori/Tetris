
#include "MyKeyListener.hpp"
#include <threepp/threepp.hpp>

#include <iostream>

using namespace threepp;

// sets the keys to move the tetrinos
MyKeyListener::MyKeyListener (TetrisScene &tetrisGame): _tetrisGame(tetrisGame) {}

void MyKeyListener::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::D) {            // override? Ask!
        _tetrisGame.moveRight();
    }
    if (evt.key == Key::A) {
        _tetrisGame.moveLeft();
    }
    if (evt.key == Key::S) {
        _tetrisGame.moveDown(false);
    }
    if (evt.key == Key::W) {
        _tetrisGame.rotateTetrino();
    }
    if (evt.key == Key::SPACE) {
        _tetrisGame.moveDown(true);
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
        _tetrisGame.moveDown(false);
    }
}

void setDeltaTime(float dt);
