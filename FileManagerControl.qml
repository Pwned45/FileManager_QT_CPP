import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    RowLayout{

        Button{
            id: buttonHome
            text: "home"
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathHome())
                //rectest.text = filesModel.getRootPath()
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
            }
        }
        Button{
            id: buttonUsb1
            text: "usb1"
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathUSB1())
                //rectest.text = filesModel.getRootPath()
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
            }
        }
        Button{
            id: buttonUsb2
            text: "usb2"
            onClicked: {
                filesModel.setRootPath(filesModel.getRootPathUSB2())
                //rectest.text = filesModel.getRootPath()
                filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
            }
        }

    }
}
