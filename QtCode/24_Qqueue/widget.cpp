#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    qDebug()<<"主线程号："<<QThread::currentThread();

    it = new InThread();
    ot = new OutThread();

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_released()
{

    it->start();
    ot->start();
}

void Widget::on_pushButton_2_released()
{
    QMap<string,Point> map;
    Point p1,p2;
    p1.pointId=1;
    p2.pointId=2;
    map.insert("1",p1);
    map.insert("2",p2);
    qDebug()<<"pointId:"<<map["1"].pointId;
//    qDebug<<1;

}
