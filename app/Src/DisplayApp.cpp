/**
 *   Copyright 2025 Lucas Taba
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
*/

#include <QQmlEngine>

#include "DisplayApp.h"


DisplayApp::DisplayApp(QGuiApplication* qtApp, QQuickView* qtView):
    m_tempSensor(2),
    m_humSensor(5),
    m_controller(),
    m_qtApp(qtApp),
    m_qtView(qtView) {

}

void DisplayApp::Setup(const QUrl& url) {
    m_controller.Subscribe(&m_tempSensor, SENSOR_TEMPERATURE);
    m_controller.Subscribe(&m_humSensor, SENSOR_HUMIDITY);
    m_controller.SetupUI(m_qtView->engine()->rootContext());
    m_controller.SetupTempAlarm(m_coldTemp, m_hotTemp);
    m_controller.SetupHumAlarm(m_lowHumdity, m_highHumdity);
    m_controller.SetDataBase(&m_db, m_dbPath);
    m_qtView->setSource(url);
}

int DisplayApp::Run() {
    m_tempSensor.RunService();
    m_humSensor.RunService();
    m_qtView->show();
    return m_qtApp->exec();
}
