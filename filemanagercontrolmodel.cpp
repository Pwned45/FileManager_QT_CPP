#include "filemanagercontrolmodel.h"

FileManagerControlModel::FileManagerControlModel(QObject *parent) : QAbstractListModel(parent)
{

}

int FileManagerControlModel::rowCount(const QModelIndex &parent) const
{
    return this->m_buttons.size();
}

QVariant FileManagerControlModel::data(const QModelIndex &index, int role) const
{
    QVariant value;
    if (index.row()<0 || index.row()>=m_buttons.size()){
        return QVariant();
    }
            switch ( role )
            {
                case FileManagerControlModelRoles::FileManagerControlModelName: //string
                {
                    value = this->m_buttons.at(index.row())->getName();
                }
                break;
                case FileManagerControlModelRoles::FileManagerControlModelPath: //string
                {
                    value = this->m_buttons.at(index.row())->getPath();
                }
                break;
                case FileManagerControlModelRoles::FileManagerControlModelStage: //int
                {
                   value = this->m_buttons.at(index.row())->getStage();
                }
                break;
                case FileManagerControlModelRoles::FileManagerControlModelMarked: //bool
                {
                   value = this->m_buttons.at(index.row())->getMarked();
                }
                default:
                    break;
            }

            return value;
}

const QList<FileManagerButton *> FileManagerControlModel::getButtons() const
{
    return this->m_buttons;
}

void FileManagerControlModel::setButtons(const QList<FileManagerButton *> newButtons)
{
    this->m_buttons = newButtons;
    emit buttonsChanged();
}

void FileManagerControlModel::addToButtons(QString path, QString name, int stage)
{
    this->m_buttons.append(new FileManagerButton(path,name,stage,false));
}

void FileManagerControlModel::switchMarkedOfIndex(int index)
{
    QList<FileManagerButton*> buttons = m_buttons;
    for (int i = 0 ; i<buttons.size();i++){
        if (buttons.at(i)->getMarked() && i!= index){
            buttons.at(i)->setMarked(false);
        }
    }
    if(!buttons.at(index)->getMarked()){
        buttons.at(index)->setMarked(true);
    }
    this->beginResetModel();
    this->m_buttons = buttons;
    this->endResetModel();
}

QHash<int, QByteArray> FileManagerControlModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[FileManagerControlModelName] = "name";
    roles[FileManagerControlModelPath] = "path";
    roles[FileManagerControlModelMarked] = "marked";
    roles[FileManagerControlModelStage] = "stage";
    return roles;
}


