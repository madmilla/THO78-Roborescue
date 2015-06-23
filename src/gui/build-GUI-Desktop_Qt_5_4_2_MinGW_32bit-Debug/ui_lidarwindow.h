/********************************************************************************
** Form generated from reading UI file 'lidarwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LIDARWINDOW_H
#define UI_LIDARWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LidarWindow
{
public:
    QWidget *centralwidget;
    QPushButton *startLidar;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *LidarWindow)
    {
        if (LidarWindow->objectName().isEmpty())
            LidarWindow->setObjectName(QStringLiteral("LidarWindow"));
        LidarWindow->resize(215, 109);
        centralwidget = new QWidget(LidarWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        startLidar = new QPushButton(centralwidget);
        startLidar->setObjectName(QStringLiteral("startLidar"));
        startLidar->setGeometry(QRect(70, 60, 75, 23));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(50, 20, 113, 20));
        LidarWindow->setCentralWidget(centralwidget);

        retranslateUi(LidarWindow);

        QMetaObject::connectSlotsByName(LidarWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LidarWindow)
    {
        LidarWindow->setWindowTitle(QApplication::translate("LidarWindow", "MainWindow", 0));
        startLidar->setText(QApplication::translate("LidarWindow", "Start Scan", 0));
        lineEdit->setText(QApplication::translate("LidarWindow", "Manual Lidar Gui", 0));
    } // retranslateUi

};

namespace Ui {
    class LidarWindow: public Ui_LidarWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LIDARWINDOW_H
