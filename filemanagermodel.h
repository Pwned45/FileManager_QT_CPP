#ifndef FILEMANAGERMODEL_H
#define FILEMANAGERMODEL_H

#include <QDir>
#include <QModelIndex>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QStorageInfo>
#include <QDate>
#include "filemanagerbutton.h"

class FileManagerModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QFileInfoList * m_DirList READ getADirList WRITE setADirList NOTIFY aDirListChanged)

public:
    enum FileManagerModelRoles {
        FileManagerModelIconName = Qt::UserRole +1,
        FileManagerModelFileName
    };

    FileManagerModel(QObject *parent=nullptr,QString rootPath = nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE void getFolderList(QString folderPath, QFileInfoList *dirList);
    Q_INVOKABLE void getFolderList(QString folderPath);

    Q_INVOKABLE QString getRootPath();
    Q_INVOKABLE void setRootPath(QString rootPath);
    Q_INVOKABLE void switchDir(int index);


    Q_INVOKABLE QFileInfoList *getADirList() const;
    void setADirList(QFileInfoList *newADirList);

    QString parseRootAndURL(QString root, QString str);
    QString makeURLfromRootAndNewURL(QString root, QString str);

    Q_INVOKABLE const QString getCurrMarked() const;
    Q_INVOKABLE const QString getCurrMarkedInfo() const;
    Q_INVOKABLE void setCurrMarked( QString newCurrMarket);
    Q_INVOKABLE void setCurrMarked(int index);

    Q_INVOKABLE const QString getEnterDirCurrMarked() const;
    void setEnterDirCurrMarked( QString newEnterDirCurrMarked);

signals:
    void aDirListChanged();
    void sendCurrMarkedToQML(QString currmarked);
    void sendCurrMarkedInfoToQML(QString currmarkedinfo);
    void changeRootPath();

public slots:


private:
    QFileInfoList *m_DirList;
    QString m_rootPath;
    QString m_currMarked;
    QString m_enterDirCurrMarked;

    QString fileSize (qint64 nSize) const;


    // QAbstractItemModel interface

    // QAbstractItemModel interface

};

#endif // FILEMANAGERMODEL_H
