#include "widget.h"
#include "ui_widget.h"
#include <QtSerialPort/QSerialPortInfo>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
//    QStringList comname;//活动串口表
//    comname.clear();
//    ui->comboBox->clear();
//    foreach(const QSerialPortInfo &info,QSerialPortInfo::availablePorts()){
//        comname.append(info.portName());
//    }
//    ui->comboBox->addItems(comname);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_comboBox_activated(int index)
{
    qDebug()<<index;
}

void Widget::on_comboBox_activated(const QString &arg1)
{
    qDebug()<<arg1;
}

void Widget::on_pushButton_released()
{
    QStringList comname;//活动串口表
    comname.clear();
    ui->comboBox->clear();
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        comname.append(info.portName());
    }
    ui->comboBox->addItems(comname);

//    QSerialPort serial;
//    serial.setPort(info);
//    if(serial.open(QIODevice::ReadWrite))
//    {
//        ui->comboBox->addItem(serial.portName());
//        serial.close();
//    }



}
