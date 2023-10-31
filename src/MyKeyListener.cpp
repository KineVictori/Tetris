
#include "MyKeyListener.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;

// sets the keys to move the boxes
MyKeyListener::MyKeyListener (TetrisGame& TetrisGame): TetrisGame_(TetrisGame) {}

void MyKeyListener::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::D) {            // override? Ask!
        TetrisGame_.getTetrinoGroup()->position.x += 1;
    }
    if (evt.key == Key::A) {
        TetrisGame_.getTetrinoGroup()->position.x -= 1;
    }
    if (evt.key == Key::W) {            // rotate later
        TetrisGame_.getTetrinoGroup()->position.y += 1;
    }
    if (evt.key == Key::S) {
        TetrisGame_.getTetrinoGroup()->position.y -= 1;
    }
}

void MyKeyListener::onKeyRepeat(KeyEvent evt) {
    if (evt.key == Key::D) {
        TetrisGame_.getTetrinoGroup()->position.x += 1;
    }
    if (evt.key == Key::A) {
        TetrisGame_.getTetrinoGroup()->position.x -= 1;
    }
    if (evt.key == Key::W) {            // rotate later
        TetrisGame_.getTetrinoGroup()->position.y += 1;
    }
    if (evt.key == Key::S) {
        TetrisGame_.getTetrinoGroup()->position.y -= 1;
    }
}

void setDeltaTime(float dt);
