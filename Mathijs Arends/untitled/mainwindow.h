#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QContextMenuEvent>
#include <QMainWindow>
#include "widget.h"
#include "QMouseEvent"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  explicit MainWindow(Widget *widget,QWidget *parent = 0);
  ~MainWindow();
private slots:
    void on_actionAddObject_triggered();

    void on_actionSelectObject1_triggered();

    void on_actionSelectObject2_triggered();

    void on_actionSelectFile_triggered();

    void on_actionQuit_triggered();

private:
    int selectedType=1;
    Widget* widget;
  Ui::MainWindow *ui;
protected:
  void mousePressEvent(QMouseEvent* event);
};

#endif // MAINWINDOW_H
