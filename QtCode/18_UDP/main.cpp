#include "udpwidget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UDPWidget w;
    w.show();
    return a.exec();
}
