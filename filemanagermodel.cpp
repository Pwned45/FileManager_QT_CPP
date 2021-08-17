#include "filemanagermodel.h"


FileManagerModel::FileManagerModel(QObject *parent, QString rootPath):QAbstractListModel(parent)
{
    this->m_rootPath = rootPath;
    this->m_currMarked = rootPath;
    emit sendCurrMarkedToQML(m_currMarked);
    this->m_enterDirCurrMarked = rootPath;

}

void FileManagerModel::getFolderList(QString folderPath, QFileInfoList *dirList)
{
    QDir dir = QDir(folderPath);


    if (folderPath == m_rootPath || (m_rootPath +"/")==folderPath) //some root path
    {
        *dirList = dir.entryInfoList(QDir::NoDotAndDotDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->m_DirList = dirList;
        this->m_enterDirCurrMarked = folderPath;
        this->m_currMarked = folderPath;
        emit sendCurrMarkedToQML(m_currMarked);
        this->endResetModel();

    } else{
        if (folderPath > m_rootPath) {
        *dirList = dir.entryInfoList(QDir::NoDot | QDir::Files | QDir::Dirs, QDir::DirsFirst);
        this->beginResetModel();
        this->m_DirList = dirList;
        this->m_enterDirCurrMarked = folderPath;
        this->m_currMarked = folderPath;
        emit sendCurrMarkedToQML(m_currMarked);
        this->endResetModel();
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
    emit changeRootPath();
    this->m_currMarked = rootPath;
    emit sendCurrMarkedInfoToQML(getCurrMarkedInfo());
}

void FileManagerModel::switchDir(int index)
{
    if (this->m_DirList->at(index).isSymLink()){
        return;
    }
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

const QString FileManagerModel::getCurrMarked() const
{
    return m_currMarked;
}

const QString FileManagerModel::getCurrMarkedInfo() const
{
    QString str = "";
    if (QFile(m_currMarked).exists()){
        if(QFileInfo(m_currMarked).isDir()){
            str += QFileInfo(m_currMarked).lastModified().toString()
                    +" "+ fileSize(QStorageInfo(m_rootPath).bytesAvailable())
                    +"/"+ fileSize(QStorageInfo(m_rootPath).bytesTotal());
            return str;
        }else {
            str += QFileInfo(m_currMarked).lastModified().toString()
                    +" "+ fileSize(QFileInfo(m_currMarked).size())
                    +" "+ fileSize(QStorageInfo(m_rootPath).bytesAvailable())
                    +"/"+ fileSize(QStorageInfo(m_rootPath).bytesTotal());
            return str;
        }

    }else {
        return str = "catalog does not exists";
    }
}
QString FileManagerModel::fileSize(qint64 nSize) const
{
    qint64 i = 0;
    for (; nSize > 1023; nSize /= 1024, ++i) {
        if(i >= 4) {
        break;
        }
    }
    return QString().setNum(nSize) + "BKMGT"[i];
}

void FileManagerModel::setCurrMarked(QString newCurrMarked)
{
    m_currMarked = newCurrMarked;
    emit sendCurrMarkedToQML(m_currMarked);
    emit sendCurrMarkedInfoToQML(getCurrMarkedInfo());
}

void FileManagerModel::setCurrMarked(int index)
{
    m_currMarked = this->m_DirList->at(index).absoluteFilePath();
    emit sendCurrMarkedToQML(m_currMarked);
    emit sendCurrMarkedInfoToQML(getCurrMarkedInfo());
}

const QString FileManagerModel::getEnterDirCurrMarked() const
{
    return m_enterDirCurrMarked;
}

void FileManagerModel::setEnterDirCurrMarked(QString newEnterDirCurrMarked)
{
    m_enterDirCurrMarked = newEnterDirCurrMarked;
}

const QString FileManagerModel::getChoosenButtonRootPath()
{
    return m_choosenButtonRootPath;
}

void FileManagerModel::setChoosenButtonRootPath(QString newChoosenButtonRootPath)
{
    m_choosenButtonRootPath = newChoosenButtonRootPath;
}

int FileManagerModel::getVisibleButtonUSB1() const
{
    return m_visibleButtonUSB1;
}

int FileManagerModel::getVisibleButtonUSB2() const
{
    return m_visibleButtonUSB2;
}

void FileManagerModel::setVisibleButtonUSB2(int newVisibleButtonUSB2)
{
    m_visibleButtonUSB2 = newVisibleButtonUSB2;
}

void FileManagerModel::setVisibleButtonUSB1(int newVisibleButtonUSB1)
{
    m_visibleButtonUSB1 = newVisibleButtonUSB1;
}

QString FileManagerModel::getbyIdFromRoots(int index)
{
    return m_roots->at(index);

}

void FileManagerModel::addToRoots(QString item)
{
    m_roots->append(item);
}

void FileManagerModel::removeFromRoots(int index)
{
    m_roots->removeAt(index);
}

QString FileManagerModel::getPathByIdFromButtons(int index)
{
    return m_buttons.at(index)->getPath();
}

QString FileManagerModel::getNameByIdFromButtons(int index)
{
    return m_buttons.at(index)->getName();
}

void FileManagerModel::addToButtons(QString path, QString name)
{
    m_buttons.append(new FileManagerButton(path,name));

}

void FileManagerModel::addToButtons(QString path, QString name, int stage, bool ismarked)
{
    m_buttons.append(new FileManagerButton(path,name,stage,ismarked));
}

void FileManagerModel::removeFromButtons(int index)
{
    m_buttons.removeAt(index);

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
