cmake_minimum_required(VERSION 3.28)
project(coffee LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_PREFIX_PATH "/Users/jamesxsc/Qt/6.7.0/macos/lib/cmake")

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(coffee main.cpp
        mainwindow.cpp
        initialsettings.cpp
        coffeeinput.cpp
        coffeeinput.h
        coffeeinput.ui
        coffeesetup.h
        settingsupdate.cpp
        settingsupdate.h
        settingsupdate.ui
)

target_link_libraries(coffee
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

set_target_properties(coffee PROPERTIES
        MACOSX_BUNDLE TRUE
)

