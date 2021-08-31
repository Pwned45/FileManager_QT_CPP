import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    RowLayout{
        Connections{
            target: filesModel
            function onSendCurrMarkedInfoToQML(currmarkedinfo){
                labelCurrMarked.text = currmarkedinfo
            }
        }
        Label{
            id: labelCurrMarked
            text:filesModel.getCurrMarkedInfo()
        }

    }
}
