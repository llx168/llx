#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QDebug>
#include <QtMath>
#include <vtkSmartPointer.h>
#include <vtkRegularPolygonSource.h>
#include <vtkNew.h>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>
#include <QSqlRecord>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    ui->splitter->setSizes(QList<int>()<<1/3*width<<2/3*width);
    //splitter子窗口按比例分配空间
    ui->splitter->setStretchFactor(0,1);
    ui->splitter->setStretchFactor(1,9);
    ui->splitter->setStretchFactor(2,1);
    myTimer = new QTimer(this);
    connect(myTimer,&QTimer::timeout,this,&MainWindow::dealTimeout);//每隔几秒刷新一次数据
    themodel = new QStandardItemModel(1000,6,this);//显示点云数据
//    QItemSelectionModel *theselection = new QItemSelectionModel(themodel);
    ui->tableView->setModel(themodel);
    //2.设置表格表头,水平反向和竖直反向的都要有:
    QStringList horizontalHeader= QStringList();
    horizontalHeader<<"点ID"<<"角度"<<"距离"<<"强度"<<"时间"<<"XYZ坐标";
        //底下这个是核心方法
    themodel->setHorizontalHeaderLabels(horizontalHeader);
//    lidarDeviceModel = new QStandardItemModel(20,3,this);
//    ui->tableView_2->setModel(lidarDeviceModel);//显示雷达设备
//    QStringList LidarDeviceHeader= QStringList();
//    LidarDeviceHeader<<"设备名称"<<"设备状态"<<"网络地址";
//    lidarDeviceModel->setHorizontalHeaderLabels(LidarDeviceHeader);




    //自定义类对象，分配空间，不可以指定父对象
    myThread = new DrawPointCloud;
    //创建子线程
    thread = new QThread(this);
    //把自定义模块添加到子线程
    myThread->moveToThread(thread);
    //启动子线程，但是并没有启动线程处理函数
    thread->start();
    //线程处理函数必须通过信号和槽调用
    connect(ui->pushButton_5,&QPushButton::pressed,myThread,&DrawPointCloud::drawPointCloud);
    connect(myThread,&DrawPointCloud::updatePointCloud,this,&MainWindow::getImage);
    connect(this, &MainWindow::destroyed,this,&MainWindow::dealClose);

    //PCL
    qRegisterMetaType<pcl::PointCloud<pcl::PointXYZ>::Ptr>("pcl::PointCloud<pcl::PointXYZ>::Ptr");
    viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
    //画网格
    for (int i = -100; i <= 100; i += 10) {
        viewer->addLine(pcl::PointXYZ(i, -100, 0), pcl::PointXYZ(i, 100, 0), QString("GridlineY%1").arg(i).toStdString(), 0);
        viewer->addLine(pcl::PointXYZ(-100, i, 0), pcl::PointXYZ(100, i, 0), QString("GridlineX%1").arg(i).toStdString(), 0);

//        if(i > 0){
//            viewer->addText3D(QString::number(i).append("m").toStdString(), pcl::PointXYZ(0, i, 0), 0.8, 0.5, 0.5, 0.5, QString("GridText%1").arg(i).toStdString(), 0);
//        }
//        viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 0.1, QString("GridlineY%1").arg(i).toStdString(), 0);
//        viewer->setShapeRenderingProperties(pcl::visualization::PCL_VISUALIZER_LINE_WIDTH, 0.1, QString("GridlineX%1").arg(i).toStdString(), 0);

    }


    viewer->setBackgroundColor (showPara.bgColorR/255.0, showPara.bgColorG/255.0, showPara.bgColorB/255.0);
    viewer->addCoordinateSystem (5);//设置坐标轴大小
    viewer->initCameraParameters ();
    viewer->setCameraPosition(0.0,0.0,80.0,1.0,0.0,0.0); //设置观察位置和方向
    viewer->setupInteractor(ui->qvtkwidget->GetInteractor(), ui->qvtkwidget->GetRenderWindow());
    ui->qvtkwidget->SetRenderWindow(viewer->getRenderWindow());


