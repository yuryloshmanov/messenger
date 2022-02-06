cmake_minimum_required(VERSION 3.21)
project(terminal_client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(terminal_client main.cpp include/terminal_client.hpp)

target_link_libraries(terminal_client libserver ${CONAN_LIBS})
