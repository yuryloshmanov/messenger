cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LIBLOGGER STATIC ../include/Logger.hpp Logger.cpp)
add_library(LIBSERVER STATIC Server.cpp ../include/Server.hpp)
add_library(LIBDATABASEPROXY STATIC ../include/DatabaseProxy/PostgresqlProxy.hpp DatabaseProxy/PostgresqlProxy.cpp)

add_executable(server main.cpp ../include/Server.hpp ../include/DatabaseProxy/DatabaseProxy.hpp DatabaseProxy/DatabaseProxy.cpp)

target_link_libraries(server
        LIBLOGGER
        LIBDATABASEPROXY
        LIBSERVER
        ${CONAN_LIBS_LIBSODIUM}
        ${CONAN_LIBS_ZMQPP}
        ${CONAN_LIBS_ZEROMQ}
        ${CONAN_LIBS_FMT}
        ${CONAN_LIBS_LIBPQXX}
        )
