/********************************************************************************
** Form generated from reading UI file 'editmapwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITMAPWINDOW_H
#define UI_EDITMAPWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_EditMapWindow
{
public:
    QPushButton *saveMapButton;
    QRadioButton *obstacleButton;
    QRadioButton *noneButton;

    void setupUi(QDialog *EditMapWindow)
    {
        if (EditMapWindow->objectName().isEmpty())
            EditMapWindow->setObjectName(QStringLiteral("EditMapWindow"));
        EditMapWindow->resize(640, 480);
        saveMapButton = new QPushButton(EditMapWindow);
        saveMapButton->setObjectName(QStringLiteral("saveMapButton"));
        saveMapButton->setGeometry(QRect(520, 440, 113, 32));
        obstacleButton = new QRadioButton(EditMapWindow);
        obstacleButton->setObjectName(QStringLiteral("obstacleButton"));
        obstacleButton->setGeometry(QRect(540, 10, 102, 20));
        obstacleButton->setChecked(true);
        noneButton = new QRadioButton(EditMapWindow);
        noneButton->setObjectName(QStringLiteral("noneButton"));
        noneButton->setGeometry(QRect(540, 40, 102, 20));

        retranslateUi(EditMapWindow);

        QMetaObject::connectSlotsByName(EditMapWindow);
    } // setupUi

    void retranslateUi(QDialog *EditMapWindow)
    {
        EditMapWindow->setWindowTitle(QApplication::translate("EditMapWindow", "Dialog", 0));
        saveMapButton->setText(QApplication::translate("EditMapWindow", "Save Map", 0));
        obstacleButton->setText(QApplication::translate("EditMapWindow", "Obstacle", 0));
        noneButton->setText(QApplication::translate("EditMapWindow", "None", 0));
    } // retranslateUi

};

namespace Ui {
    class EditMapWindow: public Ui_EditMapWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITMAPWINDOW_H
