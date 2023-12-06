
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

    int pointsValue = 0;
    void pointsCalculation(int rowsDeleted);
    bool getBlock(int x, int y, Color color = Color(1, 1, 1));
    void addBlock(int x, int y, bool invisible = false, Color color = Color(1, 1, 1));
    void delBlock(int x, int y, bool invisible = false);

    std::shared_ptr<Group> getBorderGroup ();
    std::shared_ptr<Group> getTetrinoGroup ();
    Tetrino getCurrentTetrino();

    void moveLeft();
    void moveRight();
    void moveDown();

    static Orientation rotateI(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateJ(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateL(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateS(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateZ(Orientation orientation, std::array<Vector2, 4> &offsets);
    static Orientation rotateT(Orientation orientation, std::array<Vector2, 4> &offsets);

    bool rotateTetrino();
    static Tetrino randomTetrino();
    static Color randomColor();

    int moveRowDown();

    std::shared_ptr<Group> renderedGroup;
    //TetrisScene *sceneHandler;
    void (*newTetrinoSceneFunction)(Tetrino);
    void (*removeTetrinoSceneFunction)(Tetrino);

private:
    std::shared_ptr<Group> _borderGroup;
    Tetrino _currentTetrino;

    std::vector<std::shared_ptr<Mesh>> _boxes = {};
    std::array<std::array<bool, 20>, 28> _boardGrid = {false};

};


#endif//EXAM_TETRIS_TETRISGAME_HPP
