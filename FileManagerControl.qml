import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    RowLayout{
        Connections{
            target: filesModel
            function onSendCurrMarkedToQML(currmarked){
                labelCurrMarked.text = currmarked
            }
        }
        height: 50
        anchors.top: parent.top
        anchors.left: parent.left
        anchors.right: parent.right


        // ListView для представления данных в виде списка
//        ListView {
//            id: listView1
//            // Размещаем его в оставшейся части окна приложения
//            anchors.top: row.bottom
//            anchors.bottom: parent.bottom
//            anchors.left: parent.left
//            anchors.right: parent.right
//            spacing: 3
//            /* в данном свойстве задаём вёрстку одного объекта
//                 * который будем отображать в списке в качестве одного элемента списка
//                 * */
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
//                                /* самое интересное в данном объекте
//                         * задаём свойству text переменную, по имени которой будем задавать
//                         * свойства элемента
//                         * */

//                                // По клику по кнопке отдаём в текстовое поле индекс элемента в ListView
//                                onClicked: {
//                                    textIndex.text = index
//                                    filesModel.setRootPath(filesModel.getbyIdFromRoots(index))
//                                    filesModel.getFolderList(filesModel.getbyIdFromRoots(index),filesModel.getADirList())
//                                }
//                                Text {
//                                    anchors.centerIn: parent
//                                    renderType: Text.NativeRendering
//                                    text: idshnik
//                                }
//                            }
//                        }
//                        // Сама модель, в которой будут содержаться все элементы
//                        model: ListModel {
//                            id: listModel // задаём ей id для обращения
//                        }
//                    }

//                }
//            }
//        }
        ListView {
            id: listView1
            // Размещаем его в оставшейся части окна приложения
            anchors.top: row.bottom
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.right: parent.right
            spacing: 3
            model:controlmodel
            /* в данном свойстве задаём вёрстку одного объекта
                 * который будем отображать в списке в качестве одного элемента списка
                 * */
            Flickable {
                anchors.fill: parent
                contentWidth: row.width
                Row {
                    id: row

                    height: parent.height

                    Repeater {

                        delegate: Rectangle {
                            id: theDelegate
                            height: 45
                            width: 45
                            radius: 5
                            // В данном элементе будет находиться одна кнопка
                            Button {
                                anchors.margins: 3
                                anchors.fill: parent
                                background: Rectangle {
                                    implicitWidth: 40
                                    implicitHeight: 40
                                    color:filesModel.getRootPath() === filesModel.getRootPathHome()? "#ff00ffff" : "#bde0ff"
                                    radius: 5
                                }
                                onClicked: {
                                    textIndex.text = index
                                }
                                Text {
                                    anchors.centerIn: parent
                                    renderType: Text.NativeRendering
                                    text: model.name
                                }
                            }
                        }
                    }

                }
            }
        }

        Button{
            id: buttonHome
            text: "home"
            background: Rectangle {
                id: homebg
                implicitWidth: 40
                implicitHeight: 40
                color:filesModel.getRootPath() === filesModel.getRootPathHome()? "#ff00ffff" : "#bde0ff"
                radius: 5
            }
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathHome())
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
                filesModel.getRootPath() === filesModel.getRootPathHome()? homebg.color="#ff00ffff" : homebg.color="#bde0ff"
                filesModel.getRootPath() === filesModel.getRootPathUSB1()? usb1bg.color="#ff00ffff" : usb1bg.color="#bde0ff"
                filesModel.getRootPath() === filesModel.getRootPathUSB2()? usb2bg.color="#ff00ffff" : usb2bg.color="#bde0ff"
            }
        }
        Button{
            id: buttonUsb1
            text: "usb1"
            visible: filesModel.getVisibleButtonUSB1() === 1? true :false
            background: Rectangle {
                id: usb1bg
                implicitWidth: 40
                implicitHeight: 40
                color:filesModel.getRootPath() === filesModel.getRootPathUSB1()? "#ff00ffff" : "#bde0ff"
                radius: 5
            }

            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathUSB1())
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
                filesModel.getRootPath() === filesModel.getRootPathHome()? homebg.color="#ff00ffff" : homebg.color="#bde0ff"
                filesModel.getRootPath() === filesModel.getRootPathUSB1()? usb1bg.color="#ff00ffff" : usb1bg.color="#bde0ff"
                filesModel.getRootPath() === filesModel.getRootPathUSB2()? usb2bg.color="#ff00ffff" : usb2bg.color="#bde0ff"
            }

        }
        Button{
            id: buttonUsb2
            text: "usb2"
            visible: filesModel.getVisibleButtonUSB2() === 1? true :false
            background: Rectangle {
                id: usb2bg
                implicitWidth: 40
                implicitHeight: 40
                color:filesModel.getRootPath() === filesModel.getRootPathUSB2()? "#ff00ffff" : "#bde0ff"
                radius: 5
            }
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathUSB2())
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
                filesModel.getRootPath() === filesModel.getRootPathHome()? homebg.color="#ff00ffff" : homebg.color="#bde0ff"
                filesModel.getRootPath() === filesModel.getRootPathUSB1()? usb1bg.color="#ff00ffff" : usb1bg.color="#bde0ff"
                filesModel.getRootPath() === filesModel.getRootPathUSB2()? usb2bg.color="#ff00ffff" : usb2bg.color="#bde0ff"
            }
        }
        Label{
            id: labelCurrMarked
            text:filesModel.getCurrMarked()
        }

    }
}
