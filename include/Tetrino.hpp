
#ifndef EXAM_TETRIS_TETRINO_HPP
#define EXAM_TETRIS_TETRINO_HPP

#include "threepp/threepp.hpp"
#include "TetrinoEnum.hpp"

using namespace threepp;


class Tetrino {
public:
    Tetrino(shapes shape, const Vector3& pos, const Color& color);
    std::shared_ptr<Group> getGroup ();
//    auto group = Group::create();
//    group->add(createBox({-1, 0, 0}, Color::orange));
//    group->add(createBox({1, 0, 0}, Color::yellow));
//    scene->add(group);

private:
    std::shared_ptr<Group> _group;
};


#endif//EXAM_TETRIS_TETRINO_HPP
