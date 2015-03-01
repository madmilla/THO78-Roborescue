/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openFileButton;
    QPushButton *exitButton;
    QGraphicsView *mapView;
    QGraphicsView *legendView;
    QMenuBar *menuBar;
    QMenu *menuMap;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(640, 640);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openFileButton = new QPushButton(centralWidget);
        openFileButton->setObjectName(QStringLiteral("openFileButton"));
        openFileButton->setGeometry(QRect(10, 10, 115, 32));
        sizePolicy.setHeightForWidth(openFileButton->sizePolicy().hasHeightForWidth());
        openFileButton->setSizePolicy(sizePolicy);
        openFileButton->setFocusPolicy(Qt::NoFocus);
        openFileButton->setAutoRepeatDelay(1000);
        exitButton = new QPushButton(centralWidget);
        exitButton->setObjectName(QStringLiteral("exitButton"));
        exitButton->setGeometry(QRect(515, 10, 115, 32));
        mapView = new QGraphicsView(centralWidget);
        mapView->setObjectName(QStringLiteral("mapView"));
        mapView->setGeometry(QRect(10, 80, 480, 480));
        sizePolicy.setHeightForWidth(mapView->sizePolicy().hasHeightForWidth());
        mapView->setSizePolicy(sizePolicy);
        mapView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        mapView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        legendView = new QGraphicsView(centralWidget);
        legendView->setObjectName(QStringLiteral("legendView"));
        legendView->setGeometry(QRect(500, 80, 130, 480));
        sizePolicy.setHeightForWidth(legendView->sizePolicy().hasHeightForWidth());
        legendView->setSizePolicy(sizePolicy);
        legendView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 640, 22));
        menuMap = new QMenu(menuBar);
        menuMap->setObjectName(QStringLiteral("menuMap"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMap->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openFileButton->setText(QApplication::translate("MainWindow", "Open file...", 0));
        exitButton->setText(QApplication::translate("MainWindow", "Exit", 0));
        menuMap->setTitle(QApplication::translate("MainWindow", "Map", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
