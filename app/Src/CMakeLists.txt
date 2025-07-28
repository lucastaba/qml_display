qt_add_executable(display
    Controller.cpp
    GaussianRNG.cpp
    HumiditySensor.cpp
    main.cpp
    Sensor.cpp
    Subject.cpp
    TemperatureSensor.cpp
)

qt_add_qml_module(display
    URI qml_display
    QML_FILES
        Main.qml
)

target_link_libraries(display PRIVATE Qt6::Gui Qt6::Quick)