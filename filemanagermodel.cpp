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
        emit aDirListChanged();
    } else{
        if (folderPath > rootPath) {
        *dirList = dir.entryInfoList(QDir::NoDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->aDirList = dirList;
        this->endResetModel();
        emit aDirListChanged();
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

void FileManagerModel::switchDir(const QModelIndex &index)
{
    if (this->aDirList->at(index.row()).isDir())
    {
        QString tmp = this->aDirList->at(index.row()).absoluteFilePath();
        this->getFolderList(this->aDirList->at(index.row()).absoluteFilePath(),this->aDirList);
        emit aDirListChanged();
        //this->ui->lineEdit->setText(parseRootAndURL(this->getRootPath(),tmp));
    } else {
        QDesktopServices::openUrl(QUrl(this->aDirList->at(index.row()).absoluteFilePath()));
        emit aDirListChanged();
    }

}

QFileInfoList *FileManagerModel::getADirList() const
{
    return aDirList;

}

void FileManagerModel::setADirList(QFileInfoList *newADirList)
{
    this->aDirList = newADirList;
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
QString FileManagerModel::parseRootAndURL(QString root, QString str)
{

    QStringList list = str.split(root);
    if(list.at(1).indexOf('/')==0){
        return list.at(1).right(list.at(1).size()-1);
    }
    return list.at(1);
}

