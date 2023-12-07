
#include "TetrisScene.hpp"
//#include "MyKeyListener.hpp"
#include "TetrisGame.hpp"
#include <iostream>
#include <threepp/threepp.hpp>
#include "ThreeppHelper.hpp"

using namespace threepp;

TetrisScene::TetrisScene(TetrisGame &game)
    : _canvas("Tetris", {{"aa", 4}}),
      _renderer(_canvas.size()),
      _textRenderer(),
      _scene(Scene::create()),
      _camera(PerspectiveCamera::create()),
      _clock(),
      _game(game)
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

//void TetrisScene::addKeyListener(MyKeyListener &l) {
//    _canvas.addKeyListener(&l);
//}

void TetrisScene::_updateScene() {

    _scene->clear();
    auto borderGroup = _game.getBorderGroup();
    _scene->add(borderGroup);

    auto board = _game.getBoard();
    for (int row = 0; row < 24; row++)
    {
        for (int col = 0; col < 17; col++)
        {
            auto color = board.at(row).at(col);
            if (color != Color{0, 0, 0})
            {
                Vector3 pos = {static_cast<float>(col), static_cast<float>(row), 0};
                _scene->add(ThreeppHelper::createBox(pos, color));
            }
        }
    }
}

void TetrisScene::animateCanvas() {

    int iterations = 0;
    _canvas.animate([&] {

        _updateScene();
        _renderer.render(*_scene, *_camera);
        _renderer.resetState();                                 // needed when using TextRenderer
        _textRenderer.render();

        iterations++;

        if (iterations % 60 == 0) {
            _game.moveDown();
        }

        _textHandles.at(0)->setText("Points: " + std::to_string(_game.pointsValue));
    });
}
