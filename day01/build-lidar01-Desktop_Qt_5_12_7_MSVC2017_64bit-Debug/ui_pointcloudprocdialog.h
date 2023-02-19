/********************************************************************************
** Form generated from reading UI file 'pointcloudprocdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POINTCLOUDPROCDIALOG_H
#define UI_POINTCLOUDPROCDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>

QT_BEGIN_NAMESPACE

class Ui_PointCloudProcDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_5;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_6;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_7;

    void setupUi(QDialog *PointCloudProcDialog)
    {
        if (PointCloudProcDialog->objectName().isEmpty())
            PointCloudProcDialog->setObjectName(QString::fromUtf8("PointCloudProcDialog"));
        PointCloudProcDialog->resize(520, 566);
        buttonBox = new QDialogButtonBox(PointCloudProcDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(70, 510, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(PointCloudProcDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(50, 30, 381, 171));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 30, 261, 19));
        checkBox_2 = new QCheckBox(groupBox);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(30, 60, 261, 19));
        checkBox_3 = new QCheckBox(groupBox);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(30, 90, 261, 19));
        checkBox_4 = new QCheckBox(groupBox);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(30, 120, 261, 19));
        groupBox_2 = new QGroupBox(PointCloudProcDialog);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(60, 230, 371, 80));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 30, 321, 19));
        groupBox_3 = new QGroupBox(PointCloudProcDialog);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(60, 330, 371, 80));
        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(20, 30, 321, 19));
        groupBox_4 = new QGroupBox(PointCloudProcDialog);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(60, 420, 371, 80));
        checkBox_7 = new QCheckBox(groupBox_4);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(20, 30, 321, 19));

        retranslateUi(PointCloudProcDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), PointCloudProcDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PointCloudProcDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(PointCloudProcDialog);
    } // setupUi

    void retranslateUi(QDialog *PointCloudProcDialog)
    {
        PointCloudProcDialog->setWindowTitle(QApplication::translate("PointCloudProcDialog", "Dialog", nullptr));
        groupBox->setTitle(QApplication::translate("PointCloudProcDialog", "\345\237\272\347\241\200\347\202\271\344\272\221\347\256\227\346\263\225", nullptr));
        checkBox->setText(QApplication::translate("PointCloudProcDialog", "\345\216\273\351\231\244\347\202\271\344\272\221\345\274\202\345\270\270\345\201\217\345\267\256\345\200\274", nullptr));
        checkBox_2->setText(QApplication::translate("PointCloudProcDialog", "\345\257\271\347\274\272\345\244\261\347\232\204\347\202\271\344\272\221\346\225\260\346\215\256\350\277\233\350\241\214\350\241\245\345\201\277", nullptr));
        checkBox_3->setText(QApplication::translate("PointCloudProcDialog", "\345\257\271\346\234\211\345\231\252\345\243\260\347\232\204\347\202\271\344\272\221\346\225\260\346\215\256\350\277\233\350\241\214\345\271\263\346\273\221\346\273\244\346\263\242", nullptr));
        checkBox_4->setText(QApplication::translate("PointCloudProcDialog", "\345\257\271\347\202\271\344\272\221\346\225\260\346\215\256\350\277\233\350\241\214\345\210\206\345\211\262\345\210\244\346\226\255\345\222\214\345\210\206\347\273\204", nullptr));
        groupBox_2->setTitle(QApplication::translate("PointCloudProcDialog", "\345\271\263\351\235\242\346\225\260\346\215\256\350\236\215\345\220\210\347\256\227\346\263\225", nullptr));
        checkBox_5->setText(QApplication::translate("PointCloudProcDialog", "\345\257\271\345\244\232\345\217\260\346\277\200\345\205\211\351\233\267\350\276\276\347\232\204\347\202\271\344\272\221\346\225\260\346\215\256\350\277\233\350\241\214\345\220\214\346\255\245\345\222\214\345\205\263\350\201\224", nullptr));
        groupBox_3->setTitle(QApplication::translate("PointCloudProcDialog", "\344\270\211\347\273\264\347\233\256\346\240\207\346\243\200\346\265\213\347\202\271\344\272\221\347\256\227\346\263\225", nullptr));
        checkBox_6->setText(QApplication::translate("PointCloudProcDialog", "\350\257\206\345\210\253\347\202\271\344\272\221\346\225\260\346\215\256\345\210\206\347\273\204\347\232\204\347\211\251\344\275\223\350\275\256\345\273\223", nullptr));
        groupBox_4->setTitle(QApplication::translate("PointCloudProcDialog", "\344\270\211\347\273\264\347\233\256\346\240\207\350\267\237\350\270\252\347\202\271\344\272\221\347\256\227\346\263\225", nullptr));
        checkBox_7->setText(QApplication::translate("PointCloudProcDialog", "\350\216\267\345\217\226\347\233\256\346\240\207\347\232\204\350\277\236\347\273\255\350\277\220\345\212\250\350\275\250\350\277\271\347\202\271\344\272\221\346\225\260\346\215\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PointCloudProcDialog: public Ui_PointCloudProcDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POINTCLOUDPROCDIALOG_H
