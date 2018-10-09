import QtQuick 2.0
import EnumID 1.0

Item {
    Rectangle {
        id: working_icon
        x:100
        y:100
        width: 80
        height: 80
        color: "lightBlue"
        border.color: "black"
        Text {
            text: qsTr("Run")
            anchors.centerIn: parent
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent("", EnumID.HMI_UPDATE_DATABASE, "")
            }
        }
    }
}
