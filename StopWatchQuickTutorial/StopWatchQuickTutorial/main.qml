import QtQuick 2.12
import QtQuick.Window 2.12
import dsx3.d3xs.stopwatch 1.0
import QtQuick.Controls 2.12

Window {
    id:wnd
    visible: true
    width: 640
    height: 480
    title: qsTr("StopWatch")

    StopWatch {
        id: stopwatch
        onBestChanged: {
            console.log("onBestChanged")
        }
        onDisplayChanged: {
            console.log("onBestChanged")
        }




    }
    Timer {
        id: timer
//        onTriggered:


            anchors {
                top: parent.top
                topMargin: 8
                horizontalCenterOffset: 0
                horizontalCenter: parent.horizontalCenter
            }

            spacing: 3
            Button {
                id: btnStop
                text: "Stop"
                onClicked: {
                    //Stop
                    console.log("Stop")
                    stopwatch.stop()
                }
            }

            Button {
                id: btnStart
                text: "Start"
                onClicked: {
                    //Start
                    console.log("Start")
                    stopwatch.start()
                }
            }

            Button {
                id: btnReset
                text: "Reset"
                onClicked: {
                    //Reset
                    console.log("Reset")
                    stopwatch.reset()
                }
            }

            Button {
                id: btnGoal
                text: "Goal 3.0"
                onClicked: {
                    console.log("Goal 3.0")
                    stopwatch.best = 3.0


                }
            }

        }
        Row {

            Text {
                id: text_display
                text: stopwatch.display
                anchors {
                    //            centerIn: parent
                }
            }

            Text {
                id: text_best
                text: Number(stopwatch.best).toFixed(2)
                anchors {
                    //                centerIn: parent
                }
            }
        }
    }
