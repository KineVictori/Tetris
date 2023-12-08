
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>

//#include <Vector3.hpp>
#include <threepp/threepp.hpp>
#include "Tetrino.hpp"

using namespace threepp;


TEST_CASE("test tetrino move") {

    Tetrino testTetrino1(Shapes::I, {1, 1, 0}, Color::orange);
    Tetrino testTetrino2(Shapes::I, {2, 1, 0}, Color::orange);

    auto positions = testTetrino1.getPositions();

    std::array<Vector3, 4> newPos;
    for (int i = 0; i < 4; i++) {
        auto tmp = positions.at(i);
        tmp.x += 1;
        newPos.at(i) = tmp;
    }

    testTetrino1.setPositions(newPos);

    CHECK(testTetrino1.getPositions() == testTetrino2.getPositions());
}