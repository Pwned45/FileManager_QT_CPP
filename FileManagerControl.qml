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
            function onChangeRootPath(){

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
