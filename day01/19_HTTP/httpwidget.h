#ifndef HTTPWIDGET_H
#define HTTPWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class HTTPWidget; }
QT_END_NAMESPACE

class HTTPWidget : public QWidget
{
    Q_OBJECT

public:
    HTTPWidget(QWidget *parent = nullptr);
    ~HTTPWidget();

private:
    Ui::HTTPWidget *ui;
};
#endif // HTTPWIDGET_H
