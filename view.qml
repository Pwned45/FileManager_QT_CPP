/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
//![0]

ListView {
    id: filesView
    width: 400
    height: 800

    currentIndex: -1

    model: filesModel

    spacing: 3

    ColumnLayout {

    RowLayout {
        id:rowL
/*
    Button{
        id: buttonHome
        text: "home"
        onClicked: {
            //filesModel.setRootPath("C:/Users/Daniil/Documents")
            //filesModel.rootPath = "C:/Users/Daniil/Documents"
//            filesModel.dataChanged()
//            filesModel.data()
            filesModel.setRootPath(filesModel.getRootPathHome())
            rectest.text = filesModel.getRootPath()
            filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())

        }

    }
    Button{
        id: buttonUsb1
        text: "usb1"
        onClicked: {
            //filesModel.rootPath = "F:/"
            filesModel.setRootPath(filesModel.getRootPathUSB1())
            rectest.text = filesModel.getRootPath()
            filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
        }

    }

    Button{
        id: buttonUsb2
        text: "usb2"
        onClicked: {
            filesModel.setRootPath(filesModel.getRootPathUSB2())
            rectest.text = filesModel.getRootPath()
            filesModel.getFolderList(filesModel.getRootPath(),filesModel.getADirList())
        }

    }

    TextEdit{
        id:rectest
        text: "URL://....."
        //EditingFinished: rectest.text =filesModel.getRootPath()
    }
*/
    }
    }
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
                if (filesView.currentIndex == index)
                    filesView.currentIndex = -1
                else
                    filesView.currentIndex = index
            }


            //onDoubleClicked: console.log("MouseArea clicked" )
            onDoubleClicked: {
                //console.log("MouseArea clicked" + model.display)
                //filesModel.getFolderList(filesModel.getRootPath() +"/" + model.display,filesModel.getADirList())
                filesModel.switchDir(index)
            }
        }
    }
}
//![0]
