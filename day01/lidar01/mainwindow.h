#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "showparadialog.h"
#include "pointcloudprocdialog.h"
#include <QStandardItemModel>
#include <QTimer>//定时器头文件
#include <QImage>
#include "radarimage.h"
#include <QThread>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void dealTimeout();
    //重写绘图事件
    void paintEvent(QPaintEvent *event);
    void getImage(QImage image);//槽函数
    void dealClose();


private slots:
    void on_pushButton_4_released();

    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_5_released();



    void on_pushButton_6_released();

private:
    Ui::MainWindow *ui;
    bool lidarDataShow = true;
    Dialog lidarParaDialog;
    ShowParaDialog showParaDialog;
    PointCloudProcDialog pointCloudProcDialog;
    QStandardItemModel *themodel;
    QTimer *myTimer;
    int myCount=0;
    QImage image;
    RadarImage *myThread;//自定义线程
    QThread *thread;//子线程
    QLabel *label;
};
#endif // MAINWINDOW_H
