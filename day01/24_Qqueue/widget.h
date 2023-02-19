#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include"mydata.h"
#include"inthread.h"
#include"outthread.h"

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

private:
    Ui::Widget *ui;
    InThread *it;
    OutThread *ot;
};
#endif // WIDGET_H
