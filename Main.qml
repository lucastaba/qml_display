import QtQuick
import QtQuick.Layouts

Item {
    width: 640
    height: 480
    visible: true
    // title: qsTr("Nice Display")
    // color: "blue"

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
                        text: __sensor1.text
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
                        text: __sensor2.text
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
                    text: __sensor3.text
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


}
