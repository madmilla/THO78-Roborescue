#include "map.h"


map::map()
{

}

map::~map()
{

}


item *map::getcel(int x,int y){
    return &items[x][y];
}

void map::saveFile(QString fileName){
    QFile file(fileName);

    if (file.open(QFile::WriteOnly))
    {
        QTextStream data( &file );
        for (int r = 0; r < 20; ++r){
            for( int c = 0; c < 20; ++c ){
                data << (int)getcel(r,c)->t << " ";
                std::cout << (int)getcel(r,c)->t;
            }
        }
      file.close();
    }
}


void map::loadFile(QString fileName){
    std::ifstream loadFile;
    loadFile.open(fileName.toStdString().c_str());
    if(loadFile){
      for (int r = 0; r < 20 ; ++r){
          for( int c = 0; c < 20 ; ++c ){
          int i;
          loadFile >> i;
          getcel(r,c)->t = (terrain)i;
          }

      }

   }

}


