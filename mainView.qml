import QtQuick 2.2
import QtQuick.Controls 2.2

Item {
    id: mainItem
    anchors.fill: parent
    property int from: -1

    function item_clicked(index) {
        if (from == -1) {
            from = index
        } else {

            my_model.replace(from, index)
            from = -1
        }
    }

    function refresh_model()
    {
        my_model.clear()
        for (var i = 0; i < 64; ++i) {

            if (game_core.getCell_(i) === 1)
            {
                if (game_core.getSide_(i))
                    my_model.append({"item": "qrc:/visualsources/blueFigure.png"})
                if (!game_core.getSide_(i))
                    my_model.append({"item": "qrc:/visualsources/redFigure.png"})
            } else
                my_model.append({"item": ""})
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
                    id: backModel
                    Component.onCompleted: {

                        var line_count = 1;
                        for (var i = 0; i < 64; ++i) {
                            if (i % 8 === 0)
                                ++line_count;
                            if (line_count % 2 !== 0)
                                if (i % 2 === 0)
                                    append({"backColor": "black"})
                                else
                                    append({"backColor": "#2C3846"})
                            else
                                if (i % 2 === 0)
                                    append({"backColor": "#2C3846"})
                                else
                                    append({"backColor": "black"})

                        }
                    }
                }

                Grid {
                    columns: 8
                    z: 2

                    Repeater {
                        id: backRepeater
                        model: backModel
                        Rectangle {
                            id: backCell
                            color: model.backColor
                            width: gameItem.width / 8
                            height: gameItem.width / 8
                        }

                    }
                }

                ListModel {
                    id: my_model
                    dynamicRoles: true
                    Component.onCompleted: {

                        refresh_model()


//                        for (var i = 0; i < 64; ++i) {

//                            if (game_core.getCell_(i) === 1)
//                            {
//                                if (game_core.getSide_(i))
//                                    append({"item": "qrc:/visualsources/blueFigure.png"})
//                                if (!game_core.getSide_(i))
//                                    append({"item": "qrc:/visualsources/redFigure.png"})
//                            } else
//                                append({"item": ""})
//                        }

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


                ParallelAnimation {
                    id: anim
                    property Item toItem
                    property Item fromItem
                    property point fromPosition: Qt.point(0, 0)
                    property point toPosition: Qt.point(0, 0)
                    property int duration: 150



                    function start_animation(from, to) {
                        fromItem = from
                        fromItem.z += 1
                        toItem = to
                        fromPosition = Qt.point(from.x, from.y)
                        toPosition = Qt.point(to.x, to.y)
                        start()
                    }

                    NumberAnimation {
                        target: anim.fromItem
                        property: "x"
                        easing.overshoot: 3
                        easing.type: Easing.OutBack
                        duration: 200
                        from: anim.fromPosition.x
                        to: anim.toPosition.x

                    }

                    NumberAnimation {
                        target: anim.fromItem
                        property: "y"
                        duration: 200
                        from: anim.fromPosition.y
                        to: anim.toPosition.y
                        easing.overshoot: 3
                        easing.type: Easing.OutBack
                    }
                    onStopped: {
                        fromItem.x = fromPosition.x
                        fromItem.y = fromPosition.y
                        fromItem.z -= 1
                        my_model.replace(fromItem._index, toItem._index)
                        refresh_model();
                    }
                }

                property Item from: null

                function item_clicked(item) {
                    if (from == null) {
                        from = item

                        from.scale = 0.8
                    } else {
                        item.scale = 1
                        if (game_core.move_(from._index, item._index))
                        {
                            anim.start_animation(from, item)

                        }
//                        console.log(from._index);
//                        console.log(item._index);
                        from = null
                    }
                }

                Grid {
                    columns: 8
                    z: 5
                    Repeater {
                        id: repeater
                        model: my_model
                        Rectangle {
                            id: root_item
                            property int _index: index
                            width: gameItem.width / 8
                            height: gameItem.width / 8
                            color: "transparent" // from === root_item ? "lightblue" : "lightgray"

                            Image {
                                id: cellImg
                                anchors.centerIn: parent
                                width: root_item.width
                                height: root_item.height
                                source: model.item
                                fillMode: Image.PreserveAspectFit

                            }

                            MouseArea {
                                anchors.fill: parent
                                onClicked: {
                                    gameItem.item_clicked(root_item)
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


























