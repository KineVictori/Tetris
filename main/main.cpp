
#include <threepp/threepp.hpp>
#include "MyKeyListener.hpp"
#include "TetrisGame.hpp"
#include "TetrisScene.hpp"

using namespace threepp;


int main() {

    TetrisScene sceneHandler;

// implements TetrisGame in main
    TetrisGame game{};
//    game.sceneHandler = &sceneHandler;
    game.newTetrinoSceneFunction = TetrisScene::newTetrino;
    game.removeTetrinoSceneFunction = TetrisScene::removeTetrino;

// sets the Tetrino (via TetrisGame) to move with keys
    MyKeyListener l(game);
    sceneHandler.addKeyListener(l);

// adds the border and tetrinos in the scene
    TetrisScene::getScene()->add(game.getBorderGroup());
    TetrisScene::newTetrino(game.getCurrentTetrino());

    // animates canvas
    sceneHandler.animateCanvas(game);
}

