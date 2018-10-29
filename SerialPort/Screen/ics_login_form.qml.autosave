import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

Item {
    property alias login: login

    Rectangle {
        id: pane
        x: 144
        y: 117
        width: 353
        height: 246
        clip: false

        ColumnLayout {
            id: columnLayout
            x: 139
            y: -158
            anchors.fill: parent

            TextField {
                id: username
                Layout.fillWidth: true
                placeholderText: qsTr("Username")
            }

            TextField {
                id: password
                Layout.fillWidth: true
                placeholderText: qsTr("Password")
            }

            Button {
                id: login
                text: qsTr("Login")
                //spacing: -2
                //font.capitalization: Font.MixedCase
                Layout.fillWidth: true
                //highlighted: false
//                background: Rectangle {
//                            implicitWidth: 100
//                            implicitHeight: 40
//                            color: button.down ? "#d6d6d6" : "#f6f6f6"
//                            border.color: "#26282a"
//                            border.width: 1
//                            radius: 4

//                        }

            }
        }
    }
}
