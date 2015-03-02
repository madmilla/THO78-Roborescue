#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Load_map_clicked()
{
    ui->listWidget->clear();
    QStringList nameFilter("*.map");
    QDir directory("");
    QStringList maps = directory.entryList(nameFilter);
    ui->listWidget->addItems(maps);
}

void MainWindow::on_Show_map_clicked()
{
    map->show_map();
}


void MainWindow::on_NewButton_clicked()
{
    bool xBool;
    bool yBool;
    int XSize = ui->XSizeField->displayText().toInt(&xBool);
    int YSize = ui->YSizeField->displayText().toInt(&yBool);
    if(xBool && yBool && YSize!=1){
        QVector<QString> load_map;
        for(int x = 0; x < YSize; x++){
            QString line;
            for(int i = 0; i < XSize; i++){
                line.append("X");
            }
            load_map.push_back(line);
        }
        map->setMap(load_map, "NEW MAP");
        map->show();
    }
}
void MainWindow::on_listWidget_currentTextChanged(const QString &currentText)
{
    QFile file(currentText);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QVector<QString> load_map;
    QTextStream stream(&file);
    ui->textEdit->setPlainText(file.readAll());
    file.seek(0);
    QString line = stream.readLine();

    while(!line.isNull()){
        load_map.push_back(line);
        line = stream.readLine();
    }
    map->setMap(load_map,currentText);
    file.close();
}
