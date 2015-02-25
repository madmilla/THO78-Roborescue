#ifndef MAPWINDOW_H
#define MAPWINDOW_H

#include <QMainWindow>

namespace Ui {
class MapWindow;
}

class MapWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MapWindow(QWidget * MainWindow,QWidget *parent = 0);
    ~MapWindow();

private slots:
    void on_actionSave_triggered();
    void closeEvent (QCloseEvent *event);

private:
    Ui::MapWindow *ui;
    QWidget *MainWindow;
};

#endif // MAPWINDOW_H
