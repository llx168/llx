#ifndef TCPSERVERWIDGET_H
#define TCPSERVERWIDGET_H

#include <QWidget>
#include <QTcpServer>
#include <QTcpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class TCPServerWidget; }
QT_END_NAMESPACE

class TCPServerWidget : public QWidget
{
    Q_OBJECT

public:
    TCPServerWidget(QWidget *parent = nullptr);
    ~TCPServerWidget();

private slots:
    void on_pushButtonSend_released();

    void on_pushButtonClose_released();

private:
    Ui::TCPServerWidget *ui;
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
};
#endif // TCPSERVERWIDGET_H
