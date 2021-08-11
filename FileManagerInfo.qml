import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ColumnLayout {
    RowLayout{
        Connections{
            target: filesModel
            function onSendCurrMarkedInfoToQML(currmarked){
                labelCurrMarked.text = currmarked
            }
        }
        Label{
            id: labelCurrMarked
            text:filesModel.getCurrMarkedInfo()
        }

    }
}
