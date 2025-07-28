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

#include <iostream>

#include "../Inc/Controller.h"
#include "../Inc/TemperatureSensor.h"
#include "../Inc/HumiditySensor.h"

Controller::Controller() {

}

void Controller::Subscribe(ISubject* subject, SubjectType type) {
    subject->Attach(this);
    m_subjects.insert({subject, type});
}

void Controller::Update(ISubject* subject) {
    switch (m_subjects.at(subject)) {
        case SENSOR_TEMPERATURE:
            std::cout << "Subject TEMP: " << static_cast<TemperatureSensor*>(subject)->ReadData() << " C\n";
            break;
        case SENSOR_HUMIDITY:
            std::cout << "Subject HUM: " << static_cast<HumiditySensor*>(subject)->ReadData() << " %\n";
        default:
            break;
    }
}
