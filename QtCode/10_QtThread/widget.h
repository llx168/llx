#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTimer>//定时器头文件
#include "mythread.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void dealTimeOut();//定时器槽函数
    void dealTheadClose();//处理线程关闭
    void dealDone();//线程结束槽函数
    void stopThread();//停止线程槽函数

private slots:
    void on_pushButton_released();

    void on_pushButton_2_clicked();


private:
    Ui::Widget *ui;

    QTimer *myTimer;//声明变量
    MyThread *thread;//线程对象
    QThread *thread1;
    QThread *thread2;
    QThread *thread3;
};
#endif // WIDGET_H
