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

#include "../Inc/Subject.h"

Subject::Subject() {

}

void Subject::Attach(IObserver* observer) {
    m_observers.push_back(observer);
}

void Subject::Detach(IObserver* observer) {
    for (auto it = m_observers.cbegin(); it != m_observers.cend(); ++it) {
        if (*it == observer) {
            m_observers.erase(it);
            break;
        }
    }
}

void Subject::Notify() {
    for (auto it = m_observers.cbegin(); it != m_observers.cend(); ++it) {
        (*it)->Update(this);
    }
}