//    //画圆环
//    QVector<pcl::PointXYZ> points;
//    for (int j = 1; j <= 10; j++) {
//        int r = 10 * j;
//        vtkSmartPointer<vtkRegularPolygonSource>   source = vtkSmartPointer<vtkRegularPolygonSource>::New();
//        vtkSmartPointer<vtkPolyDataMapper>         mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
//        vtkSmartPointer<vtkActor>                  actor = vtkSmartPointer<vtkActor>::New();
//        source->SetNumberOfSides(70);    //多边形边数
//        source->SetRadius(r);            //半径
//        source->SetCenter(0, 0, 0);      //圆心
//        mapper->SetInputConnection(source->GetOutputPort());
//        actor->SetMapper(mapper);
//        actor->GetProperty()->SetColor(0.5, 0.5, 0.5);    //颜色
//        actor->GetProperty()->SetOpacity(1);    //透明度
//        actor->GetProperty()->SetRepresentationToWireframe();//图形不填充，只要边框

//        ui->qvtkwidget->GetRenderWindow()->GetRenderers()->GetFirstRenderer()->AddActor(actor);
//    }





    ui->qvtkwidget->update();

    connect(&showParaDialog,&ShowParaDialog::showParaSignal,this,&MainWindow::dealShowPara);


    //打印Qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();

    //添加Sqlite数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    //设置数据库
    db.setDatabaseName("info.db");



    //打开数据库
    if(!db.open())//数据库打开失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }else{
        qDebug()<<"db is ok!";
    }
    QSqlQuery query;
    query.exec("create table LidarDevice(id int primary key,name varchar(255),status varchar(255),ip_address varchar(255),x_ordin float,y_ordin float,angle int)");//id不能自增

    //设置模型
    lidarModel = new QSqlTableModel(this);
    lidarModel->setTable("LidarDevice");//指定使用哪个表
    //把model放在view
    ui->tableView_2->setModel(lidarModel);
    //显示model里的数据
    lidarModel->select();
    lidarModel->setHeaderData(0,Qt::Horizontal,"ID");
    lidarModel->setHeaderData(1,Qt::Horizontal,"设备名称");
    lidarModel->setHeaderData(2,Qt::Horizontal,"设备状态");
    lidarModel->setHeaderData(3,Qt::Horizontal,"网络地址");
    lidarModel->setHeaderData(4,Qt::Horizontal,"X坐标");
    lidarModel->setHeaderData(5,Qt::Horizontal,"Y坐标");
    lidarModel->setHeaderData(6,Qt::Horizontal,"朝向角度");


    lidarModel->setEditStrategy(QSqlTableModel::OnFieldChange);


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
    double x,y,z;
    double azimuth,distance;
    //修改表格内容
    for(int i=0;i<themodel->rowCount();i++){
        azimuth = i*0.36;
        distance = qrand()%10/5.0+10;
        themodel->setData(themodel->index(i,0),i,Qt::DisplayRole);//点id
        themodel->setData(themodel->index(i,1),azimuth,Qt::DisplayRole);//角度
        themodel->setData(themodel->index(i,2),distance,Qt::DisplayRole);//距离
        themodel->setData(themodel->index(i,3),(qrand()%10)/5.0+1.0,Qt::DisplayRole);//强度
        themodel->setData(themodel->index(i,4),i,Qt::DisplayRole);//时间
        x = distance*cos(azimuth/180.0*M_PI);
        y = distance*sin(azimuth/180.0*M_PI);
        z = 0.00;

        themodel->setData(themodel->index(i,5),QString("%1, %2, %3").arg(QString::number(x, 'f', 2)).arg(QString::number(y, 'f', 2)).arg(QString::number(z, 'f', 2)),Qt::DisplayRole);//坐标
//        for(int j=0;j<themodel->columnCount();j++){
//            themodel->setData(themodel->index(i,j),myCount,Qt::DisplayRole);
//        }

//        pcl::PointCloud<pcl::PointXYZ>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>());

//        //正方体点云
//        for(int i=0; i<20; i++)
//        {
//            for(int j=0; j<20; j++)
//            {
//                for(int k = 0; k<20; k++)
//                {
//                    cloud->push_back(pcl::PointXYZ((i-10)/1.0f, (j-10)/1.0f, (k-10)/1.0f));

//                }
//            }
//        }
//        viewer->removeAllPointClouds();
//        pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, 255, 0, 0);
//        viewer->addPointCloud<pcl::PointXYZ>(cloud,single_color,"cloud");
//        viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 10, "cloud");
        myThread->drawPointCloud();
//        ui->qvtkwidget->update ();

    }


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
void MainWindow::getImage(pcl::PointCloud<pcl::PointXYZ>::Ptr cloud)
{
//    image = temp;
    viewer->removeAllPointClouds();
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud, showPara.pointColorR, showPara.pointColorG, showPara.pointColorB);
    viewer->addPointCloud<pcl::PointXYZ>(cloud,single_color,"cloud");
    //设置点的大小
    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, showPara.pointSize, "cloud");
    ui->qvtkwidget->update ();
