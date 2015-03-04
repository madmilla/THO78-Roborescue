#include "maplogic.h"
#include <QMessageBox>

// Called when testing without GUI
mapLogic::mapLogic(){
    map = create2DArray(20, 20);
    screenWidth = 480;
    screenHeight = 480;
}

// Called when testing with GUI
mapLogic::mapLogic(QWidget * parent)
{
    inst = parent;
    map = create2DArray(20, 20);
    screenWidth = inst->width();
    screenHeight = inst->height();
}

// Function that returns a 2D array based on the parameters height and width
int** mapLogic::create2DArray(unsigned height, unsigned width){
    int** array2D = 0;
    array2D = new int*[height];

    for (unsigned int h = 0; h < height; h++){
        array2D[h] = new int[width];
        for (unsigned int w = 0; w < width; w++){
            array2D[h][w] = EMPTY;
        }
    }

    return array2D;
}

// Destructor deletes map
mapLogic::~mapLogic(){
    delete map;
}

// Function that returns the map
int ** mapLogic::getMap(){
    return map;
}

// Function that clears map and resets the current file
void mapLogic::newFile(){    
    map = create2DArray(20, 20);
    curFile = "";
}

// Function that opens a file chosen with the QFileDialog
void mapLogic::openFile(){
    QString desktop = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    curFile = QFileDialog::getOpenFileName(inst, "Open Map", desktop, "Map Files (*.map)");
    readFile(curFile);
}

// Function that reads the filename parameter and populates the map
void mapLogic::readFile(QString filename){
    map = create2DArray(20, 20);

    QFile file(filename);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        int x = 0;
        while(!stream.atEnd()){
            QString line = stream.readLine();
            QStringList sLine = line.split(' ');
            for(int y = 0; y < 20; y++){
                map[y][x] = sLine[y].toInt();
            }
            ++x;
        }
        file.close();
    }
}

// Function that saves the current map to a file
void mapLogic::saveFile(){
    if(curFile == NULL || curFile == ""){
        QString desktop = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
        curFile = QFileDialog::getSaveFileName(inst, "Open Map", desktop, "Map Files (*.map)");
    }

    QFile file(curFile);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        for(int x = 0; x < HEIGHT; x++){
            for(int y = 0; y < WIDTH; y++){
                stream << QString::number(map[y][x]) << " ";
            }
            stream << "\n";
        }
    }
    file.close();
}

// Function that returns the cell position in the map
QVector2D mapLogic::getCell(QPoint point){
    int cellWidth = screenWidth / 20;
    int cellHeight = (screenHeight - OFFSET) / 20;

    int xPos = point.x();
    int yPos = point.y() - OFFSET;

    int columnPos = xPos / cellWidth;
    int rowPos = yPos / cellHeight;

    return QVector2D(columnPos, rowPos);
}

// Function that returns the celltype of parameter cell position from the map
int mapLogic::getCelltype(QVector2D point){
    return map[(int)point.x()][(int)point.y()];
}

// Function that changes a map grid item depending on the position of the mouse and the mouse button pressed
void mapLogic::mouseClicked(QPoint pos, Qt::MouseButtons button){
    QVector2D combo = getCell(pos);
    int row = combo.x();
    int column = combo.y();

    if(row < 20 && column < 20){
        switch(getCelltype(combo)){
            case EMPTY:
                map[row][column] = button == Qt::LeftButton ? OBJECT : COPTER;
                break;
            case OBJECT:
                map[row][column] = button == Qt::LeftButton ? EMPTY : COPTER;
                break;
            case COPTER:
                map[row][column] = button == Qt::LeftButton ? OBJECT : EMPTY;
                break;
            default:
                map[row][column] = EMPTY;
                break;
        }
    }
}

// Function that returns the map as QString
QString mapLogic::toString(){
    QString retn = "";
    for(int x = 0; x < WIDTH; x++){
        for (int y = 0; y < HEIGHT; y++){
            retn += "" + QString::number(map[x][y]) + " ";
        }
        retn += "\n";
    }
    return retn;
}
