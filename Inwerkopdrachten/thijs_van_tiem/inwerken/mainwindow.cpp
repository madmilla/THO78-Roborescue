#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionExit->setText("Exit");
    ui->actionLoad->setText("Load");
    ui->actionSave->setText("Save");
    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close())); // slot reageerd op signiaal dat er een cel is geselecteerd
    map * M = new map;
    activemap = M; //dus een verwijzing naar m

    for(int i=0; i <20; i++){
        for(int x=0; x<20; x++){
            ui->tableWidget->setItem(i,x,M->getcel(i,x)->formatCell());
        }
    }

    // pakt dus hieronder telkens de active cell
    connect(ui->tableWidget,SIGNAL(currentCellChanged(int,int,int,int)),this,SLOT(currentCellChanged(int,int,int,int))); // heeft zelf door dat hij de ints mag doorgeven




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::currentCellChanged(int xn, int yn, int xo, int yo)
{
    activecell = activemap->getcel(xn,yn); // dit is de nieuwe active cell
}

void MainWindow::on_actionExit_triggered()
{
    qDebug() <<  "exit pressed \n";
}

void MainWindow::on_actionSave_triggered()
{
    qDebug() << "Save pressed \n";
    QString name = QFileDialog::getSaveFileName(this, tr("Save file"), QString(), tr("Data (*.txt)"));
    savefile(name);
}

void MainWindow::on_actionLoad_triggered()
{
    qDebug() << "Load pressed \n";
    loadFile();
}

void MainWindow::on_RadioEmpty_clicked(bool checked)
{
    if(checked){
        qDebug() << "empty geselecteerd\n";
        activecell->changeTerrein(terreinTypen::none);
    }
    else{

    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::on_RadioQuad_clicked(bool checked)
{
    if(checked){
        qDebug() << "Quad geselecteerd \n";
        activecell->changeTerrein(terreinTypen::quad);
    }
    else{

    }
        ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());




}

void MainWindow::on_RadioATV_clicked(bool checked)
{
    if(checked){
        qDebug() << "ATV geselecteerd \n";
        activecell->changeTerrein(terreinTypen::atv);

    }
    else{

    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::on_RadioRosbee_clicked(bool checked)
{
    if(checked){
        qDebug() << "ROSBEE geselecteerd \n";
        activecell->changeTerrein(terreinTypen::rosbee);
    }
    else{

    }
   ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::on_RadioConcrete_clicked(bool checked)
{
    if(checked){
        qDebug() << "Concrete geselecteerd \n";
        activecell->changeTerrein(terreinTypen::concrete);

    }
    else{

    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}


void MainWindow::on_RadioGreen_clicked(bool checked)
{
    if(checked){
        qDebug() << "Green geselecteerd \n";
        activecell->changeTerrein(terreinTypen::green);
    }
    else{

    }

   ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());

}


void MainWindow::on_RadioWater_clicked(bool checked)
{
    if(checked){
        qDebug() << "Water geselecteerd \n";
        activecell->changeTerrein(terreinTypen::water);
    }
    else{

    }
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),activemap->getcel(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn())->formatCell());
}

void MainWindow::savefile(const QString &name)
{
    QFile file(name);

    if (file.open(QFile::WriteOnly))
    {
        QTextStream data( &file );
        for (int r = 0; r < ui->tableWidget->rowCount(); ++r){
            for( int c = 0; c < ui->tableWidget->columnCount(); ++c ){
                data << (int)activemap->getcel(r,c)->omgeving << " ";
                std::cout << (int)activemap->getcel(r,c)->omgeving;
            }
        }
      file.close();
    }
}


void MainWindow::loadFile()
{
    fileName = QFileDialog::getOpenFileName(this, ("Open File"), NULL, ("Data (*.txt)"));

    std::ifstream loadFile(fileName.toStdString().c_str());
    if(loadFile){
        for (int r = 0; r < ui->tableWidget->rowCount(); ++r){
            for( int c = 0; c < ui->tableWidget->columnCount(); ++c ){
                int i;
                loadFile >> i;
                std::cout << i;
                activemap->getcel(r,c)->omgeving = (terreinTypen)i;
                ui->tableWidget->setItem(r,c,activecell->formatCellLoad(i));
            }
        }
    }


}

// meest recent ingedrukt table opvragen met currentCollom en CurrentRow
