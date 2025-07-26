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