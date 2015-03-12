#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionExit->setText("Exit");
    ui->actionLoad->setText("Load");
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->actionExit,SIGNAL(triggered()),this,SLOT(close()));
    connect(ui->actionLoad, SIGNAL(triggered()), this,SLOT(loadButton()));
    connect(ui->actionClear, SIGNAL(triggered()), this, SLOT(clearButton()));
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveButton()));
    connect(ui->tableWidget, SIGNAL( cellPressed (int, int) ),
                this, SLOT( cellSelected( int, int ) ) );

    clearButton();


}
void MainWindow::cellSelected(int nRow, int nCol)
{
    if(mode == 0){
        printAndSave(nRow, nCol, 0);
    }
    if(mode == 1){
        printAndSave(nRow, nCol, 1);
    }
    if(mode == 2){
        printAndSave(nRow, nCol, 2);
    }
}
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::clearButton(){
    for(int i = 0; i< MAX ; i++){
         for(int j = 0; j < MAX; j++){
             printOnScreen(i, j, Qt::white);
             printAndSave(i,j,0);
            }
        }
}

void MainWindow::loadButton(){
    QString charFromMap;
    int x = 0;
    int y = 0;

    filename = QFileDialog::getOpenFileName(this, ("Open File"), NULL, ("Data (*.txt)"));
    QFile file(filename);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        while(!file.atEnd())
        {
            QString line = in.readAll();

            for(int i = 0; i < line.length(); i++)
            {
                charFromMap = line.at(i);
                charFromMap.remove("\n");
                if(x >= MAX) {
                    x = 0;
                    y++;
                }
                int number =  charFromMap.toStdString().c_str()[0] - '0';
                if(number == FREE || number == OBSTACLE || number == ATW) {
                    MapObjects[x][y] = number; x++;  \
                }
            }
        }
        file.close();
    }
    showOnBoard();
}

void MainWindow::saveButton(){
    filename = QFileDialog::getSaveFileName(this, ("Save File"), NULL, tr("Data (*.txt)"));
    QFile output(filename);
    output.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&output);
    QString type;
    int enter = 0;
    for(int y = 0; y < MAX; y++)
    {
        for(int x = 0; x < MAX; x++)
        {
            if(enter == MAX){
                out << '\n';
                enter = 0;
            }
            out << QString::fromStdString(std::to_string(MapObjects[x][y])) << ' ';
            enter++;
        }
    }

}

void MainWindow::printOnScreen(int x, int y, QColor color){
    ui->tableWidget->setItem(x,y, new QTableWidgetItem());
    ui->tableWidget->item(x,y)->setBackgroundColor(color);
}

void MainWindow::showOnBoard(){
    for(int y = 0; y < MAX; y++){
        for(int x = 0; x < MAX; x++){
            if(MapObjects[x][y] == FREE){

                printOnScreen(x, y, Qt::white);
            }
            else if(MapObjects[x][y] == OBSTACLE)
            {
                printOnScreen(x, y, Qt::red);
            }
            else if(MapObjects[x][y] == ATW){
                printOnScreen(x,y, Qt::black);
            }
        }
    }
}

void MainWindow::on_radioButton_clicked(bool checked) //set cell free
{
    if(checked){
        mode = 0;

   }
   else{
        mode = 10;
    }
}

void MainWindow::on_radioButton_2_clicked(bool checked) //set obstacle
{\
    if(checked){
        mode = 1;
   }
    else{
        mode = 10;
    }

}


void MainWindow::on_radioButton_3_clicked(bool checked) //set Atv in cell
{
    if(checked){
         mode = 2;
    }
    else{
        mode = 10;
    }
}

void MainWindow::printAndSave(int x, int y, int color){
    if(color == 1){
        printOnScreen(x, y, Qt::red);
        MapObjects[x][y] = 1;
    }
    if(color == 0){
        printOnScreen(x, y, Qt::white);
        MapObjects[x][y] = 0;
    }
    if(color == 2){
        printOnScreen(x, y, Qt::black);
        MapObjects[x][y] = 2;
    }

}



