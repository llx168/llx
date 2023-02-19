#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QImage>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    //线程处理函数
    void drawImage();
    void drawRadarMap();


signals:
    void updateImage(QImage temp);



};

#endif // MYTHREAD_H
