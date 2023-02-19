#ifndef POINTCLOUDPROCDIALOG_H
#define POINTCLOUDPROCDIALOG_H

#include <QDialog>

namespace Ui {
class PointCloudProcDialog;
}

class PointCloudProcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PointCloudProcDialog(QWidget *parent = nullptr);
    ~PointCloudProcDialog();

private:
    Ui::PointCloudProcDialog *ui;
};

#endif // POINTCLOUDPROCDIALOG_H
