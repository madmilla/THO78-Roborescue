#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QJsonObject>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:

private slots:
    void saveMap();

    void loadMap();

    void clearMap();

    void refreshMap();

    void on_actionClear_clicked();

    void on_actionSave_clicked();

    void on_actionReload_clicked();

    void setHeight(int x, int y, int height);

    void setObject(int x, int y, bool object);

    bool isObject(int x, int y);

    int getHeight(int x, int y);

    void on_heightSelection_valueChanged(int arg1);

    void on_radioDriveable_toggled(bool checked);

    void on_radioObject_toggled(bool checked);

    void on_map_currentCellChanged(int currentRow, int currentColumn, int previousRow, int previousColumn);

private:
    Ui::MainWindow *ui;

    QJsonObject json;
};

#endif // MAINWINDOW_H
