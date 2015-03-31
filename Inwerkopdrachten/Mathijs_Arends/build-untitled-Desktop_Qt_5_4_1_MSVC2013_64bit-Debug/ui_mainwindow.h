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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAddObject;
    QAction *actionSelectObject1;
    QAction *actionSelectObject2;
    QAction *actionSelectFile;
    QAction *actionQuit;
    QWidget *centralWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(480, 480);
        actionAddObject = new QAction(MainWindow);
        actionAddObject->setObjectName(QStringLiteral("actionAddObject"));
        actionSelectObject1 = new QAction(MainWindow);
        actionSelectObject1->setObjectName(QStringLiteral("actionSelectObject1"));
        actionSelectObject2 = new QAction(MainWindow);
        actionSelectObject2->setObjectName(QStringLiteral("actionSelectObject2"));
        actionSelectFile = new QAction(MainWindow);
        actionSelectFile->setObjectName(QStringLiteral("actionSelectFile"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSelectFile);
        toolBar->addAction(actionSelectObject1);
        toolBar->addAction(actionSelectObject2);
        toolBar->addAction(actionQuit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionAddObject->setText(QApplication::translate("MainWindow", "AddObject", 0));
        actionSelectObject1->setText(QApplication::translate("MainWindow", "SelectObject1", 0));
        actionSelectObject2->setText(QApplication::translate("MainWindow", "SelectObject2", 0));
        actionSelectFile->setText(QApplication::translate("MainWindow", "SelectFile", 0));
        actionQuit->setText(QApplication::translate("MainWindow", "Quit", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
