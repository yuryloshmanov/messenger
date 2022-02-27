cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(LIBLOGGER STATIC ../include/Logger.hpp Logger.cpp)
add_library(LIBSERVER STATIC Server.cpp ../include/Server.hpp)
add_library(LIBDATABASEPROXY STATIC ../include/DatabaseProxy/PostgresqlProxy.hpp DatabaseProxy/PostgresqlProxy.cpp)
add_library(LIBCONFIGPARSER STATIC ../include/ConfigParser.hpp ConfigParser.cpp)

add_executable(server main.cpp ../include/Server.hpp ../include/DatabaseProxy/DatabaseProxy.hpp DatabaseProxy/DatabaseProxy.cpp)

target_link_libraries(server
        LIBLOGGER
        LIBDATABASEPROXY
        LIBSERVER
        LIBCONFIGPARSER
        ${CONAN_LIBS_LIBSODIUM}
        ${CONAN_LIBS_ZMQPP}
        ${CONAN_LIBS_ZEROMQ}
        ${CONAN_LIBS_FMT}
        ${CONAN_LIBS_LIBPQ}
        ${CONAN_LIBS_LIBPQXX}
        ${CONAN_LIBS_BOOST}
        )
