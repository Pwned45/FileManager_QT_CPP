#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "filemanagermodel.h"

#include <QFileInfoList>
#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_listView_2_doubleClicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_homeButton_clicked();

    void on_homeButton_2_clicked();

private:
    Ui::MainWindow *ui;

    QString rootHome = "C:/Users/Daniil/Documents";
    QString rootHome_2 = "C:/Users/Daniil/Documents";

    QFileInfoList *aDirList;

    FileManagerModel *model;

    QFileInfoList *aDirList2;

    FileManagerModel *model2;
};
#endif // MAINWINDOW_H
