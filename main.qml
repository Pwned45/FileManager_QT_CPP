import QtQuick 2.0
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3

Window {
    visible: true
    width: 800
    height: 600

    ColumnLayout {
        anchors.fill: parent

        FileManagerControl {
            Layout.fillWidth: true
            Layout.fillHeight: false
            Layout.preferredHeight: 80
        }

        FileManagerView {
            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.preferredHeight: 40
        }
        FileManagerInfo {
            Layout.fillWidth: true
            Layout.fillHeight: false
            Layout.preferredHeight: 40
        }
    }
}
