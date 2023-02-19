#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->splitter->setSizes(QList<int>()<<1/3*width<<2/3*width);
    //splitter子窗口按比例分配空间
    ui->splitter->setStretchFactor(0,9);
    ui->splitter->setStretchFactor(1,1);
    QPalette pa = ui->scrollArea->palette();
    pa.setBrush(QPalette::Dark, Qt::transparent);
    pa.setColor(QPalette::Background,QColor(0,0,0));

    ui->scrollArea->setPalette(pa);
    myTimer = new QTimer(this);
    connect(myTimer,&QTimer::timeout,this,&MainWindow::dealTimeout);

    themodel = new QStandardItemModel(1000,5,this);
    QItemSelectionModel *theselection = new QItemSelectionModel(themodel);

    //设置选择模型
    ui->tableView-> setSelectionModel(theselection) ;
    ui->tableView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    ui->tableView->setSelectionBehavior(QAbstractItemView::SelectItems);



    ui->tableView->setModel(themodel);

    //下面依次进行一些基本操作:

//        //1.首先是初始化表格内容:
//        QStandardItem*item;
//        for(int i=0;i<themodel->columnCount();i++){
//            for(int j=0;j<themodel->rowCount();j++){
//                item=new QStandardItem(QString::number(1000));//这里注意一下,QStandard构造时参数要求是QString
////                item->setCheckable(true);//这个函数可以给每个小格加个勾选框
//                //底下这个是核心方法.
//                themodel->setItem(j,i,item);
//                /*void QStandardItemModel::setItem(int row, int column, QStandardItem *item)
//                不用索引模型,直接修改,方便不少*/
//            }
//        }

//        qDebug()<<themodel->rowCount()<<themodel->columnCount();

        //修改表格内容
//        for(int k=0;k<10000;k++){
//            for(int i=0;i<themodel->rowCount();i++){
//                for(int j=0;j<themodel->columnCount();j++){
//                    themodel->setData(themodel->index(i,j),k,Qt::DisplayRole);
//                }
//            }
//            Sleep(1000);
//        }


        //2.设置表格表头,水平反向和竖直反向的都要有:
        QStringList horizontalHeader= QStringList();
        horizontalHeader<<"点ID"<<"角度"<<"距离"<<"强度"<<"时间";
            //底下这个是核心方法
        themodel->setHorizontalHeaderLabels(horizontalHeader);

        //自定义类对象，分配空间，不可以指定父对象
        myThread = new RadarImage;
        //创建子线程
        thread = new QThread(this);
        //把自定义模块添加到子线程
        myThread->moveToThread(thread);
        //启动子线程，但是并没有启动线程处理函数
        thread->start();

        //线程处理函数必须通过信号和槽调用
//        connect(ui->pushButton_5,&QPushButton::pressed,myThread,&RadarImage::drawRadarMap);
        connect(myThread,&RadarImage::updateRadarImage,this,&MainWindow::getImage);
        connect(this, &MainWindow::destroyed,this,&MainWindow::dealClose);

        label = new QLabel;



        ui->scrollArea->setWidget(label);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_4_released()
{
//    Dialog *d = new Dialog();
//    d->show();

    lidarParaDialog.show();

}

void MainWindow::on_pushButton_released()
{
    if(lidarDataShow==true){
        ui->tableView->setHidden(true);
        lidarDataShow=false;
    }else{
        ui->tableView->setVisible(true);
        ui->tableView->setGeometry(0,0,300,800);
        lidarDataShow=true;

    }
}

void MainWindow::on_pushButton_2_released()
{
    showParaDialog.show();
}

void MainWindow::on_pushButton_3_released()
{
    pointCloudProcDialog.show();
}

void MainWindow::dealTimeout()
{
    //修改表格内容
    for(int i=0;i<themodel->rowCount();i++){
        themodel->setData(themodel->index(i,0),i,Qt::DisplayRole);//点id
        themodel->setData(themodel->index(i,1),i*0.36,Qt::DisplayRole);//角度
        themodel->setData(themodel->index(i,2),qrand()%10/5.0+10,Qt::DisplayRole);//距离
        themodel->setData(themodel->index(i,3),(qrand()%10)/5.0+1.0,Qt::DisplayRole);//强度
        themodel->setData(themodel->index(i,4),i,Qt::DisplayRole);//时间
//        for(int j=0;j<themodel->columnCount();j++){
//            themodel->setData(themodel->index(i,j),myCount,Qt::DisplayRole);
//        }
    }

//    myCount++;
//    qDebug()<<(qrand()%10)/10.0+2.0;
    myThread->drawRadarMap();
}
void MainWindow::on_pushButton_5_released()
{
    if(myTimer->isActive() == false){
        myTimer->start(50);
    }
}

void MainWindow::on_pushButton_6_released()
{
    if(myTimer->isActive() == true){
        myTimer->stop();

    }
}
void MainWindow::getImage(QImage temp)
{
    image = temp;
    update();//更新窗口，间接调用paintEvent()
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    label->setPixmap(QPixmap::fromImage(image));
//    QPainter p(label);//创建画家，指定绘图设备为窗口
//    p.drawImage(50,50,image);

}
void MainWindow::dealClose()
{
    //退出子线程
    thread->quit();
    //回收资源
    thread->wait();
    delete myThread;
}
