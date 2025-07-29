import QtQuick
import QtQuick.Layouts

Item {
    width: 640
    height: 480
    visible: true

    Rectangle {
        anchors.fill: parent
        color: "black"

        ColumnLayout {
            anchors.fill: parent

            RowLayout {
                Layout.fillWidth: parent
                Layout.alignment: Qt.AlignBottom | Qt.AlignHCenter
                spacing: 5

                RowLayout {
                    Layout.fillWidth: parent

                    Text {
                        text: __tempSensorC.text + "\xB0C"
                        color: __tempSensorC.color
                    }
                }

                RowLayout {
                    Layout.fillWidth: parent

                    Text {
                        text: __tempSensorF.text + "\xB0F"
                        color: __tempSensorF.color
                    }
                }
            }

            RowLayout {
                Layout.fillWidth: parent
                Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

                Text {
                    text: "Humidity: " + __humSensor.text + "%"
                    color: __humSensor.color
                    font.italic: true
                }

            }

        }
    }


}
