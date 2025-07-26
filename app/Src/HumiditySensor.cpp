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

#include <algorithm>

#include "../Inc/HumiditySensor.h"
#include "../Inc/GaussianRNG.h"

HumiditySensor::HumiditySensor(int interval):
    Sensor::Sensor(interval) {
}

float HumiditySensor::GetData() {
    /* A serial bus access to retrieve data. Here the GaussianRNG is emulating this behaviour. */
    static GaussianRNG rng{m_mean, 2.0};
    return std::clamp(rng.GetRN(), m_minValue, m_maxValue);
}