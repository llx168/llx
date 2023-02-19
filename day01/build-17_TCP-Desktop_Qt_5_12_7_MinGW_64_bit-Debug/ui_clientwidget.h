/********************************************************************************
** Form generated from reading UI file 'clientwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTWIDGET_H
#define UI_CLIENTWIDGET_H

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

class Ui_ClientWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lineEditIP;
    QLabel *label_2;
    QLineEdit *lineEditPort;
    QPushButton *pushButtonConnect;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *ClientWidget)
    {
        if (ClientWidget->objectName().isEmpty())
            ClientWidget->setObjectName(QString::fromUtf8("ClientWidget"));
        ClientWidget->resize(502, 530);
        widget = new QWidget(ClientWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 458, 487));
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

        pushButtonConnect = new QPushButton(widget);
        pushButtonConnect->setObjectName(QString::fromUtf8("pushButtonConnect"));

        gridLayout->addWidget(pushButtonConnect, 1, 3, 1, 1);

        textEditRead = new QTextEdit(widget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 2, 0, 1, 4);

        textEditWrite = new QTextEdit(widget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 3, 0, 1, 4);

        pushButtonSend = new QPushButton(widget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 4, 0, 1, 2);

        horizontalSpacer = new QSpacerItem(258, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 4, 2, 1, 1);

        pushButtonClose = new QPushButton(widget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 4, 3, 1, 1);


        retranslateUi(ClientWidget);

        QMetaObject::connectSlotsByName(ClientWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientWidget)
    {
        ClientWidget->setWindowTitle(QApplication::translate("ClientWidget", "Form", nullptr));
        label->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250IP:", nullptr));
        lineEditIP->setText(QApplication::translate("ClientWidget", "127.0.0.1", nullptr));
        label_2->setText(QApplication::translate("ClientWidget", "\346\234\215\345\212\241\345\231\250\347\253\257\345\217\243:", nullptr));
        lineEditPort->setText(QApplication::translate("ClientWidget", "8888", nullptr));
        pushButtonConnect->setText(QApplication::translate("ClientWidget", "connect", nullptr));
        pushButtonSend->setText(QApplication::translate("ClientWidget", "send", nullptr));
        pushButtonClose->setText(QApplication::translate("ClientWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientWidget: public Ui_ClientWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTWIDGET_H
