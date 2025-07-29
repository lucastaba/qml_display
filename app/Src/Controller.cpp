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

#include <sstream>
#include <iomanip>

#include "Controller.h"
#include "TemperatureSensor.h"
#include "HumiditySensor.h"

Controller::Controller():
    m_tempSensorC("0.0"),
    m_tempSensorF("0.0"),
    m_humSensor("0.0") {

}

void Controller::Subscribe(ISubject* subject, SubjectType type) {
    subject->Attach(this);
    m_subjects.insert({subject, type});
}

void Controller::SetupUI(QQmlContext* context) {
    context->setContextProperty("__tempSensorC", &m_tempSensorC);
    context->setContextProperty("__tempSensorF", &m_tempSensorF);
    context->setContextProperty("__humSensor", &m_humSensor);
}

void Controller::Update(ISubject* subject) {
    float data;
    switch (m_subjects.at(subject)) {
        case SENSOR_TEMPERATURE:
            data = static_cast<TemperatureSensor*>(subject)->ReadData();
            m_tempSensorC.SetText(m_Float2QString(data));
            m_tempSensorF.SetText(m_Float2QString(m_Celsius2Fahrenheit(data)));
            break;
        case SENSOR_HUMIDITY:
            data = static_cast<HumiditySensor*>(subject)->ReadData();
            m_humSensor.SetText(m_Float2QString(data));
        default:
            break;
    }
}

QString Controller::m_Float2QString(float f) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(1) << f;
    return QString(ss.str().c_str());
}

float Controller::m_Celsius2Fahrenheit(float f) {
    return (f*9/5)+32;
}
