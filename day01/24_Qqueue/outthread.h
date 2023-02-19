#ifndef OUTTHREAD_H
#define OUTTHREAD_H

#include <QThread>
#include <QDebug>
#include "mydata.h"

class OutThread : public QThread
{
    Q_OBJECT
public:
    explicit OutThread(QObject *parent = nullptr);
    virtual void run();

signals:

};

#endif // OUTTHREAD_H
