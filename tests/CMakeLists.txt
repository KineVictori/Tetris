
add_executable(testTetrino testTetrinoMove.cpp)
add_test(NAME testTetrino COMMAND testTetrino) # Ctest
target_link_libraries(testTetrino PRIVATE Catch2::Catch2WithMain)
target_include_directories(testTetrino PRIVATE "${CMAKE_SOURCE_DIR}/include")

target_link_libraries(testTetrino PUBLIC threepp::threepp)
