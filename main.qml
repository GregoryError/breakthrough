import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Window {
    id: mainWindow
    visible: true
    width: 540 * 0.7
    height: 960 * 0.7



    Item {
        id: bar
        z: 4
        x: 0
        y: 0
        width: mainWindow.width
        height: mainWindow.height / 20
        // clip: true

        Rectangle{
            id: toolRect
            anchors.verticalCenter: bar.verticalCenter
            color: "transparent"
            radius: 25
            // clip: true
            height: bar.height
            width: height
            x: 20

            Image {
                id: toolPic
                width: 20
                height: 20
                source: "qrc:/visualsources/toolPic.png"
                anchors.centerIn: toolRect
                fillMode: Image.PreserveAspectFit
            }

            Rectangle {
                id: toolButtoncolorRect
                height: 0
                width: 0
                anchors.centerIn: toolRect
                color: "white"
                transform: Translate {
                }
            }

            MouseArea{
                id: toolButton
                anchors.fill: parent
                onPressed: {
                    toolButtoncircleAnimation.start()
                    toolButtonOpacityAnimation.start()
                }
            }
        }

        PropertyAnimation {
            id: toolButtoncircleAnimation
            target: toolButtoncolorRect
            properties: "width,height,radius"
            from: 0
            to: toolRect.width * 2
            duration: 400
            onRunningChanged: {
                if (stackView.depth > 1) {
                    stackView.pop()
                } else {
                    drawer.open()
                }
            }

            onStopped: {
                toolButtoncolorRect.width = 0
                toolButtoncolorRect.height = 0
            }
        }

        PropertyAnimation {
            id: toolButtonOpacityAnimation
            target: toolButtoncolorRect
            properties: "opacity"
            from: 1
            to: 0
            duration: 700
        }

        Rectangle{
            id: shareRect
            anchors.verticalCenter: bar.verticalCenter
            color: "transparent"
            radius: 25
            // clip: true
            height: bar.height
            width: height


            x: bar.width - width - 20

            Image {
                id: sharePic
                width: 16
                height: 16
                source: "qrc:/visualsources/shareBtn.png"
                anchors.centerIn: shareRect
                fillMode: Image.PreserveAspectFit

            }
            Rectangle {
                id: shareButtoncolorRect
                height: 0
                width: 0
                anchors.centerIn: shareRect
                color: "white"

                transform: Translate {
                }
            }
            MouseArea{
                id: shareutton
                anchors.fill: parent
                onPressed: {
                    shareButtoncircleAnimation.start()
                    shareButtonOpacityAnimation.start()
                    game_core.newGame();
                }
            }
        }

        PropertyAnimation {
            id: shareButtoncircleAnimation
            target: shareButtoncolorRect
            properties: "width,height,radius"
            from: 0
            to: shareRect.width * 2
            duration: 400

            onStopped: {
                shareButtoncolorRect.width = 0
                shareButtoncolorRect.height = 0
            }
        }

        PropertyAnimation {
            id: shareButtonOpacityAnimation
            target: shareButtoncolorRect
            properties: "opacity"
            from: 1
            to: 0
            duration: 700
        }
    }

    Item {
        id: mainField
        anchors.fill: parent

        StackView {
            id: stackView
            z: 1
            anchors.fill: parent
            initialItem: "mainView.qml"
            Drawer {
                id: drawer
                width: mainWindow.width * 0.8 + 5
                height: mainWindow.height
                dragMargin: 25
                clip: true
                interactive: true

                onAboutToShow: {
                    drawerAnimOpacity.start()
                }

                Rectangle{
                    id: drawBack
                    anchors.fill: parent
                    color: "#1d242b"
                }
            }
            PropertyAnimation {
                id: drawerAnimOpacity
                target: drawer
                easing.type: Easing.InCubic
                properties: "opacity"
                from: 0
                to: 1
                duration: 350
            }
        }
    }
}


