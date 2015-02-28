#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QFileDialog>
#include <mapProcessor.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_openFileButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    QString mapFile;
};

#endif // MAINWINDOW_H
