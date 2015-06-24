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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RosbeeWindow
{
public:
    QWidget *root;
    QGroupBox *statusGroupBox;
    QProgressBar *batteryBar;
    QLabel *batteryLabel;
    QLabel *initLabel;
    QLabel *initResultLabel;
    QLabel *statusLabel;
    QLabel *statusValueLabel;
    QPushButton *abortButton;
    QPushButton *stopButton;
    QPushButton *startButton;

    void setupUi(QMainWindow *RosbeeWindow)
    {
        if (RosbeeWindow->objectName().isEmpty())
            RosbeeWindow->setObjectName(QStringLiteral("RosbeeWindow"));
        RosbeeWindow->resize(350, 139);
        root = new QWidget(RosbeeWindow);
        root->setObjectName(QStringLiteral("root"));
        statusGroupBox = new QGroupBox(root);
        statusGroupBox->setObjectName(QStringLiteral("statusGroupBox"));
        statusGroupBox->setGeometry(QRect(10, 10, 331, 91));
        batteryBar = new QProgressBar(statusGroupBox);
        batteryBar->setObjectName(QStringLiteral("batteryBar"));
        batteryBar->setEnabled(true);
        batteryBar->setGeometry(QRect(90, 60, 231, 20));
        batteryBar->setLayoutDirection(Qt::RightToLeft);
        batteryBar->setMaximum(100);
        batteryBar->setValue(0);
        batteryBar->setAlignment(Qt::AlignCenter);
        batteryBar->setTextVisible(true);
        batteryBar->setInvertedAppearance(true);
        batteryLabel = new QLabel(statusGroupBox);
        batteryLabel->setObjectName(QStringLiteral("batteryLabel"));
        batteryLabel->setEnabled(true);
        batteryLabel->setGeometry(QRect(10, 60, 81, 20));
        initLabel = new QLabel(statusGroupBox);
        initLabel->setObjectName(QStringLiteral("initLabel"));
        initLabel->setGeometry(QRect(10, 20, 47, 16));
        initResultLabel = new QLabel(statusGroupBox);
        initResultLabel->setObjectName(QStringLiteral("initResultLabel"));
        initResultLabel->setGeometry(QRect(90, 20, 231, 16));
        statusLabel = new QLabel(statusGroupBox);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(10, 40, 47, 13));
        statusValueLabel = new QLabel(statusGroupBox);
        statusValueLabel->setObjectName(QStringLiteral("statusValueLabel"));
        statusValueLabel->setGeometry(QRect(90, 36, 231, 20));
        abortButton = new QPushButton(root);
        abortButton->setObjectName(QStringLiteral("abortButton"));
        abortButton->setEnabled(false);
        abortButton->setGeometry(QRect(240, 100, 101, 31));
        abortButton->setAutoFillBackground(false);
        stopButton = new QPushButton(root);
        stopButton->setObjectName(QStringLiteral("stopButton"));
        stopButton->setEnabled(false);
        stopButton->setGeometry(QRect(130, 100, 101, 31));
        stopButton->setAutoFillBackground(false);
        startButton = new QPushButton(root);
        startButton->setObjectName(QStringLiteral("startButton"));
        startButton->setGeometry(QRect(10, 100, 111, 31));
        RosbeeWindow->setCentralWidget(root);

        retranslateUi(RosbeeWindow);

        QMetaObject::connectSlotsByName(RosbeeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RosbeeWindow)
    {
        RosbeeWindow->setWindowTitle(QApplication::translate("RosbeeWindow", "Rosbee", 0));
        statusGroupBox->setTitle(QApplication::translate("RosbeeWindow", "Status", 0));
        batteryLabel->setText(QApplication::translate("RosbeeWindow", "Battery status:", 0));
        initLabel->setText(QApplication::translate("RosbeeWindow", "Init results:", 0));
        initResultLabel->setText(QApplication::translate("RosbeeWindow", "OZNG", 0));
        statusLabel->setText(QApplication::translate("RosbeeWindow", "Status:", 0));
        statusValueLabel->setText(QApplication::translate("RosbeeWindow", "ONG2", 0));
        abortButton->setText(QApplication::translate("RosbeeWindow", "ABORT", 0));
        stopButton->setText(QApplication::translate("RosbeeWindow", "Stop", 0));
        startButton->setText(QApplication::translate("RosbeeWindow", "Start", 0));
    } // retranslateUi

};

namespace Ui {
    class RosbeeWindow: public Ui_RosbeeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ROSBEEWINDOW_H
