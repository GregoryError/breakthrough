import QtQuick 2.12
import QtQuick.Controls 2.2

Item {
    id: mainTtem
    anchors.fill: parent

    Image {
        id: backImg
        source: "qrc:/visualsources/draw_back.png"
        anchors.fill: parent

        Component.onCompleted: focus = true;

        Flickable{
            id: rulesFlick
            width: backImg.width
            height: backImg.height
            anchors.horizontalCenter: backImg.horizontalCenter
            contentHeight: (rulesTXT.height + introTXT.height + moveGif.height +
                           botomTXT.height + winGif.height) * 1.5
            contentWidth: parent.width
            smooth: true
            boundsBehavior: Flickable.StopAtBounds
            interactive: true
            maximumFlickVelocity: 1000000
            clip: true

            Text {
                id: rulesTXT
                anchors.top: parent.top
                anchors.topMargin: 50
                anchors.leftMargin: 50
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Segoe UI Light"
                font.pointSize: 20
                minimumPointSize: 14
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                width: parent.width * 0.9
                color: "white"
                text: "Правила игры:"

            }

            Text {
                id: introTXT
                anchors.top: rulesTXT.bottom
                anchors.topMargin: 50
                anchors.leftMargin: 50
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Segoe UI Light"
                font.pointSize: 15
                minimumPointSize: 12
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                width: parent.width * 0.9
                color: "white"
                text: "Ходы делаются одновременно, <br>
что существенно отличает игру <br>
от большинства других игр, <br>
в которых противники ходят по очереди.<br>
Cыграть можно любой <br>
своей шашкой на любое <br>
свободное соседнее поле. <br>
Если в результате перемещений<br>
шашек какие-либо <br>
две шашки оказались на одном поле,<br>
они обе снимаются <br>
с доски. В противном случае<br>
шашки переставляются."
            }

            AnimatedImage {
                id: moveGif
                source: "qrc:/visualsources/gifs/move.gif"
                width: parent.width
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: introTXT.bottom
                anchors.topMargin: 20
                playing: true
                speed: 0.7
            }


            Text {
                id: botomTXT
                anchors.top: moveGif.bottom
                anchors.topMargin: 50
                anchors.leftMargin: 50
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Segoe UI Light"
                font.pointSize: 15
                minimumPointSize: 12
                fontSizeMode: Text.Fit
                horizontalAlignment: Text.AlignHCenter
                width: parent.width * 0.9
                color: "white"
                text: "Цель игры для синих - прорваться<br>
какой-нибудь своей шашкой <br>
на восьмую горизонталь;<br>
цель игры для красных - добраться до <br>
первой горизонтали. Если в результате хода<br>
оба игрока достигли<br>
своей цели, партия считается<br>
окончившейся вничью.<br><br>
ПОБЕДА СИНИХ: "

            }

            AnimatedImage {
                id: winGif
                source: "qrc:/visualsources/gifs/win.gif"
                width: parent.width
                fillMode: Image.PreserveAspectFit
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.top: botomTXT.bottom
                anchors.topMargin: 20
                playing: true
                speed: 0.7
            }
        }
    }
}





















