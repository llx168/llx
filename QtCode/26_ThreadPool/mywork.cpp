#include "mywork.h"
#include <QThread>
#include <QDebug>
MyWork::MyWork(QObject *parent) : QObject(parent)
{
    setAutoDelete(true);
}

void MyWork::run()
{
    qDebug()<<"子线程号："<<QThread::currentThread();

}
