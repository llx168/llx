/********************************************************************************
** Form generated from reading UI file 'showparadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPARADIALOG_H
#define UI_SHOWPARADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ShowParaDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label_4;

    void setupUi(QDialog *ShowParaDialog)
    {
        if (ShowParaDialog->objectName().isEmpty())
            ShowParaDialog->setObjectName(QString::fromUtf8("ShowParaDialog"));
        ShowParaDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(ShowParaDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(ShowParaDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(60, 40, 271, 141));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 68, 15));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 20, 113, 15));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 50, 68, 15));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(90, 50, 113, 15));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 80, 68, 15));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(90, 80, 113, 15));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(90, 110, 113, 15));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 110, 68, 15));

        retranslateUi(ShowParaDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ShowParaDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ShowParaDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShowParaDialog);
    } // setupUi

    void retranslateUi(QDialog *ShowParaDialog)
    {
        ShowParaDialog->setWindowTitle(QApplication::translate("ShowParaDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("ShowParaDialog", "\346\204\237\345\205\264\350\266\243\345\214\272\345\237\237", nullptr));
        label->setText(QApplication::translate("ShowParaDialog", "\350\265\267\345\247\213\350\247\222\345\272\246\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ShowParaDialog", "\347\273\210\346\255\242\350\247\222\345\272\246\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ShowParaDialog", "\350\265\267\345\247\213\350\267\235\347\246\273\357\274\232", nullptr));
        lineEdit_4->setText(QString());
        label_4->setText(QApplication::translate("ShowParaDialog", "\347\273\210\346\255\242\350\267\235\347\246\273\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ShowParaDialog: public Ui_ShowParaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPARADIALOG_H
