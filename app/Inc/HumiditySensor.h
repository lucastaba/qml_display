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

#include "Sensor.h"
#include "Subject.h"

class HumiditySensor: public Sensor {
public:
    HumiditySensor(int interval = 5);
    float GetData(void) override;
    ~HumiditySensor() = default;
private:
    const float m_mean = 60.0f;
    const float m_minValue = 0.0f;
    const float m_maxValue = 100.0f;
};