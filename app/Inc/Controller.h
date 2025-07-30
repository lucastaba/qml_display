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

#include <string>

#include <QQmlContext>

#include "IObserver.h"
#include "ISubject.h"
#include "SensorTextObject.h"
#include "IDataBaseHandler.h"
#include "DataBaseData.h"
#include "SocketClient.h"

typedef enum {
    SENSOR_TEMPERATURE,
    SENSOR_HUMIDITY,
} SubjectType;

class Controller: public IObserver {
public:
    Controller();
    void Subscribe(ISubject* subject, SubjectType type);
    void SetupUI(QQmlContext* context);
    void SetupTempAlarm(float coldTemp = 10.0f, float hotTemp= 40.0f);
    void SetupHumAlarm(float lowHum = 40.0, float highHum = 87.0);
    void SetDataBase(IDataBaseHandler* db, const std::string& path);
    void SetClient(SocketClient* client);
    void Update(ISubject* subject) override;
    ~Controller() = default;
private:
    std::unordered_map<ISubject*, SubjectType> m_subjects;

    /* could be inside UI object */
    SensorTextObject m_tempSensorC;
    SensorTextObject m_tempSensorF;
    SensorTextObject m_humSensor;

    QString m_Float2QString(float f);
    float m_Celsius2Fahrenheit(float f);

    /* could be inside Alarm object */
    float m_coldTemp;
    float m_hotTemp;
    float m_lowHum;
    float m_highHum;

    bool m_IsTempAbnormal(float temp);
    bool m_IsHumidityAbonormal(float humidity);

    /* data base */
    IDataBaseHandler* m_db;

    void m_DataBaseConnect(const std::string& path);
    void m_DataBaseDisconnect();
    void m_DataBaseInsert(DataBaseData& data);
    void m_SetDataBaseData(DataBaseData& dbData, const SubjectType type, const float data);

    /* TCP socket */
    SocketClient* m_client;

    void m_ClientConnect();
    void m_ClientDisconnect();
    void m_ClientWrite(DataBaseData& dbData);
};
