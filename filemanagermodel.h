#ifndef FILEMANAGERMODEL_H
#define FILEMANAGERMODEL_H

#include <QDir>
#include <QModelIndex>
#include <QPixmap>

class FileManagerModel : public QAbstractListModel
{
public:
    FileManagerModel(QObject *parent=nullptr,QString rootPath = nullptr);
    int rowCount(const QModelIndex &) const;
    QVariant data(const QModelIndex &index, int role) const;
    void getFolderList(QString folderPath, QFileInfoList *dirList);

private:
    QFileInfoList *aDirList;
    QString rootPath;
};

#endif // FILEMANAGERMODEL_H
