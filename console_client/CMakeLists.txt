cmake_minimum_required(VERSION 3.21)
project(console_client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_library(libconsoleclient STATIC include/console_client.hpp src/console_client.cpp)

add_executable(console_client main.cpp include/console_client.hpp)

target_link_libraries(console_client libconsoleclient ${CONAN_LIBS})
