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

#include "SensorTextObject.h"

SensorTextObject::SensorTextObject(const QString& text, const QString& color):
    m_text(text),
    m_color(color) {
}

QString SensorTextObject::GetText() const {
    return m_text;
}

QString SensorTextObject::GetColor() const {
    return m_color;
}

void SensorTextObject::SetText(const QString& text) {
    if (m_text == text) {
        return;
    }
    m_text = text;
    emit TextChanged();
}

void SensorTextObject::SetColor(const QString& color) {
    if (m_color == color) {
        return;
    }
    m_color = color;
    emit ColorChanged();
}

void SensorTextObject::SetColorFault() {
    SetColor("red");
}

void SensorTextObject::SetColorNormal() {
    SetColor("white");
}

#include "moc_SensorTextObject.cpp"
