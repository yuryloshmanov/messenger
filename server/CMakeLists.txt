cmake_minimum_required(VERSION 3.21)
project(Server)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(liblogger STATIC include/Logger.hpp src/Logger.cpp)
add_library(libserver STATIC src/Server.cpp include/Server.hpp)

add_executable(server main.cpp include/Server.hpp include/DatabaseProxy.hpp src/DatabaseProxy.cpp)

target_link_libraries(server liblogger libserver ${CONAN_LIBS})
