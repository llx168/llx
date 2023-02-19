#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "mythread.h"
#include <QThread>
#include <QImage>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    //重写绘图事件
    void paintEvent(QPaintEvent *event);
    void getImage(QImage image);//槽函数
    void dealClose();

private:
    Ui::Widget *ui;
    QImage image;
    MyThread *myThread;//自定义线程
    QThread *thread;//子线程
    QLabel *label;
};
#endif // WIDGET_H
