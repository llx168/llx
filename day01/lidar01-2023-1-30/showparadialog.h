#ifndef SHOWPARADIALOG_H
#define SHOWPARADIALOG_H

#include <QDialog>

namespace Ui {
class ShowParaDialog;
}

typedef struct
{
    //背景色
    float bgColorR=70;
    float bgColorG=70;
    float bgColorB=70;
    //点云颜色
    int pointColorR=255;
    int pointColorG=0;
    int pointColorB=0;
    //点云单点尺寸
    int pointSize=4;
}ShowPara;

class ShowParaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowParaDialog(QWidget *parent = nullptr);
    ~ShowParaDialog();

signals:
    void showParaSignal(ShowPara s);

private slots:
    void on_pushButton_released();

    void on_pushButton_3_released();

    void on_pushButton_2_released();

private:
    Ui::ShowParaDialog *ui;
    ShowPara showPara;
};

#endif // SHOWPARADIALOG_H
