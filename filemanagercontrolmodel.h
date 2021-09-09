#ifndef FILEMANAGERCONTROLMODEL_H
#define FILEMANAGERCONTROLMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include "filemanagerbutton.h"

class FileManagerControlModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QList<FileManagerButton *> buttons READ getButtons WRITE setButtons NOTIFY buttonsChanged)
public:
    enum FileManagerControlModelRoles {
        FileManagerControlModelName = Qt::UserRole +1,
        FileManagerControlModelPath,
        FileManagerControlModelMarked,
        FileManagerControlModelStage
    };
    explicit FileManagerControlModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Q_INVOKABLE const QList<FileManagerButton *> getButtons() const;
    void setButtons(const QList<FileManagerButton *> newButtons);

    Q_INVOKABLE void addToButtons(QString path,QString name, int stage);

    Q_INVOKABLE void switchMarkedOfIndex(int index);

    Q_INVOKABLE void removeFromButtonsByIndex(int index);

    Q_INVOKABLE QString getRootPathFirstButton();

    QHash<int, QByteArray> roleNames() const;


signals:
    void buttonsChanged();

private:
    QList<FileManagerButton*> m_buttons;


};

#endif // FILEMANAGERCONTROLMODEL_H
