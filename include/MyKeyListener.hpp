
#ifndef EXAM_TETRIS_MYKEYLISTENER_HPP
#define EXAM_TETRIS_MYKEYLISTENER_HPP

#include "threepp/threepp.hpp"

using namespace threepp;


// sets the keys to control the boxes
class MyKeyListener: public KeyListener {

    public:
        MyKeyListener(Object3D& obj);

        void onKeyPressed(KeyEvent evt);

        void onKeyRepeat(KeyEvent evt);

        void setDeltaTime(float dt);

    private:
        float dt_{0};
        Object3D& obj_;
};



#endif//THREEPP_VCPKG_DEMO_MYKEYLISTENER_HPP
