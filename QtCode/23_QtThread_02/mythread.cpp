#include "mythread.h"
#include <QThread>
#include <QDebug>
MyThread::MyThread(QObject *parent) : QObject(parent)
{

}

void MyThread::myTimeout()
{
    while (isStop == false) {
        QThread::sleep(1);
        emit mySingal();

        qDebug()<<"子线程号："<<QThread::currentThread();

        if(true == isStop){
            break;
        }
    }
}

void MyThread::setFlag(bool flag)
{
    isStop = flag;
}
