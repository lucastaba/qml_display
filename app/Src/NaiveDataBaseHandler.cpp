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

#include <cstring>
#include <vector>

#include "NaiveDataBaseHandler.h"

NaiveDataBaseHandler::NaiveDataBaseHandler():
    m_path("") {

}

void NaiveDataBaseHandler::Connect(const std::string& path) {
    m_path = path;
    (void)m_of.open(m_path, std::ofstream::binary | std::ofstream::trunc);
    (void)m_of.close();
}

void NaiveDataBaseHandler::Disconnect() {
    (void)m_of.close();
}

void NaiveDataBaseHandler::InsertItem(DataBaseData& data) {
    auto binData = data.SerializeData();
    m_of.open(m_path, std::ofstream::binary | std::ofstream::app);
    m_of.write(reinterpret_cast<char*>(binData.data()), binData.size());
    m_of.close();
}