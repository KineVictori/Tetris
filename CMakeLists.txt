cmake_minimum_required(VERSION 3.15)
project(exam_tetris)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

set(
        headers
        include/MyKeyListener.hpp
        include/Tetrino.hpp
        include/ThreeppHelper.hpp
        include/TetrinoEnum.hpp
        include/TetrisGame.hpp
)

set(
        sources
        src/main.cpp
        src/MyKeyListener.cpp
        src/Tetrino.cpp
        src/ThreeppHelper.cpp
        src/TetrisGame.cpp
)

add_executable(tetris ${sources} ${headers})

target_include_directories(tetris PUBLIC include)
target_link_libraries(tetris PRIVATE threepp::threepp)
