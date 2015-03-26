#ifndef EDITMAPWINDOW_H
#define EDITMAPWINDOW_H

#include <QDialog>

namespace Ui {
class EditMapWindow;
}

class EditMapWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditMapWindow(QWidget *parent = 0);
    void showMap(Map* map);
    ~EditMapWindow();

private slots:
    void on_obstacleButton_clicked();

    void on_saveMapButton_clicked();

private:
    Ui::EditMapWindow *ui;
};

#endif // EDITMAPWINDOW_H
