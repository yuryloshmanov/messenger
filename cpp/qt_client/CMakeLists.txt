cmake_minimum_required(VERSION 3.21)
project(qt_client)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(qt_client main.cpp)
target_link_libraries(qt_client
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

