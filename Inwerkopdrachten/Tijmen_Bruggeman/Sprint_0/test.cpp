#include "test.h"

Test::Test()
{

}

Test::~Test()
{

}
void Test::print_map(Map & map){
    for(QString line: map.getMap()){
        std::cout << line.toStdString()<< "\n";
    }
}

void Test::Test_1(){
    Map map("test_1.map");
    if(map.checkMap()!= 1){
        std::cout << "MAP IS NIET CORRECT\n";
    }
    else{
        std::cout << "MAP IS CORRECT\n";
    }
    print_map(map);
    map.setObject('b',1,1);
    if(map.checkMap() != 1){
        std::cout << "MAP IS NIET CORRECT\n";
    }
    else{
        std::cout << "MAP IS CORRECT\n" << map.checkMap();
    }
    print_map(map);
}
