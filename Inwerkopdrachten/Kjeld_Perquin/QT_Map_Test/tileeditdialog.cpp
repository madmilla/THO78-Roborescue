#include "tileeditdialog.h"
#include "ui_tileeditdialog.h"
#include "tile.h"

TileEditDialog::TileEditDialog(Tile* tile, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TileEditDialog)
{
    ui->setupUi(this);
}

TileEditDialog::~TileEditDialog()
{
    delete ui;
}
