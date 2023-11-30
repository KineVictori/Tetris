
#ifndef EXAM_TETRIS_TETRISSCENE_HPP
#define EXAM_TETRIS_TETRISSCENE_HPP

#include <threepp/threepp.hpp>
#include "TetrisGame.hpp"
#include "MyKeyListener.hpp"
#include <vector>

using namespace threepp;


class TetrisScene {

public:
    TetrisScene();

    static std::shared_ptr<Scene> getScene();
    void addKeyListener(MyKeyListener &l);
    void animateCanvas(TetrisGame &game);
    static void newTetrino(Tetrino pastTetrino);

private:
    Canvas _canvas;
    GLRenderer _renderer;
    TextRenderer _textRenderer;
    std::shared_ptr<PerspectiveCamera> _camera;
    inline static std::shared_ptr<Scene> _scene = Scene::create();
    Clock _clock;

    std::vector<TextHandle*> _textHandles;
};


#endif//EXAM_TETRIS_TETRISSCENE_HPP
