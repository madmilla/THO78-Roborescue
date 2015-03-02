#include "maplogic.h"
#include <QMessageBox>

mapLogic::mapLogic(QWidget * parent)
{
    inst = parent;
    for(int x = 0; x < WIDTH; x++){
        for (int y = 0; y < HEIGHT; y++){
            map[x][y] = EMPTY;
        }
    }
    //std::cout << toString().toUtf8().constData();;
}

mapLogic::~mapLogic(){
    std::cout << "Deleting mapLogic\n";
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
    QMessageBox Msgbox;
    Msgbox.setText("coors: " + QString::number(pos.x()) + "; " + QString::number(pos.y() - OFFSET));
    Msgbox.exec();
}

int mapLogic::getCellType(){

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
