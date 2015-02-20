#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QPainter>
#include <QColor>
#include <Qt>
#include "QMessageBox"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;



protected:
    void paintOnce();
    void paintEvent(QPaintEvent *e);
private slots:
    void on_Load_clicked();
    void on_Quit_clicked();
    void on_Editor_clicked();
    void on_ReloadFiles_clicked();
    void on_Newmap_clicked();
    void on_Delete_clicked();
};

#endif // MAINWINDOW_H
