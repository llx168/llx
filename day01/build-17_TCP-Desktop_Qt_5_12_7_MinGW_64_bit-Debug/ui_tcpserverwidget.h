/********************************************************************************
** Form generated from reading UI file 'tcpserverwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TCPSERVERWIDGET_H
#define UI_TCPSERVERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TCPServerWidget
{
public:
    QWidget *widget;
    QGridLayout *gridLayout;
    QTextEdit *textEditRead;
    QTextEdit *textEditWrite;
    QPushButton *pushButtonSend;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonClose;

    void setupUi(QWidget *TCPServerWidget)
    {
        if (TCPServerWidget->objectName().isEmpty())
            TCPServerWidget->setObjectName(QString::fromUtf8("TCPServerWidget"));
        TCPServerWidget->resize(656, 499);
        widget = new QWidget(TCPServerWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(60, 20, 558, 426));
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        textEditRead = new QTextEdit(widget);
        textEditRead->setObjectName(QString::fromUtf8("textEditRead"));
        textEditRead->setReadOnly(true);

        gridLayout->addWidget(textEditRead, 0, 0, 1, 3);

        textEditWrite = new QTextEdit(widget);
        textEditWrite->setObjectName(QString::fromUtf8("textEditWrite"));

        gridLayout->addWidget(textEditWrite, 1, 0, 1, 3);

        pushButtonSend = new QPushButton(widget);
        pushButtonSend->setObjectName(QString::fromUtf8("pushButtonSend"));

        gridLayout->addWidget(pushButtonSend, 2, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(358, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 2, 1, 1, 1);

        pushButtonClose = new QPushButton(widget);
        pushButtonClose->setObjectName(QString::fromUtf8("pushButtonClose"));

        gridLayout->addWidget(pushButtonClose, 2, 2, 1, 1);


        retranslateUi(TCPServerWidget);

        QMetaObject::connectSlotsByName(TCPServerWidget);
    } // setupUi

    void retranslateUi(QWidget *TCPServerWidget)
    {
        TCPServerWidget->setWindowTitle(QApplication::translate("TCPServerWidget", "TCPServerWidget", nullptr));
        pushButtonSend->setText(QApplication::translate("TCPServerWidget", "send", nullptr));
        pushButtonClose->setText(QApplication::translate("TCPServerWidget", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TCPServerWidget: public Ui_TCPServerWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TCPSERVERWIDGET_H
