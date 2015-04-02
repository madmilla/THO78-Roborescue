#ifndef QUADCOPTERWINDOW_H
#define QUADCOPTERWINDOW_H

#include <QMainWindow>

namespace Ui {
class QuadCopterWindow;
}

class QuadCopterWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit QuadCopterWindow(QWidget *parent = 0);
    ~QuadCopterWindow();

private:
    Ui::QuadCopterWindow *ui;
};

#endif // QUADCOPTERWINDOW_H
