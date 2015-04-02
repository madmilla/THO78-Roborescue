#include "mainwindow.h"

#include <QApplication>
#include <QVBoxLayout>
#include <QPushButton>

#ifdef TEST
#include "Libs/mapCreator.h"
#include <fstream>
int main(int argc, char *argv[])
{
    bool error = false;

    //test map -1 size LELIJKE TEST, MOET HERSCHREVEN
    if(1){
        objectMap map(-1, -1, "mapje-1");
        std::ifstream mapFile;
        mapFile.open("Maps/mapje-1.txt");
        if(mapFile.is_open()){
            error = true;
            std::cout << "map with -1 size could be made" << std::endl;
        }
        else{
            std::cout << "objectmap(-1, -1) failed, SUCCES!" << std::endl;
        }
    }

    //test map 20 size LELIJKE TEST, MOET HERSCHREVEN
    if(1){
        objectMap map(20, 20, "mapje20");
        std::ifstream mapFile;
        mapFile.open("Maps/mapje20.txt");
        if(!mapFile.is_open()){
            error = true;
            std::cout << "map with 20 size couldn't be made" << std::endl;
        }
        else{
            std::cout << "objectmap(20, 20) SUCCES!" << std::endl;
        }
        mapFile.close();
    }

    //check size LELIJKE TEST, MOET HERSCHREVEN
    if(1){
        objectMap map(10, 10, "mapje10");
        size mapSize;
        std::ifstream mapFile;
        mapFile.open("Maps/mapje10.txt");

        std::string tmp;
        std::getline(mapFile, tmp);
        mapSize.x = (int)tmp.length()/3;
        int ySize = 0;
        while(!mapFile.eof()){
            ++ySize;
            std::getline(mapFile, tmp);
        }
        mapSize.y = ySize;

        if(mapSize.x == 10 && mapSize.y == 10){
            std::cout << "Size make Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "Size make failed!" << std::endl;
        }
        if(map.getSize().x == 10 && map.getSize().y == 10){
             std::cout << "map.getSize Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "map.getSize failed!" << std::endl;
        }
        if(map.getSize("Maps/mapje10.txt").x == 10 && map.getSize("Maps/mapje10.txt").y == 10){
            std::cout << "map.getSize(mapname) Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "map.getSize(mapname) failed!" << std::endl;
        }

        if(map.getSize("mapje9.txt").x == -1 && map.getSize("mapje9.txt").y == -1){
            std::cout << "can't get size of non existing map, Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "can get size of non existing map, failed!" << std::endl;
        }

        mapFile.close();
    }

    //set object
    if(1){
        objectMap map(1, 1, "mapje1");

        if(map.setObject(-1, -1, object::water) == -1){
            std::cout << "Can't set object -1, Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "Can set object -1, failed!" << std::endl;
        }


        if(map.setObject(0, 0, object::water) == -1 ){
            std::cout << "Can't set object 0, Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "Can set object 0, failed!" << std::endl;
        }

        if(map.setObject(1, 1, object::water) == 0){
            if(map.getObject(1, 1) == (int)object::water){
                std::cout << "Can set object 1, Succes!" << std::endl;
            }
        }
        else{
            error = true;
            std::cout << "Can't set object 1, failed!" << std::endl;
        }
    }

    //get object
    if(1){
        objectMap map(1, 1, "mapje11");
        map.setObject(1, 1, object::quadcopter);

        if(map.getObject(-1, -1) == -1){
           std::cout << "Can't get object -1, Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "Can get object 1, Failed!" << std::endl;
        }

        if(map.getObject(0, 0) == -1){
           std::cout << "Can't get object 0, Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "Can get object 0, Failed!" << std::endl;
        }

        if(map.getObject(1, 1) == (int)object::quadcopter){
           std::cout << "Can get object 1, Succes!" << std::endl;
        }
        else{
            error = true;
            std::cout << "Can't get object 1, Failed!" << std::endl;
        }

    }

    return error;
}

#else
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;

    w.show();

    return a.exec();
}
#endif
