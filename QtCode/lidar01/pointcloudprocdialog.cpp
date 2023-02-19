#include "pointcloudprocdialog.h"
#include "ui_pointcloudprocdialog.h"

PointCloudProcDialog::PointCloudProcDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PointCloudProcDialog)
{
    ui->setupUi(this);
}

PointCloudProcDialog::~PointCloudProcDialog()
{
    delete ui;
}
