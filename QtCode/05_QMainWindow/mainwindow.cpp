#include "mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QDebug>
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QTextEdit>
#include <QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(500,500);
    //菜单栏
    //工具栏
    //状态栏
    //核心控件
    //浮动窗口

    //菜单栏
    QMenuBar *mBar = menuBar();
    //添加菜单
    QMenu *pFile = mBar->addMenu("文件");
    //添加菜单项，添加动作
    QAction *pNew = pFile->addAction("新建");

    connect(pNew,&QAction::triggered,
            [=]()
    {
        qDebug()<<"按下了新建";
    }
            );
    //添加分割线
    pFile->addSeparator();
    QAction *pOpen = pFile->addAction("打开");

    //工具栏，菜单栏的快捷方式
    QToolBar *toolBar = addToolBar("toolBar");
    //工具栏上添加快捷方式
    toolBar->addAction(pNew);

    QPushButton *p1 = new QPushButton(this);
    p1->setText("打开");
    //工具栏上添加一个控件
    toolBar->addWidget(p1);

    connect(p1,&QPushButton::clicked,
            [=](){
        p1->setText("@_@");
    }
            );

    //状态栏
    QStatusBar *staBar = statusBar();
    QLabel *label = new QLabel(staBar);
    label->setText("status is ok");
    staBar->addWidget(staBar);//从左往右添加
    staBar->addPermanentWidget(new QLabel("hello",this));//从右往左添加


    //核心控件
    QTextEdit *tEdit = new QTextEdit(this);
    setCentralWidget(tEdit);

    //浮动窗口
    QDockWidget *dock = new QDockWidget(this);
//    addDockWidget(1,1)写上参数再按F1看帮助文档，不然看不到有参数的函数
    addDockWidget(Qt::RightDockWidgetArea,dock);
    QTextEdit *tEdit1 = new QTextEdit(this);
    dock->setWidget(tEdit1);





}

MainWindow::~MainWindow()
{
}

