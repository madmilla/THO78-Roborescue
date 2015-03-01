#ifndef TILEEDITDIALOG_H
#define TILEEDITDIALOG_H
#include <QDialog>

class Tile;

namespace Ui {
class TileEditDialog;
}

class TileEditDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TileEditDialog(Tile* tile, QWidget *parent = 0);
    ~TileEditDialog();

private:
    Ui::TileEditDialog *ui;
};

#endif // TILEEDITDIALOG_H
