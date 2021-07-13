#ifndef FILEMANAGERMODEL_H
#define FILEMANAGERMODEL_H

#include <QDir>
#include <QModelIndex>
#include <QPixmap>
#include <QDesktopServices>
#include <QUrl>

class FileManagerModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QFileInfoList * aDirList READ getADirList WRITE setADirList NOTIFY aDirListChanged)
    //Q_PROPERTY(QString rootPath READ rootPath WRITE setRootPath NOTIFY rootPathChanged)
    //Q_PROPERTY(QFileInfoList * aDirList READ aDirList WRITE setADirList NOTIFY aDirListChanged)

public:

    FileManagerModel(QObject *parent=nullptr,QString rootPath = nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    Q_INVOKABLE void getFolderList(QString folderPath, QFileInfoList *dirList);
    Q_INVOKABLE QString getRootPath();
    Q_INVOKABLE void setRootPath(QString rootPath);
    Q_INVOKABLE void switchDir(const QModelIndex &index);

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
    //const QString &rootPath() const;

    //QFileInfoList *aDirList() const;



signals:
    void aDirListChanged();

    //void rootPathChanged();

public slots:


private:
    QFileInfoList *aDirList;
    QString rootPath;
    QString rootPathUSB1;
    QString rootPathUSB2;
    QString rootPathHome;


    // QAbstractItemModel interface

    // QAbstractItemModel interface


    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) ;

};

#endif // FILEMANAGERMODEL_H
