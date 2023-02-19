#include "widget.h"
#include "ui_widget.h"
#include <QPainter>
#include <QBitmap>
#include <QPen>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //创建绘图设备
    //
    QPixmap pixMap(200,200);
    QPainter p(&pixMap);
    QPen pen;
    pen.setWidth(5);//线条宽度为5个像素
//    pen.setColor(Qt::red);
    pen.setColor(QColor(34,56,78));//rgb设置颜色
    pen.setStyle(Qt::DashLine);//设置风格

    //把画笔交给画家
    p.setPen(pen);
    p.drawRect(50,50,100,100);
    pixMap.fill(Qt::white);//填充颜色
    pixMap.save("../image/save1.png");


    //创建一个Qimage绘图设备，可对图片像素点进行操作，也可以线程绘图
    QImage image(500,500,QImage::Format_ARGB32);
    QPainter p2(&image);
    p2.drawEllipse(200,200,50,50);
    p2.setPen(pen);
    for(int i=0;i<50;i++){
        for(int j=0;j<50;j++){
            image.setPixel(i,j,qRgb(255,0,0));
        }
    }
    image.save("../image/Qimage.png");

    //创建一个QPicture绘图设备，这个保存的结果为二进制文件，用法同上




}

void Widget::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(0,0,QPixmap("../image/face.png"));
    //bitmap 灰度图片
    QBitmap bitMap;
    bitMap.load("../image/face.png");
    p.drawPixmap(0,200,bitMap);
}

Widget::~Widget()
{
    delete ui;
}

