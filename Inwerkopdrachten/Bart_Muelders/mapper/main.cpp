#include "mainwindow.h"
#include "ObjectMap.h"
#include <iostream>
#include <QApplication>


void check(std::string description, bool success){
    std::cout << description << ": ";
    if (success){
        std::cout << " OK\n";
    }
    else{
        std::cout << " failed.\n";
        exit(1);
    }
 }



int test(ObjectMap & objectMap){
    std::cout << " starting test...\n";
    std::cout << " ==empty map==\n";
    objectMap.clear();
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            std::string s = "empty map (";
            s+= std::to_string(x);
            s+=",";
            s+= std::to_string(y);
            s+= ")";
            check(s, !objectMap.isObject(x, y) && objectMap.getHeight(x,y) == 0 );

        }
    }

    check("no vehicle placed", !objectMap.vehiclePlaced());
    check("vehicle location 0,0", objectMap.vehicleAt(0,0));


    std::cout << " ==object placements==\n";
    objectMap.setObject(3, 7, true);
    objectMap.setObject(40, 7, true);
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(x == 3 && y == 7){
                std::string s = "object at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, objectMap.isObject(x, y) );
            }
            else{
                std::string s = "no object at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, !objectMap.isObject(x, y) );
            }
        }
    }


    std::cout << " ==terrain level==\n";
    objectMap.setHeight(8, 9, 54);
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(x == 3 && y == 7){
                std::string s = "object at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, objectMap.isObject(x, y) &&  objectMap.getHeight(x, y) == 0);
            }
            else if(x == 8 && y == 9)
            {
                std::string s = "height ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                s+= " 54";
                check(s, objectMap.getHeight(x, y) == 54 && !objectMap.isObject(x, y));
            }
            else{
                std::string s = "height ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                s+= " 0";
                check(s, !objectMap.isObject(x, y) &&  objectMap.getHeight(x, y) == 0 );
            }
        }
    }

    std::cout << " ==vehicle placement==\n";
    check("no vehicle placed", !objectMap.vehiclePlaced());
    objectMap.setVehicle(6, 8);
    check("vehicle placed", objectMap.vehiclePlaced());
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(x == 6 && y == 8){
                std::string s = "vehicle at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, objectMap.vehicleAt(x, y));
            }
            else{
                std::string s = "no vehicle at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, !objectMap.vehicleAt(x, y));
            }
        }
    }


    std::cout << " ==vehicle re-placement==\n";
    check("vehicle placed", objectMap.vehiclePlaced());
    objectMap.setVehicle(19, 16);
    check("vehicle re-placed", objectMap.vehiclePlaced());
    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(x == 19 && y == 16){
                std::string s = "vehicle at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, objectMap.vehicleAt(x, y));
            }
            else{
                std::string s = "no vehicle at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, !objectMap.vehicleAt(x, y));
            }
        }
    }

    std::cout << " ==save/load file==\n";
    objectMap.save();
    objectMap.clear();

    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            std::string s = "empty map (";
            s+= std::to_string(x);
            s+=",";
            s+= std::to_string(y);
            s+= ")";
            check(s, !objectMap.isObject(x, y) && objectMap.getHeight(x,y) == 0 );

        }
    }

    objectMap.load();

    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(x == 19 && y == 16){
                std::string s = "vehicle at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, objectMap.vehicleAt(x, y));
            }
            else{
                std::string s = "no vehicle at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, !objectMap.vehicleAt(x, y));
            }
        }
    }

    for(int x = 0; x < 20; ++x){
        for(int y = 0; y < 20; ++y){
            if(x == 3 && y == 7){
                std::string s = "object at ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                check(s, objectMap.isObject(x, y) &&  objectMap.getHeight(x, y) == 0);
            }
            else if(x == 8 && y == 9)
            {
                std::string s = "height ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                s+= " 54";
                check(s, objectMap.getHeight(x, y) == 54 && !objectMap.isObject(x, y));
            }
            else{
                std::string s = "height ";
                s+= std::to_string(x);
                s+=",";
                s+= std::to_string(y);
                s+= " 0";
                check(s, !objectMap.isObject(x, y) &&  objectMap.getHeight(x, y) == 0 );
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[])
{
   ObjectMap objectMap;

   if(argc > 1 && strcmp(argv[1], "-test") == 0){

        std::cout << "test mode";
        test(objectMap);
        return 0;
   }
   else{

        QApplication a(argc, argv);
        MainWindow w(objectMap);
        w.show();
        return a.exec();
   }
}



