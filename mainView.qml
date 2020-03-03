import QtQuick 2.0

Item {
    id: mainItem
    anchors.fill: parent

    Rectangle {
        id: mainRect
        anchors.fill: parent
        Rectangle {                         // The main information field
            id: infoRect
            color: "#2C3846"
            anchors.top: mainRect.top
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            height: (mainRect.height / 16) * 6
        }
        Rectangle {
            id: middleRect                  // In wich we can place some extra info
            color: "#232D38"
            anchors.top: infoRect.bottom
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            height: infoRect.height / 6
        }

        Rectangle {
            id: gameRect                    // For Playboard; MB use as a background for grid ?
            anchors.top: middleRect.bottom
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            anchors.bottom: mainRect.bottom
            color: "#000106"

            Grid {
                id: gameGrid
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                rows: 8
                columns: 8
                width: parent.width * 0.9
                height: width

                Repeater {
                    id: rptr
                    model: 64

                    Loader {
                        id: cellLoader
                        anchors.fill: parent
                    }
                    Rectangle {
                        width: gameGrid.width / 8
                        height: width
                        color: "transparent"

                        Text {
                            id: txr
                            anchors.centerIn: parent.Center
                            text: index
                            color: "white"
                        }

                        MouseArea {
                            id: mouseCellArea
                            anchors.fill: parent
                        }
                    }

                    Component.onCompleted: {

                        var lineCount = 0;
                        for (var i = 0; i < 64; ++i) {                   // "#2C3846" : "#020911"
                            if (i % 8 == 0)
                                ++lineCount;
                            if (lineCount % 2 != 0) {
                                if (i % 2 == 0)
                                    rptr.itemAt(i, lineCount).color = "#2C3846"
                                else
                                    rptr.itemAt(i, lineCount).color = "#020911"
                            }
                            else {
                                if (i % 2 == 0)
                                    rptr.itemAt(i, lineCount).color = "#020911"
                                else
                                    rptr.itemAt(i, lineCount).color = "#2C3846"
                            }
                        }
                        addFigure(3, 3, 0);
                        addFigure(5, 5, 1);
                    }
                }
            }
        }
    }
}




































