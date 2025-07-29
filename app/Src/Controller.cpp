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
    m_humSensor("0.0"),
    m_db(nullptr) {

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

void Controller::SetupTempAlarm(float coldTemp, float hotTemp) {
    m_coldTemp = coldTemp;
    m_hotTemp = hotTemp;
}

void Controller::SetupHumAlarm(float lowHum, float highHum) {
    m_lowHum = lowHum;
    m_highHum = highHum;
}

void Controller::SetDataBase(IDataBaseHandler* db, const std::string& path) {
    m_db = db;
    m_DataBaseConnect(path);
}

void Controller::Update(ISubject* subject) {
    float data;
    switch (m_subjects.at(subject)) {
        case SENSOR_TEMPERATURE:
            data = static_cast<TemperatureSensor*>(subject)->ReadData();
            m_tempSensorC.SetText(m_Float2QString(data));
            m_tempSensorF.SetText(m_Float2QString(m_Celsius2Fahrenheit(data)));
            if (m_IsTempAbnormal(data)) {
                m_tempSensorC.SetColorFault();
                m_tempSensorF.SetColorFault();
            } else {
                m_tempSensorC.SetColorNormal();
                m_tempSensorF.SetColorNormal();
            }
            break;
        case SENSOR_HUMIDITY:
            data = static_cast<HumiditySensor*>(subject)->ReadData();
            m_humSensor.SetText(m_Float2QString(data));
            if (m_IsHumidityAbonormal(data)) {
                m_humSensor.SetColorFault();
            } else {
                m_humSensor.SetColorNormal();
            }
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

bool Controller::m_IsTempAbnormal(float temp) {
    return (temp < m_coldTemp) || (temp > m_hotTemp);
}
bool Controller::m_IsHumidityAbonormal(float humidity) {
    return (humidity < m_lowHum) || (humidity > m_highHum);
}

void Controller::m_DataBaseConnect(const std::string& path) {
    if (nullptr == m_db) {
        return;
    }
}
void Controller::m_DataBaseDisconnect() {
    if (nullptr == m_db) {
        return;
    }
}
void Controller::m_DataBaseInsert(const std::any& item) {
    if (nullptr == m_db) {
        return;
    }
}