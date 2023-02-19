#include "widget.h"
#include "ui_widget.h"
#include <QSqlDatabase>
#include <QtDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariantList>//泛型

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //打印Qt支持的数据库驱动
    qDebug()<<QSqlDatabase::drivers();

    //添加mysql数据库
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("127.0.0.1");//数据库服务器IP
    db.setUserName("root");//数据库用户名
    db.setPassword("123456");//密码
    db.setDatabaseName("info");//使用哪个数据库

    //打开数据库
    if(!db.open())//数据库打开失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }

    QSqlQuery query;
    query.exec("sql语句");//增删改查
    //批量插入
    //odbc风格
    //预处理语句
    //?相当于占位符
   /* query.prepare("insert into student(name,age,score) values(?,?,?)");
    //给字段设置内容 list
    QVariantList nameList;
    nameList << "zhangsan" << "lisi";
    QVariantList ageList;
    ageList<<11<<22<<33;
    QVariantList scoreList;
    scoreList<<59<<69<<99;
    //给字段绑定相应的值 按顺序绑定
    query.addBindValue(nameList);
    query.addBindValue(ageList);
    query.addBindValue(scoreList);
    //执行预处理命令
    query.execBatch();*/

    //oracle风格
    //占位符 : + 自定义名字
    query.prepare("insert into student(name,age,score) values(:name,:age,:score)");
    //给字段设置内容 list
    QVariantList nameList;
    nameList << "zhangsan" << "lisi";
    QVariantList ageList;
    ageList<<11<<22<<33;
    QVariantList scoreList;
    scoreList<<59<<69<<99;
    //给字段绑定,相当于map
    query.bindValue(":name",nameList);
    query.bindValue(":age",ageList);
    query.bindValue(":score",scoreList);
    //执行预处理命令
    query.execBatch();

    //查询
    query.exec("select * from student");

    while (query.next()) {//一行一行遍历
        //取出当前行的内容
        qDebug()<<query.value(0).toInt()//第一列
               <<query.value(1).toString()//第二列
              <<query.value("age").toInt()
             <<query.value("score").toInt();

    }


/*
    //多个个数据库
    QSqlDatabase db1 = QSqlDatabase::addDatabase("QMYSQL");
    //连接数据库
    db.setHostName("127.0.0.1");//数据库服务器IP
    db.setUserName("root");//数据库用户名
    db.setPassword("123456");//密码
    db.setDatabaseName("test");//使用哪个数据库
    //打开数据库
    if(!db1.open())//数据库打开失败
    {
        QMessageBox::warning(this,"错误",db.lastError().text());
        return;
    }
    QSqlQuery query1(db1);
    query1.exec("sql语句");
    */

}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{
    //获取行编辑内容
    QString name = ui->lineEdit->text();
     QString sql = QString("delete from student where name = '%1'").arg(name);
    //开启一个事物
    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.exec(sql);

}

void Widget::on_pushButton_2_clicked()
{
    //确定删除
    QSqlDatabase::database().commit();

}

void Widget::on_pushButton_3_clicked()
{
    //回滚，撤销
     QSqlDatabase::database().rollback();

}
