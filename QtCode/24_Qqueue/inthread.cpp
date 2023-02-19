#include "inthread.h"
#include <QDebug>
InThread::InThread(QObject *parent) : QThread(parent)
{

}

void InThread::run()
{
    qDebug()<<"inthread线程号："<<QThread::currentThread();
    int count=0;
//    vector<Point> temdata;
    Point tempdata;
    while(1){
//        temdata.clear();
//        Point point;
        tempdata.pointId = count;
        tempdata.azimuth = 100.0+count;
        tempdata.dist = 20.0+count;
//        temdata.push_back(point);
//        d_queue.enqueue(tempdata);
        count++;
        msleep(1);
    }


}
