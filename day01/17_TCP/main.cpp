#include "tcpserverwidget.h"

#include <QApplication>
#include <clientwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TCPServerWidget w;
    w.show();
    ClientWidget client;
    client.show();
    return a.exec();
}
