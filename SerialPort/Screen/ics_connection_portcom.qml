import QtQuick 2.5
import QtQuick.Window 2.2
import EnumID 1.0

Item {
    Rectangle {
        id: back_home
        width: 50
        height: 30
        color: "lightsteelblue"
        border.color: "black"
        x: 5
        y: 5
        Text {text: qsTr("Back");anchors.centerIn: parent}
        MouseArea {
            anchors.fill: parent
            onClicked: UIBridge.hmiEvent("", EnumID.HMI_HOME_SCREEN,"")
        }
    }

    Text {
        text: qsTr("Port")
        x: 50
        y: 40
    }

    Rectangle {
        x: 50
        y: 60
        width: 50
        height: 25
        border.color: "black"
        TextInput {
            id: port_to_connect
            objectName: "port_to_connect"
            anchors.left: parent.left
            width: 250
            height: 25
        }
    }

    Rectangle {
        id: connect_server_button
        x: 130
        y: 60
        width: 70
        height: 20
        border.color: "black"
        Text {
            id: connection_status
            objectName: "connection_status"
            anchors.centerIn: parent
            text: "Connect"
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent(this.objectName, EnumID.HMI_TEST_CONNECTIONS_SERIALPORT, port_to_connect.text)
            }
        }
    }

    Rectangle {
        id: popup1
        x: 400
        y: 60
        width: 70
        height: 20
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Check")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent("", EnumID.HMI_CONNECTED_POPUP,"")
                console.log("Vao roi day")
            }
        }
    }

    Text {
        text: qsTr("Send Data")
        x: 50
        y: 100
    }

    Rectangle {
        x: 50
        y: 120
        width: 200
        height: 25
        border.color: "black"
        TextInput {
            id: data_send
            objectName: "data_send"
            anchors.left: parent.left
            width: 250
            height: 25
        }
    }

    Rectangle {
        id: send_button
        x: 260
        y: 120
        width: 70
        height: 20
        border.color: "black"
        Text {
            anchors.centerIn: parent
            text: qsTr("Send")
        }
        MouseArea {
            anchors.fill: parent
            onClicked: {
                UIBridge.hmiEvent(this.objectName, EnumID.HMI_SEND_DATA_SERIALPORT, data_send.text)
            }
        }
    }

    Text {
        id:status
        text: qsTr("Receive/send data")
        x: 50
        y: 160
    }

    Rectangle {
        id: notification_Connect
        width: 300
        height: 150
        border.color: "black"
        x:50
        y:180
        Text {
            id: show_notification
            text: {
                MySerialPort.message
            }
        }
    }
}


