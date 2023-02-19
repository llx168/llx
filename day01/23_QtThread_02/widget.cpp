#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //动态分配空间,不能指定父对象
    myThread = new MyThread;

    //创建子线程
    thread = new QThread(this);

    //把自定义线程加入到子线程中
    myThread->moveToThread(thread);

    connect(myThread,&MyThread::mySingal,this,&Widget::dealSignal);

    qDebug()<<"主线程号："<<QThread::currentThread();

    connect(this,&Widget::startThread,myThread,&MyThread::myTimeout);

    connect(this,&Widget::destroyed,this,&Widget::dealClose);

    //线程处理函数内部，不允许操作图形界面

    //connect()第五个参数的作用，连接方式：默认，队列，直接
    //多线程时才有意义
    //默认的时候
    //如果是多线程，默认使用队列
    //如何判断多线程，会根据发送方和接收方的类判断是否在同一线程
    //如果单线程，默认使用直接方式
    //队列：槽函数所在的线程和接收者一样
    //直接：槽函数所在线程和发送者一样


}

Widget::~Widget()
{
    delete ui;
}

void Widget::dealSignal()
{
    static int i=0;
    i++;
    ui->lcdNumber->display(i);

}

void Widget::dealClose()
{
    on_stopButton_released();

    delete myThread;
}


void Widget::on_startButton_released()
{
    if(thread->isRunning() == true){
        return;
    }
    //启动线程，但是没有启动线程处理函数
    thread->start();
    myThread->setFlag(false);

    //不能直接调用线程处理函数
    //直接调用，导致线程处理函数和主线程是在同一个线程
//    myThread->myTimeout();

    //只能通过  signal - slot 方式调用
    emit startThread();
}

void Widget::on_stopButton_released()
{
    if(thread->isRunning() == false){
        return;
    }
    myThread->setFlag(true);
    thread->quit();
    thread->wait();
}
