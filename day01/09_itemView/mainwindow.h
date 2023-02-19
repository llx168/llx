#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QTimer>//定时器头文件

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

private slots:
    void on_pushButton_released();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *themodel;
    QTimer *myTimer;
    int myCount=0;
};
#endif // MAINWINDOW_H
