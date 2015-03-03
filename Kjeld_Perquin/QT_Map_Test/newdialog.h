#ifndef NEWDIALOG_H
#define NEWDIALOG_H

#include <QDialog>

namespace Ui {
class NewDialog;
}

class NewDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewDialog(QWidget *parent = 0);
    ~NewDialog();

    /*!
     * \brief Retrieve the values entered in this dialog.
     *
     * \return A pair of integer values making up the number of
     * rows and columns for the new map
     */
    std::pair<int,int> getValues();
private:
    Ui::NewDialog *ui;
};

#endif // NEWDIALOG_H
