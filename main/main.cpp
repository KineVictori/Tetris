
#include <threepp/threepp.hpp>
#include "MyKeyListener.hpp"
#include "TetrisGame.hpp"
#include "TetrisScene.hpp"

using namespace threepp;


int main() {

    TetrisScene sceneHandler;

// implements TetrisGame in main
    TetrisGame game{};

// sets the Tetrino (via TetrisGame) to move with keys
    MyKeyListener l(game);
    sceneHandler.addKeyListener(l);

// adds the border and tetrinos in the scene
    sceneHandler.getScene()->add(game.getBorderGroup());
    sceneHandler.getScene()->add(game.getTetrinoGroup());

    // animates canvas
    sceneHandler.animateCanvas(game);
}

