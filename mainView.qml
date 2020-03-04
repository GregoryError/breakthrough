import QtQuick 2.2
import QtQuick.Controls 2.2

Item {
    id: mainItem
    anchors.fill: parent

    ParallelAnimation {
        id: imgAnim
        running: false
        NumberAnimation { target: cellImg; property: "x"; to: mouseX; duration: 500 }
        NumberAnimation { target: cellImg; property: "y"; to: mouseY; duration: 500 }
    }

    property int from: -1

    function item_clicked(index) {
        if (from == -1) {
            from = index
        } else {
            imgAnim.start()

            my_model.replace(from, index)
            from = -1
            //cellImg.state = "returnParent"

        }
    }

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


                ListModel {
                    id: my_model
                    Component.onCompleted: {
                        for (var i = 0; i < 64; ++i) {
                            if (i < 16)
                                append({"item": "qrc:/visualsources/blueFigure.png"})
                            if (i >= 16 && i < 48)
                                append({"item": ""})
                            if (i >= 48 && i < 64)
                                append({"item": "qrc:/visualsources/redFigure.png"})
                        }
                    }

                    function get_item(index) {
                        return get(index).item
                    }

                    function set_item(index, item) {
                        set(index, {"item": item})
                    }

                    function replace(from_index, to_index) {
                        var from_obj = get_item(from_index)
                        var to_obj = get_item(to_index)
                        set_item(to_index, from_obj)
                        set_item(from_index, to_obj)

                    }

                }


                Grid {
                    id: gridBoard
                    columns: 8

                    add: Transition {
                        NumberAnimation { property: "opacity"; from: 0; to: 1.0; duration: 300 }
                        NumberAnimation { property: "scale"; from: 0; to: 1.0; duration: 50 }
                    }


                    Repeater {
                        model: my_model

                        Rectangle {
                            id: itemWrapper
                            width: gameItem.width / 8
                            height: gameItem.width / 8
                            scale: index == from ? 0.9 : 1
                            color: "transparent" // index == from ? "white" : "transparent"
                            radius: 25
                            //border.color: "white"
                            //border.width: 3

                            Image {
                                id: cellImg
                                // anchors.centerIn: parent
                                width: itemWrapper.width
                                height: itemWrapper.height
                                source: model.item
                                fillMode: Image.PreserveAspectFit

                                states: State {
                                    name: "changeParent"
                                    PropertyChanges { target: cellImg; parent: gameItem }
                                }

                                State {
                                    name: "returnParent"
                                    PropertyChanges { target: cellImg; parent: itemWrapper }
                                }




                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                   // cellImg.state = "changeParent"
                                    item_clicked(index)

                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


























