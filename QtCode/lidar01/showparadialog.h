#ifndef SHOWPARADIALOG_H
#define SHOWPARADIALOG_H

#include <QDialog>

namespace Ui {
class ShowParaDialog;
}

class ShowParaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ShowParaDialog(QWidget *parent = nullptr);
    ~ShowParaDialog();

private:
    Ui::ShowParaDialog *ui;
};

#endif // SHOWPARADIALOG_H
