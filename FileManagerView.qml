import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
//![0]

ListView {
    id: filesView
    width: 400
    height: 800
    clip: true

    currentIndex: -1

    model: filesModel
    spacing: 3

/*
    TextEdit{
        id:rectest
        text: "URL://....."
        //EditingFinished: rectest.text =filesModel.getRootPath()
    }
*/
    delegate: Rectangle {
        height: 80
        width: filesView.width

        radius: 5

        color: filesView.currentIndex == index?"#8000ffff":"transparent"

        border {
            width: 2
            color: filesView.currentIndex == index?"#ff00ffff":"#20000000"
        }

        RowLayout {
            id: theDelegate

            anchors {
                fill : parent
                margins: 5
            }

            Image {
                id: name

                Layout.fillWidth: false
                Layout.fillHeight: false
                Layout.preferredHeight: theDelegate.height
                Layout.preferredWidth: theDelegate.height

                source: model.decoration
            }

            Text {
                Layout.fillWidth: true
                Layout.fillHeight: true

                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter

                font {
                    pixelSize: 22
                }

                elide: Text.ElideRight

                color: "red"

                text: model.display
            }
        }

        MouseArea {
            id: mousearea
            anchors.fill: parent

            onPressed: {
                if (filesView.currentIndex == index) {
                    filesView.currentIndex = -1
                    filesModel.setCurrMarked(filesModel.getEnterDirCurrMarked())
                }
                else {
                    filesView.currentIndex = index
                    filesModel.setCurrMarked(index)
                }

            }
            onDoubleClicked: {
                filesModel.switchDir(index)
            }
        }
    }
}

//![0]
