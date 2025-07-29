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

#pragma once

#include <QGuiApplication>
#include <QQuickView>

#include "TemperatureSensor.h"
#include "Controller.h"
#include "HumiditySensor.h"

class DisplayApp {
public:
    DisplayApp(QGuiApplication* qtApp, QQuickView* qtView);
    void Setup(const QUrl& url);
    int Run();
    virtual ~DisplayApp() = default;
private:
    TemperatureSensor m_tempSensor;
    HumiditySensor m_humSensor;
    Controller m_controller;
    QGuiApplication* m_qtApp;
    QQuickView* m_qtView;

    const float m_coldTemp = 10.0f;
    const float m_hotTemp = 40.0f;
    const float m_lowHumdity = 40.0f;
    const float m_highHumdity = 87.0f;
};
