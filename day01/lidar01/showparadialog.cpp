#include "showparadialog.h"
#include "ui_showparadialog.h"

ShowParaDialog::ShowParaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShowParaDialog)
{
    ui->setupUi(this);
}

ShowParaDialog::~ShowParaDialog()
{
    delete ui;
}
