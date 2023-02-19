#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

class MyThread : public QObject
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    //线程处理函数
    void myTimeout();

    void setFlag(bool flag = true);

signals:
    void mySingal();

private:
    bool isStop;

};

#endif // MYTHREAD_H
