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

            Item {
                id: gameItem
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width - 40
                height: width


                Component {
                    id: dndDelegate


                    Item {
                        id: wrapper
                        width: dndGrid.cellWidth
                        height: dndGrid.cellHeight
                        Rectangle {
                            id: imageBorder
                            anchors.fill: parent
                            radius: 2
                            color: "transparent"
                            border.color: "#ffffff"
                            border.width: 1
                            opacity: 0
                        }
                        states: [
                            State {
                                name: "inDrag"
                                when: index == dndGrid.draggedItemIndex
                                PropertyChanges { target: imageBorder; opacity: 1 }

                                PropertyChanges { target: itemImage; scale: 0.9 }
                                PropertyChanges { target: itemImage; anchors.centerIn: parent }

                            }
                        ]

                        Image {
                            id: itemImage
                            source: imagePath
                             anchors.fill: parent
                            width: dndGrid.cellWidth - 5
                            height: width
                            smooth: true
                            fillMode: Image.PreserveAspectFit
                        }
                    }
                }

                ListModel {
                    id: dndModel
                }

                GridView {
                    id: dndGrid
                    interactive: false
                    anchors.fill: parent
                    //                    anchors.margins: 10
                    cellWidth: gameItem.width / 8
                    cellHeight: gameItem.height / 8
                    model: dndModel
                    delegate: dndDelegate
                    property int draggedItemIndex: -1
                    Item {
                        id: dndContainer
                        anchors.fill: parent
                    }

                    MouseArea {
                        id: coords
                        anchors.fill: parent
                        onReleased: {
                            if (dndGrid.draggedItemIndex != -1) {
                                var draggedIndex = dndGrid.draggedItemIndex
                                dndGrid.draggedItemIndex = -1
                                dndModel.move(draggedIndex,dndGrid.indexAt(mouseX, mouseY), 1)
                            }
                        }
//                        onPressed: {
//                            dndGrid.draggedItemIndex = dndGrid.indexAt(mouseX, mouseY)
//                        }

                        onClicked: {
                            dndGrid.draggedItemIndex = dndGrid.indexAt(mouseX, mouseY)
                        }


                    }

                    Component.onCompleted: {
                        for (var i = 0; i < 64; ++i) {
                            if (i < 16) {
                                dndModel.append({"imagePath": "qrc:/visualsources/blueFigure.png"})
                                continue
                            }
                            if (i >= 48 && i < 64) {
                                dndModel.append({"imagePath": "qrc:/visualsources/redFigure.png"})
                                continue
                            }
                            dndModel.append({"imagePath": "qrc:/visualsources/lightCell.png"})
                        }
                    }
                }
            }
        }
    }
}




































