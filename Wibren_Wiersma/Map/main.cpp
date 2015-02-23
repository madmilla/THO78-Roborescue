
#include <QApplication>
#include <iostream>

#include "map.h"
#include "mapreadfailure.h"
#include "mainwindow.h"

void printMap(Map & map){
    for(unsigned int r = 0; r < map.rowCount(); r++){
        for(unsigned int c = 0; c < map.collomCount(); c++){
            std::cout << (unsigned int)map.get(r, c) << ' ';
        }
        std::cout << '\n';
    }
}

int main(int argc, char *argv[])
{
    if(argc > 1 && strcmp(argv[1], "-runtest") == 0){
        std::string filename = "temp.dat";
        Map::createEmpty(filename, 20, 20);

        try{
            Map map{filename};

            printMap(map);
        }catch(MapReadFailure mrf){
            std::cout << "Error: " << mrf.what();
            exit(1);
        }

        return 0;
    }else{
        QApplication app(argc,argv);
        MainWindow window;
        window.show();
        return app.exec();
    }

}
