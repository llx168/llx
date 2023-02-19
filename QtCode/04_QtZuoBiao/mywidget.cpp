#include "mywidget.h"
#include <QPushButton>
#include "mybutton.h"
MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    //对于主窗口，坐标系统相对于屏幕坐上角为原点，x为水平方向，y为垂直方向
    move(50,100);
    //子窗口，坐标系统相对于父窗口左上角为原点（不包括边框），x为水平方向，y为垂直方向
    QPushButton *p1 = new QPushButton(this);
    p1->move(100,100);
    p1->resize(200,200);
    p1->setText("^_^");
    QPushButton *p2 = new QPushButton(p1);
    p2->move(50,20);
    p2->setText("@_@");

    //  1）指定父对象后   2）直接或者间接继承QObject
    //子对象如果是动态分配空间的 new，不需要手动释放 delete，系统会自动释放（对象树）
    MyButton *b1 = new MyButton(this);
    b1->setText("MyButton");

}

MyWidget::~MyWidget()
{
}

