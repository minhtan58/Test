import QtQuick 2.5
import QtQuick.Window 2.2
import EnumID 1.0

Item {
    id: toast
    property alias timeout: tim.interval
    property alias message: textContent.text
    width: 800
    height: 480

    Timer {
        id: tim
        repeat: false
        onTriggered: UIBridge.hmiEvent(this.objectName, EnumID.HMI_HIDE_POPUP, "")
    }

    Rectangle {
        anchors.fill: parent
        color: "#000000"
        opacity: 0.5
    }

    Rectangle {
        id: qnBgr
        width: 400
        height: 100
        anchors.centerIn: parent
        color: "#315b7d"
        opacity: 0.95
    }

    Text {
        id: textContent
        anchors.fill: qnBgr
        text: "Save Successful"
        color: "#ffffff"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 25
        wrapMode: Text.Wrap
    }

    MouseArea {
        anchors.fill: parent
        onClicked: UIBridge.hmiEvent(this.objectName, EnumID.HMI_HIDE_POPUP, "")
    }

    Component.onCompleted: {
        tim.start()
    }
}

Image {
    id: mymedia_play_pause
    /*OTHERSPROPERTIES*/
    /*ELEMENTPROPERTIES*/
    property string normalSource: UIBridge.getImageSourceByName("play_normal")
    property string focusSource: UIBridge.getImageSourceByName("pause_highlight")
    property string buttonState: ""
    property string onEventPressed: ""
    property string onEventReleased: ""
    property string onEventClick: "evG_Media_RequestPlaybackAction_PBAPause"
    property string onEventPressAndHold: ""
    property string onEventHoldAndReleased: ""
    property string eventParameterString: ""
    property bool isContainsMouse: false

    /* Magic! Do not touch */
    function emitSignal( callBack ) {
        if (callBack !== "")
            UIBridge.hmiEvent(this.objectName, callBack + (eventParameterString === "" ? "" : "(" + eventParameterString + ")" ));
        }
    onButtonStateChanged: {
        if(buttonState == '') {}
        else if (buttonState == '1') {
            mymedia_play_pause.normalSource = UIBridge.getImageSourceByName("pause_normal")
            mymedia_play_pause.focusSource = UIBridge.getImageSourceByName("pause_highlight")
        }
        else if (buttonState == '0') {
            mymedia_play_pause.normalSource = UIBridge.getImageSourceByName("play_normal")
            mymedia_play_pause.focusSource = UIBridge.getImageSourceByName("play_active")
        }
        else if (buttonState == '3') {
            mymedia_play_pause.normalSource = UIBridge.getImageSourceByName("pause_disabled")
        }
        else if (buttonState == '2') {
            mymedia_play_pause.normalSource = UIBridge.getImageSourceByName("play_disabled")
        }
    }

    objectName: "mymedia_play_pause"
    width: 100
    height: 100
    source: isContainsMouse ? focusSource : normalSource
    y: 296
    x: 284

    MouseArea {
        anchors.fill: parent
        property bool _isLongpress: false
        onContainsMouseChanged: parent.isContainsMouse = containsMouse
        onPressed: {
            parent.emitSignal(parent.onEventPressed);
        }
        onReleased: {
            if(!_isLongpress) {
                parent.emitSignal(parent.onEventReleased);
            } else if (_isLongpress) {
                parent.emitSignal((parent.onEventHoldAndReleased != "") ?
                                   parent.onEventHoldAndReleased : parent.onEventClick);
                _isLongpress = false;
            }
        }
        onClicked: {
            parent.emitSignal(parent.onEventClick);
        }
        onPressAndHold: {
            _isLongpress = true;
            parent.emitSignal(parent.onEventPressAndHold);
        }
        Component.onDestruction: {
            if (_isLongpress) {
                parent.emitSignal(parent.onEventHoldAndReleased);
            }
        }
    }
} /* End Touchable Image Widget: mymedia_play_pause */
