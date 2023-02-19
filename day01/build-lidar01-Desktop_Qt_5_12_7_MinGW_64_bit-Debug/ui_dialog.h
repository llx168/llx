/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
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
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_6;
    QLabel *label_8;
    QComboBox *comboBox_2;
    QLineEdit *lineEdit_7;
    QLabel *label_9;
    QPushButton *pushButton;
    QLabel *label_4;
    QComboBox *comboBox;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(605, 386);
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(190, 300, 341, 31));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(30, 60, 541, 181));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 61, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(80, 30, 141, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(310, 30, 81, 16));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(410, 30, 113, 21));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 60, 71, 16));
        lineEdit_3 = new QLineEdit(groupBox);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(80, 60, 141, 21));
        lineEdit_4 = new QLineEdit(groupBox);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(410, 60, 113, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(300, 60, 101, 20));
        lineEdit_5 = new QLineEdit(groupBox);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(80, 90, 141, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 90, 71, 16));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 90, 121, 20));
        lineEdit_6 = new QLineEdit(groupBox);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(410, 90, 113, 21));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 130, 71, 16));
        comboBox_2 = new QComboBox(groupBox);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(90, 125, 87, 22));
        lineEdit_7 = new QLineEdit(groupBox);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));
        lineEdit_7->setGeometry(QRect(410, 120, 113, 21));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(280, 120, 121, 20));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(210, 299, 93, 28));
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(110, 20, 101, 16));
        comboBox = new QComboBox(Dialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(220, 20, 87, 22));

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("Dialog", "\351\233\267\350\276\276\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("Dialog", "\351\233\267\350\276\276IP\357\274\232", nullptr));
        label_2->setText(QApplication::translate("Dialog", "\351\233\267\350\276\276\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Dialog", "\344\270\212\344\275\215\346\234\272IP\357\274\232", nullptr));
        lineEdit_4->setText(QString());
        label_5->setText(QApplication::translate("Dialog", "\344\270\212\344\275\215\346\234\272\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        lineEdit_5->setText(QString());
        label_6->setText(QApplication::translate("Dialog", "mac\345\234\260\345\235\200\357\274\232", nullptr));
        label_7->setText(QApplication::translate("Dialog", "\346\225\260\346\215\256\345\214\205\346\227\266\351\227\264\351\227\264\351\232\224\357\274\232", nullptr));
        lineEdit_6->setText(QString());
        label_8->setText(QApplication::translate("Dialog", "\347\224\265\346\234\272\350\275\254\351\200\237\357\274\232", nullptr));
        comboBox_2->setItemText(0, QApplication::translate("Dialog", "5HZ", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("Dialog", "10HZ", nullptr));

        lineEdit_7->setText(QString());
        label_9->setText(QApplication::translate("Dialog", "\345\215\225\347\202\271\346\265\213\350\267\235\350\247\222\345\272\246\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("Dialog", "\350\216\267\345\217\226\345\217\202\346\225\260", nullptr));
        label_4->setText(QApplication::translate("Dialog", "\351\200\211\346\213\251\351\200\232\350\256\257\346\226\271\345\274\217", nullptr));
        comboBox->setItemText(0, QApplication::translate("Dialog", "\344\270\262\345\217\243", nullptr));
        comboBox->setItemText(1, QApplication::translate("Dialog", "\347\275\221\345\217\243", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
