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

#include <thread>
#include <memory>
#include <queue>
#include <mutex>
#include <condition_variable>

#include <QObject>

#include "DataBaseData.h"

class SocketClient: public QObject {
    Q_OBJECT
public:
    SocketClient();
    void Connect(const QString& serverAddr, const int serverPort);
    void Disconnect();
    void WriteData(const DataBaseData& data);
    void Reconnect();
    virtual ~SocketClient();
public slots:
    void m_OnConnected();
private:
    std::unique_ptr<std::thread> m_thread;
    std::queue<DataBaseData> m_queue;
    std::mutex m_mutex;
    std::condition_variable m_cv;
    QString m_addr;
    int m_port;
    bool m_run;

    void m_Run();
};