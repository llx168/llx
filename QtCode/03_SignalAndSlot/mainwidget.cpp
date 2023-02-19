#include "mainwidget.h"
#include <QDebug>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(300,300);
    w.resize(300,300);
    this->setWindowTitle("父窗口");
//    w.show();
    p1.setParent(this);
    p1.setText("切换到子窗口");
    p1.move(100,100);
    p2 = new QPushButton(this);

    p2->setText("hello");
//    connect(&p1,&QPushButton::pressed,this,&MainWidget::close);
//    connect(&p1,&QPushButton::pressed,this,&MainWidget::MySlot);
//    connect(&p1,&QPushButton::pressed,p2,&QPushButton::hide);
//    connect(&p1,&QPushButton::pressed,this,&MainWidget::MySlot);

    //子窗口发送信号
//    connect(&w,&SubWidget::MySignal,this,&MainWidget::dealWin);

    //信号函数重载，带参数的信号函数
    void (SubWidget::*mySignal1)()=&SubWidget::MySignal;
    void (SubWidget::*mySignal2)(int,QString)=&SubWidget::MySignal;

    connect(&p1,&QPushButton::pressed,this,&MainWidget::MySlot);
    connect(&w,mySignal1,this,&MainWidget::dealWin);
    connect(&w,mySignal2,this,&MainWidget::printInfo);

    //Lambda表达式
    //C++11增加的新特性，项目文件：CONFIG += C++11
    //Qt配合信号一起使用，非常方便
    QPushButton *button4 = new QPushButton(this);
    button4->setText("lambda表达式");

    button4->move(50,50);

    int a=100,b=300;
//    connect(button4,&QPushButton::released,
    connect(button4,&QPushButton::clicked,
            // = :把外部局部变量，和类中所有成员以值传递方式
            // this :类中所有成员以值传递方式
            // & : 引用 (少用)
//            [=]()mutable
            [=](bool isChecked)
            {
                qDebug()<<a<<b;
                qDebug()<<isChecked;
            }

            );
    //信号槽的扩展
    //信号和槽是多对多的关系，一个信号对多个槽，槽函数的执行顺序随机
    //信号可以连接信号，参数要一致
    //信号槽连接成功之后，可以用disconnect断开连接
    //槽函数可以是lambda表达式
}

void MainWidget::MySlot(){
//    p1.setText("change");
    hide();
    w.show();

}
void MainWidget::printInfo(int a,QString str)
{
    qDebug()<<a<<str.toUtf8().data();
}
void MainWidget::dealWin()
{
    w.hide();
    this->show();
}
MainWidget::~MainWidget()
{

}

