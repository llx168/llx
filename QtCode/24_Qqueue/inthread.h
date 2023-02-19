#ifndef INTHREAD_H
#define INTHREAD_H

#include <QThread>
#include "mydata.h"

class InThread : public QThread
{
    Q_OBJECT
public:
    explicit InThread(QObject *parent = nullptr);
    virtual void run();

signals:

};

#endif // INTHREAD_H
