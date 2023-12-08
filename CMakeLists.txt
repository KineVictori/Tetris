cmake_minimum_required(VERSION 3.15)
project(exam_tetris)

option(testingTetris "tetris test" on)

set(CMAKE_CXX_STANDARD 17)

find_package(threepp CONFIG REQUIRED)

add_subdirectory(src)
add_subdirectory(main)


# ============================
# Testing code copied from excercise1 from Markaren on GitHub
# ============================

if (testingTetris)

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
