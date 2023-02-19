#include "outthread.h"
#include <QVector>

OutThread::OutThread(QObject *parent) : QThread(parent)
{

}

void OutThread::run()
{
    qDebug()<<"outthread线程号："<<QThread::currentThread();
//    vector<Point> temdata;
    Point temdata;
    while(1){
        if(!d_queue.isEmpty()){
//            temdata=d_queue.dequeue();
            qDebug()<<"id:"<<temdata.pointId;
//            qDebug()<<"azimuth:"<<temdata.azimuth;
            qDebug()<<"size: "<<d_queue.size();
//            temdata.clear();
        }

        sleep(1);
    }


}
