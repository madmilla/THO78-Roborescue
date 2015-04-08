#ifndef ATVWINDOW_H
#define ATVWINDOW_H

#include <QMainWindow>
#include <QTimer>
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

   void timerTick();

   void armed(bool is_armed);

private:
   ATV * atv;
   QTimer * timer;
   Ui::ATVWindow *ui;
};

#endif // ATVWINDOW_H
