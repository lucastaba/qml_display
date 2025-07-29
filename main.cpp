#include <QGuiApplication>
#include <QQuickView>

#include "DisplayApp.h"

int main(int argc, char *argv[]) {
    QGuiApplication app(argc, argv);
    QQuickView view;
    DisplayApp displayApp(&app, &view);
    displayApp.Setup(QUrl("qrc:/qt/qml/qml_display/Main.qml"));
    (void)displayApp.Run();
    return 0;
}
