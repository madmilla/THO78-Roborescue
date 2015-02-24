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
                    if((unsigned int)map.get(r, c) != 0){
                        std::cerr << "row: " << r << " collom: " << c << " is not empty!\n";
                        return succeed = false;
                    }
                }
            }
            return succeed = true;
        }catch(MapReadFailure mrf){
            std::cerr << "Error: " << mrf.what();
            return succeed = false;
        }
    }
};





Tester::Tester()
{
    tests.push_back(new CleanMapTest());
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
