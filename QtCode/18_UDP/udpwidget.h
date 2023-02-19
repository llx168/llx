#ifndef UDPWIDGET_H
#define UDPWIDGET_H

#include <QWidget>
#include <QUdpSocket>

QT_BEGIN_NAMESPACE
namespace Ui { class UDPWidget; }
QT_END_NAMESPACE

class UDPWidget : public QWidget
{
    Q_OBJECT

public:
    UDPWidget(QWidget *parent = nullptr);
    ~UDPWidget();

private slots:
    void on_pushButtonSend_clicked();

private:
    Ui::UDPWidget *ui;
    QUdpSocket *udpSocket;
};
#endif // UDPWIDGET_H
