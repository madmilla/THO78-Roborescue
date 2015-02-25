#ifndef LOADDIALOG_H
#define LOADDIALOG_H

#include <QDialog>

namespace Ui {
class loadDialog;
}

class loadDialog : public QDialog
{
    Q_OBJECT

public:
    explicit loadDialog(QWidget *parent = 0);
    ~loadDialog();

private slots:
    void on_LoadButton_clicked();

private:
    Ui::loadDialog *ui;
};

#endif // LOADDIALOG_H
