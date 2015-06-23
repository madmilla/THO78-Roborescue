/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *QuadButton;
    QPushButton *ATVButton;
    QPushButton *RosbeeButton;
    QPushButton *LidarButton;
    QPushButton *MapButton;
    QPushButton *ExitButton;
    QListView *Rosbeelist;
    QListView *listView;
    QListView *listView_2;
    QListView *listView_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(992, 671);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QuadButton = new QPushButton(centralWidget);
        QuadButton->setObjectName(QStringLiteral("QuadButton"));
        QuadButton->setGeometry(QRect(10, 310, 231, 71));
        ATVButton = new QPushButton(centralWidget);
        ATVButton->setObjectName(QStringLiteral("ATVButton"));
        ATVButton->setGeometry(QRect(360, 310, 231, 71));
        RosbeeButton = new QPushButton(centralWidget);
        RosbeeButton->setObjectName(QStringLiteral("RosbeeButton"));
        RosbeeButton->setGeometry(QRect(10, 10, 231, 71));
        LidarButton = new QPushButton(centralWidget);
        LidarButton->setObjectName(QStringLiteral("LidarButton"));
        LidarButton->setGeometry(QRect(360, 10, 231, 71));
        MapButton = new QPushButton(centralWidget);
        MapButton->setObjectName(QStringLiteral("MapButton"));
        MapButton->setGeometry(QRect(690, 110, 191, 141));
        ExitButton = new QPushButton(centralWidget);
        ExitButton->setObjectName(QStringLiteral("ExitButton"));
        ExitButton->setGeometry(QRect(690, 420, 191, 141));
        Rosbeelist = new QListView(centralWidget);
        Rosbeelist->setObjectName(QStringLiteral("Rosbeelist"));
        Rosbeelist->setGeometry(QRect(10, 90, 231, 192));
        listView = new QListView(centralWidget);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(360, 90, 231, 192));
        listView_2 = new QListView(centralWidget);
        listView_2->setObjectName(QStringLiteral("listView_2"));
        listView_2->setGeometry(QRect(10, 390, 231, 192));
        listView_3 = new QListView(centralWidget);
        listView_3->setObjectName(QStringLiteral("listView_3"));
        listView_3->setGeometry(QRect(360, 390, 231, 192));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        QuadButton->setText(QApplication::translate("MainWindow", "Quadcopter", 0));
        ATVButton->setText(QApplication::translate("MainWindow", "ATV", 0));
        RosbeeButton->setText(QApplication::translate("MainWindow", "Rosbee Gui", 0));
        LidarButton->setText(QApplication::translate("MainWindow", "Lidar Gui", 0));
        MapButton->setText(QApplication::translate("MainWindow", "Map", 0));
        ExitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
