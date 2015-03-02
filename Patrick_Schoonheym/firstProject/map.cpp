#include "map.h"
#include "ui_map.h"

Map::Map(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Map),
    edit_mode { false}
{
    ui->setupUi(this);

    addImage(":/images/beker.jpg");
    addImage(":/images/deur.jpg");
    addImage(":/images/muur.jpg");
    addImage(":/images/plant.jpg");
    addImage(":/images/tafel.jpg");

    ui->beker->setEnabled(false);
    ui->deur->setEnabled(false);
    ui->muur->setEnabled(false);
    ui->plant->setEnabled(false);
    ui->tafel->setEnabled(false);
}

Map::~Map()
{
    delete ui;
}

void Map::addImage(const QString & name) {
    QPixmap image;

    if(!image.load(name)) {
        qDebug() << "could not load image with path" << name << "\n";
        return;
    }
    images.push_back(image);
}

void Map::setMap(std::vector<QString> & map) {
    this->map = map;
}

void Map::paintEvent(QPaintEvent* e) {
    QPainter painter;
    painter.begin(this);

    int x = 0;
    int y = 0;
    const int grootte = 480/static_cast<int>(map.size());
    for(const QString & s : map) {
        for(const QChar & c : s) {

            if(c == Objects::BEKER) {
                painter.drawPixmap(x, y, grootte, grootte, images[0]);
                QRect rect(x, y, grootte, grootte);
            }
            else if(c == Objects::DEUR) {
                painter.drawPixmap(x, y, grootte, grootte, images[1]);
            }
            else if(c == Objects::MUUR) {
                painter.drawPixmap(x, y, grootte, grootte, images[2]);
            }
            else if(c == Objects::PLANT) {
                painter.drawPixmap(x, y, grootte, grootte, images[3]);
            }
            else if(c == Objects::TAFEL) {
                painter.drawPixmap(x, y, grootte, grootte, images[4]);
            }
            x += grootte;
        }
        y += grootte;
        x = 0;
    }
    painter.end();
    update();
}

void Map::mouseMoveEvent(QMouseEvent *event) {
     if(edit_mode) {
         const int grootte = 480/static_cast<int>(map.size());

         int x = event->pos().x();
         int y = event->pos().y();

         if(x > 480 || y > 480)
             return;

         int x_index = 0;
         int y_index = 0;

         for(int i=0; i<480; i+=grootte) {
             if(x > grootte) {
                 x_index++;
                 x -= grootte;
             }
             if(y > grootte) {
                 y_index++;
                 y -= grootte;
             }
         }
         map[y_index][x_index] = selected_object;
     }
 }

void Map::on_beker_clicked()
{
    ui->deur->setChecked(false);
    ui->muur->setChecked(false);
    ui->plant->setChecked(false);
    ui->tafel->setChecked(false);
    selected_object = Objects::BEKER;
}

void Map::on_deur_clicked()
{
    ui->beker->setChecked(false);
    ui->muur->setChecked(false);
    ui->plant->setChecked(false);
    ui->tafel->setChecked(false);
    selected_object = Objects::DEUR;
}

void Map::on_muur_clicked()
{
    ui->beker->setChecked(false);
    ui->deur->setChecked(false);
    ui->plant->setChecked(false);
    ui->tafel->setChecked(false);
    selected_object = Objects::MUUR;
}

void Map::on_plant_clicked()
{
    ui->deur->setChecked(false);
    ui->muur->setChecked(false);
    ui->beker->setChecked(false);
    ui->tafel->setChecked(false);
    selected_object = Objects::PLANT;
}

void Map::on_tafel_clicked()
{
    ui->deur->setChecked(false);
    ui->muur->setChecked(false);
    ui->beker->setChecked(false);
    ui->plant->setChecked(false);
    selected_object = Objects::TAFEL;
}

void Map::on_edit_button_clicked()
{
    if(!edit_mode) {
        ui->beker->setEnabled(true);
        ui->beker->setChecked(true);
        selected_object = Objects::BEKER;
        ui->deur->setEnabled(true);
        ui->muur->setEnabled(true);
        ui->plant->setEnabled(true);
        ui->tafel->setEnabled(true);
        ui->edit_button->setText("safe as");
    }
    else {
        QString name = QFileDialog::getSaveFileName(this, tr("Save as"),
        QString(), tr("map files (*.map);;All Files (*)"));
        QFile file(name);

        if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            qDebug() << "could not load image with path" << name << "\n";
        }
        else {
            QTextStream stream( &file );
            for(auto & s : map) {
               stream << s << '\n';
            }
        }
        file.close();
    }
    edit_mode = true;
}






















