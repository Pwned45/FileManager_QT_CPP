#ifndef FILEMANAGERMODEL_H
#define FILEMANAGERMODEL_H

#include <QDir>
#include <QModelIndex>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>
#include <QStorageInfo>
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
    Q_INVOKABLE QString getRootPath();
    Q_INVOKABLE void setRootPath(QString rootPath);
    Q_INVOKABLE void switchDir(int index);

    Q_INVOKABLE QString getRootPathUSB1() ;
    Q_INVOKABLE void setRootPathUSB1( QString newRootPathUSB1);

    Q_INVOKABLE QString getRootPathUSB2();
    Q_INVOKABLE void setRootPathUSB2( QString newRootPathUSB2);

    Q_INVOKABLE QString getRootPathHome();
    Q_INVOKABLE void setRootPathHome( QString newRootPathHome);


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

    const QString getChoosenButtonRootPath() ;
    void setChoosenButtonRootPath( QString newChoosenButtonRootPath);

    Q_INVOKABLE int getVisibleButtonUSB1() const;

    Q_INVOKABLE int getVisibleButtonUSB2() const;
    void setVisibleButtonUSB2(int newVisibleButtonUSB2);

    void setVisibleButtonUSB1(int newVisibleButtonUSB1);

    Q_INVOKABLE QString getbyIdFromRoots(int index);
    Q_INVOKABLE void addToRoots(QString item);
    Q_INVOKABLE void removeFromRoots(int index);

    Q_INVOKABLE QString getPathByIdFromButtons(int index);
    Q_INVOKABLE QString getNameByIdFromButtons(int index);
    Q_INVOKABLE void addToButtons(QString path,QString name);
    Q_INVOKABLE void addToButtons(QString path,QString name,int stage, bool ismarked);
    Q_INVOKABLE void removeFromButtons(int index);

signals:
    void aDirListChanged();
    void sendCurrMarkedToQML(QString currmarked);
    void sendCurrMarkedInfoToQML(QString currmarked);
    void changeRootPath();

public slots:


private:
    QFileInfoList *m_DirList;
    QString m_rootPath;
    QString m_rootPathUSB1;
    QString m_rootPathUSB2;
    QString m_rootPathHome;
    QList<FileManagerButton*> m_buttons;
    QStringList * m_roots = new QStringList();
    QString m_currMarked;
    QString m_enterDirCurrMarked;
    QString m_choosenButtonRootPath;
    int m_visibleButtonUSB1;
    int m_visibleButtonUSB2;

    QString fileSize (qint64 nSize) const;
    qint64 listFolder ( QString path ) const;


    // QAbstractItemModel interface

    // QAbstractItemModel interface

};

#endif // FILEMANAGERMODEL_H
