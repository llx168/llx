#include "widget.h"
#include "ui_widget.h"
#include <QThread>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    myTimer = new QTimer(this);
    //只要定时器启动，自动触发timeout()
    connect(myTimer,&QTimer::timeout,this,&Widget::dealTimeOut);
    //分配空间
    thread = new MyThread(this);
    connect(thread,&MyThread::isDone,this,&Widget::dealDone);
    //当按窗口右上角关闭时，窗口触发destroyed()
    connect(this,&Widget::destroyed,this,&Widget::stopThread);

    connect(this,&Widget::close,this,&Widget::dealTheadClose);
}

void Widget::dealTimeOut()
{
    static int i = 0;
    i++;
    ui->lcdNumber->display(i);
//    QThread::sleep(20);//睡20秒

}

void Widget::dealTheadClose()
{

    thread->quit();

}

void Widget::dealDone()
{
    qDebug() << "it is over";
    myTimer->stop();//关闭定时器

}

void Widget::stopThread()
{
    //停止线程,线程运行完结束
    thread->quit();
    //等待线程处理完手头工作
    thread->wait();

}

Widget::~Widget()
{
    delete ui;
}

//开始按钮
void Widget::on_pushButton_released()
{
    //如果定时器没有工作
    if(myTimer->isActive() == false){
        myTimer->start(100);
    }

//    //非常复杂的数据处理，耗时较长
//    QThread::sleep(5);

    //启动线程，处理数据
    thread->start();

    //处理完数据后，关闭定时器
//    myTimer->stop();
    qDebug() << "over";

}
//启动线程按钮
void Widget::on_pushButton_2_clicked()
{
    thread->start();
}
