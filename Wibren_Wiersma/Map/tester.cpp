#include "tester.h"
#include "iostream"
#include "map.h"
#include "mapreadfailure.h"

class CleanMapTest : public Test{
    std::string name() override{
        return "clean map";
    }

    bool test() override{
        std::string filename = "temp.dat";
        Map::createEmpty(filename, 20, 20);

        try{
            Map map{filename};

            for(unsigned int r = 0; r < map.rowCount(); r++){
                for(unsigned int c = 0; c < map.collomCount(); c++){
                    if(map.get(r, c) != 0){
                        std::cerr << "Value is not 0\n";
                        return succeed = false;
                    }
                }
            }

            return succeed = true;
        }catch(MapReadFailure mrf){
            std::cerr << "Error: " << mrf.what() << '\n';
            return succeed = false;
        }
    }
};

class EditMapTest : public Test{
    std::string name() override{
        return "edit map";
    }

    bool test() override{
        std::string filename = "temp.dat";
        Map::createEmpty(filename, 20, 20);

        try{
            Map map{filename};

            for(int i = 0; i < 10; i++){
                unsigned int row = rand() % map.rowCount();
                unsigned int collom = rand() % map.collomCount();
                unsigned int value = 1 <<( rand() % 30);
                map.set(value, row, collom);
                if(map.get(row, collom) != value){
                    std::cerr << "Value is not been set / Random value test\n";
                    return succeed = false;
                }
            }

            for(unsigned int r = 0; r < map.rowCount(); r++){
                for(unsigned int c = 0; c < map.collomCount(); c++){
                    map.set(0, r, c);
                    if(map.get(r, c) != 0){
                        std::cerr << "Value is not set to 0 / Clear test\n";
                        return succeed = false;
                    }
                }
            }

            map.set(1, 25, 30);

            for(unsigned int r = 0; r < map.rowCount(); r++){
                for(unsigned int c = 0; c < map.collomCount(); c++){
                    if(r == 25 && c == 30){
                        if(map.get(r, c) != 1){
                            std::cerr << "Value is not set to 1 / edit only 1 test\n";
                            return succeed = false;
                        }
                    } else if(map.get(r, c) != 0){
                        std::cerr << "Value is not 0 / edit only 1 test\n";
                        return succeed = false;
                    }
                }
            }

            return succeed = true;
        }catch(MapReadFailure mrf){
            std::cerr << "Error: " << mrf.what() << '\n';
            return succeed = false;
        }
    }
};

class SaveMapTest : public Test{
    std::string name() override{
        return "save map";
    }

    bool test() override{
        std::string filename = "temp.dat";
        Map::createEmpty(filename, 20, 20);

        try{
            Map map{filename};

            map.set(1, 25, 30);

            map.save();
            map = Map{filename};

            for(unsigned int r = 0; r < map.rowCount(); r++){
                for(unsigned int c = 0; c < map.collomCount(); c++){
                    if(r == 25 && c == 30){
                        if(map.get(r, c) != 1){
                            std::cerr << "Value is not set to 1\n";
                            return succeed = false;
                        }
                    } else if(map.get(r, c) != 0){
                        std::cerr << "Value is not 0\n";
                        return succeed = false;
                    }
                }
            }

            return succeed = true;
        }catch(MapReadFailure mrf){
            std::cerr << "Error: " << mrf.what() << '\n';
            return succeed = false;
        }
    }
};

class NamesTest : public Test{
    std::string name() override{
        return "names";
    }

    bool test() override{
        std::string filename = "temp.dat";
        Map::createEmpty(filename, 20, 20);

        try{
            Map map{filename};

            map.names().push_back("Wall");
            map.names().push_back("Me");

            if(map.names().at(1) != "Wall"){
                std::cerr << "Wall is not added or not on right position / Edited\n";
                return succeed = false;
            }
            if(map.names().at(2) != "Me"){
                std::cerr << "Me is not added or not on right position / Edited\n";
                return succeed = false;
            }

            map.save();

            map = Map{filename};

            if(map.names().at(1) != "Wall"){
                std::cerr << "Wall is not added or not on right position / Saved\n";
                return succeed = false;
            }
            if(map.names().at(2) != "Me"){
                std::cerr << "Me is not added or not on right position / Saved\n";
                return succeed = false;
            }

            return succeed = true;
        }catch(MapReadFailure mrf){
            std::cerr << "Error: " << mrf.what() << '\n';
            return succeed = false;
        }
    }
};




Tester::Tester()
{
    tests.push_back(new CleanMapTest());
    tests.push_back(new EditMapTest());
    tests.push_back(new SaveMapTest());
    tests.push_back(new NamesTest());
}

Tester::~Tester()
{
    for(Test * t : tests){
        delete t;
    }
}

int Tester::run(){
    int returner = 0;
    std::cout << "Start tests\n";
    for(Test * t : tests){
        std::cout << "[" << t->name() << "] Started\n";
        bool result = t->test();
        if(result){
            std::cout << "[" << t->name() << "] Succeed!\n";
        }else{
            std::cerr << "[" << t->name() << "] Failed!\n";
            std::cerr << "##########\n";
            returner++;
        }
    }
    return returner;
}
