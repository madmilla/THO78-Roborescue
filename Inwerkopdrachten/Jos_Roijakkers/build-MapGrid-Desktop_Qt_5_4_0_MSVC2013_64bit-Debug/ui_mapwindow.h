/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QAction *actionSave;
    QAction *actionClear;
    QWidget *centralwidget;
    QPushButton *cancelButton;
    QPushButton *randomButton;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QCheckBox *isQuadcopter;
    QCheckBox *isATV;
    QCheckBox *isRosbee;
    QRadioButton *isEmpty;
    QRadioButton *isGrass;
    QRadioButton *isConcrete;
    QRadioButton *isDirt;
    QRadioButton *isWater;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QStringLiteral("MapWindow"));
        MapWindow->resize(800, 600);
        actionSave = new QAction(MapWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionClear = new QAction(MapWindow);
        actionClear->setObjectName(QStringLiteral("actionClear"));
        centralwidget = new QWidget(MapWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        cancelButton = new QPushButton(centralwidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(690, 480, 93, 28));
        randomButton = new QPushButton(centralwidget);
        randomButton->setObjectName(QStringLiteral("randomButton"));
        randomButton->setGeometry(QRect(560, 480, 93, 28));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(580, 80, 141, 211));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        isQuadcopter = new QCheckBox(layoutWidget);
        isQuadcopter->setObjectName(QStringLiteral("isQuadcopter"));

        verticalLayout->addWidget(isQuadcopter);

        isATV = new QCheckBox(layoutWidget);
        isATV->setObjectName(QStringLiteral("isATV"));

        verticalLayout->addWidget(isATV);

        isRosbee = new QCheckBox(layoutWidget);
        isRosbee->setObjectName(QStringLiteral("isRosbee"));

        verticalLayout->addWidget(isRosbee);

        isEmpty = new QRadioButton(layoutWidget);
        isEmpty->setObjectName(QStringLiteral("isEmpty"));

        verticalLayout->addWidget(isEmpty);

        isGrass = new QRadioButton(layoutWidget);
        isGrass->setObjectName(QStringLiteral("isGrass"));

        verticalLayout->addWidget(isGrass);

        isConcrete = new QRadioButton(layoutWidget);
        isConcrete->setObjectName(QStringLiteral("isConcrete"));

        verticalLayout->addWidget(isConcrete);

        isDirt = new QRadioButton(layoutWidget);
        isDirt->setObjectName(QStringLiteral("isDirt"));

        verticalLayout->addWidget(isDirt);

        isWater = new QRadioButton(layoutWidget);
        isWater->setObjectName(QStringLiteral("isWater"));

        verticalLayout->addWidget(isWater);

        MapWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MapWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MapWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MapWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MapWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClear);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MapWindow", 0));
        actionSave->setText(QApplication::translate("MapWindow", "Save", 0));
        actionClear->setText(QApplication::translate("MapWindow", "Clear", 0));
        cancelButton->setText(QApplication::translate("MapWindow", "Cancel", 0));
        randomButton->setText(QApplication::translate("MapWindow", "Random", 0));
        isQuadcopter->setText(QApplication::translate("MapWindow", "Quadcopter", 0));
        isATV->setText(QApplication::translate("MapWindow", "ATV", 0));
        isRosbee->setText(QApplication::translate("MapWindow", "Rosbee", 0));
        isEmpty->setText(QApplication::translate("MapWindow", "Empty", 0));
        isGrass->setText(QApplication::translate("MapWindow", "Grass", 0));
        isConcrete->setText(QApplication::translate("MapWindow", "Concrete", 0));
        isDirt->setText(QApplication::translate("MapWindow", "Dirt", 0));
        isWater->setText(QApplication::translate("MapWindow", "Water", 0));
        menuFile->setTitle(QApplication::translate("MapWindow", "Menu", 0));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
