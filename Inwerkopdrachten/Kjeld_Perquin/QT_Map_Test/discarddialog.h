#ifndef DISCARDDIALOG_H
#define DISCARDDIALOG_H

#include <QDialog>

namespace Ui {
class DiscardDialog;
}

class DiscardDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DiscardDialog(QWidget *parent = 0);
    ~DiscardDialog();

private:
    Ui::DiscardDialog *ui;
};

#endif // DISCARDDIALOG_H