//    update();//更新窗口，间接调用paintEvent()
}

//void MainWindow::paintEvent(QPaintEvent *event)
//{
////    label->setPixmap(QPixmap::fromImage(image));
////    QPainter p(label);//创建画家，指定绘图设备为窗口
////    p.drawImage(50,50,image);

//}
void MainWindow::dealClose()
{
    //退出子线程
    thread->quit();
    //回收资源
    thread->wait();
    delete myThread;
}

void MainWindow::dealShowPara(ShowPara s)
{
    viewer->setBackgroundColor(s.bgColorR, s.bgColorG, s.bgColorB);
    this->showPara.pointColorB = s.pointColorB;
    this->showPara.pointColorG = s.pointColorG;
    this->showPara.pointColorR = s.pointColorR;
    this->showPara.pointSize = s.pointSize;
    ui->qvtkwidget->update();
}

void MainWindow::on_pushButton_7_released()
{
    if(coordinateShow==true){
        viewer->removeCoordinateSystem();
        coordinateShow = false;
        ui->qvtkwidget->update();
    }else{
        viewer->addCoordinateSystem(5);
        coordinateShow = true;
        ui->qvtkwidget->update();
    }

}



void MainWindow::on_pushButton_8_released()
{
    if(gridShow == true){
        viewer->removeAllShapes();//清空网格线
        gridShow = false;
    }else{
        //画网格
        for (int i = -100; i <= 100; i += 10) {
            viewer->addLine(pcl::PointXYZ(i, -100, 0), pcl::PointXYZ(i, 100, 0), QString("GridlineY%1").arg(i).toStdString(), 0);
            viewer->addLine(pcl::PointXYZ(-100, i, 0), pcl::PointXYZ(100, i, 0), QString("GridlineX%1").arg(i).toStdString(), 0);

        }
        gridShow = true;
    }

    ui->qvtkwidget->update();
}

void MainWindow::on_pushButton_9_released()
{

}

void MainWindow::on_pushButton_12_released()
{

}
//帮助按钮弹框
void MainWindow::on_pushButton_10_released()
{
    QMessageBox::about(this,"关于","高精度激光雷达");
}
//打开点云数据文件
void MainWindow::on_pushButton_11_released()
{
    QString path = QFileDialog::getOpenFileName(this,"open","../","source(*.pcd *.fly)");
    qDebug()<<path;
    // 定义点云
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);

    // 读取点云，失败返回-1
    if (pcl::io::loadPCDFile<pcl::PointXYZ>(path.toStdString(), *cloud1) == -1)
    {
        qDebug()<<"couldn't read file\n";
        return;
    }

    // 输出点云大小 cloud->width * cloud->height
    qDebug() << "点云大小：" << cloud1->size();
    viewer->removeAllPointClouds();
//    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> single_color(cloud1, showPara.pointColorR, showPara.pointColorG, showPara.pointColorB);
    viewer->addPointCloud<pcl::PointXYZ>(cloud1,"cloud");
    //设置点的大小
//    viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, showPara.pointSize, "cloud");
    ui->qvtkwidget->update ();
}

//显示雷达设备
void MainWindow::on_pushButton_15_released()
{
    if(lidarDeviceShow==true){
        ui->tableView_2->setHidden(true);
        lidarDeviceShow=false;
    }else{
        ui->tableView_2->setVisible(true);
        ui->tableView_2->setGeometry(0,0,300,800);
        lidarDeviceShow=true;

    }

}
//添加雷达设备
void MainWindow::on_pushButton_17_released()
{
    //添加空记录
    QSqlRecord record = lidarModel->record();//获取空记录
    //获取行号
    int row = lidarModel->rowCount();
    lidarModel->insertRecord(row,record);

}
//删除雷达设备
void MainWindow::on_pushButton_18_released()
{
    lidarModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    //获取选中的模型
   QItemSelectionModel *sModel = ui->tableView_2->selectionModel();
   //取出模型中的索引
   QModelIndexList list = sModel->selectedRows();
   //删除所有选中的行
   for(int i=0;i<list.size();i++){
       lidarModel->removeRow(list.at(i).row());
   }
   lidarModel->submitAll();
   lidarModel->setEditStrategy(QSqlTableModel::OnFieldChange);


}
//更新设备
void MainWindow::on_pushButton_16_released()
{
    //提交动作
    lidarModel->submitAll();

}
