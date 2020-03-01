import QtQuick 2.0

Item {
    id: mainItem
    anchors.fill: parent
    Rectangle{
        id: mainRect
        anchors.fill: parent
        Rectangle {
            id: infoRect
            color: "steelblue"
            anchors.top: mainRect.top
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            height: (mainRect.height / 16) * 6
        }
        Rectangle{
            id: gameRect
            anchors.top: infoRect.bottom
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            anchors.bottom: mainRect.bottom
            color: "lightblue"
        }
    }
}

