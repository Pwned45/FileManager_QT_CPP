import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    RowLayout{
        Connections{
            target: filesModel
            function onSendCurrMarkedToQML(currmarked){
                labelCurrMarked.text = currmarked
                console.log("got change")
            }
        }
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right

//        ListView {
//            id: listView1
//            anchors.top: row.bottom
//            anchors.bottom: parent.bottom
//            anchors.left: parent.left
//            anchors.right: parent.right
//            spacing: 3
//            model:controlModel
//            Flickable {
//                anchors.fill: parent
//                contentWidth: row.width
//                Row {
//                    id: row
//                    height: parent.height
//                    Repeater {

//                        delegate: Rectangle {
//                            id: theDelegate
//                            height: 45
//                            width: 45
//                            radius: 5
//                            // В данном элементе будет находиться одна кнопка
//                            Button {
//                                anchors.margins: 3
//                                anchors.fill: parent
//                                background: Rectangle {
//                                    implicitWidth: 40
//                                    implicitHeight: 40
//                                    color:filesModel.getRootPath() === filesModel.getRootPathHome()? "#ff00ffff" : "#bde0ff"
//                                    radius: 5
//                                }
//                                onClicked: {
//                                    textIndex.text = index
//                                }
//                                Text {
//                                    anchors.centerIn: parent
//                                    renderType: Text.NativeRendering
//                                    text: model.name
//                                }
//                            }
//                        }
//                    }

//                }
//            }
//        }

//        Button{
//            id: buttonHome
//            text: "home"
//            background: Rectangle {
//                id: homebg
//                implicitWidth: 40
//                implicitHeight: 40
//                color:filesModel.getRootPath() === filesModel.getRootPathHome()? "#ff00ffff" : "#bde0ff"
//                radius: 5
//            }
//            onClicked: {
//                filesModel.setRootPath(filesModel.getRootPathHome())
//                filesModel.getFolderList(filesModel.getRootPath())
//                filesModel.getRootPath() === filesModel.getRootPathHome()? homebg.color="#ff00ffff" : homebg.color="#bde0ff"
//                filesModel.getRootPath() === filesModel.getRootPathUSB1()? usb1bg.color="#ff00ffff" : usb1bg.color="#bde0ff"
//                filesModel.getRootPath() === filesModel.getRootPathUSB2()? usb2bg.color="#ff00ffff" : usb2bg.color="#bde0ff"
//            }
//        }
//        Button{
//            id: buttonUsb1
//            text: "usb1"
//            visible: filesModel.getVisibleButtonUSB1() === 1? true :false
//            background: Rectangle {
//                id: usb1bg
//                implicitWidth: 40
//                implicitHeight: 40
//                color:filesModel.getRootPath() === filesModel.getRootPathUSB1()? "#ff00ffff" : "#bde0ff"
//                radius: 5
//            }

//            onClicked: {
//                filesModel.setRootPath(filesModel.getRootPathUSB1())
//                filesModel.getFolderList(filesModel.getRootPath())
//                filesModel.getRootPath() === filesModel.getRootPathHome()? homebg.color="#ff00ffff" : homebg.color="#bde0ff"
//                filesModel.getRootPath() === filesModel.getRootPathUSB1()? usb1bg.color="#ff00ffff" : usb1bg.color="#bde0ff"
//                filesModel.getRootPath() === filesModel.getRootPathUSB2()? usb2bg.color="#ff00ffff" : usb2bg.color="#bde0ff"
//            }

//        }
//        Button{
//            id: buttonUsb2
//            text: "usb2"
//            visible: filesModel.getVisibleButtonUSB2() === 1? true :false
//            background: Rectangle {
//                id: usb2bg
//                implicitWidth: 40
//                implicitHeight: 40
//                color:filesModel.getRootPath() === filesModel.getRootPathUSB2()? "#ff00ffff" : "#bde0ff"
//                radius: 5
//            }
//            onClicked: {
//                filesModel.setRootPath(filesModel.getRootPathUSB2())
//                filesModel.getFolderList(filesModel.getRootPath())
//                filesModel.getRootPath() === filesModel.getRootPathHome()? homebg.color="#ff00ffff" : homebg.color="#bde0ff"
//                filesModel.getRootPath() === filesModel.getRootPathUSB1()? usb1bg.color="#ff00ffff" : usb1bg.color="#bde0ff"
//                filesModel.getRootPath() === filesModel.getRootPathUSB2()? usb2bg.color="#ff00ffff" : usb2bg.color="#bde0ff"
//            }
//        }
        ListView {
            id: filesView
            width: 400
            height: 80
            clip: true

            currentIndex: -1

            model: controlModel
            spacing: 3

            delegate: Rectangle {
                height: 40
                width: 40

                radius: 5

                color: model.marked ?"#8000ffff":"transparent"

                border {
                    width: 2
                    color: filesView.currentIndex == index?"#ff00ffff":"#20000000"
                }

                RowLayout {
                    id: theDelegate

                    Text {
                        Layout.fillWidth: true
                        Layout.fillHeight: true

                        font {
                            pixelSize: 22
                        }

                        elide: Text.ElideRight

                        color: "red"

                        text: model.name
                    }
                }

                MouseArea {
                    id: mousearea
                    anchors.fill: parent

                    onClicked: {
                        filesModel.setRootPath(model.path)
                        filesModel.getFolderList(filesModel.getRootPath())
                        controlModel.switchMarkedOfIndex(index)
                    }
                }
            }
            Label{
                id: labelCurrMarked
                text:filesModel.getCurrMarked()
            }
        }
    }
}
