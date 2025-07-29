#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>

#include "Controller.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "SensorTextObject.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQuickView view;
    QQmlContext* context = view.engine()->rootContext();

    TemperatureSensor tSensor{2};
    HumiditySensor hSensor{5};
    Controller controller{};
    SensorTextObject sensor1;
    SensorTextObject sensor2;
    SensorTextObject sensor3;
    
    sensor1.SetText("sensor1");
    sensor2.SetText("sensor2");
    sensor3.SetText("sensor3");
    context->setContextProperty("__sensor1", &sensor1);
    context->setContextProperty("__sensor2", &sensor2);
    context->setContextProperty("__sensor3", &sensor3);

    controller.Subscribe(&tSensor, SENSOR_TEMPERATURE);
    controller.Subscribe(&hSensor, SENSOR_HUMIDITY);
    tSensor.RunService();
    hSensor.RunService();

    view.setSource(QUrl("qrc:/qt/qml/qml_display/Main.qml"));
    view.show();

    return app.exec();
}
