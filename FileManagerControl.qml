import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
        Connections{
            target: filesModel
            function onSendCurrMarkedToQML(currmarked){
                labelCurrMarked.text = currmarked
                //console.log("Got change")
            }
        }
        anchors.fill : parent

        ListView {
            id: filesView
            width: 400
            height: 40
            clip: true

            currentIndex: -1

            model: controlModel
            spacing: 3
            orientation: ListView.Horizontal

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
                        if (filesModel.checkForEmptyRoot(model.path)) {
                            filesModel.setRootPath(controlModel.getRootPathFirstButton())
                            filesModel.getFolderList(filesModel.getRootPath())
                            controlModel.removeFromButtonsByIndex(index)
                            controlModel.switchMarkedOfIndex(0)

                        } else {
                            filesModel.setRootPath(model.path)
                            filesModel.getFolderList(filesModel.getRootPath())
                            controlModel.switchMarkedOfIndex(index)
                        }
                    }
                }
            }
        }
        Label{
            anchors.right: filesView
            id: labelCurrMarked
            text:filesModel.getCurrMarked()
        }
    }
