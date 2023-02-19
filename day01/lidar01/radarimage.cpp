#include "radarimage.h"
#include <QImage>
#include <QPainter>
#include <QPoint>
#include <QPen>
#include <QBrush>
#include <QtMath>
#include <QtDebug>

RadarImage::RadarImage(QObject *parent) : QObject(parent)
{

}



void RadarImage::drawRadarMap()
{
        //画雷达图
        //定义Qimage绘图设备
        QImage image(900,900,QImage::Format_ARGB32);
        QPainter painter(&image);
            painter.setRenderHint(QPainter::Antialiasing, true);
            painter.setBrush(QBrush(QColor(0,0,0)));
            painter.drawRect(0,0,image.width()-1,image.height()-1);
            //绘制文字
            painter.setPen(QPen(QColor(255,255,255),5));
            painter.drawText(10,30,QString::number(12) + " ts");
            painter.drawText(100,30,QString::number(5) + " Hz");
            //移动到中间
            int m_step = (image.width()-50)/6;//圆步长
            painter.translate(image.width()/2,image.height()/2);

            //每30度画线
            painter.setPen(QPen(QColor(128,128,128),1));
            for(int i = 0; i < 12;i++){
                double radian = 30*i * M_PI / 180;
                double xMargin = cos(radian) * (m_step*3+10);
                double yMargin = sin(radian) * (m_step*3+10);
                QPoint t_point(xMargin,yMargin);
                QPoint t_pointSrc(0,0);
                painter.drawLine(t_pointSrc,t_point);
                if(i==0){
                    painter.drawText(t_point,QString("%1").arg(0));
                }else{
                    painter.drawText(t_point,QString("%1").arg(360-30*i));
                }
            }

            //画圆
            painter.setBrush(Qt::NoBrush);
            painter.setPen(QPen(QColor(128,128,128)));
            painter.drawEllipse(QPointF(0,0),m_step*1,m_step*1);
            painter.drawEllipse(QPointF(0,0),m_step*2,m_step*2);
            painter.drawEllipse(QPointF(0,0),m_step*3,m_step*3);
            //绘制文本
            double m_max_dist=100.0;
            double t_dist_step = m_max_dist/3;
            painter.drawText(QPointF(m_step*1-20,0),QString::number(t_dist_step,'f',1));
            painter.drawText(QPointF(m_step*2-20,0),QString::number(t_dist_step*2,'f',1));
            painter.drawText(QPointF(m_step*3-20,0),QString::number(t_dist_step*3,'f',1));
            painter.setPen(QPen(QColor(	220,20,60),2));

    //        for(int i = 0;i < t_dis_points.size();i++){
    //            painter.drawEllipse(t_dis_points.at(i),1,1);//画数据
    //        }
            //画点
            painter.setPen(QPen(QColor(255,0,0),10));
            painter.setBrush(Qt::red);
            int radius = 3;
            double distance = 300;
            int x,y = 0;
            double azimuth = 0;
            int ran = 0;
            for(int i=0;i<100;i++){
                ran = qrand()%30;
                azimuth = 360.0/100.0*i/180.0*M_PI;
                x = (distance+ran)*cos(azimuth);
                y = (distance+ran)*sin(azimuth);
//                qDebug()<<y;
                painter.drawEllipse(QPoint(x,y),radius,radius);
//                painter.drawPoint(QPoint(x,y));
            }



//            painter.drawPoint(QPoint(100+qrand()%100,10+qrand()%100));
//            painter.drawPoint(QPoint(100+qrand()%100,10+qrand()%100));
//            painter.drawPoint(QPoint(100+qrand()%100,10+qrand()%100));
//            painter.drawPoint(QPoint(100+qrand()%100,10+qrand()%100));

            //通过信号发送图片
            emit updateRadarImage(image);

}
