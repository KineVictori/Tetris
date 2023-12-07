
#include <threepp/threepp.hpp>
#include "MyKeyListener.hpp"
#include "TetrisGame.hpp"
#include "TetrisScene.hpp"
#include <iostream>

using namespace threepp;


int main() {



// implements TetrisGame in main
    TetrisGame game{};
    TetrisScene sceneHandler{game};

    MyKeyListener l(sceneHandler);
    sceneHandler.getCanvas().addKeyListener(&l);
    //sceneHandler.addKeyListener(l);

    sceneHandler.animateCanvas();
}

