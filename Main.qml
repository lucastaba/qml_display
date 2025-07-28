import QtQuick
import QtQuick.Layouts

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Nice Display")
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
                    text: "10.0"
                    color: "white"
                }

                Text {
                    text: "\xB0C"
                    color: "white"
                }
            }

            RowLayout {
                Layout.fillWidth: parent

                Text {
                    text: "50.0"
                    color: "white"
                }

                Text {
                    text: "\xB0F"
                    color: "white"
                }
            }
        }

        RowLayout {
            Layout.fillWidth: parent
            Layout.alignment: Qt.AlignTop | Qt.AlignHCenter

            Text {
                text: "Humidity: "
                color: "white"
                font.italic: true
            }

            Text {
                text: "80.0"
                color: "white"
                font.italic: true
            }

            Text {
                text: "%"
                color: "white"
                font.italic: true
            }
        }

    }
}
