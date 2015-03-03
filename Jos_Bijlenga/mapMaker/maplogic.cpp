#include "maplogic.h"
#include <QMessageBox>

mapLogic::mapLogic(QWidget * parent)
{
    inst = parent;
    /*for(int x = 0; x < WIDTH; x++){
        for (int y = 0; y < HEIGHT; y++){
            map[x][y] = EMPTY;
        }
    }*/
    //std::cout << toString().toUtf8().constData();

    map = create2DArray(20, 20);
}

int** mapLogic::create2DArray(unsigned height, unsigned width){
      int** array2D = 0;
      array2D = new int*[height];

      for (int h = 0; h < height; h++)
      {
            array2D[h] = new int[width];

            for (int w = 0; w < width; w++)
            {
                  // fill in some initial values
                  // (filling in zeros would be more logic, but this is just for the example)
                  array2D[h][w] = 0;
            }
    }

    return array2D;
}

mapLogic::~mapLogic(){
    std::cout << "Deleting mapLogic\n";
}

int ** mapLogic::getMap(){
    return map;
}

void mapLogic::newFile(){

}

void mapLogic::openFile(){
    QString desktop = QStandardPaths::writableLocation(QStandardPaths::DesktopLocation);
    QString curFile = QFileDialog::getOpenFileName(inst, "Open Image", desktop, "Map Files (*.map)");
}

void mapLogic::saveFile(){

}

void mapLogic::mouseClicked(QPoint pos){
    //Modify map -> check pos compared to map and check current value
    //React accordingly and change value (or not)
    //Repaint inst->repaint();
}

int mapLogic::getCellType(){
    return 0;
}

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
