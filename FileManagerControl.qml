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

        Button{
            id: buttonHome
            text: "home"
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathHome())
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
            }
        }
        Button{
            id: buttonUsb1
            text: "usb1"
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathUSB1())
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
            }
        }
        Button{
            id: buttonUsb2
            text: "usb2"
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathUSB2())
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
            }
        }
       Label{
           id: labelCurrMarked
           text:filesModel.getCurrMarked()
       }

    }
}
