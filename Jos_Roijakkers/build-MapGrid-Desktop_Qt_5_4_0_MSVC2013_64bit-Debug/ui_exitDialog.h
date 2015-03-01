/********************************************************************************
** Form generated from reading UI file 'exitDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXITDIALOG_H
#define UI_EXITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_exitDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *exitDialog)
    {
        if (exitDialog->objectName().isEmpty())
            exitDialog->setObjectName(QStringLiteral("exitDialog"));
        exitDialog->resize(278, 147);
        verticalLayout = new QVBoxLayout(exitDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(exitDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        okButton = new QPushButton(exitDialog);
        okButton->setObjectName(QStringLiteral("okButton"));

        verticalLayout->addWidget(okButton);

        cancelButton = new QPushButton(exitDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        retranslateUi(exitDialog);

        QMetaObject::connectSlotsByName(exitDialog);
    } // setupUi

    void retranslateUi(QDialog *exitDialog)
    {
        exitDialog->setWindowTitle(QApplication::translate("exitDialog", "Exit", 0));
        label->setText(QApplication::translate("exitDialog", "Afsluiten? Niet opgeslagen gegevens\n"
"zullen verloren gaan.", 0));
        okButton->setText(QApplication::translate("exitDialog", "Ok", 0));
        cancelButton->setText(QApplication::translate("exitDialog", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class exitDialog: public Ui_exitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXITDIALOG_H
