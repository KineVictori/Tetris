
#include "TetrisScene.hpp"
#include "MyKeyListener.hpp"
#include "TetrisGame.hpp"
#include <iostream>
#include <threepp/threepp.hpp>

using namespace threepp;

TetrisScene::TetrisScene()
    : _canvas("Tetris", {{"aa", 4}}),
      _renderer(_canvas.size()),
      _textRenderer(),
      _camera(PerspectiveCamera::create()),
      _clock()
{
    // creates the canvas
    _canvas.setSize({600, 800});
    _renderer.setClearColor(0x183f3e); // use 0x for # in hex

    // sets the camera position
    _camera->position.set(8, 10, 30);
    _camera->aspect = _canvas.size().aspect();
    _camera->updateProjectionMatrix();
    _renderer.setSize(_canvas.size());

    // makes the canvas resize correctly on full screen
    _canvas.onWindowResize([&] (WindowSize size) {
        _camera->aspect = size.aspect();
        _camera->updateProjectionMatrix();
        _renderer.setSize(size);
    });

    // text
    auto& textHandle = _textRenderer.createHandle("Points: ");
    textHandle.verticalAlignment = threepp::TextHandle::VerticalAlignment::TOP;
    textHandle.setPosition(0, 0);
    textHandle.scale = 2;
    _textHandles.push_back(&textHandle);

}

std::shared_ptr<Scene> TetrisScene::getScene() {
    return _scene;
}

void TetrisScene::addKeyListener(MyKeyListener &l) {
    _canvas.addKeyListener(&l);
}

void TetrisScene::animateCanvas(TetrisGame &game) {

    // makes stuff move at a specific speed
    int iterations = 0;
    _canvas.animate([&] {
        auto dt = _clock.getDelta();
        //l.setDeltaTime(dt);

// noe skulle her ... husker ikke

        _renderer.render(*_scene, *_camera);
        _renderer.resetState();                                 // needed when using TextRenderer
        _textRenderer.render();

        iterations++;

        if (iterations % 60 == 0) {
            if (game.getTetrinoGroup()->position.y > (-21)) {
                game.moveDown();
            }
        }

//        _textHandles.at(0)->setText("Points: " + std::to_string(points()));
    });
}

void TetrisScene::newTetrino(Tetrino newTetrino) {
    getScene()->add(newTetrino.getGroup());
}

void TetrisScene::removeTetrino(Tetrino previousTetrino) {
//    getScene()->remove(previousTetrino.getGroup());

//    previousTetrino.getGroup()->removeFromParent();
    getScene()->remove(*previousTetrino.getGroup());

//    std::array<Vector3, 4> newPos;
//    for (int i = 0; i < 4; i++) {
//        newPos.at(i) = {0, -100, 0};
//    }
//
//    previousTetrino.setPositions(newPos);
//    previousTetrino.updateGroup();
}
