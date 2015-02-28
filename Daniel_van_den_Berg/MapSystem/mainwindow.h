#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "mapeditor.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    static MainWindow* MainWindow::getInstance();
    ~MainWindow();
    MapEditor* getMapEditor();

    static MapEditor::Objects MainWindow::selectedObject;
    static int MainWindow::shouldEdit;

private slots:
    void on_Load_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_clicked(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

private:
    Ui::MainWindow *ui;
    void MainWindow::loadMaps();
};

#endif // MAINWINDOW_H
