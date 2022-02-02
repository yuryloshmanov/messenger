cmake_minimum_required(VERSION 3.21)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(server main.cpp include/Server.hpp src/Server.cpp include/Database.hpp src/Database.cpp)
target_link_libraries(server ${CONAN_LIBS})
