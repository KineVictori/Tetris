cmake_minimum_required(VERSION 3.15)
project(exam_tetris)

option(Testing_Tetris "tetris test" on)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

set(
        headers
        include/MyKeyListener.hpp
        include/Tetrino.hpp
        include/ThreeppHelper.hpp
        include/TetrinoEnum.hpp
        include/TetrisGame.hpp
        include/TetrisScene.hpp
)

set(
        sources
        src/main.cpp
        src/MyKeyListener.cpp
        src/Tetrino.cpp
        src/ThreeppHelper.cpp
        src/TetrisGame.cpp
        src/TetrisScene.cpp
)

add_executable(tetris ${sources} ${headers})

target_include_directories(tetris PUBLIC include)
target_link_libraries(tetris PRIVATE threepp::threepp)


# ============================
# Testing code copied from excercise1 from Markaren on GitHub
# ============================

if (Testing_Tetris)

    # Download Catch2 unit-test framework from GitHub
    include(FetchContent)
    FetchContent_Declare(
            Catch2
            GIT_REPOSITORY https://github.com/catchorg/Catch2.git
            GIT_TAG v3.4.0
    )
    FetchContent_MakeAvailable(Catch2)

    enable_testing()
    add_subdirectory(tests)

endif ()
