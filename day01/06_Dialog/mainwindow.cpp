#include "mainwindow.h"
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QDialog>
#include <QtDebug>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,500);
    QMenuBar *mBar = menuBar();
    QMenu *myMenu = mBar->addMenu("对话框");
    QAction *myAction = myMenu->addAction("模态对话框");
    QAction *myAction1 = myMenu->addAction("非模态对话框");

    //模态对话框
    connect(myAction,&QAction::triggered,
            []()
    {
        QDialog myDia;
        myDia.exec();
        qDebug()<<1111111;
    }
            );
    //非模态对话框
    connect(myAction1,&QAction::triggered,

            [=]()
    {
        //两种方式，第一种放在类的成员函数，第二种new一个QDialog并且不指定父对象以及关闭时清除堆内存
        myDialogNotModel.show();//第一种
        qDebug()<<111111;

//        QDialog *p = new QDialog;//第二种
//        p->setAttribute(Qt::WA_DeleteOnClose);
//        p->show();
//        qDebug()<<111111;

    }
            );

    QAction *p3 = myMenu->addAction("关于对话框");
    connect(p3,&QAction::triggered,
            [=]()
    {
        QMessageBox::about(this,"关于","第一个Qt软件");
    });

    QAction *p4 = myMenu->addAction("问题对话框");
    connect(p4,&QAction::triggered,
            [=]()
    {
        int ret = QMessageBox::question(this,"问题","are you ok?",QMessageBox::Ok|QMessageBox::Cancel);
        switch (ret) {
        case QMessageBox::Ok:
            qDebug()<<"ok";
            break;
        case QMessageBox::Cancel:
            qDebug()<<"cancel";
            break;
        default:
            break;
        }
    });

    QAction *p5 = myMenu->addAction("文件对话框");
    connect(p5,&QAction::triggered,
            [=]()
    {
        QString path = QFileDialog::getOpenFileName(this,"open","../","source(*.cpp *.h);;text(*.txt);;all(*.*)");
        qDebug()<<path;
    });

}

MainWindow::~MainWindow()
{
}

