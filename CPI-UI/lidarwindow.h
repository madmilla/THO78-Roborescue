#ifndef LIDARWINDOW_H
#define LIDARWINDOW_H

#include <QMainWindow>

namespace Ui {
class lidarwindow;
}

class lidarwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit lidarwindow(QWidget *parent = 0);
    ~lidarwindow();

private slots:
    void on_lineEdit_returnPressed();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_setRpm_returnPressed();

    void on_startLidar_clicked();

    void on_stopLidar_clicked();

private:
    Ui::lidarwindow *ui;
};

#endif // LIDARWINDOW_H
