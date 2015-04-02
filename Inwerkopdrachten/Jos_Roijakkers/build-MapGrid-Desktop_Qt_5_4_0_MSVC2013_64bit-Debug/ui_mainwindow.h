/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionLoad;
    QAction *actionExit;
    QAction *actionOptions;
    QAction *actionNew_Grid;
    QWidget *centralWidget;
    QLabel *label;
    QDial *dial;
    QLabel *label_3;
    QLabel *label_2;
    QMenuBar *menuBar;
    QMenu *menuMapGrid;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(595, 433);
        MainWindow->setAutoFillBackground(false);
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionNew_Grid = new QAction(MainWindow);
        actionNew_Grid->setObjectName(QStringLiteral("actionNew_Grid"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(11, 11, 561, 111));
        QFont font;
        font.setFamily(QStringLiteral("Courier New"));
        font.setPointSize(22);
        label->setFont(font);
        dial = new QDial(centralWidget);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(390, 190, 50, 64));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(340, 270, 241, 91));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(14, 100, 301, 261));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/Resources/Resources/rock1--article_image.jpg")));
        label_2->setScaledContents(true);
        MainWindow->setCentralWidget(centralWidget);
        label_3->raise();
        label->raise();
        dial->raise();
        label_2->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 595, 26));
        menuMapGrid = new QMenu(menuBar);
        menuMapGrid->setObjectName(QStringLiteral("menuMapGrid"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMapGrid->menuAction());
        menuMapGrid->addAction(actionNew_Grid);
        menuMapGrid->addAction(actionOptions);
        menuMapGrid->addAction(actionLoad);
        menuMapGrid->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", 0));
        actionNew_Grid->setText(QApplication::translate("MainWindow", "New Map", 0));
        label->setText(QApplication::translate("MainWindow", "MapGrid. Handy Mapbuilder", 0));
        label_3->setText(QApplication::translate("MainWindow", "MapGrid. \n"
"\n"
"Made by Jos Roijakkers\n"
"\n"
"Vi2A\n"
"\n"
"25/2/2015\n"
"\n"
"made possible by coffee.. lots of coffee\n"
"\n"
"Megaman approved\n"
"\n"
"Stop scrolling\n"
"\n"
"I mean it\n"
"\n"
"Go build a map or somthing.", 0));
        label_2->setText(QString());
        menuMapGrid->setTitle(QApplication::translate("MainWindow", "MapGrid", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
