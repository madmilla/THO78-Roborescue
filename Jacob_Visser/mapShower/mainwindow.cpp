#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createActions();
    createMenus();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createActions(){
     newAct = new QAction(tr("&New"), this);
     newAct->setShortcuts(QKeySequence::New);  //control+n werkt ook als new file
     newAct->setStatusTip(tr("Create a new file"));
     connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

     openAct = new QAction(tr("&Open..."), this);
     openAct->setShortcuts(QKeySequence::Open); //control+o werkt ook om te openen
     openAct->setStatusTip(tr("Open an existing file"));
     connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

     exitAct = new QAction(tr("E&xit"), this);
     exitAct->setShortcuts(QKeySequence::Quit);
     exitAct->setStatusTip(tr("Exit the application"));
     connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::createMenus(){
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
}


void MainWindow::showMap(objectMap& map){
        QLayoutItem *item;
        for(int i = 0; i < horizontalLines.size(); ++i){

            while ((item = horizontalLines[i]->takeAt(0)) != 0) {
                delete item;
            }
        }
        while ((item = verticalLines.takeAt(0)) != 0) {
            delete item;
        }
        horizontalLines.clear();

    for(int i = 1; i <= map.getSize().y; i++){ //Y!
        horizontalLines.push_back(new QHBoxLayout);
        verticalLines.addLayout(horizontalLines[i-1]);
        //voeg horizontale + verticale lijnen toe
        for(int j = 1; j <= map.getSize().x; j++ ){ //X!
            object obj = (object)map.getObject(j, i);
            QImage image(getIcon(obj));
            QLabel * picLabel = new QLabel;
            picLabel->setPixmap(QPixmap::fromImage(image).scaled(26, 26, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            horizontalLines[i-1]->addWidget(picLabel);
        }
    }
    tileMap.setLayout(&(verticalLines));
    setCentralWidget(&tileMap);
    show();
}

void MainWindow::newFile(){
    QStringList filePath = QFileDialog::getSaveFileName(this,  //load map
             tr("Make a new map"), "Maps/mapje",
             tr("Map (*.txt)")).split("/");
    if(filePath.isEmpty()){
        return;
    }
    QStringList file = filePath.value(filePath.length() -1).split(".");
    QString fileName = file.value(file.length() -2);

    map = objectMap(20, 20, fileName.toStdString()); //20 is coded map size
    qDebug() << "file: "<< fileName;
    showMap(map);
 }

 void MainWindow::open(){
    QStringList filePath = QFileDialog::getOpenFileName(this,
            tr("Open map"), "Maps/",
            tr("Map (*.txt)")).split("/");
    if(filePath.isEmpty()){
        return;
    }
    QStringList file = filePath.value(filePath.length() -1).split(".");
    QString fileName = file.value(file.length() -2);
qDebug() << "file: "<< fileName;
    map = objectMap(fileName.toStdString());

    showMap(map);

 }

 QString MainWindow::getIcon(object obj){
     QString pathName;
     for(auto &object : objectss){
         if(obj == object.obj){

             pathName = QString::fromStdString(object.path);
         }
     }
     return pathName;
 }

