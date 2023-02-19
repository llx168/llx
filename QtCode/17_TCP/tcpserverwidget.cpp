#include "tcpserverwidget.h"
#include "ui_tcpserverwidget.h"

TCPServerWidget::TCPServerWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TCPServerWidget)
{
    ui->setupUi(this);
    setWindowTitle("服务器端");
    tcpSocket = NULL;
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any,8888);
    connect(tcpServer,&QTcpServer::newConnection,
            [=]()
    {
        tcpSocket = tcpServer->nextPendingConnection();
        QString IP = tcpSocket->peerAddress().toString();
        qint16 port = tcpSocket->peerPort();
        QString temp = QString("[%1:%2]:连接成功").arg(IP).arg(port);
        ui->textEditRead->setText(temp);

        connect(tcpSocket,&QTcpSocket::readyRead,
                [=]()
        {
            QByteArray array = tcpSocket->readAll();
            ui->textEditRead->append(array);
        }
                );

    }
            );


}

TCPServerWidget::~TCPServerWidget()
{
    delete ui;
}


void TCPServerWidget::on_pushButtonSend_released()
{
    if(NULL==tcpSocket){
        return;
    }
    //获取编辑区的内容
    QString str = ui->textEditWrite->toPlainText();
    //使用tcpSocket套接字
    tcpSocket->write(str.toUtf8().data());
}

void TCPServerWidget::on_pushButtonClose_released()
{
    //主动和客户端断开连接
    if(NULL==tcpSocket){
        return;
    }
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
    tcpSocket = NULL;

}
