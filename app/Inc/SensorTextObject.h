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

#include <QObject>
#include <QString>

class SensorTextObject: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString text READ GetText NOTIFY TextChanged)
    Q_PROPERTY(QString color READ GetColor NOTIFY ColorChanged)
public:
    SensorTextObject(const QString& text = QString(), const QString& color = QString("white"));
    QString GetText() const;
    QString GetColor() const;
    void SetText(const QString& text);
    void SetColor(const QString& color);
    void SetColorFault();
    void SetColorNormal();
    virtual ~SensorTextObject() = default;
signals:
    void TextChanged();
    void ColorChanged();
private:
    QString m_text;
    QString m_color;
};
