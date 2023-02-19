/********************************************************************************
** Form generated from reading UI file 'udpwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UDPWIDGET_H
#define UI_UDPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UDPWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QTextEdit *textEdit;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *UDPWidget)
    {
        if (UDPWidget->objectName().isEmpty())
            UDPWidget->setObjectName(QString::fromUtf8("UDPWidget"));
        UDPWidget->resize(800, 600);
        widget = new QWidget(UDPWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(70, 20, 581, 521));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEditIP = new QLineEdit(widget);
        lineEditIP->setObjectName(QString::fromUtf8("lineEditIP"));

        gridLayout->addWidget(lineEditIP, 0, 1, 1, 2);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEditPort = new QLineEdit(widget);
        lineEditPort->setObjectName(QString::fromUtf8("lineEditPort"));

        gridLayout->addWidget(lineEditPort, 1, 1, 1, 2);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        gridLayout->addWidget(textEdit, 2, 0, 1, 4);

        pushButtonSend = new QPushButton(widget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 3, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(168, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 3, 2, 1, 1);

        pushButtonClose = new QPushButton(widget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 3, 3, 1, 1);


        retranslateUi(UDPWidget);

        QMetaObject::connectSlotsByName(UDPWidget);
    } // setupUi

    void retranslateUi(QWidget *UDPWidget)
    {
        UDPWidget->setWindowTitle(QApplication::translate("UDPWidget", "UDPWidget", nullptr));
        label->setText(QApplication::translate("UDPWidget", "\345\257\271\346\226\271\347\232\204IP\357\274\232", nullptr));
        label_2->setText(QApplication::translate("UDPWidget", "\345\257\271\346\226\271\347\232\204\347\253\257\345\217\243\345\217\267\357\274\232", nullptr));
        pushButtonSend->setText(QApplication::translate("UDPWidget", "send", nullptr));
        pushButtonClose->setText(QApplication::translate("UDPWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UDPWidget: public Ui_UDPWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UDPWIDGET_H
