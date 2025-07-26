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

#include <list>

#include "IObserver.h"
#include "ISubject.h"

class Subject: public ISubject {
public:
    Subject();
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    virtual void Notify() override;
    virtual ~Subject() = default;
private:
    std::list<IObserver*> m_observers;
};