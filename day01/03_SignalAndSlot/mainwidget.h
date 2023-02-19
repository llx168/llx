#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "subwidget.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();
    void MySlot();
    void dealWin();
    void printInfo(int,QString);
private:
    QPushButton p1;
    QPushButton *p2;
    SubWidget w;//子窗口

};
#endif // MAINWIDGET_H
