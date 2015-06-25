/********************************************************************************
** Form generated from reading UI file 'atvwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATVWINDOW_H
#define UI_ATVWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ATVWindow
{
public:
    QWidget *root;
    QGroupBox *statusGB;
    QProgressBar *batteryStatusBar;
    QLabel *batteryStatusLabel;
    QLabel *speedLabel;
    QLCDNumber *speedLCD;
    QLabel *speedUnitLabel;
    QTextEdit *messageOutput;
    QPushButton *shutdownButton;
    QPushButton *abortButton;
    QGroupBox *steeringOrientationGB;
    QScrollBar *steeringScrollBar;
    QGroupBox *driveOrientationGB;
    QDial *dial;
    QLCDNumber *dialLCD;

    void setupUi(QMainWindow *ATVWindow)
    {
        if (ATVWindow->objectName().isEmpty())
            ATVWindow->setObjectName(QStringLiteral("ATVWindow"));
        ATVWindow->resize(531, 283);
        root = new QWidget(ATVWindow);
        root->setObjectName(QStringLiteral("root"));
        statusGB = new QGroupBox(root);
        statusGB->setObjectName(QStringLiteral("statusGB"));
        statusGB->setGeometry(QRect(10, 10, 511, 51));
        batteryStatusBar = new QProgressBar(statusGB);
        batteryStatusBar->setObjectName(QStringLiteral("batteryStatusBar"));
        batteryStatusBar->setGeometry(QRect(90, 20, 291, 23));
        batteryStatusBar->setValue(24);
        batteryStatusLabel = new QLabel(statusGB);
        batteryStatusLabel->setObjectName(QStringLiteral("batteryStatusLabel"));
        batteryStatusLabel->setGeometry(QRect(10, 20, 141, 21));
        speedLabel = new QLabel(statusGB);
        speedLabel->setObjectName(QStringLiteral("speedLabel"));
        speedLabel->setGeometry(QRect(380, 20, 31, 21));
        speedLCD = new QLCDNumber(statusGB);
        speedLCD->setObjectName(QStringLiteral("speedLCD"));
        speedLCD->setGeometry(QRect(410, 20, 64, 23));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        palette.setBrush(QPalette::Active, QPalette::Light, brush);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        QBrush brush1(QColor(255, 255, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        speedLCD->setPalette(palette);
        speedUnitLabel = new QLabel(statusGB);
        speedUnitLabel->setObjectName(QStringLiteral("speedUnitLabel"));
        speedUnitLabel->setGeometry(QRect(480, 20, 31, 21));
        messageOutput = new QTextEdit(root);
        messageOutput->setObjectName(QStringLiteral("messageOutput"));
        messageOutput->setGeometry(QRect(120, 130, 401, 141));
        messageOutput->setReadOnly(true);
        shutdownButton = new QPushButton(root);
        shutdownButton->setObjectName(QStringLiteral("shutdownButton"));
        shutdownButton->setGeometry(QRect(10, 180, 101, 41));
        abortButton = new QPushButton(root);
        abortButton->setObjectName(QStringLiteral("abortButton"));
        abortButton->setGeometry(QRect(10, 230, 101, 41));
        steeringOrientationGB = new QGroupBox(root);
        steeringOrientationGB->setObjectName(QStringLiteral("steeringOrientationGB"));
        steeringOrientationGB->setEnabled(true);
        steeringOrientationGB->setGeometry(QRect(120, 70, 401, 51));
        steeringScrollBar = new QScrollBar(steeringOrientationGB);
        steeringScrollBar->setObjectName(QStringLiteral("steeringScrollBar"));
        steeringScrollBar->setGeometry(QRect(10, 20, 381, 21));
        steeringScrollBar->setMinimum(-401);
        steeringScrollBar->setMaximum(401);
        steeringScrollBar->setTracking(true);
        steeringScrollBar->setOrientation(Qt::Horizontal);
        steeringScrollBar->setInvertedControls(true);
        driveOrientationGB = new QGroupBox(root);
        driveOrientationGB->setObjectName(QStringLiteral("driveOrientationGB"));
        driveOrientationGB->setEnabled(false);
        driveOrientationGB->setGeometry(QRect(10, 70, 101, 101));
        dial = new QDial(driveOrientationGB);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(20, 10, 61, 64));
        dialLCD = new QLCDNumber(driveOrientationGB);
        dialLCD->setObjectName(QStringLiteral("dialLCD"));
        dialLCD->setGeometry(QRect(13, 70, 81, 23));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Light, brush);
        palette1.setBrush(QPalette::Active, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Active, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Light, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Light, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Midlight, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Dark, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        dialLCD->setPalette(palette1);
        ATVWindow->setCentralWidget(root);

        retranslateUi(ATVWindow);

        QMetaObject::connectSlotsByName(ATVWindow);
    } // setupUi

    void retranslateUi(QMainWindow *ATVWindow)
    {
        ATVWindow->setWindowTitle(QApplication::translate("ATVWindow", "ATV", 0));
        statusGB->setTitle(QApplication::translate("ATVWindow", "Status", 0));
        batteryStatusLabel->setText(QApplication::translate("ATVWindow", "Battery status:", 0));
        speedLabel->setText(QApplication::translate("ATVWindow", "Speed", 0));
        speedUnitLabel->setText(QApplication::translate("ATVWindow", "km/h", 0));
        shutdownButton->setText(QApplication::translate("ATVWindow", "Restart", 0));
        abortButton->setText(QApplication::translate("ATVWindow", "Abort", 0));
        steeringOrientationGB->setTitle(QApplication::translate("ATVWindow", "Steering Orientation", 0));
        driveOrientationGB->setTitle(QApplication::translate("ATVWindow", "Driving orientation", 0));
    } // retranslateUi

};

namespace Ui {
    class ATVWindow: public Ui_ATVWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATVWINDOW_H
