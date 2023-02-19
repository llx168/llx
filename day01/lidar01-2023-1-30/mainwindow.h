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
#include <QSqlTableModel>
//pcl
#include <vtkRenderWindow.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <QVTKWidget.h>
#include "drawpointcloud.h"


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
//    void paintEvent(QPaintEvent *event);
    void getImage(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud);//槽函数
    void dealClose();
    void dealShowPara(ShowPara s);


private slots:
    void on_pushButton_4_released();

    void on_pushButton_released();

    void on_pushButton_2_released();

    void on_pushButton_3_released();

    void on_pushButton_5_released();

    void on_pushButton_6_released();

    void on_pushButton_7_released();

    void on_pushButton_12_released();

    void on_pushButton_8_released();

    void on_pushButton_9_released();

    void on_pushButton_10_released();

    void on_pushButton_11_released();

    void on_pushButton_15_released();

    void on_pushButton_17_released();

    void on_pushButton_18_released();

    void on_pushButton_16_released();

private:
    Ui::MainWindow *ui;
    bool lidarDataShow = true;//雷达数据显示开关
    bool lidarDeviceShow = true;//雷达设备显示开关
    Dialog lidarParaDialog;
    ShowParaDialog showParaDialog;//显示参数设置窗口
    PointCloudProcDialog pointCloudProcDialog;
    QStandardItemModel *themodel;
    QStandardItemModel *lidarDeviceModel;
    QTimer *myTimer;
    int myCount=0;
//    QImage image;
//    RadarImage *myThread;//自定义线程
    DrawPointCloud *myThread;//自定义线程
    QThread *thread;//子线程
//    QLabel *label;
    bool coordinateShow = true;
    bool gridShow = true;

    pcl::visualization::PCLVisualizer::Ptr viewer;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    ShowPara showPara;
    QSqlTableModel *lidarModel;
};
#endif // MAINWINDOW_H
