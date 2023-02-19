#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mydata.h"
#include"inthread.h"
#include"outthread.h"
#include <QMap>
#include<QString>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_create_queue_released();

    void on_delete_queue_released();

private:
    Ui::Widget *ui;
    InThread *it;
    OutThread *ot;

};
#endif // WIDGET_H
