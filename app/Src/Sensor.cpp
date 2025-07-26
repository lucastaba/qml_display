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

#include <memory>
#include <chrono>
#include <thread>
#include <iostream>

#include "../Inc/Sensor.h"

Sensor::Sensor(int interval):
    m_interval(interval),
    m_data(0.0f),
    m_thread(nullptr) {

}

void Sensor::SetInterval(int interval) {
    m_interval = interval;
}

float Sensor::GetData(void) {
    return 0.0;
}

void Sensor::RunService(void) {
    m_thread = std::make_unique<std::thread>([&]{
        for (;;) {
            m_data = GetData();
            std::cout << "Sensor data: " << m_data << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(m_interval));
        }
    });
    m_thread->detach();
}