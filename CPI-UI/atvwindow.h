#ifndef ATVWINDOW_H
#define ATVWINDOW_H

#include <QWidget>

namespace Ui {
class ATVWindow;
}

class ATVWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ATVWindow(QWidget *parent = 0);
    ~ATVWindow();

private:
    Ui::ATVWindow *ui;
};

#endif // ATVWINDOW_H
