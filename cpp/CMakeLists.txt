cmake_minimum_required(VERSION 3.21)
project(cpp)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(server)
add_subdirectory(console_client)
add_subdirectory(qt_client)
