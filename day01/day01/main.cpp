#include "mymainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MyMainWindow w;
//    w.setWindowTitle("my window");
//    w.show();
    QWidget w;
    w.setWindowTitle("2 window");
    QPushButton p;
    p.setText("button aa");
    p.setParent(&w);
    p.move(200,200);
    QPushButton p2(&w);
    p2.setText("second");

    w.show();
    return a.exec();
}
