#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->myButton->setText("123");
    ui->labelText->setText("^_^");
//    ui->labelGraph->setPixmap(QPixmap("://image/lidar.jpg"));
//    ui->labelImage->setPixmap(QPixmap("://image/lidar.jpg"));
//    ui->labelGraph->setScaledContents(true);


}

MainWindow::~MainWindow()
{
    delete ui;
}

