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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionClear;
    QAction *actionReload;
    QAction *actionSave;
    QAction *actionUnload;
    QWidget *centralWidget;
    QSpinBox *heightSelection;
    QRadioButton *radioDriveable;
    QRadioButton *radioStaticObject;
    QFrame *line;
    QLabel *label;
    QLabel *areaType;
    QFrame *line_2;
    QFrame *line_3;
    QTableWidget *map;
    QPushButton *vehicleButton;
    QFrame *line_4;
    QLabel *areaType_2;
    QMenuBar *menuBar;
    QMenu *menuMap;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(600, 498);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(600, 498));
        MainWindow->setMaximumSize(QSize(600, 498));
        actionClear = new QAction(MainWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        actionClear->setEnabled(true);
        actionReload = new QAction(MainWindow);
        actionReload->setObjectName(QStringLiteral("actionReload"));
        actionReload->setEnabled(true);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(true);
        actionUnload = new QAction(MainWindow);
        actionUnload->setObjectName(QStringLiteral("actionUnload"));
        actionUnload->setEnabled(false);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        heightSelection = new QSpinBox(centralWidget);
        heightSelection->setObjectName(QStringLiteral("heightSelection"));
        heightSelection->setGeometry(QRect(500, 450, 61, 21));
        heightSelection->setFrame(true);
        heightSelection->setReadOnly(true);
        heightSelection->setMaximum(100);
        radioDriveable = new QRadioButton(centralWidget);
        radioDriveable->setObjectName(QStringLiteral("radioDriveable"));
        radioDriveable->setGeometry(QRect(500, 391, 91, 20));
        radioDriveable->setCheckable(false);
        radioDriveable->setChecked(false);
        radioDriveable->setAutoExclusive(true);
        radioStaticObject = new QRadioButton(centralWidget);
        radioStaticObject->setObjectName(QStringLiteral("radioStaticObject"));
        radioStaticObject->setGeometry(QRect(500, 371, 91, 20));
        radioStaticObject->setCheckable(false);
        radioStaticObject->setChecked(false);
        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(470, 0, 21, 491));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(490, 421, 101, 20));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        areaType = new QLabel(centralWidget);
        areaType->setObjectName(QStringLiteral("areaType"));
        areaType->setGeometry(QRect(490, 350, 101, 21));
        areaType->setFont(font);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(480, 411, 121, 20));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setGeometry(QRect(480, 340, 121, 21));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        map = new QTableWidget(centralWidget);
        if (map->columnCount() < 20)
            map->setColumnCount(20);
        if (map->rowCount() < 20)
            map->setRowCount(20);
        map->setObjectName(QStringLiteral("map"));
        map->setGeometry(QRect(0, 0, 480, 480));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(map->sizePolicy().hasHeightForWidth());
        map->setSizePolicy(sizePolicy1);
        map->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        map->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        map->setAutoScroll(false);
        map->setAutoScrollMargin(12);
        map->setEditTriggers(QAbstractItemView::NoEditTriggers);
        map->setTabKeyNavigation(false);
        map->setProperty("showDropIndicator", QVariant(false));
        map->setDragDropOverwriteMode(false);
        map->setSelectionMode(QAbstractItemView::SingleSelection);
        map->setShowGrid(true);
        map->setGridStyle(Qt::DashLine);
        map->setRowCount(20);
        map->setColumnCount(20);
        map->horizontalHeader()->setVisible(false);
        map->horizontalHeader()->setDefaultSectionSize(24);
        map->horizontalHeader()->setHighlightSections(true);
        map->verticalHeader()->setVisible(false);
        map->verticalHeader()->setDefaultSectionSize(24);
        map->verticalHeader()->setHighlightSections(true);
        map->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        vehicleButton = new QPushButton(centralWidget);
        vehicleButton->setObjectName(QStringLiteral("vehicleButton"));
        vehicleButton->setEnabled(false);
        vehicleButton->setGeometry(QRect(500, 323, 81, 20));
        vehicleButton->setCheckable(false);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setGeometry(QRect(480, 290, 121, 21));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);
        areaType_2 = new QLabel(centralWidget);
        areaType_2->setObjectName(QStringLiteral("areaType_2"));
        areaType_2->setGeometry(QRect(490, 300, 101, 21));
        areaType_2->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 18));
        menuMap = new QMenu(menuBar);
        menuMap->setObjectName(QStringLiteral("menuMap"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMap->menuAction());
        menuMap->addAction(actionClear);
        menuMap->addAction(actionReload);
        menuMap->addAction(actionSave);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionClear->setText(QApplication::translate("MainWindow", "clear", 0));
        actionReload->setText(QApplication::translate("MainWindow", "reload", 0));
        actionSave->setText(QApplication::translate("MainWindow", "save", 0));
        actionUnload->setText(QApplication::translate("MainWindow", "unload", 0));
        heightSelection->setSpecialValueText(QString());
        radioDriveable->setText(QApplication::translate("MainWindow", "driveable", 0));
        radioStaticObject->setText(QApplication::translate("MainWindow", "static object", 0));
        label->setText(QApplication::translate("MainWindow", "terrain height", 0));
        areaType->setText(QApplication::translate("MainWindow", "areatype", 0));
        vehicleButton->setText(QApplication::translate("MainWindow", "place vehicle", 0));
        areaType_2->setText(QApplication::translate("MainWindow", "vehicle", 0));
        menuMap->setTitle(QApplication::translate("MainWindow", "map", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
