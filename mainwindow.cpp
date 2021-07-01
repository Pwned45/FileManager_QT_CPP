#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->aDirList = new QFileInfoList();
    this->aDirList2 = new QFileInfoList();

    this->model = new FileManagerModel(nullptr,rootHome);
    this->model->getFolderList(rootHome,this->aDirList);

    this->model2 = new FileManagerModel(nullptr,rootHome_2);
    this->model2->getFolderList(rootHome_2,this->aDirList2);

    this->ui->listView->setModel(model);
    this->ui->listView_2->setModel(model2);
    this->ui->lineEdit->setText(rootHome);
    this->ui->lineEdit_2->setText(rootHome_2);
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_listView_2_doubleClicked(const QModelIndex &index)
{
    if (this->aDirList2->at(index.row()).isDir())
        {
            QString tmp = this->aDirList2->at(index.row()).absoluteFilePath();
            model2->getFolderList(this->aDirList2->at(index.row()).absoluteFilePath(),this->aDirList2);
            this->ui->lineEdit_2->setText(tmp);
        } else {
            QDesktopServices::openUrl(QUrl(this->aDirList2->at(index.row()).absoluteFilePath()));
        }
}


void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    if (this->aDirList->at(index.row()).isDir())
        {
            QString tmp = this->aDirList->at(index.row()).absoluteFilePath();
            model->getFolderList(this->aDirList->at(index.row()).absoluteFilePath(),this->aDirList);
            this->ui->lineEdit->setText(tmp);
        } else {
            QDesktopServices::openUrl(QUrl(this->aDirList->at(index.row()).absoluteFilePath()));
        }
}



void MainWindow::on_homeButton_clicked()
{
    this->model->getFolderList(rootHome,this->aDirList);
    this->ui->lineEdit->setText(rootHome);
}


void MainWindow::on_homeButton_2_clicked()
{
    this->model2->getFolderList(rootHome_2,this->aDirList2);
    this->ui->lineEdit_2->setText(rootHome_2);
}

