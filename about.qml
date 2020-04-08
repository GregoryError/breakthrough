import QtQuick 2.12

Item {
    id: mainTtem
    Image {
        id: backImg
        source: "qrc:/visualsources/draw_back.png"
        anchors.fill: parent
        opacity: 0.9

        Text {
            id: aboutTXT
            anchors.top: parent.top
            anchors.topMargin: 50
            anchors.leftMargin: 50
            anchors.horizontalCenter: parent.horizontalCenter
            font.family: "Segoe UI Light"
            font.pointSize: 16
            minimumPointSize: 14
            fontSizeMode: Text.Fit
            horizontalAlignment: Text.AlignHCenter
            width: parent.width * 0.9
            color: "white"
            text: "Прорывные шашки v 1.0<br>
Gregory Kolesnikoff 2020<br>"

        }

        Text {
            id: linkTXT
           anchors.top: aboutTXT.bottom
           anchors.topMargin: 5
           anchors.horizontalCenter: parent.horizontalAlignment
           font.family: "Segoe UI Light"
           font.pointSize: 30
           minimumPointSize: 14
           fontSizeMode: Text.Fit
           horizontalAlignment: Text.AlignHCenter
           width: parent.width * 0.9
           text: '<html><style type="text/css"><font color="white"><font size="30"></style><a href="https://github.com/GregoryError">GIT</a></font></font></html>'
           onLinkActivated: Qt.openUrlExternally(link)
        }
    }

}



