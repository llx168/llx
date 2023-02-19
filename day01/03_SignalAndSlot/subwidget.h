#ifndef SUBWIDGET_H
#define SUBWIDGET_H

#include <QWidget>
#include <QPushButton>

class SubWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SubWidget(QWidget *parent = nullptr);
    void EmitSignal();

signals:
    //signals关键字
    //只有声明没有定义
    //没有返回值，可以有参数
    //使用emit MySignal()
    //可以重载
    void MySignal();
    void MySignal(int,QString);
private:
    QPushButton p1;

};

#endif // SUBWIDGET_H
