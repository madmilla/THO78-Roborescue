#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mapreadfailure.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QInputDialog>
#include <QGraphicsScene>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    map{nullptr},
    isDisplayingFile{false},
    currentHover{nullptr}
{
    ui->setupUi(this);

    connect(ui->actionClose_program, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->actionCreate_new, SIGNAL(triggered()), this, SLOT(createFile()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
    connect(ui->actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(ui->tableWidget, SIGNAL(cellDoubleClicked(int,int)), this, SLOT(editCell(int,int)));
}

MainWindow::~MainWindow() {
    closeFile();
    delete ui;
}

void MainWindow::openFile(){
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), QString(), tr("Data (*.dat)"));
    if(fileName != nullptr){
        openFile(fileName.toStdString());
    }
}

void MainWindow::openFile(std::string filename){
    closeFile();
    try{
        map = new Map(filename);
        setDisplayingFile(true);

        //tabelWidget resize settings
        ui->tableWidget->setColumnCount(map->collomCount());
        ui->tableWidget->setRowCount(map->rowCount());
        for (int c = 0; c < ui->tableWidget->horizontalHeader()->count(); ++c){
            ui->tableWidget->horizontalHeader()->setSectionResizeMode(c, QHeaderView::Stretch);
        }
        for (int r = 0; r < ui->tableWidget->horizontalHeader()->count(); ++r){
            ui->tableWidget->verticalHeader()->setSectionResizeMode(r, QHeaderView::Stretch);
        }

        //add items to tableWidget
        for(unsigned int r = 0; r < map->rowCount(); r++){
            for(unsigned int c = 0; c < map->collomCount(); c++){
                GridPart * gp = new GridPart(map->get(r, c));
                ui->tableWidget->setItem(r, c, gp->getWidget());
                gridContent.push_back(gp);
            }
        }

        for(std::string dataName : map->names()){
            QAction * temp = ui->menuEdit->addAction(QString::fromStdString(dataName));
            connect(temp, SIGNAL(triggered()), this, SLOT(editAction()));
        }

        ui->menuEdit->addSeparator();
        QAction * temp = ui->menuEdit->addAction(tr("Add..."));
        connect(temp, SIGNAL(triggered()), this, SLOT(addName()));
    }catch(MapReadFailure prf){
        QMessageBox::critical(
                    this,
                    tr("Error while loading file"),
                    QString::fromStdString(std::string{"Error while loading file: "} + prf.what())
        );
        closeFile();
    }
}

void MainWindow::createFile(){
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), QString(), tr("Data (*.dat)"));
    if(fileName != nullptr){
        bool ok;
        int width = QInputDialog::getInt(this, tr("Width of map"), "Input the WIDTH of the map", 1, 1, 2147483647, 1, &ok);
        if(!ok) return;
        int height = QInputDialog::getInt(this, tr("Height of map"), "Input the HEIGHT of the map", 1, 1, 2147483647, 1, &ok);
        if(!ok) return;
        Map::createEmpty(fileName.toStdString(), (unsigned int)height, (unsigned int)width);
        openFile(fileName.toStdString());
    }
}

void MainWindow::saveFile(){
    if(map != nullptr) map->save();
}

void MainWindow::closeFile(){
    if(map != nullptr){
        delete map;
        map = nullptr;
        setDisplayingFile(false);
        ui->tableWidget->setColumnCount(0);
        ui->tableWidget->setRowCount(0);
        for(GridPart * content : gridContent){
            delete content;
        }
        gridContent.clear();
        ui->menuEdit->clear();
    }
}

void MainWindow::setDisplayingFile(bool value){
    if(value != isDisplayingFile){
        ui->actionClose->setEnabled(value);
        ui->actionSave->setEnabled(value);
        ui->actionCreate_new->setEnabled(!value);
        ui->actionOpen->setEnabled(!value);
        ui->menuEdit->setEnabled(value);
        isDisplayingFile = value;
    }
}

void MainWindow::addName(){
    if(map != nullptr){
        bool ok;
        QString name = QInputDialog::getText(this, tr("Name"), tr("Type the name"), QLineEdit::Normal, QString(), &ok);
        if(ok){
            map->names().push_back(name.toStdString());

            ui->menuEdit->clear();
            for(std::string dataName : map->names()){
                QAction * temp = ui->menuEdit->addAction(QString::fromStdString(dataName));
                connect(temp, SIGNAL(triggered()), this, SLOT(editAction()));
            }

            ui->menuEdit->addSeparator();
            QAction * temp = ui->menuEdit->addAction(tr("Add..."));
            connect(temp, SIGNAL(triggered()), this, SLOT(addName()));
        }
    }
}

void MainWindow::editAction(){
    QAction * action = static_cast<QAction *>(sender());
    if(map != nullptr && action != nullptr){
        std::string name = action->text().toStdString();
        unsigned int i = 0;
        for(; i < map->names().size(); i++){
            if(name == map->names().at(i)){
                break;
            }
        }

        if(i != map->names().size()){
            for(QTableWidgetItem * twi : ui->tableWidget->selectedItems()){
                map->set(i, twi->row(), twi->column());
                if(i == 0){
                    GridPart::changeData(i, twi);
                }else{
                    GridPart::changeData(1 << (i - 1), twi);
                }
            }
        }
    }
}

void MainWindow::editCell(int row, int collom){
    row = collom * 2; collom = row * 3;//resolve warning
    ui->menuEdit->exec(QCursor::pos());
}
