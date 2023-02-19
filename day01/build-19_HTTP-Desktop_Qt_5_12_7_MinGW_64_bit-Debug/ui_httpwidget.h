/********************************************************************************
** Form generated from reading UI file 'httpwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HTTPWIDGET_H
#define UI_HTTPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HTTPWidget
{
public:

    void setupUi(QWidget *HTTPWidget)
    {
        if (HTTPWidget->objectName().isEmpty())
            HTTPWidget->setObjectName(QString::fromUtf8("HTTPWidget"));
        HTTPWidget->resize(800, 600);

        retranslateUi(HTTPWidget);

        QMetaObject::connectSlotsByName(HTTPWidget);
    } // setupUi

    void retranslateUi(QWidget *HTTPWidget)
    {
        HTTPWidget->setWindowTitle(QApplication::translate("HTTPWidget", "HTTPWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HTTPWidget: public Ui_HTTPWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HTTPWIDGET_H
