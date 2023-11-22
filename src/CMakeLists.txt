
add_library(TetrisLibrary
    MyKeyListener.cpp
    Tetrino.cpp
    TetrisGame.cpp
    TetrisScene.cpp
    ThreeppHelper.cpp
)

target_include_directories(TetrisLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(TetrisLibrary PUBLIC threepp::threepp)