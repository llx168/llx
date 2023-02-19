#include "udpwidget.h"
#include "ui_udpwidget.h"
#include <QHostAddress>

UDPWidget::UDPWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UDPWidget)
{
    ui->setupUi(this);
    //分配空间，指定父对象
    udpSocket = new QUdpSocket(this);

    //绑定
    udpSocket->bind(8888);

    setWindowTitle("服务器端口为：8888");
    //当对方成功发送数据过来，自动触发 readyRead()
    connect(udpSocket,&QUdpSocket::readyRead,
            [=]()
    {
        //读取对方发送的内容
        char buf[1024]={0};
        QHostAddress cliAddr;//对方地址
        quint16 port; //对方端口
        qint64 len = udpSocket->readDatagram(buf,sizeof(buf),&cliAddr,&port);

        if(len>0){
            //格式化
            QString str = QString("[%1:%2] %3")
                    .arg(cliAddr.toString())
                    .arg(port)
                    .arg(buf);
            //编辑区设置内容
            ui->textEdit->setText(str);

        }
    }
            );
}

UDPWidget::~UDPWidget()
{
    delete ui;
}


void UDPWidget::on_pushButtonSend_clicked()
{
    //先获取对方的ip和端口号
    QString ip = ui->lineEditIP->text();
    qint16 port = ui->lineEditPort->text().toInt();
    if(NULL==ip || NULL==port){
        return;
    }

    //获取编辑区内容
    QString str = ui->textEdit->toPlainText();

    //给指定的IP发送数据
    udpSocket->writeDatagram(str.toUtf8(),QHostAddress(ip),port);

}
