#ifndef ATVWINDOW_H
#define ATVWINDOW_H

#include <QMainWindow>
#include "atv.h"

namespace Ui {
class ATVWindow;
}

class ATVWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ATVWindow(ATV * atv, QWidget *parent = 0);
    ~ATVWindow();

private slots:
   void handleButton();

   void scrollbarValueChanged(int value);

private:
    Ui::ATVWindow *ui;

    ATV * atv;
};

#endif // ATVWINDOW_H
