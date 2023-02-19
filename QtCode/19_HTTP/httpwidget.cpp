#include "httpwidget.h"
#include "ui_httpwidget.h"

HTTPWidget::HTTPWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HTTPWidget)
{
    ui->setupUi(this);
}

HTTPWidget::~HTTPWidget()
{
    delete ui;
}

