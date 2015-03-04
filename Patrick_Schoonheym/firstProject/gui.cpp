#include "gui.h"
#include "ui_gui.h"

Gui::Gui(QPoint & SCREEN_SIZE, std::vector<QPixmap> & images, Map* map, QWidget *parent) :
    SCREEN_SIZE { SCREEN_SIZE },
    images { images},
    map { map},
    edit_mode { false },
    QDialog(parent),
    ui(new Ui::Gui)
{
    ui->setupUi(this);

    ui->beker_button->setEnabled(false);
    ui->deur_button->setEnabled(false);
    ui->muur_button->setEnabled(false);
    ui->plant_button->setEnabled(false);
    ui->tafel_button->setEnabled(false);

    selected_object = Objects::BEKER;
}

Gui::~Gui()
{
    delete ui;
    delete map;
}

void Gui::paintEvent(QPaintEvent* e) {
    QPainter painter;
    painter.begin(this);

    int x = 0;
    int y = 0;

    const int step = (int)SCREEN_SIZE.y()/map->getHeight();
    for(const QString & s : map->getMap()) {
        for(const QChar & c : s) {

            if(c == Objects::BEKER) {
                painter.drawPixmap(x, y, step, step, images[0]);
                QRect rect(x, y, step, step);
            }
            else if(c == Objects::DEUR) {
                painter.drawPixmap(x, y, step, step, images[1]);
            }
            else if(c == Objects::MUUR) {
                painter.drawPixmap(x, y, step, step, images[2]);
            }
            else if(c == Objects::PLANT) {
                painter.drawPixmap(x, y, step, step, images[3]);
            }
            else if(c == Objects::TAFEL) {
                painter.drawPixmap(x, y, step, step, images[4]);
            }
            x += step;
        }
        y += step;
        x = 0;
    }
    painter.end();
    update();
}

void Gui::changeMap() {
    if(edit_mode) {
        const int step = SCREEN_SIZE.y()/map->getHeight();

        int x = cursorPos.x();
        int y = cursorPos.y();

        if(x > SCREEN_SIZE.x() || y > SCREEN_SIZE.y())
            return;

        int x_index = 0;
        int y_index = 0;

        for(int i=0; i<SCREEN_SIZE.y(); i+=step) {
            if(x > step) {
                x_index++;
                x -= step;
            }
            if(y > step) {
                y_index++;
                y -= step;
            }
        }
        map->getMap()[y_index][x_index] = selected_object;
    }
}

void Gui::mouseMoveEvent(QMouseEvent *event) {
    cursorPos.setX(event->pos().x());
    cursorPos.setY(event->pos().y());
    changeMap();
}

void Gui::mousePressEvent(QMouseEvent *event) {
    cursorPos.setX(event->pos().x());
    cursorPos.setY(event->pos().y());
    changeMap();
}

void Gui::on_beker_button_clicked()
{
    selected_object = Objects::BEKER;
}

void Gui::on_deur_button_clicked()
{
    selected_object = Objects::DEUR;
}

void Gui::on_muur_button_clicked()
{
    selected_object = Objects::MUUR;
}

void Gui::on_plant_button_clicked()
{
    selected_object = Objects::PLANT;
}

void Gui::on_tafel_button_clicked()
{
    selected_object = Objects::TAFEL;
}

void Gui::on_edit_button_clicked() {
    if(!edit_mode) {
        ui->beker_button->setEnabled(true);
        ui->beker_button->setChecked(true);
        ui->deur_button->setEnabled(true);
        ui->muur_button->setEnabled(true);
        ui->plant_button->setEnabled(true);
        ui->tafel_button->setEnabled(true);
        ui->edit_button->setText("safe as");
    }
    else {
        QString name = QFileDialog::getSaveFileName(this, tr("Save as"),
        QString(), tr("map files (*.map);;All Files (*)"));
        QFile file(name);

        if(!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
            std::cout << "could not load image with path" << name.toStdString() << "\n";
        }
        else {
            QTextStream stream( &file );
            for(auto & s : map->getMap()) {
                stream << s << '\n';
            }
        }
     file.close();
    }
    edit_mode = true;
}
