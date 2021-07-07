#include "filemanagermodel.h"


FileManagerModel::FileManagerModel(QObject *parent, QString rootPath):QAbstractListModel(parent)
{
    this->rootPath = rootPath;

}

void FileManagerModel::getFolderList(QString folderPath, QFileInfoList *dirList)
{
    QDir dir = QDir(folderPath);


    if (folderPath == rootPath || (rootPath +"/")==folderPath) //some root path
    {
        *dirList = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->aDirList = dirList;
        this->endResetModel();
    } else{
        if (folderPath > rootPath) {
        *dirList = dir.entryInfoList(QDir::NoDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->aDirList = dirList;
        this->endResetModel();
        }
    }
}

QString FileManagerModel::getRootPath()
{
    return this->rootPath;
}

void FileManagerModel::setRootPath(QString rootPath)
{
    this->rootPath = rootPath;
}

int FileManagerModel::rowCount(const QModelIndex &) const
{
    return this->aDirList->count();
}

QVariant FileManagerModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;

            switch ( role )
            {
                case Qt::DisplayRole: //string
                {
                    value = this->aDirList->at(index.row()).fileName();
                }
                break;

                case Qt::DecorationRole: //icon
                {
                    if (this->aDirList->at(index.row()).isDir()) {
                        QPixmap icon = QPixmap(":/img/folder.png");
                        QPixmap tmp = icon.scaled(30, 30, Qt::KeepAspectRatio);
                        value = tmp;
                        break;
                    }

                    if (this->aDirList->at(index.row()).isFile()) {
                        QPixmap icon = QPixmap(":/img/file.png");
                        QPixmap tmp = icon.scaled(30, 30, Qt::KeepAspectRatio);
                        value = tmp;
                        break;
                    }

                    value = this->aDirList->at(index.row()).fileName();
                }
                break;

                case Qt::UserRole: //data
                {
                    value = this->aDirList->at(index.row()).fileName();
                }
                break;

                default:
                    break;
            }

        return value;
}
