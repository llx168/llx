/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionopen;
    QAction *actionnew;
    QAction *actionclose;
    QWidget *centralwidget;
    QPushButton *myButton;
    QLabel *labelImage;
    QLabel *labelText;
    QLabel *labelGraph;
    QMenuBar *menubar;
    QMenu *menufile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionopen = new QAction(MainWindow);
        actionopen->setObjectName(QString::fromUtf8("actionopen"));
        actionnew = new QAction(MainWindow);
        actionnew->setObjectName(QString::fromUtf8("actionnew"));
        actionclose = new QAction(MainWindow);
        actionclose->setObjectName(QString::fromUtf8("actionclose"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        myButton = new QPushButton(centralwidget);
        myButton->setObjectName(QString::fromUtf8("myButton"));
        myButton->setGeometry(QRect(30, 40, 93, 28));
        labelImage = new QLabel(centralwidget);
        labelImage->setObjectName(QString::fromUtf8("labelImage"));
        labelImage->setGeometry(QRect(390, 130, 151, 191));
        labelImage->setPixmap(QPixmap(QString::fromUtf8(":/image/lidar.jpg")));
        labelText = new QLabel(centralwidget);
        labelText->setObjectName(QString::fromUtf8("labelText"));
        labelText->setGeometry(QRect(100, 210, 68, 15));
        labelGraph = new QLabel(centralwidget);
        labelGraph->setObjectName(QString::fromUtf8("labelGraph"));
        labelGraph->setGeometry(QRect(350, 20, 181, 91));
        labelGraph->setPixmap(QPixmap(QString::fromUtf8(":/image/lidar.jpg")));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menufile = new QMenu(menubar);
        menufile->setObjectName(QString::fromUtf8("menufile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menufile->menuAction());
        menufile->addAction(actionopen);
        menufile->addAction(actionnew);
        menufile->addSeparator();
        menufile->addAction(actionclose);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionopen->setText(QApplication::translate("MainWindow", "open", nullptr));
        actionnew->setText(QApplication::translate("MainWindow", "new", nullptr));
        actionclose->setText(QApplication::translate("MainWindow", "close", nullptr));
        myButton->setText(QApplication::translate("MainWindow", "hello", nullptr));
        labelImage->setText(QString());
        labelText->setText(QApplication::translate("MainWindow", "TextLabel", nullptr));
        labelGraph->setText(QString());
        menufile->setTitle(QApplication::translate("MainWindow", "file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
