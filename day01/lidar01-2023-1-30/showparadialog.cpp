#include "showparadialog.h"
#include "ui_showparadialog.h"

ShowParaDialog::ShowParaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowParaDialog)
{
    ui->setupUi(this);
    //只能输入数字
    ui->lineEdit_5->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_6->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_7->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_8->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_9->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_10->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_11->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
}

ShowParaDialog::~ShowParaDialog()
{
    delete ui;
}

void ShowParaDialog::on_pushButton_released()
{
    showPara.bgColorR = ui->lineEdit_5->text().toFloat()/255.0;
    showPara.bgColorG = ui->lineEdit_8->text().toFloat()/255.0;
    showPara.bgColorB = ui->lineEdit_9->text().toFloat()/255.0;
    showPara.pointColorR = ui->lineEdit_7->text().toInt();
    showPara.pointColorG = ui->lineEdit_11->text().toInt();
    showPara.pointColorB = ui->lineEdit_10->text().toInt();
    if(ui->lineEdit_6->text().toInt()==0){
        showPara.pointSize = 1;
    }else{
        showPara.pointSize = ui->lineEdit_6->text().toInt();
    }
    emit showParaSignal(showPara);
    this->close();
}

void ShowParaDialog::on_pushButton_3_released()
{

    ShowPara show;
    showPara.bgColorR = show.bgColorR/255.0;
    showPara.bgColorG = show.bgColorG/255.0;
    showPara.bgColorB = show.bgColorB/255.0;
    showPara.pointColorR = show.pointColorR;
    showPara.pointColorG = show.pointColorG;
    showPara.pointColorB = show.pointColorB;
    showPara.pointSize = show.pointSize;
    emit showParaSignal(showPara);
}

void ShowParaDialog::on_pushButton_2_released()
{
    this->close();
}
