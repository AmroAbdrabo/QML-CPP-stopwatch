import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import ch.epfl.stopwatch 1.0

ApplicationWindow {
    id: root
    visible: true
    width: 640
    height: 480
    title: qsTr("Stopwatch")

    Stopwatch {
        id: stopwatch
    }

    Row {
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.horizontalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        spacing: 3
        Button {
            id: btnStart
            text: "Start"
            onClicked:{
                console.log("Start");
                stopwatch.start();
            }
        }
        Button {
            id: btnStop
            text: "Stop"
            onClicked: {
                console.log("Stop");
                stopwatch.stop();
            }
        }

        Button {
            id: btnReset;
            text : "Reset"
            onClicked: {
                console.log("Reset");
                stopwatch.reset();
            }
        }

        Button {
            id: btnGoal
            text: "Goal: 3.0"
            onClicked: {
                console.log("Set goal");
                stopwatch.best = 3.0;
            }
        }
    }

    Text {
        anchors.verticalCenterOffset: -80
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        text: "Current time"
        font.bold: true
        font.family: "Arial"
    }
    Text {
        id: userDisplay
        width: 155
        height: 41
        text : stopwatch.display
        anchors.verticalCenterOffset: -50
        anchors.horizontalCenterOffset: -30
        font.pointSize: 60
        color: "blue"
        font.bold: true
        font.family: "Arial"
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
    }
}
