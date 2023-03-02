#ifndef MYWORK_H
#define MYWORK_H

#include <QObject>
#include <QRunnable>
#include <QTimer>

class MyWork : public QObject,public QRunnable
{
    Q_OBJECT
public:
    explicit MyWork(QObject *parent = nullptr);

signals:


    // QRunnable interface
public:
    void run();
    QString name;

};

#endif // MYWORK_H
