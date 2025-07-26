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

#include "../Inc/ISensor.h"

void ISensor::SetInterval(int interval) {
    t_interval = interval;
}

void ISensor::RunService(void) {
    t_thread = std::make_unique<std::thread>([&]{
        for (;;) {
            t_data = GetData();
            std::cout << "Data: " << t_data << "\n";
            std::this_thread::sleep_for(std::chrono::seconds(t_interval));
        }
    });
    t_thread->detach();
}