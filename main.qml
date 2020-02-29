import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.12

Window {
    id: mainWindow
    visible: true
    width: 540
    height: 960
    Item {
        id: bar
        x: 0
        y: 0
        width: mainWindow.width
        height: mainWindow.height / 30
        clip: true
        Rectangle{
            anchors.fill: parent
            color: "#323643"
        }

    }

    StackView {
        id: stack
        anchors.fill: parent
       // initialItem: mainView
    }

}


