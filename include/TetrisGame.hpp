
#ifndef EXAM_TETRIS_TETRISGAME_HPP
#define EXAM_TETRIS_TETRISGAME_HPP

#include "Enums.hpp"
#include "Tetrino.hpp"
#include <threepp/threepp.hpp>

using namespace threepp;

class TetrisScene;

class TetrisGame {

public:
    TetrisGame();

    void points();
    bool getBlock(int x, int y);
    void addBlock(int x, int y, bool invisible = false);
    void delBlock(int x, int y, bool invisible = false);

    std::shared_ptr<Group> getBorderGroup ();
    std::shared_ptr<Group> getTetrinoGroup ();
    Tetrino getTetrinoCopy();

    void moveLeft();
    void moveRight();
    void moveDown();

    Orientation rotateI(Orientation orientation, std::array<Vector2, 4> &offsets);
    Orientation rotateJ(Orientation orientation, std::array<Vector2, 4> &offsets);
    Orientation rotateL(Orientation orientation, std::array<Vector2, 4> &offsets);
    Orientation rotateS(Orientation orientation, std::array<Vector2, 4> &offsets);
    Orientation rotateZ(Orientation orientation, std::array<Vector2, 4> &offsets);
    Orientation rotateT(Orientation orientation, std::array<Vector2, 4> &offsets);

    bool rotateTetrino();
    static Tetrino randomTetrino();
    static Color randomColor();

    void moveRowDown();

    std::shared_ptr<Group> renderedGroup;
    TetrisScene *sceneHandler;
    void (*newTetrinoSceneFunction)(Tetrino);
    void (*removeTetrinoSceneFunction)(Tetrino);

private:
    std::shared_ptr<Group> _borderGroup;
    Tetrino _current_tetrino;

    std::vector<std::shared_ptr<Mesh>> _boxes = {};
    std::array<std::array<bool, 20>, 28> _boardGrid = {false};

};


#endif//EXAM_TETRIS_TETRISGAME_HPP
