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
                anchors.fill: parent
                rows: 8
                columns: 8

                Repeater { model: 64
                    Rectangle {
                        width: gameGrid.width / 8
                        height: width
                        color:                      // index + 1 % 8 == 0 ? index % 2 == 0 ? "#2C3846" : "#020911" : index % 2 == 0 ? "#2C3846" : "#020911"

                        Text { text: index
                            font.pointSize: 30
                            anchors.centerIn: parent } }
                }

            }






            //            Component {
            //                id: boardDelegate
            //                Item {
            //                    width: gridBoard.cellWidth;
            //                    height: gridBoard.cellHeight
            //                    Column {
            //                        anchors.fill: parent
            //                        Image {
            //                            source: backImg;
            //                            anchors.centerIn: parent.Center
            //                            width: gridBoard.cellWidth
            //                            height: gridBoard.cellHeight
            //                            Image {
            //                                id: figureRed
            //                                source: figureImgRed;
            //                                visible: false
            //                                anchors.horizontalCenter: parent.horizontalCenter
            //                                width: gridBoard.cellWidth
            //                                height: gridBoard.cellHeight
            //                            }
            //                            Image {
            //                                id: figureBlue
            //                                source: figureImgBlue;
            //                                visible: false
            //                                anchors.horizontalCenter: parent.horizontalCenter
            //                                width: gridBoard.cellWidth
            //                                height: gridBoard.cellHeight
            //                            }
            //                        }
            //                    }
            //                }
            //            }

            //            ListModel {
            //                id: boardModel
            //            }
            //            Item {
            //                id: gridItem
            //                width: gameRect.width - 60
            //                height: gameRect.height - 60
            //                anchors.centerIn: gameRect

            //                GridView{
            //                    id: gridBoard
            //                    anchors.fill: parent
            //                    cellHeight: parent.width / 8
            //                    cellWidth: cellHeight
            //                    focus: true
            //                    delegate: boardDelegate
            //                    model: boardModel
            //                    interactive: false

            //                }
            //            }

            //            Component.onCompleted: {
            //                var newLine = 1;
            //                for (var i = 0; i < 64; ++i) {

            //                    if (i < 16) {

            //                    }

            //                    if ((i) % 8 == 0)
            //                        ++newLine;
            //                    if (newLine % 2 == 0)
            //                        if (i % 2 != 0)
            //                            boardModel.append({"backImg": "", "figureImgRed": "qrc:/visualsources/redFigure.png", "figureImgBlue": "qrc:/visualsources/blueFigure.png"})
            //                        else
            //                            boardModel.append({"backImg": "qrc:/visualsources/lightCell.png", "figureImgRed": "qrc:/visualsources/redFigure.png", "figureImgBlue": "qrc:/visualsources/blueFigure.png"})
            //                    else {
            //                        if (i % 2 != 0)
            //                            boardModel.append({"backImg": "qrc:/visualsources/lightCell.png", "figureImgRed": "qrc:/visualsources/redFigure.png", "figureImgBlue": "qrc:/visualsources/blueFigure.png"})
            //                        else
            //                            boardModel.append({"backImg": "", "figureImgRed": "qrc:/visualsources/redFigure.png", "figureImgBlue": "qrc:/visualsources/blueFigure.png"})
            //                    }
            //                }
            //            }
        }
    }
}




































