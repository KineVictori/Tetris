
add_executable(test_tetrino test_tetrino_crash.cpp)
add_test(NAME test_tetrino COMMAND test_tetrino) # Ctest
target_link_libraries(test_tetrino PRIVATE Catch2::Catch2WithMain)
target_include_directories(test_tetrino PRIVATE "${CMAKE_SOURCE_DIR}/include")

