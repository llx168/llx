#ifndef MYWORK_H
#define MYWORK_H

#include <QObject>
#include <QRunnable>

class MyWork : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MyWork(QObject *parent = nullptr);

signals:


    // QRunnable interface
public:
    void run();
};

#endif // MYWORK_H
