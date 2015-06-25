/********************************************************************************
** Form generated from reading UI file 'rosbeewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ROSBEEWINDOW_H
#define UI_ROSBEEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RosbeeWindow
{
public:
    QWidget *root;
    QPushButton *abortButton;
    QPushButton *stopButton;
    QPushButton *startButton;
    QLabel *statusLabel;
    QLabel *statusValueLabel;

    void setupUi(QMainWindow *RosbeeWindow)
    {
        if (RosbeeWindow->objectName().isEmpty())
            RosbeeWindow->setObjectName(QStringLiteral("RosbeeWindow"));
        RosbeeWindow->resize(350, 80);
        root = new QWidget(RosbeeWindow);
        root->setObjectName(QStringLiteral("root"));
        abortButton = new QPushButton(root);
        abortButton->setObjectName(QStringLiteral("abortButton"));
        abortButton->setEnabled(false);
        abortButton->setGeometry(QRect(240, 40, 101, 31));
        abortButton->setAutoFillBackground(false);
        stopButton = new QPushButton(root);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);
        stopButton->setGeometry(QRect(130, 40, 101, 31));
        stopButton->setAutoFillBackground(false);
        startButton = new QPushButton(root);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(10, 40, 111, 31));
        statusLabel = new QLabel(root);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 10, 47, 21));
        statusValueLabel = new QLabel(root);
        statusValueLabel->setObjectName(QStringLiteral("statusValueLabel"));
        statusValueLabel->setGeometry(QRect(60, 10, 231, 20));
        RosbeeWindow->setCentralWidget(root);

        retranslateUi(RosbeeWindow);

        QMetaObject::connectSlotsByName(RosbeeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RosbeeWindow)
    {
        RosbeeWindow->setWindowTitle(QApplication::translate("RosbeeWindow", "Rosbee", 0));
        abortButton->setText(QApplication::translate("RosbeeWindow", "ABORT", 0));
        stopButton->setText(QApplication::translate("RosbeeWindow", "Stop", 0));
        startButton->setText(QApplication::translate("RosbeeWindow", "Start", 0));
        statusLabel->setText(QApplication::translate("RosbeeWindow", "Status:", 0));
        statusValueLabel->setText(QApplication::translate("RosbeeWindow", "ONG2", 0));
    } // retranslateUi

};

namespace Ui {
    class RosbeeWindow: public Ui_RosbeeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROSBEEWINDOW_H
