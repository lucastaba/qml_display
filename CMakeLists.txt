cmake_minimum_required(VERSION 3.16)

project(QML_Display)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 COMPONENTS Quick Gui REQUIRED)
qt_standard_project_setup()

qt_add_executable(test
    main.cpp
)

qt_add_qml_module(test
    URI qml_display
    QML_FILES
        Main.qml
)

target_link_libraries(test PRIVATE Qt6::Gui Qt6::Quick)