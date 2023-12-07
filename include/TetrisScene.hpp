
#ifndef EXAM_TETRIS_TETRISSCENE_HPP
#define EXAM_TETRIS_TETRISSCENE_HPP

#include <threepp/threepp.hpp>
#include "TetrisGame.hpp"
//#include "MyKeyListener.hpp"
#include <vector>

using namespace threepp;


class TetrisScene {

public:
    TetrisScene(TetrisGame &game);

    //void addKeyListener(MyKeyListener &l);
    void animateCanvas();

    Canvas& getCanvas() {return _canvas;}
    void moveRight() {_game.moveRight();}
    void moveLeft() {_game.moveLeft();}
    void rotateTetrino() {_game.rotateTetrino();}
    void moveDown(bool allTheWay) {_game.moveDown(allTheWay);}
private:
    Canvas _canvas;
    GLRenderer _renderer;
    TextRenderer _textRenderer;
    std::shared_ptr<PerspectiveCamera> _camera;
    std::shared_ptr<Scene> _scene;
    Clock _clock;

    void _updateScene();
    TetrisGame _game;

    std::vector<TextHandle*> _textHandles;
};


#endif//EXAM_TETRIS_TETRISSCENE_HPP
