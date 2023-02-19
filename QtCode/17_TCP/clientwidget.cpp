#include "clientwidget.h"
#include "ui_clientwidget.h"
#include <QHostAddress>

ClientWidget::ClientWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ClientWidget)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    setWindowTitle("客户端");

    connect(tcpSocket,&QTcpSocket::connected,
            [=]()
    {
        ui->textEditRead->setText("成功和服务器建立连接");


    }
            );
    connect(tcpSocket,&QTcpSocket::readyRead,
            [=]()
    {
        //获取对方发送的内容
        QByteArray byteArray = tcpSocket->readAll();
        ui->textEditRead->append(byteArray);

    }
            );
}

ClientWidget::~ClientWidget()
{
    delete ui;
}

void ClientWidget::on_pushButtonConnect_clicked()
{
    QString IP = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();

    //主动和服务器建立连接
    tcpSocket->connectToHost(QHostAddress(IP),port);
}

void ClientWidget::on_pushButtonSend_clicked()
{
    QString str = ui->textEditWrite->toPlainText();
    //发送数据
    tcpSocket->write(str.toUtf8().data());

}

void ClientWidget::on_pushButtonClose_clicked()
{
    //主动和对方断开连接
    tcpSocket->disconnectFromHost();
    tcpSocket->close();
}
