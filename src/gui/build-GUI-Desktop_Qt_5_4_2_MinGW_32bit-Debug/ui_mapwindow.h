/********************************************************************************
** Form generated from reading UI file 'mapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAPWINDOW_H
#define UI_MAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "glwidget.h"

QT_BEGIN_NAMESPACE

class Ui_MapWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    GLWidget *glWidget;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *buttonUp;
    QPushButton *buttonLeft;
    QPushButton *buttonRight;
    QPushButton *buttonDown;
    QHBoxLayout *horizontalLayout_2;
    QSlider *zoom;
    QSlider *xAxis;
    QSlider *yAxis;
    QSlider *zAxis;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MapWindow)
    {
        if (MapWindow->objectName().isEmpty())
            MapWindow->setObjectName(QStringLiteral("MapWindow"));
        MapWindow->resize(533, 364);
        centralWidget = new QWidget(MapWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        glWidget = new GLWidget(centralWidget);
        glWidget->setObjectName(QStringLiteral("glWidget"));

        horizontalLayout_3->addWidget(glWidget);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        gridLayout->setContentsMargins(0, -1, -1, -1);
        buttonUp = new QPushButton(centralWidget);
        buttonUp->setObjectName(QStringLiteral("buttonUp"));
        buttonUp->setMinimumSize(QSize(10, 23));
        buttonUp->setMaximumSize(QSize(23, 23));

        gridLayout->addWidget(buttonUp, 0, 1, 1, 1, Qt::AlignHCenter|Qt::AlignTop);

        buttonLeft = new QPushButton(centralWidget);
        buttonLeft->setObjectName(QStringLiteral("buttonLeft"));
        buttonLeft->setMaximumSize(QSize(23, 23));

        gridLayout->addWidget(buttonLeft, 1, 0, 1, 1, Qt::AlignRight|Qt::AlignVCenter);

        buttonRight = new QPushButton(centralWidget);
        buttonRight->setObjectName(QStringLiteral("buttonRight"));
        buttonRight->setMaximumSize(QSize(23, 23));

        gridLayout->addWidget(buttonRight, 1, 2, 1, 1, Qt::AlignLeft|Qt::AlignVCenter);

        buttonDown = new QPushButton(centralWidget);
        buttonDown->setObjectName(QStringLiteral("buttonDown"));
        buttonDown->setMaximumSize(QSize(23, 23));

        gridLayout->addWidget(buttonDown, 2, 1, 1, 1, Qt::AlignHCenter|Qt::AlignBottom);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        zoom = new QSlider(centralWidget);
        zoom->setObjectName(QStringLiteral("zoom"));
        zoom->setMaximum(100);
        zoom->setSingleStep(5);
        zoom->setPageStep(15);
        zoom->setOrientation(Qt::Vertical);
        zoom->setTickPosition(QSlider::TicksBelow);
        zoom->setTickInterval(10);

        horizontalLayout_2->addWidget(zoom);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout_3);

        xAxis = new QSlider(centralWidget);
        xAxis->setObjectName(QStringLiteral("xAxis"));
        xAxis->setEnabled(true);
        xAxis->setMaximum(360);
        xAxis->setSingleStep(1);
        xAxis->setPageStep(15);
        xAxis->setOrientation(Qt::Horizontal);
        xAxis->setTickPosition(QSlider::TicksBelow);
        xAxis->setTickInterval(32);

        verticalLayout->addWidget(xAxis);

        yAxis = new QSlider(centralWidget);
        yAxis->setObjectName(QStringLiteral("yAxis"));
        yAxis->setMaximum(360);
        yAxis->setSingleStep(1);
        yAxis->setPageStep(15);
        yAxis->setOrientation(Qt::Horizontal);
        yAxis->setTickPosition(QSlider::TicksBelow);
        yAxis->setTickInterval(32);

        verticalLayout->addWidget(yAxis);

        zAxis = new QSlider(centralWidget);
        zAxis->setObjectName(QStringLiteral("zAxis"));
        zAxis->setMaximum(360);
        zAxis->setSingleStep(1);
        zAxis->setPageStep(15);
        zAxis->setOrientation(Qt::Horizontal);
        zAxis->setTickPosition(QSlider::TicksBelow);
        zAxis->setTickInterval(32);

        verticalLayout->addWidget(zAxis);


        horizontalLayout->addLayout(verticalLayout);

        MapWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MapWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MapWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MapWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MapWindow->setStatusBar(statusBar);

        retranslateUi(MapWindow);

        QMetaObject::connectSlotsByName(MapWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MapWindow)
    {
        MapWindow->setWindowTitle(QApplication::translate("MapWindow", "MainWindow", 0));
        buttonUp->setText(QApplication::translate("MapWindow", "\342\206\221", 0));
        buttonLeft->setText(QApplication::translate("MapWindow", " 	\342\206\220", 0));
        buttonRight->setText(QApplication::translate("MapWindow", " 	\342\206\222", 0));
        buttonDown->setText(QApplication::translate("MapWindow", " 	\342\206\223", 0));
    } // retranslateUi

};

namespace Ui {
    class MapWindow: public Ui_MapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAPWINDOW_H
