cmake_minimum_required(VERSION 3.16)

project(QML_Display)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Quick Gui REQUIRED)
qt_standard_project_setup()

include_directories(app/Inc)
add_subdirectory(app/Src)