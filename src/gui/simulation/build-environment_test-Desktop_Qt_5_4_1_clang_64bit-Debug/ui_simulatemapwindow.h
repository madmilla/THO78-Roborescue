/********************************************************************************
** Form generated from reading UI file 'simulatemapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIMULATEMAPWINDOW_H
#define UI_SIMULATEMAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SimulateMapWindow
{
public:
    QPushButton *simulateButton;
    QRadioButton *noneButton;
    QRadioButton *checkpointButton;
    QPushButton *savePcButton;

    void setupUi(QWidget *SimulateMapWindow)
    {
        if (SimulateMapWindow->objectName().isEmpty())
            SimulateMapWindow->setObjectName(QStringLiteral("SimulateMapWindow"));
        SimulateMapWindow->resize(673, 475);
        simulateButton = new QPushButton(SimulateMapWindow);
        simulateButton->setObjectName(QStringLiteral("simulateButton"));
        simulateButton->setGeometry(QRect(560, 440, 111, 23));
        noneButton = new QRadioButton(SimulateMapWindow);
        noneButton->setObjectName(QStringLiteral("noneButton"));
        noneButton->setGeometry(QRect(560, 70, 102, 20));
        checkpointButton = new QRadioButton(SimulateMapWindow);
        checkpointButton->setObjectName(QStringLiteral("checkpointButton"));
        checkpointButton->setGeometry(QRect(560, 30, 102, 20));
        checkpointButton->setChecked(true);
        savePcButton = new QPushButton(SimulateMapWindow);
        savePcButton->setObjectName(QStringLiteral("savePcButton"));
        savePcButton->setGeometry(QRect(560, 410, 113, 32));

        retranslateUi(SimulateMapWindow);

        QMetaObject::connectSlotsByName(SimulateMapWindow);
    } // setupUi

    void retranslateUi(QWidget *SimulateMapWindow)
    {
        SimulateMapWindow->setWindowTitle(QApplication::translate("SimulateMapWindow", "Form", 0));
        simulateButton->setText(QApplication::translate("SimulateMapWindow", "Simulate", 0));
        noneButton->setText(QApplication::translate("SimulateMapWindow", "None", 0));
        checkpointButton->setText(QApplication::translate("SimulateMapWindow", "Checkpoints", 0));
        savePcButton->setText(QApplication::translate("SimulateMapWindow", "Save PC", 0));
    } // retranslateUi

};

namespace Ui {
    class SimulateMapWindow: public Ui_SimulateMapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIMULATEMAPWINDOW_H
