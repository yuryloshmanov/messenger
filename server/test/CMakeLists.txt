cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(test test.cpp)

target_link_libraries(test LIBCONFIGPARSER ${CONAN_LIBS_GTEST})
