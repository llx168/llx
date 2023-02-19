#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include <QAbstractItemView>
#include <QHeaderView>
#include <QDebug>
#include <windows.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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

        //1.首先是初始化表格内容:
        QStandardItem*item;
        for(int i=0;i<themodel->columnCount();i++){
            for(int j=0;j<themodel->rowCount();j++){
                item=new QStandardItem(QString::number(1000));//这里注意一下,QStandard构造时参数要求是QString
//                item->setCheckable(true);//这个函数可以给每个小格加个勾选框
                //底下这个是核心方法.
                themodel->setItem(j,i,item);
                /*void QStandardItemModel::setItem(int row, int column, QStandardItem *item)
                不用索引模型,直接修改,方便不少*/
            }
        }

        qDebug()<<themodel->rowCount()<<themodel->columnCount();

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
        /*void QTableView::setVerticalHeader(QHeaderView *header)
            这个设置表头的是view而不是model,
            显然,表头的数据不归数据模型管,
            所以表头不算在列数和行数内*/
            //竖直表头同理
//        QHeaderView *headerView = new QHeaderView(Qt::Horizontal);
//        ui->tableView->setHorizontalHeader(headerView);

        //设置垂直方向的表头
//        QStringList vertical=QStringList();
//        vertical<<"no.1"<<"no.2"<<"no.3"<<"no.4"<<"no.5";
//        themodel->setVerticalHeaderLabels(vertical);




//        //3.添加一行
//        QList<QStandardItem*> newrow;
//        for(int i=0;i<themodel->columnCount();i++){
//            newrow<<new QStandardItem("0");
//        }
            //底下这个是核心方法
//        themodel->insertRow(themodel->rowCount(),newrow);
        //删除同理.方法是:QList<QStandardItem *> QStandardItemModel::takeRow(int row)


//        //4.获取选中的单元格并操作
//            //获取选择单元格的模型索引列表
//        QModelIndexList selectedIndex=theselection->selectedIndexes();

//        for (int i=0;i<selectedIndex.count();i++)
//        {     //获取一个模型索引
//            QModelIndex aIndex=selectedIndex.at(i);
//                //获取项数据
//            QStandardItem* aItem=themodel->itemFromIndex(aIndex);
//            //然后就可以对项数据进行操作了
//        }


//        //5.查看某处的单元格的勾选框选中情况
//        QStandardItem* aItem=themodel->item(1,2); //最后一列是逻辑型
//        if (aItem->checkState()==Qt::Checked){
//            //这里就是对勾选中的单元格进行的操作
//        }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dealTimeout()
{
    //修改表格内容
    for(int i=0;i<themodel->rowCount();i++){
        for(int j=0;j<themodel->columnCount();j++){
            themodel->setData(themodel->index(i,j),myCount,Qt::DisplayRole);
        }
    }
    myCount++;
}

void MainWindow::on_pushButton_released()
{
    if(myTimer->isActive() == false){
        myTimer->start(50);
    }

}
