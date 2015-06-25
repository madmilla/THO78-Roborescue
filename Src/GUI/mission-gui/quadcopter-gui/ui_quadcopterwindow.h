/********************************************************************************
** Form generated from reading UI file 'quadcopterwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUADCOPTERWINDOW_H
#define UI_QUADCOPTERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QuadcopterWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *statusBox;
    QGroupBox *componentBox;
    QLabel *cameraLabel;
    QLabel *gpsLabel;
    QLabel *gyroscopeLabel;
    QGroupBox *rotorStatusBox;
    QLabel *flLabel;
    QLabel *blLabel;
    QLabel *frLabel;
    QLabel *brLabel;
    QLCDNumber *flValue;
    QLCDNumber *blValue;
    QLCDNumber *frValue;
    QLCDNumber *brValue;
    QProgressBar *batteryBar;
    QLabel *batteryLabel;
    QLabel *armedLabel;
    QGroupBox *positionBox;
    QLabel *pitchLabel;
    QLabel *yawLabel;
    QLabel *rotationLabel;
    QLabel *altitudeLabel;
    QLCDNumber *pitchValue;
    QLCDNumber *yawValue;
    QLCDNumber *rotationValue;
    QLCDNumber *altitudeValue;
    QLabel *headingLabel;
    QLCDNumber *headingValue;
    QCheckBox *armedCheck;
    QPushButton *abortButton;
    QPushButton *takeOff_LandButton;
    QPushButton *armButton;
    QPushButton *restartButton;
    QGroupBox *settingsBox;
    QLabel *cmLabel;
    QLabel *maxAltitudeLabel;
    QPushButton *sendMaxAltitudeButton;
    QDoubleSpinBox *maxAltitudeInput;
    QTextEdit *messageOutput;

    void setupUi(QMainWindow *QuadcopterWindow)
    {
        if (QuadcopterWindow->objectName().isEmpty())
            QuadcopterWindow->setObjectName(QStringLiteral("QuadcopterWindow"));
        QuadcopterWindow->setEnabled(true);
        QuadcopterWindow->resize(800, 600);
        QuadcopterWindow->setMinimumSize(QSize(800, 600));
        QuadcopterWindow->setMaximumSize(QSize(800, 600));
        centralwidget = new QWidget(QuadcopterWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        statusBox = new QGroupBox(centralwidget);
        statusBox->setObjectName(QStringLiteral("statusBox"));
        statusBox->setGeometry(QRect(10, 10, 771, 241));
        componentBox = new QGroupBox(statusBox);
        componentBox->setObjectName(QStringLiteral("componentBox"));
        componentBox->setGeometry(QRect(10, 20, 120, 131));
        cameraLabel = new QLabel(componentBox);
        cameraLabel->setObjectName(QStringLiteral("cameraLabel"));
        cameraLabel->setGeometry(QRect(20, 30, 41, 21));
        gpsLabel = new QLabel(componentBox);
        gpsLabel->setObjectName(QStringLiteral("gpsLabel"));
        gpsLabel->setGeometry(QRect(20, 60, 47, 21));
        gyroscopeLabel = new QLabel(componentBox);
        gyroscopeLabel->setObjectName(QStringLiteral("gyroscopeLabel"));
        gyroscopeLabel->setGeometry(QRect(20, 90, 61, 21));
        rotorStatusBox = new QGroupBox(statusBox);
        rotorStatusBox->setObjectName(QStringLiteral("rotorStatusBox"));
        rotorStatusBox->setGeometry(QRect(150, 50, 471, 101));
        flLabel = new QLabel(rotorStatusBox);
        flLabel->setObjectName(QStringLiteral("flLabel"));
        flLabel->setGeometry(QRect(20, 20, 47, 21));
        blLabel = new QLabel(rotorStatusBox);
        blLabel->setObjectName(QStringLiteral("blLabel"));
        blLabel->setGeometry(QRect(20, 60, 47, 20));
        frLabel = new QLabel(rotorStatusBox);
        frLabel->setObjectName(QStringLiteral("frLabel"));
        frLabel->setGeometry(QRect(300, 20, 61, 21));
        brLabel = new QLabel(rotorStatusBox);
        brLabel->setObjectName(QStringLiteral("brLabel"));
        brLabel->setGeometry(QRect(300, 60, 61, 21));
        flValue = new QLCDNumber(rotorStatusBox);
        flValue->setObjectName(QStringLiteral("flValue"));
        flValue->setGeometry(QRect(100, 20, 64, 23));
        blValue = new QLCDNumber(rotorStatusBox);
        blValue->setObjectName(QStringLiteral("blValue"));
        blValue->setGeometry(QRect(100, 60, 64, 23));
        frValue = new QLCDNumber(rotorStatusBox);
        frValue->setObjectName(QStringLiteral("frValue"));
        frValue->setGeometry(QRect(390, 20, 64, 23));
        brValue = new QLCDNumber(rotorStatusBox);
        brValue->setObjectName(QStringLiteral("brValue"));
        brValue->setGeometry(QRect(390, 60, 64, 23));
        batteryBar = new QProgressBar(statusBox);
        batteryBar->setObjectName(QStringLiteral("batteryBar"));
        batteryBar->setGeometry(QRect(237, 20, 241, 23));
        batteryBar->setMaximum(100);
        batteryBar->setValue(0);
        batteryBar->setTextVisible(true);
        batteryBar->setInvertedAppearance(true);
        batteryLabel = new QLabel(statusBox);
        batteryLabel->setObjectName(QStringLiteral("batteryLabel"));
        batteryLabel->setGeometry(QRect(150, 20, 81, 20));
        armedLabel = new QLabel(statusBox);
        armedLabel->setObjectName(QStringLiteral("armedLabel"));
        armedLabel->setGeometry(QRect(560, 20, 41, 21));
        positionBox = new QGroupBox(statusBox);
        positionBox->setObjectName(QStringLiteral("positionBox"));
        positionBox->setGeometry(QRect(10, 170, 571, 51));
        pitchLabel = new QLabel(positionBox);
        pitchLabel->setObjectName(QStringLiteral("pitchLabel"));
        pitchLabel->setGeometry(QRect(30, 10, 47, 20));
        yawLabel = new QLabel(positionBox);
        yawLabel->setObjectName(QStringLiteral("yawLabel"));
        yawLabel->setGeometry(QRect(150, 10, 47, 20));
        rotationLabel = new QLabel(positionBox);
        rotationLabel->setObjectName(QStringLiteral("rotationLabel"));
        rotationLabel->setGeometry(QRect(250, 10, 47, 20));
        altitudeLabel = new QLabel(positionBox);
        altitudeLabel->setObjectName(QStringLiteral("altitudeLabel"));
        altitudeLabel->setGeometry(QRect(450, 10, 47, 16));
        pitchValue = new QLCDNumber(positionBox);
        pitchValue->setObjectName(QStringLiteral("pitchValue"));
        pitchValue->setGeometry(QRect(40, 30, 64, 23));
        pitchValue->setFrameShape(QFrame::Box);
        pitchValue->setFrameShadow(QFrame::Raised);
        pitchValue->setLineWidth(1);
        pitchValue->setMidLineWidth(0);
        pitchValue->setSegmentStyle(QLCDNumber::Flat);
        yawValue = new QLCDNumber(positionBox);
        yawValue->setObjectName(QStringLiteral("yawValue"));
        yawValue->setGeometry(QRect(170, 30, 64, 23));
        yawValue->setSegmentStyle(QLCDNumber::Flat);
        rotationValue = new QLCDNumber(positionBox);
        rotationValue->setObjectName(QStringLiteral("rotationValue"));
        rotationValue->setGeometry(QRect(290, 30, 64, 23));
        rotationValue->setSegmentStyle(QLCDNumber::Flat);
        altitudeValue = new QLCDNumber(positionBox);
        altitudeValue->setObjectName(QStringLiteral("altitudeValue"));
        altitudeValue->setGeometry(QRect(490, 30, 64, 23));
        altitudeValue->setSegmentStyle(QLCDNumber::Flat);
        headingLabel = new QLabel(positionBox);
        headingLabel->setObjectName(QStringLiteral("headingLabel"));
        headingLabel->setGeometry(QRect(360, 10, 47, 16));
        headingValue = new QLCDNumber(positionBox);
        headingValue->setObjectName(QStringLiteral("headingValue"));
        headingValue->setGeometry(QRect(390, 30, 64, 23));
        headingValue->setSegmentStyle(QLCDNumber::Flat);
        armedCheck = new QCheckBox(statusBox);
        armedCheck->setObjectName(QStringLiteral("armedCheck"));
        armedCheck->setGeometry(QRect(610, 20, 16, 21));
        abortButton = new QPushButton(centralwidget);
        abortButton->setObjectName(QStringLiteral("abortButton"));
        abortButton->setGeometry(QRect(630, 510, 151, 71));
        abortButton->setAutoFillBackground(false);
        takeOff_LandButton = new QPushButton(centralwidget);
        takeOff_LandButton->setObjectName(QStringLiteral("takeOff_LandButton"));
        takeOff_LandButton->setGeometry(QRect(520, 450, 261, 41));
        armButton = new QPushButton(centralwidget);
        armButton->setObjectName(QStringLiteral("armButton"));
        armButton->setEnabled(true);
        armButton->setGeometry(QRect(520, 390, 261, 41));
        restartButton = new QPushButton(centralwidget);
        restartButton->setObjectName(QStringLiteral("restartButton"));
        restartButton->setGeometry(QRect(520, 510, 91, 71));
        settingsBox = new QGroupBox(centralwidget);
        settingsBox->setObjectName(QStringLiteral("settingsBox"));
        settingsBox->setGeometry(QRect(520, 260, 261, 111));
        cmLabel = new QLabel(settingsBox);
        cmLabel->setObjectName(QStringLiteral("cmLabel"));
        cmLabel->setGeometry(QRect(190, 20, 61, 16));
        maxAltitudeLabel = new QLabel(settingsBox);
        maxAltitudeLabel->setObjectName(QStringLiteral("maxAltitudeLabel"));
        maxAltitudeLabel->setGeometry(QRect(20, 20, 71, 21));
        sendMaxAltitudeButton = new QPushButton(settingsBox);
        sendMaxAltitudeButton->setObjectName(QStringLiteral("sendMaxAltitudeButton"));
        sendMaxAltitudeButton->setGeometry(QRect(20, 50, 221, 41));
        maxAltitudeInput = new QDoubleSpinBox(settingsBox);
        maxAltitudeInput->setObjectName(QStringLiteral("maxAltitudeInput"));
        maxAltitudeInput->setGeometry(QRect(100, 20, 62, 22));
        maxAltitudeInput->setMaximum(100);
        messageOutput = new QTextEdit(centralwidget);
        messageOutput->setObjectName(QStringLiteral("messageOutput"));
        messageOutput->setGeometry(QRect(20, 270, 481, 311));
        QuadcopterWindow->setCentralWidget(centralwidget);

        retranslateUi(QuadcopterWindow);

        QMetaObject::connectSlotsByName(QuadcopterWindow);
    } // setupUi

    void retranslateUi(QMainWindow *QuadcopterWindow)
    {
        QuadcopterWindow->setWindowTitle(QApplication::translate("QuadcopterWindow", "Quadcopter", 0));
        statusBox->setTitle(QApplication::translate("QuadcopterWindow", "Status", 0));
        componentBox->setTitle(QApplication::translate("QuadcopterWindow", "Components", 0));
        cameraLabel->setText(QApplication::translate("QuadcopterWindow", "Camera", 0));
        gpsLabel->setText(QApplication::translate("QuadcopterWindow", "GPS", 0));
        gyroscopeLabel->setText(QApplication::translate("QuadcopterWindow", "Gyroscope", 0));
        rotorStatusBox->setTitle(QApplication::translate("QuadcopterWindow", "Rotors", 0));
        flLabel->setText(QApplication::translate("QuadcopterWindow", "Front Left", 0));
        blLabel->setText(QApplication::translate("QuadcopterWindow", "Back Left", 0));
        frLabel->setText(QApplication::translate("QuadcopterWindow", "Front Right", 0));
        brLabel->setText(QApplication::translate("QuadcopterWindow", "Back Right", 0));
        batteryLabel->setText(QApplication::translate("QuadcopterWindow", "Battery status:", 0));
        armedLabel->setText(QApplication::translate("QuadcopterWindow", "Armed:", 0));
        positionBox->setTitle(QApplication::translate("QuadcopterWindow", "Position", 0));
        pitchLabel->setText(QApplication::translate("QuadcopterWindow", "Pitch", 0));
        yawLabel->setText(QApplication::translate("QuadcopterWindow", "Yaw", 0));
        rotationLabel->setText(QApplication::translate("QuadcopterWindow", "Rotation", 0));
        altitudeLabel->setText(QApplication::translate("QuadcopterWindow", "Altitude", 0));
        headingLabel->setText(QApplication::translate("QuadcopterWindow", "heading", 0));
        armedCheck->setText(QString());
        abortButton->setText(QApplication::translate("QuadcopterWindow", "ABORT", 0));
        takeOff_LandButton->setText(QApplication::translate("QuadcopterWindow", "Take Off", 0));
        armButton->setText(QApplication::translate("QuadcopterWindow", "Arm", 0));
        restartButton->setText(QApplication::translate("QuadcopterWindow", "Restart", 0));
        settingsBox->setTitle(QApplication::translate("QuadcopterWindow", "Settings", 0));
        cmLabel->setText(QApplication::translate("QuadcopterWindow", "Meter", 0));
        maxAltitudeLabel->setText(QApplication::translate("QuadcopterWindow", "Max Altitude", 0));
        sendMaxAltitudeButton->setText(QApplication::translate("QuadcopterWindow", "Send Max Altitude", 0));
    } // retranslateUi

};

namespace Ui {
    class QuadcopterWindow: public Ui_QuadcopterWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUADCOPTERWINDOW_H
