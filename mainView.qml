import QtQuick 2.2
import QtQuick.Controls 2.2

Item {
    id: mainItem
    property int from: -1
    property int needRefresh: 0


    //    function item_clicked(index) {
    //        if (from == -1) {
    //            from = index
    //        } else {

    //            my_model.replace(from, index)
    //            from = -1
    //        }
    //    }

    function refresh_model()
    {
        console.log("refresh_model called")
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

            Connections{
                target: game_core
                onOpponentReady: {
                    opponentFace.source = game_core.opponent_img();
                    opponentName.text = game_core.opponent_Name();
                    quote.text = game_core.getQuote();

                    countTable.text = "Побед: " + game_core.showVictories() + " Поражений: " +
                            game_core.showDefeats() + " | Вы: " +
                            game_core.showPlayerVictories() + "/" +
                            game_core.showPlayerDefeats();
                }

                onResetBoard: {
                    refresh_model();
                    quote.font.pointSize = 12;
                    quote.font.bold = false;
                    quote.opacity = 1;
                }
            }

            Image {
                id: opponentFace
                anchors.top: infoRect.top
                opacity: 0
                anchors.topMargin: 15
                anchors.horizontalCenter: infoRect.horizontalCenter
                width: infoRect.width / 4 + 5
                height: width
                fillMode: Image.PreserveAspectFit
                onSourceChanged: faceAnim.start()


                MouseArea{
                    anchors.fill: parent
                    onClicked: {

                    }
                }
            }

            Rectangle {
                id: faceFrame
                visible: false
                anchors.top: parent.top
                anchors.topMargin: 15
               // anchors.horizontalCenter: parent.horizontalCenter
                anchors.centerIn: opponentFace
                color: "transparent"
                border.width: 1
                border.color: "white"
                width: opponentFace.width
                height: width
                radius: 50


            }

            PropertyAnimation {
                id: faceFrameAnim
                target: faceFrame
                running: false
                properties: "width,height,radius"
                from: opponentFace.width
                to: faceFrame.width * 1.3
                duration: 1400
                loops: 2

                onStarted: {
                    faceFrame.visible = true
                    faceFrameOpacityAnim.start()
                }

                onStopped: {
                    faceFrame.width = opponentFace.width
                    faceFrame.visible = false
                }
            }

            PropertyAnimation {
                id: faceFrameOpacityAnim
                running: false
                target: faceFrame
                properties: "opacity"
                from: 1
                to: 0
                duration: 1400
                onStopped: {
                    faceFrame.opacity = 1
                }
            }



            OpacityAnimator {
                id: faceAnim
                target: opponentFace
                from: 0
                to: 1
                running: false
                duration: 500
            }

            Text {
                id: opponentName
                anchors.top: opponentFace.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 10
                font.family: "Segoe UI Light"
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 15
                color: "white"
            }
            Text {
                id: quote
                anchors.top: opponentName.bottom
                anchors.horizontalCenter: opponentName.horizontalCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 12
                anchors.topMargin: 8
                font.family: "Segoe UI Light"
                color: "white"
                width: parent.width * 0.8
                wrapMode: Text.WordWrap
            }
        }
        Rectangle {
            id: middleRect                  // In wich we can place some extra info
            color: "#232D38"
            anchors.top: infoRect.bottom
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            height: infoRect.height / 6

            Text {
                id: countTable
                anchors.left: parent.left
                anchors.leftMargin: 5
                anchors.horizontalCenter: parent.horizontalCenter
                font.family: "Segoe UI Light"
                color: "white"
                wrapMode: Text.WordWrap
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 14
                minimumPointSize: 12

            }
        }

        Rectangle {
            id: gameRect                    // For Playboard; MB use as a background for grid ?
            anchors.top: middleRect.bottom
            anchors.left: mainRect.left
            anchors.right: mainRect.right
            anchors.bottom: mainRect.bottom
            color: "#000106"

            Image {
                id: left_nums
                source: "qrc:/visualsources/vertical_nums.png"
                anchors.left: gameRect.left
                anchors.verticalCenter: gameRect.verticalCenter
                height: gameRect.width - 60
                fillMode: Image.PreserveAspectFit
            }

            Image {
                id: right_nums
                source: "qrc:/visualsources/vertical_nums.png"
                anchors.right: gameRect.right
                anchors.verticalCenter: gameRect.verticalCenter
                height: gameRect.width - 60
                fillMode: Image.PreserveAspectFit
            }


            Image {
                id: alph
                source: "qrc:/visualsources/horizontal_alph.png"
                anchors.top: gameRect.top
                anchors.horizontalCenter: gameRect.horizontalCenter
                width: gameRect.width - 70
                fillMode: Image.PreserveAspectFit
            }

            Item {
                id: gameItem
                anchors.top: alph.bottom
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                width: parent.width - 52
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
                        if (game_core.eaten())
                            refresh_model();

                        if (needRefresh == 1)
                        {
                            refresh_model();
                            needRefresh = 0;
                        }

                        if (game_core.win_() !== 3)
                        {
                            quote.font.pointSize = 16
                            quote.font.bold = true
                            if (game_core.win_() === 2)
                                quote.text = "Ну что ж, ничья так ничья!"
                            if (game_core.win_() === 1)
                            {
                                game_core.congrat();
                                quote.text = "Мои поздравления, на этот раз удача на Вашей стороне!"
                            }
                            if (game_core.win_() === 0)
                            {
                                quote.text = "Вы проиграли в этой схватке!"
                                game_core.lose();
                            }
                            quoteAnim.start();
                            faceFrameAnim.start();
                        }


                    }
                }

                OpacityAnimator {
                    id: quoteAnim
                    running: false
                    target: quote
                    from: 1
                    to: 0
                    duration: 700
                    loops: 4
                    onStopped: {
                        game_core.newGame();
                    }
                }

                ParallelAnimation {
                    id: anim_1
                    property Item toItem
                    property Item fromItem
                    property point fromPosition: Qt.point(0, 0)
                    property point toPosition: Qt.point(0, 0)
                    property int duration: 150

                    function start_animation_1(from, to) {
                        fromItem = from
                        fromItem.z += 1
                        toItem = to
                        fromPosition = Qt.point(from.x, from.y)
                        toPosition = Qt.point(to.x, to.y)
                        start()
                    }

                    NumberAnimation {
                        target: anim_1.fromItem
                        property: "x"
                        easing.overshoot: 3
                        easing.type: Easing.OutBack
                        duration: 200
                        from: anim_1.fromPosition.x
                        to: anim_1.toPosition.x
                    }

                    NumberAnimation {
                        target: anim_1.fromItem
                        property: "y"
                        duration: 200
                        from: anim_1.fromPosition.y
                        to: anim_1.toPosition.y
                        easing.overshoot: 3
                        easing.type: Easing.OutBack
                    }
                    onStopped: {
                        fromItem.x = fromPosition.x
                        fromItem.y = fromPosition.y
                        fromItem.z -= 1
                        my_model.replace(fromItem._index, toItem._index)
                        if (game_core.eaten())
                            refresh_model();
                    }
                }

                property Item from: null

                function item_clicked(item) {
                    if (from == null)
                    {
                        if (game_core.hasUnit(item._index))
                        {
                            from = item
                            from.scale = 0.8
                        }
                    }
                    else
                    {
                        if (game_core.isAvailable(from._index, item._index))
                        {
                            item.scale = 1
                            game_core.opponentPlay();
                            if (item._index !== game_core.opponent_from())
                            {
                                if (game_core.move_(from._index, item._index))
                                {
                                    item.scale = 1
                                    anim.start_animation(from, item)
                                    // lock cell

                                    if (game_core.move_0(game_core.opponent_from(), game_core.opponent_to()))
                                        anim_1.start_animation_1(repeater.itemAt(game_core.opponent_from()),
                                                                 repeater.itemAt(game_core.opponent_to()));

                                    from = null
                                }
                                else
                                    refresh_model()
                            }
                            else    // moving to same cell as opponent
                            {
                                if (from._index !== game_core.opponent_to())
                                {
                                    if (game_core.move_0(game_core.opponent_from(), game_core.opponent_to()))
                                    {
                                        anim_1.start_animation_1(repeater.itemAt(game_core.opponent_from()),
                                                                 repeater.itemAt(game_core.opponent_to()));
                                        if (game_core.move_(from._index, item._index))
                                        {
                                            item.scale = 1
                                            anim.start_animation(from, item)
                                        }

                                        from = null
                                    }
                                    else
                                        refresh_model()
                                }
                                else
                                {
                                    // moving it the same time
                                    anim_1.start_animation_1(repeater.itemAt(game_core.opponent_from()),
                                                             repeater.itemAt(game_core.opponent_to()));
                                    item.scale = 1
                                    anim.start_animation(from, item)

                                    game_core.swapCell(game_core.opponent_from(), game_core.opponent_to())
                                    needRefresh = 1;
                                }
                            }
                        }
                        else  // click on cell that isnt available for you
                        {
                            from.scale = 1
                            from = null;

                        }
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
                            color: "transparent"

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

//            Image {
//                id: alph_down
//                source: "qrc:/visualsources/horizontal_alph.png"
//                anchors.top: gameItem.bottom
//                anchors.topMargin: 2
//                anchors.horizontalCenter: gameRect.horizontalCenter
//                width: gameRect.width - 70
//                fillMode: Image.PreserveAspectFit
//            }
        }
    }
}


























