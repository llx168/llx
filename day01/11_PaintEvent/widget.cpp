#include "widget.h"
#include "ui_widget.h"
#include<QPainter>
#include<QPen>
#include<QBrush>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::paintEvent(QPaintEvent *event)
{
    //自动调用


    QPainter p(this);//创建画家对象，指定当前窗口为绘图设备

    //画背景图
//    p.drawPixmap(0,0,width(),height(),QPixmap("../image/background.png"));
    p.drawPixmap(rect(),QPixmap("../image/background.png"));//跟上一句效果一样

    //定义画笔
    QPen pen;
    pen.setWidth(5);//线条宽度为5个像素
//    pen.setColor(Qt::red);
    pen.setColor(QColor(34,56,78));//rgb设置颜色
    pen.setStyle(Qt::DashLine);//设置风格

    //把画笔交给画家
    p.setPen(pen);

    //创建画刷对象
    QBrush brush;
    brush.setColor(Qt::red);//设置颜色
    brush.setStyle(Qt::Dense1Pattern);//设置样式

    //把画刷交给画家
    p.setBrush(brush);


    //画直线
    p.drawLine(50,50,50,200);
    p.drawLine(50,50,200,400);

    //画矩形
    p.drawRect(100,100,200,355);
    //画圆形
    p.drawEllipse(QPoint(200,200),50,100);

    p.drawPixmap(xdis,400,50,50,QPixmap("../image/face.png"));





}


void Widget::on_pushButton_released()
{
    xdis+=20;
    if(xdis>width()){
        xdis=0;
    }
    //刷新窗口，让窗口重绘，整个窗口都重绘
    update();//间接调用paintEvent()
}
