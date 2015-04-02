#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>

namespace Ui {
class exitDialog;
}

class exitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit exitDialog(QWidget *parent = 0);
    ~exitDialog();

public slots:
    void quit();

private:
    Ui::exitDialog *ui;
};

#endif // EXITDIALOG_H
