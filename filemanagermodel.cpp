#include "filemanagermodel.h"


FileManagerModel::FileManagerModel(QObject *parent, QString rootPath):QAbstractListModel(parent)
{
    this->m_rootPath = rootPath;

}

void FileManagerModel::getFolderList(QString folderPath, QFileInfoList *dirList)
{
    QDir dir = QDir(folderPath);


    if (folderPath == m_rootPath || (m_rootPath +"/")==folderPath) //some root path
    {
        *dirList = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->m_DirList = dirList;
        this->endResetModel();
        emit aDirListChanged();
    } else{
        if (folderPath > m_rootPath) {
        *dirList = dir.entryInfoList(QDir::NoDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->m_DirList = dirList;
        this->endResetModel();
        emit aDirListChanged();
        }
    }
}

QString FileManagerModel::getRootPath()
{
    return this->m_rootPath;
}

void FileManagerModel::setRootPath(QString rootPath)
{
    this->m_rootPath = rootPath;
}

void FileManagerModel::switchDir(int index)
{
    if (this->m_DirList->at(index).isDir())
    {
        QString tmp = this->m_DirList->at(index).absoluteFilePath();
        this->getFolderList(this->m_DirList->at(index).absoluteFilePath(),this->m_DirList);
        emit aDirListChanged();
        //this->ui->lineEdit->setText(parseRootAndURL(this->getRootPath(),tmp));
    } else {
        QDesktopServices::openUrl(QUrl(this->m_DirList->at(index).absoluteFilePath()));
        emit aDirListChanged();
    }

}

QFileInfoList *FileManagerModel::getADirList() const
{
    return m_DirList;

}

void FileManagerModel::setADirList(QFileInfoList *newADirList)
{
    this->m_DirList = newADirList;
}



int FileManagerModel::rowCount(const QModelIndex &) const
{
    return this->m_DirList->count();
}

QVariant FileManagerModel::data( const QModelIndex &index, int role ) const
{

    QVariant value;
    if (index.row()<0 || index.row()>=m_DirList->size()){
        return QVariant();
    }

            switch ( role )
            {
                case Qt::DisplayRole: //string
                {
                    value = this->m_DirList->at(index.row()).fileName();
                }
                break;

                case Qt::DecorationRole: //icon
                {
                    if (this->m_DirList->at(index.row()).isDir()) {
                        value = QString("qrc:/img/folder.png");
                        break;
                    }

                    if (this->m_DirList->at(index.row()).isFile()) {
                        QString fileSuff = this->m_DirList->at(index.row()).completeSuffix();

                        if ( QFile::exists(":/img/" + fileSuff +".png") ) {
                           value = QString("qrc:/img/" + fileSuff +".png");
                        } else {
                            value = QString("qrc:/img/file.png");
                        }
                        break;
                    }

                    value = this->m_DirList->at(index.row()).fileName();
                }
                break;

                case Qt::UserRole: //data
                {
                    value = this->m_DirList->at(index.row()).fileName();
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

QString FileManagerModel::getRootPathUSB1()
{
    return m_rootPathUSB1;
}

void FileManagerModel::setRootPathUSB1(QString newRootPathUSB1)
{
    m_rootPathUSB1 = newRootPathUSB1;
}

QString FileManagerModel::getRootPathUSB2()
{
    return m_rootPathUSB2;
}


void FileManagerModel::setRootPathUSB2( QString newRootPathUSB2)
{
    m_rootPathUSB2 = newRootPathUSB2;
}

QString FileManagerModel::getRootPathHome()
{
    return m_rootPathHome;
}

void FileManagerModel::setRootPathHome(QString newRootPathHome)
{
    m_rootPathHome = newRootPathHome;
}
