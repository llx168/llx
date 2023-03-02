#include "widget.h"
#include "ui_widget.h"
#include "mywork.h"
#include <QThreadPool>
#include <QDebug>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"主线程号："<<QThread::currentThread();
    MyWork* task = new MyWork;
    task->name = "zhangsan";
    QThreadPool::globalInstance()->start(task);

}

Widget::~Widget()
{
    delete ui;
}

