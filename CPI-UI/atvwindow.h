#ifndef ATVWINDOW_H
#define ATVWINDOW_H

#include <QMainWindow>

namespace Ui {
class ATVWindow;
}

class ATVWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit ATVWindow(QWidget *parent = 0);
    ~ATVWindow();

private slots:
   void handleButton();

private:
    Ui::ATVWindow *ui;
};

#endif // ATVWINDOW_H
