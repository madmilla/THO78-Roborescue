/********************************************************************************
** Form generated from reading UI file 'savedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEDIALOG_H
#define UI_SAVEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_saveDialog
{
public:
    QPushButton *saveButton;
    QPushButton *cancelButton;
    QListWidget *listWidget;

    void setupUi(QDialog *saveDialog)
    {
        if (saveDialog->objectName().isEmpty())
            saveDialog->setObjectName(QStringLiteral("saveDialog"));
        saveDialog->resize(400, 300);
        saveButton = new QPushButton(saveDialog);
        saveButton->setObjectName(QStringLiteral("saveButton"));
        saveButton->setGeometry(QRect(270, 40, 101, 81));
        cancelButton = new QPushButton(saveDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(272, 200, 101, 31));
        listWidget = new QListWidget(saveDialog);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 231, 281));

        retranslateUi(saveDialog);

        QMetaObject::connectSlotsByName(saveDialog);
    } // setupUi

    void retranslateUi(QDialog *saveDialog)
    {
        saveDialog->setWindowTitle(QApplication::translate("saveDialog", "Save", 0));
        saveButton->setText(QApplication::translate("saveDialog", "Save", 0));
        cancelButton->setText(QApplication::translate("saveDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class saveDialog: public Ui_saveDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEDIALOG_H
