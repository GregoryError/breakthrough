import QtQuick 2.2
import QtQuick.Window 2.2
import QtQuick.Controls 2.2


Window {
    id: mainWindow
    visible: true
    width: 540 * 0.7
    height: 960 * 0.7



    Connections {
        target: game_core
        onShowRules: {
            drawer_timer.start()
            rulesTimer.start()
        }
    }


    Timer {
        id: drawer_timer
        interval: 1100;
        running: false;
        repeat: false;
        onTriggered: {
            drawer.open()
        }
    }

    Timer {
        id: rulesTimer
        interval: 2300
        running: false
        repeat: false
        onTriggered: {
            circleAnimation.stop()
            opacityAnimation.stop()
            game_core.clickSound();
            circleAnimation.target = opacityAnimation.target = rules_sw_colorRect
            circleAnimation.start()
            opacityAnimation.start()
        }
    }

    Item {
        id: bar
        z: 4
        x: 0
        y: 0
        width: mainWindow.width
        height: mainWindow.height / 16

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
            duration: 500
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
                    name_txt_anim.start()
                }

                Rectangle{
                    id: drawBack
                    anchors.fill: parent
                    color: "#1d242b"

                    Image {
                        id: name
                        source: "qrc:/visualsources/draw_back.png"
                        anchors.fill: parent
                        opacity: 0.7

                        Image {
                            id: app_name
                            source: "qrc:/visualsources/label.png"
                            anchors.top: parent.top
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: parent.width * 0.7
                            fillMode: Image.PreserveAspectFit
                            anchors.topMargin: 20

                            PropertyAnimation {
                                id: name_txt_anim
                                target: app_name
                                easing.type: Easing.InCubic
                                properties: "opacity"
                                from: 0
                                to: 1
                                duration: 1200
                                running: false
                            }

                        }

                        // buttons begin


                        PropertyAnimation {
                            id: circleAnimation
                            properties: "width,height,radius"
                            from: 0
                            to: drawBack.width * 2
                            duration: 300
                            onRunningChanged: {

                            }

                            onStopped: {

                                //                                music_sw
                                //                                sound_sw
                                //                                rules_sw
                                //                                about_sw
                                //                                feedback_sw

                                music_sw_colorRect.width = 0
                                music_sw_colorRect.height = 0

                                sound_sw_colorRect.width = 0
                                sound_sw_colorRect.height = 0

                                rules_sw_colorRect.width = 0
                                rules_sw_colorRect.height = 0

                                about_sw_colorRect.width = 0
                                about_sw_colorRect.height = 0

                                feedback_sw_colorRect.width = 0
                                feedback_sw_colorRect.height = 0
                            }
                        }

                        PropertyAnimation {
                            id: opacityAnimation
                            properties: "opacity"
                            from: 1
                            to: 0
                            duration: 500
                        }

                        Item {
                            id: music_sw
                            anchors.top: app_name.bottom
                            anchors.topMargin: 15
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: parent.width
                            height: (mainWindow.height / 16)
                            clip: true
                            Text {
                                id: music_txt
                                anchors.centerIn: parent
                                font.family: "Segoe UI Light"
                                font.pointSize: 16
                                color: "white"
                                text: "Музыка on/off"
                                width: parent.width * 0.6
                            }

                            Image {
                                source: "qrc:/visualsources/rght_arrow.png"
                                anchors.verticalCenter: music_sw.verticalCenter
                                anchors.left: music_txt.right
                                anchors.leftMargin: 5
                                height: music_sw.height * 0.7
                                fillMode: Image.PreserveAspectFit
                            }
                            MouseArea {
                                id: music_ms_area
                                anchors.fill: parent
                                onClicked: {
                                    circleAnimation.stop()
                                    opacityAnimation.stop()
                                    game_core.clickSound();
                                    music_sw_colorRect.x = mouseX
                                    music_sw_colorRect.y = mouseY
                                    circleAnimation.target = opacityAnimation.target = music_sw_colorRect
                                    circleAnimation.start()
                                    opacityAnimation.start()

                                }
                            }

                            Rectangle {
                                id: music_sw_colorRect
                                height: 0
                                width: 0
                                color: "white"
                                transform: Translate {
                                    x: -music_sw_colorRect.width / 2
                                    y: -music_sw_colorRect.height / 2
                                }
                            }

                        }

                        Item {
                            id: sound_sw
                            anchors.top: music_sw.bottom
                            anchors.topMargin: 10
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: parent.width
                            height: (mainWindow.height / 16)
                            clip: true
                            Text {
                                id: sound_txt
                                anchors.centerIn: parent
                                font.family: "Segoe UI Light"
                                font.pointSize: 16
                                color: "white"
                                text: "Звук on/off"
                                width: parent.width * 0.6
                            }

                            Image {
                                source: "qrc:/visualsources/rght_arrow.png"
                                anchors.verticalCenter: sound_sw.verticalCenter
                                anchors.left: sound_txt.right
                                anchors.leftMargin: 5
                                height: sound_sw.height * 0.7
                                fillMode: Image.PreserveAspectFit
                            }
                            MouseArea {
                                id: sound_ms_area
                                anchors.fill: parent
                                onClicked: {
                                    circleAnimation.stop()
                                    opacityAnimation.stop()
                                    game_core.clickSound();
                                    sound_sw_colorRect.x = mouseX
                                    sound_sw_colorRect.y = mouseY
                                    circleAnimation.target = opacityAnimation.target = sound_sw_colorRect
                                    circleAnimation.start()
                                    opacityAnimation.start()

                                }
                            }

                            Rectangle {
                                id: sound_sw_colorRect
                                height: 0
                                width: 0
                                color: "white"
                                transform: Translate {
                                    x: -sound_sw_colorRect.width / 2
                                    y: -sound_sw_colorRect.height / 2
                                }
                            }
                        }

                        Item {
                            id: rules_sw
                            anchors.top: sound_sw.bottom
                            anchors.topMargin: 10
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: parent.width
                            height: (mainWindow.height / 16)
                            clip: true
                            Text {
                                id: rules_txt
                                anchors.centerIn: parent
                                font.family: "Segoe UI Light"
                                font.pointSize: 16
                                color: "white"
                                text: "Правила игры"
                                width: parent.width * 0.6
                            }

                            Image {
                                source: "qrc:/visualsources/rght_arrow.png"
                                anchors.verticalCenter: rules_sw.verticalCenter
                                anchors.left: rules_txt.right
                                anchors.leftMargin: 5
                                height: rules_sw.height * 0.7
                                fillMode: Image.PreserveAspectFit
                            }
                            MouseArea {
                                id: rules_ms_area
                                anchors.fill: parent
                                onClicked: {
                                    circleAnimation.stop()
                                    opacityAnimation.stop()
                                    game_core.clickSound();
                                    rules_sw_colorRect.x = mouseX
                                    rules_sw_colorRect.y = mouseY
                                    circleAnimation.target = opacityAnimation.target = rules_sw_colorRect
                                    circleAnimation.start()
                                    opacityAnimation.start()
                                    stackView.push("qrc:/rules.qml")

                                }
                            }

                            Rectangle {
                                id: rules_sw_colorRect
                                height: 0
                                width: 0
                                color: "white"
                                transform: Translate {
                                    x: -rules_sw_colorRect.width / 2
                                    y: -rules_sw_colorRect.height / 2
                                }
                            }
                        }

                        Item {
                            id: about_sw
                            anchors.top: rules_sw.bottom
                            anchors.topMargin: 10
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: parent.width
                            height: (mainWindow.height / 16)
                            clip: true
                            Text {
                                id: about_txt
                                anchors.centerIn: parent
                                font.family: "Segoe UI Light"
                                font.pointSize: 16
                                color: "white"
                                text: "О приложении"
                                width: parent.width * 0.6
                            }

                            Image {
                                source: "qrc:/visualsources/rght_arrow.png"
                                anchors.verticalCenter: about_sw.verticalCenter
                                anchors.left: about_txt.right
                                anchors.leftMargin: 5
                                height: about_sw.height * 0.7
                                fillMode: Image.PreserveAspectFit
                            }
                            MouseArea {
                                id: about_ms_area
                                anchors.fill: parent
                                onClicked: {
                                    circleAnimation.stop()
                                    opacityAnimation.stop()
                                    game_core.clickSound();
                                    about_sw_colorRect.x = mouseX
                                    about_sw_colorRect.y = mouseY
                                    circleAnimation.target = opacityAnimation.target = about_sw_colorRect
                                    circleAnimation.start()
                                    opacityAnimation.start()

                                }
                            }

                            Rectangle {
                                id: about_sw_colorRect
                                height: 0
                                width: 0
                                color: "white"
                                transform: Translate {
                                    x: -about_sw_colorRect.width / 2
                                    y: -about_sw_colorRect.height / 2
                                }
                            }
                        }

                        Item {
                            id: feedback_sw
                            anchors.top: about_sw.bottom
                            anchors.topMargin: 10
                            anchors.horizontalCenter: parent.horizontalCenter
                            width: parent.width
                            height: (mainWindow.height / 16)
                            clip: true
                            Text {
                                id: feedback_txt
                                anchors.centerIn: parent
                                font.family: "Segoe UI Light"
                                font.pointSize: 16
                                color: "white"
                                text: "Оценить"
                                width: parent.width * 0.6
                            }

                            Image {
                                source: "qrc:/visualsources/rght_arrow.png"
                                anchors.verticalCenter: feedback_sw.verticalCenter
                                anchors.left: feedback_txt.right
                                anchors.leftMargin: 5
                                height: feedback_sw.height * 0.7
                                fillMode: Image.PreserveAspectFit
                            }
                            MouseArea {
                                id: feedback_ms_area
                                anchors.fill: parent
                                onClicked: {
                                    circleAnimation.stop()
                                    opacityAnimation.stop()
                                    game_core.clickSound();
                                    feedback_sw_colorRect.x = mouseX
                                    feedback_sw_colorRect.y = mouseY
                                    circleAnimation.target = opacityAnimation.target = feedback_sw_colorRect
                                    circleAnimation.start()
                                    opacityAnimation.start()
                                }
                            }

                            Rectangle {
                                id: feedback_sw_colorRect
                                height: 0
                                width: 0
                                color: "white"
                                transform: Translate {
                                    x: -feedback_sw_colorRect.width / 2
                                    y: -feedback_sw_colorRect.height / 2
                                }
                            }
                        }

                    }
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






























