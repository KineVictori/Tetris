
#include "MyKeyListener.hpp"
#include "threepp/threepp.hpp"

using namespace threepp;


// sets the keys to move the boxes
MyKeyListener::MyKeyListener (Object3D& obj): obj_(obj) {}

void MyKeyListener::onKeyPressed(KeyEvent evt) {
    if (evt.key == Key::D) {            // override? Ask!
        obj_.position.x -= 1 * dt_;
    }
    if (evt.key == Key::A) {
        obj_.position.x += 1 * dt_;
    }
    if (evt.key == Key::W) {            // rotate later
        obj_.position.y -= 1 * dt_;
    }
    if (evt.key == Key::S) {
        obj_.position.y += 1 * dt_;
    }
}

void MyKeyListener::onKeyRepeat(KeyEvent evt) {
    if (evt.key == Key::D) {
        obj_.position.x -= 1 * dt_;
    }
    if (evt.key == Key::A) {
        obj_.position.x += 1 * dt_;
    }
    if (evt.key == Key::W) {            // rotate later
        obj_.position.y -= 1 * dt_;
    }
    if (evt.key == Key::S) {
        obj_.position.y += 1 * dt_;
    }
}

void MyKeyListener::setDeltaTime(float dt) {
    dt_ = dt;
}
