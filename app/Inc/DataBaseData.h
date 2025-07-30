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

#include <cstdint>
#include <vector>

struct DataBaseData {
    unsigned int type;
    unsigned int len;
    std::vector<uint8_t> value;

    std::vector<uint8_t> SerializeData() {
        std::vector<uint8_t> vec;
        unsigned int length = sizeof(len) + sizeof(type) + value.size();
        vec.reserve(length);
        CopyDataToVector(vec, reinterpret_cast<const uint8_t*>(&type), sizeof(type));
        CopyDataToVector(vec, reinterpret_cast<const uint8_t*>(&len), sizeof(len));
        std::copy(value.begin(), value.end(), std::back_inserter(vec));
        return vec;
    }

    void CopyDataToVector(std::vector<uint8_t>& vec, const uint8_t* data, const unsigned int len) {
        for (int i = 0; i < len; ++i) {
            vec.push_back(*(data + i));
        }
    }
};