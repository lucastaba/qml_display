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

#include <QTcpSocket>

#include "SocketClient.h"

SocketClient::SocketClient():
    m_addr("127.0.0.1"),
    m_port(0),
    m_run(false) {
}

void SocketClient::Connect(const QString& serverAddr, const int serverPort) {
    m_addr = serverAddr;
    m_port = serverPort;
    m_Run();
}

void SocketClient::Disconnect() {
    m_run = false;
    m_cv.notify_one();
}

void SocketClient::WriteData(const DataBaseData& data) {
    std::unique_lock<std::mutex> lk(m_mutex);
    m_queue.push(data);
    m_cv.notify_one();
}

void SocketClient::Reconnect() {
    Disconnect();
    m_Run();
}

void SocketClient::m_Run() {
    m_run = true;
    m_thread = std::make_unique<std::thread>([this]{
        QTcpSocket sock;
        
        while (m_run) {
            while (sock.state() != QTcpSocket::ConnectedState) {
                sock.connectToHost(m_addr, m_port);
                sock.waitForConnected();
            }
            std::unique_lock<std::mutex> lk(m_mutex);
            m_cv.wait(lk, [&]{ return !m_queue.empty();});
            if (!m_run) {
                break;
            }
            auto data = m_queue.front();
            auto d = data.SerializeData();
            sock.write(reinterpret_cast<char*>(d.data()), d.size());
            (void)sock.waitForBytesWritten();
            m_queue.pop();
        }
        sock.abort();
        sock.disconnectFromHost();
    });
    m_thread->detach();
}

void SocketClient::m_OnConnected() {
    m_cv.notify_one();
}

SocketClient::~SocketClient() {
    Disconnect();
}

#include "moc_SocketClient.cpp"