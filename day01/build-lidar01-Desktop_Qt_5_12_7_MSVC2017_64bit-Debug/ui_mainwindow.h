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
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qvtkwidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_17;
    QPushButton *pushButton_18;
    QPushButton *pushButton_16;
    QPushButton *pushButton_15;
    QWidget *tab_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *tab_4;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_3;
    QPushButton *pushButton_14;
    QWidget *tab_2;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QWidget *tab_5;
    QPushButton *pushButton_10;
    QSplitter *splitter;
    QTableView *tableView;
    QVTKWidget *qvtkwidget;
    QTableView *tableView_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1147, 879);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 70));
        tabWidget->setMaximumSize(QSize(16777215, 70));
        tabWidget->setBaseSize(QSize(1000, 300));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 3, 616, 33));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setMinimumSize(QSize(0, 0));

        horizontalLayout_2->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        pushButton_17 = new QPushButton(widget);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        horizontalLayout_2->addWidget(pushButton_17);

        pushButton_18 = new QPushButton(widget);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        horizontalLayout_2->addWidget(pushButton_18);

        pushButton_16 = new QPushButton(widget);
        pushButton_16->setObjectName(QString::fromUtf8("pushButton_16"));

        horizontalLayout_2->addWidget(pushButton_16);

        pushButton_15 = new QPushButton(widget);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        horizontalLayout_2->addWidget(pushButton_15);

        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        layoutWidget = new QWidget(tab_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1, 3, 426, 33));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_7 = new QPushButton(layoutWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(layoutWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);

        pushButton_9 = new QPushButton(layoutWidget);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout->addWidget(pushButton_9);

        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        layoutWidget1 = new QWidget(tab_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 0, 189, 33));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);

        pushButton_14 = new QPushButton(layoutWidget1);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        horizontalLayout_3->addWidget(pushButton_14);

        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        layoutWidget2 = new QWidget(tab_2);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 0, 254, 33));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_11 = new QPushButton(layoutWidget2);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout_4->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(layoutWidget2);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        horizontalLayout_4->addWidget(pushButton_12);

        pushButton_13 = new QPushButton(layoutWidget2);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        horizontalLayout_4->addWidget(pushButton_13);

        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        pushButton_10 = new QPushButton(tab_5);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(10, 4, 61, 31));
        tabWidget->addTab(tab_5, QString());

        verticalLayout->addWidget(tabWidget);

        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tableView = new QTableView(splitter);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setMaximumSize(QSize(10000, 16777215));
        splitter->addWidget(tableView);
        qvtkwidget = new QVTKWidget(splitter);
        qvtkwidget->setObjectName(QString::fromUtf8("qvtkwidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(qvtkwidget->sizePolicy().hasHeightForWidth());
        qvtkwidget->setSizePolicy(sizePolicy1);
        qvtkwidget->setMaximumSize(QSize(10000, 16777215));
        splitter->addWidget(qvtkwidget);
        tableView_2 = new QTableView(splitter);
        tableView_2->setObjectName(QString::fromUtf8("tableView_2"));
        tableView_2->setMaximumSize(QSize(1000, 16777215));
        splitter->addWidget(tableView_2);

        verticalLayout->addWidget(splitter);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton_4->setText(QApplication::translate("MainWindow", "\351\233\267\350\276\276\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "\345\201\234\346\255\242", nullptr));
        pushButton_17->setText(QApplication::translate("MainWindow", "\346\267\273\345\212\240\350\256\276\345\244\207", nullptr));
        pushButton_18->setText(QApplication::translate("MainWindow", "\345\210\240\351\231\244\350\256\276\345\244\207", nullptr));
        pushButton_16->setText(QApplication::translate("MainWindow", "\346\233\264\346\226\260\350\256\276\345\244\207", nullptr));
        pushButton_15->setText(QApplication::translate("MainWindow", "\350\256\276\345\244\207\346\230\276\347\244\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "  \351\233\267\350\276\276  ", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\351\233\267\350\276\276\346\225\260\346\215\256", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\345\217\202\346\225\260", nullptr));
        pushButton_7->setText(QApplication::translate("MainWindow", "\345\235\220\346\240\207\350\275\264", nullptr));
        pushButton_8->setText(QApplication::translate("MainWindow", "\347\275\221\346\240\274\347\272\277", nullptr));
        pushButton_9->setText(QApplication::translate("MainWindow", "\345\215\225\347\202\271\346\265\213\350\267\235", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "\346\230\276\347\244\272\350\256\276\347\275\256", nullptr));
        pushButton_3->setText(QApplication::translate("MainWindow", "\347\202\271\344\272\221\346\225\260\346\215\256\345\244\204\347\220\206", nullptr));
        pushButton_14->setText(QApplication::translate("MainWindow", "\347\202\271\344\272\221\347\275\221\346\240\274\345\214\226", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "\347\202\271\344\272\221\345\244\204\347\220\206", nullptr));
        pushButton_11->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
        pushButton_13->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "  \346\226\207\344\273\266  ", nullptr));
        pushButton_10->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "  \345\270\256\345\212\251  ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
