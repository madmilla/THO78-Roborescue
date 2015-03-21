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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSave;
    QAction *actionLoad;
    QAction *actionExit;
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButtonWater;
    QPushButton *pushButtonConcrete;
    QPushButton *pushButtonGrass;
    QPushButton *pushButtonNone;
    QPushButton *pushButtonWall;
    QPushButton *pushButtonQuad;
    QPushButton *pushButtonATV;
    QPushButton *pushButtonRosbee;
    QLabel *quadLabel;
    QLabel *ATVLabel;
    QLabel *rosbeeLabel;
    QLabel *waterLabel;
    QLabel *concreteLabel;
    QLabel *grassLabel;
    QLabel *wallLabel;
    QLabel *NoneLabel;
    QLabel *rowLabel;
    QLabel *columnLabel;
    QLabel *terrainLabel;
    QLabel *rosbeeInfoLabel;
    QLabel *ATVInfoLabel;
    QLabel *quadInfoLabel;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(848, 692);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionLoad = new QAction(MainWindow);
        actionLoad->setObjectName(QStringLiteral("actionLoad"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        if (tableWidget->columnCount() < 20)
            tableWidget->setColumnCount(20);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(13, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(14, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(15, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(16, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(17, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(18, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(19, __qtablewidgetitem19);
        if (tableWidget->rowCount() < 20)
            tableWidget->setRowCount(20);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(15, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(16, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(17, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(18, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(19, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget->setItem(0, 0, __qtablewidgetitem40);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 691, 631));
        pushButtonWater = new QPushButton(centralWidget);
        pushButtonWater->setObjectName(QStringLiteral("pushButtonWater"));
        pushButtonWater->setGeometry(QRect(700, 160, 75, 23));
        pushButtonConcrete = new QPushButton(centralWidget);
        pushButtonConcrete->setObjectName(QStringLiteral("pushButtonConcrete"));
        pushButtonConcrete->setGeometry(QRect(700, 190, 75, 23));
        pushButtonGrass = new QPushButton(centralWidget);
        pushButtonGrass->setObjectName(QStringLiteral("pushButtonGrass"));
        pushButtonGrass->setGeometry(QRect(700, 220, 75, 23));
        pushButtonNone = new QPushButton(centralWidget);
        pushButtonNone->setObjectName(QStringLiteral("pushButtonNone"));
        pushButtonNone->setGeometry(QRect(700, 280, 75, 23));
        pushButtonWall = new QPushButton(centralWidget);
        pushButtonWall->setObjectName(QStringLiteral("pushButtonWall"));
        pushButtonWall->setGeometry(QRect(700, 250, 75, 23));
        pushButtonQuad = new QPushButton(centralWidget);
        pushButtonQuad->setObjectName(QStringLiteral("pushButtonQuad"));
        pushButtonQuad->setGeometry(QRect(700, 20, 75, 23));
        pushButtonATV = new QPushButton(centralWidget);
        pushButtonATV->setObjectName(QStringLiteral("pushButtonATV"));
        pushButtonATV->setGeometry(QRect(700, 50, 75, 23));
        pushButtonRosbee = new QPushButton(centralWidget);
        pushButtonRosbee->setObjectName(QStringLiteral("pushButtonRosbee"));
        pushButtonRosbee->setGeometry(QRect(700, 80, 75, 23));
        quadLabel = new QLabel(centralWidget);
        quadLabel->setObjectName(QStringLiteral("quadLabel"));
        quadLabel->setGeometry(QRect(780, 30, 47, 13));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        quadLabel->setPalette(palette);
        ATVLabel = new QLabel(centralWidget);
        ATVLabel->setObjectName(QStringLiteral("ATVLabel"));
        ATVLabel->setGeometry(QRect(780, 60, 61, 16));
        QPalette palette1;
        QBrush brush3(QColor(255, 0, 255, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        ATVLabel->setPalette(palette1);
        rosbeeLabel = new QLabel(centralWidget);
        rosbeeLabel->setObjectName(QStringLiteral("rosbeeLabel"));
        rosbeeLabel->setGeometry(QRect(780, 90, 47, 13));
        QPalette palette2;
        QBrush brush4(QColor(255, 255, 0, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush4);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        rosbeeLabel->setPalette(palette2);
        waterLabel = new QLabel(centralWidget);
        waterLabel->setObjectName(QStringLiteral("waterLabel"));
        waterLabel->setGeometry(QRect(780, 170, 47, 13));
        QPalette palette3;
        QBrush brush5(QColor(0, 0, 255, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        waterLabel->setPalette(palette3);
        concreteLabel = new QLabel(centralWidget);
        concreteLabel->setObjectName(QStringLiteral("concreteLabel"));
        concreteLabel->setGeometry(QRect(780, 200, 47, 13));
        QPalette palette4;
        QBrush brush6(QColor(157, 157, 157, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush6);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        concreteLabel->setPalette(palette4);
        grassLabel = new QLabel(centralWidget);
        grassLabel->setObjectName(QStringLiteral("grassLabel"));
        grassLabel->setGeometry(QRect(780, 230, 47, 13));
        QPalette palette5;
        QBrush brush7(QColor(0, 255, 0, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush7);
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush7);
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        grassLabel->setPalette(palette5);
        wallLabel = new QLabel(centralWidget);
        wallLabel->setObjectName(QStringLiteral("wallLabel"));
        wallLabel->setGeometry(QRect(780, 260, 47, 13));
        NoneLabel = new QLabel(centralWidget);
        NoneLabel->setObjectName(QStringLiteral("NoneLabel"));
        NoneLabel->setGeometry(QRect(780, 290, 47, 13));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        NoneLabel->setPalette(palette6);
        rowLabel = new QLabel(centralWidget);
        rowLabel->setObjectName(QStringLiteral("rowLabel"));
        rowLabel->setGeometry(QRect(710, 330, 131, 21));
        columnLabel = new QLabel(centralWidget);
        columnLabel->setObjectName(QStringLiteral("columnLabel"));
        columnLabel->setGeometry(QRect(710, 350, 131, 21));
        terrainLabel = new QLabel(centralWidget);
        terrainLabel->setObjectName(QStringLiteral("terrainLabel"));
        terrainLabel->setGeometry(QRect(710, 370, 131, 21));
        rosbeeInfoLabel = new QLabel(centralWidget);
        rosbeeInfoLabel->setObjectName(QStringLiteral("rosbeeInfoLabel"));
        rosbeeInfoLabel->setGeometry(QRect(710, 390, 131, 21));
        ATVInfoLabel = new QLabel(centralWidget);
        ATVInfoLabel->setObjectName(QStringLiteral("ATVInfoLabel"));
        ATVInfoLabel->setGeometry(QRect(710, 410, 131, 21));
        quadInfoLabel = new QLabel(centralWidget);
        quadInfoLabel->setObjectName(QStringLiteral("quadInfoLabel"));
        quadInfoLabel->setGeometry(QRect(710, 430, 131, 21));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addAction(actionSave);
        menuMenu->addAction(actionLoad);
        menuMenu->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save", 0));
        actionLoad->setText(QApplication::translate("MainWindow", "Load", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "7", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "8", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "9", 0));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "10", 0));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "11", 0));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "12", 0));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "13", 0));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->horizontalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "14", 0));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->horizontalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "15", 0));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->horizontalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "16", 0));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->horizontalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "17", 0));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->horizontalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "18", 0));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->horizontalHeaderItem(18);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "19", 0));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->horizontalHeaderItem(19);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "20", 0));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "1", 0));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "2", 0));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "3", 0));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "4", 0));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "5", 0));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "6", 0));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "7", 0));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "8", 0));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "9", 0));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "10", 0));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "11", 0));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "12", 0));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "13", 0));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "14", 0));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "15", 0));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget->verticalHeaderItem(15);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "16", 0));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget->verticalHeaderItem(16);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "17", 0));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget->verticalHeaderItem(17);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "18", 0));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget->verticalHeaderItem(18);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "19", 0));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget->verticalHeaderItem(19);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "20", 0));

        const bool __sortingEnabled = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        tableWidget->setSortingEnabled(__sortingEnabled);

        pushButtonWater->setText(QApplication::translate("MainWindow", "Water", 0));
        pushButtonConcrete->setText(QApplication::translate("MainWindow", "Concrete", 0));
        pushButtonGrass->setText(QApplication::translate("MainWindow", "Grass", 0));
        pushButtonNone->setText(QApplication::translate("MainWindow", "Empty", 0));
        pushButtonWall->setText(QApplication::translate("MainWindow", "Wall", 0));
        pushButtonQuad->setText(QApplication::translate("MainWindow", "Quadcopter", 0));
        pushButtonATV->setText(QApplication::translate("MainWindow", "ATV", 0));
        pushButtonRosbee->setText(QApplication::translate("MainWindow", "Rosbee", 0));
        quadLabel->setText(QApplication::translate("MainWindow", "= red", 0));
        ATVLabel->setText(QApplication::translate("MainWindow", "= magenta", 0));
        rosbeeLabel->setText(QApplication::translate("MainWindow", "= yellow", 0));
        waterLabel->setText(QApplication::translate("MainWindow", "= blue", 0));
        concreteLabel->setText(QApplication::translate("MainWindow", "= gray", 0));
        grassLabel->setText(QApplication::translate("MainWindow", "= green", 0));
        wallLabel->setText(QApplication::translate("MainWindow", "= black", 0));
        NoneLabel->setText(QApplication::translate("MainWindow", "= white", 0));
        rowLabel->setText(QApplication::translate("MainWindow", "row:", 0));
        columnLabel->setText(QApplication::translate("MainWindow", "column:", 0));
        terrainLabel->setText(QApplication::translate("MainWindow", "terrain:", 0));
        rosbeeInfoLabel->setText(QApplication::translate("MainWindow", "rosbee:", 0));
        ATVInfoLabel->setText(QApplication::translate("MainWindow", "ATV:", 0));
        quadInfoLabel->setText(QApplication::translate("MainWindow", "quadCopter:", 0));
        menuMenu->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
