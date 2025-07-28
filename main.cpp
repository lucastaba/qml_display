#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Controller.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    TemperatureSensor tSensor{2};
    HumiditySensor hSensor{5};
    Controller controller{};

    controller.Subscribe(&tSensor, SENSOR_TEMPERATURE);
    controller.Subscribe(&hSensor, SENSOR_HUMIDITY);
    tSensor.RunService();
    hSensor.RunService();

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("qml_display", "Main");

    return app.exec();
}
