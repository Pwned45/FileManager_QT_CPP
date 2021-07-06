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
    void setRootHome(QString newRoot);
    QString getRootHome();
    void setRootUsb1(QString newRoot);
    QString getRootUsb1();
    void setRootUsb2(QString newRoot);
    QString getRootUsb2();


private slots:
    void on_listView_2_doubleClicked(const QModelIndex &index);
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_homeButton_clicked();

    void on_homeButton_2_clicked();
    void timerCheckDisks();

    void on_usb1Button_1_clicked();

    void on_usb2Button_1_clicked();

    void on_usb1Button_2_clicked();

    void on_usb2Button_2_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;

    QString rootHome = "C:/Users/Daniil/Documents";
    QString rootUsb1 = "F:/";
    QString rootUsb2 = "G:/";

    QFileInfoList *aDirList;

    FileManagerModel *model;

    QFileInfoList *aDirList2;

    FileManagerModel *model2;
};
#endif // MAINWINDOW_H
