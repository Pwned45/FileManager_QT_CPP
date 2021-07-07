#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QTime>
#include <QDir>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->aDirList = new QFileInfoList();
    this->aDirList2 = new QFileInfoList();

    this->model = new FileManagerModel(nullptr,rootHome);
    this->model->getFolderList(rootHome,this->aDirList);
    this->model->setRootPath(rootHome);

    this->model2 = new FileManagerModel(nullptr,rootHome);
    this->model2->getFolderList(rootHome,this->aDirList2);
    this->model2->setRootPath(rootHome);

    this->ui->listView->setModel(model);
    this->ui->listView_2->setModel(model2);
    this->ui->lineEdit->setText("");
    this->ui->lineEdit_2->setText("");

    QTimer *timer = new QTimer(this);
        connect(timer, SIGNAL(timeout()), this, SLOT(timerCheckDisks()));
        timer->start(5000);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setRootHome(QString newRoot)
{
    this->rootHome = newRoot;
}

QString MainWindow::getRootHome()
{
    return this->rootHome;
}

void MainWindow::setRootUsb1(QString newRoot)
{
    this->rootUsb1 = newRoot;
}

QString MainWindow::getRootUsb1()
{
    return this->rootUsb1;
}

void MainWindow::setRootUsb2(QString newRoot)
{
    this->rootUsb2 = newRoot;
}

QString MainWindow::getRootUsb2()
{
    return this->rootUsb2;
}


void MainWindow::on_listView_2_doubleClicked(const QModelIndex &index)
{
    if (this->aDirList2->at(index.row()).isDir())
        {
            QString tmp = this->aDirList2->at(index.row()).absoluteFilePath();
            model2->getFolderList(this->aDirList2->at(index.row()).absoluteFilePath(),this->aDirList2);
            this->ui->lineEdit_2->setText(parseRootAndURL(model2->getRootPath(),tmp));
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
            this->ui->lineEdit->setText(parseRootAndURL(model->getRootPath(),tmp));
        } else {
            QDesktopServices::openUrl(QUrl(this->aDirList->at(index.row()).absoluteFilePath()));
        }
}



void MainWindow::on_homeButton_clicked()
{
    this->model->setRootPath(rootHome);
    this->model->getFolderList(rootHome,this->aDirList);
    this->ui->lineEdit->setText("");
}


void MainWindow::on_homeButton_2_clicked()
{
    this->model2->setRootPath(rootHome);
    this->model2->getFolderList(rootHome,this->aDirList2);
    this->ui->lineEdit_2->setText("");
}

void MainWindow::timerCheckDisks()
{
    QDir dir;
    dir.Dirs;

}


void MainWindow::on_usb1Button_1_clicked()
{
    this->model->setRootPath(rootUsb1);
    this->model->getFolderList(rootUsb1,this->aDirList);
    this->ui->lineEdit->setText("");
}


void MainWindow::on_usb2Button_1_clicked()
{
    this->model->setRootPath(rootUsb2);
    this->model->getFolderList(rootUsb2,this->aDirList);
    this->ui->lineEdit->setText("");
}


void MainWindow::on_usb1Button_2_clicked()
{
    this->model2->setRootPath(rootUsb1);
    this->model2->getFolderList(rootUsb1,this->aDirList2);
    this->ui->lineEdit_2->setText("");

}



void MainWindow::on_usb2Button_2_clicked()
{
    this->model2->setRootPath(rootUsb2);
    this->model2->getFolderList(rootUsb2,this->aDirList2);
    this->ui->lineEdit_2->setText("");
}



void MainWindow::on_lineEdit_editingFinished()
{
    QString new_url = this->ui->lineEdit->displayText();
    if (!this->model->getRootPath().endsWith("/")&& new_url.size()>0){
        new_url=this->model->getRootPath() +"/" + new_url;
    }else {
    new_url = this->model->getRootPath() + new_url;
    }
    this->model->getFolderList(new_url,this->aDirList);
}


void MainWindow::on_lineEdit_2_editingFinished()
{
    QString new_url = this->ui->lineEdit_2->displayText();
    if (!this->model2->getRootPath().endsWith("/") && new_url.size()>0){
        new_url=this->model2->getRootPath() +"/" + new_url;
    }else {
    new_url = this->model2->getRootPath() + new_url;
    }
    this->model2->getFolderList(new_url,this->aDirList2);
}

QString MainWindow::parseRootAndURL(QString root, QString str)
{

    QStringList list = str.split(root);
    if(list.at(1).indexOf('/')==0){
        return list.at(1).right(list.at(1).size()-1);
    }
    return list.at(1);
}

