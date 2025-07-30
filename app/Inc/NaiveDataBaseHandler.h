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

#include <fstream>

#include "IDataBaseHandler.h"

class NaiveDataBaseHandler: public IDataBaseHandler {
public:
    NaiveDataBaseHandler();
    void Connect(const std::string& path) override;
    void Disconnect() override;
    void InsertItem(DataBaseData& data) override;
    virtual ~NaiveDataBaseHandler() = default;
private:
    std::string m_path;
    std::ofstream m_of;

    // void m_CopyDataToVector(std::vector<uint8_t>& vec, const uint8_t* data, const unsigned int len);
};