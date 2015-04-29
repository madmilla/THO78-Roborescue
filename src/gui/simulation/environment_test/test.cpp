#include "test.h"


Test::Test()
{

}

Test::~Test()
{

}

int Test::run(){
    std::cout << "Enviroment Simulator test begin" << std::endl;
    int error = 0;
    int size = 20;

    std::ofstream testResultsFile;
    testResultsFile.open("testResult.txt");
    if(!testResultsFile.is_open()){
        testResultsFile << "Result log: " << "Log file could not be opend" << std::endl;
        ++error;
    }

    testResultsFile << "Enviroment Simulator test begin" << std::endl;

    //Map from file
    testResultsFile << "Enviroment Simulator test Map from file" << std::endl;
    Map testFileMap("../testFileMap.map");

    if(static_cast<int>(testFileMap.getMapContent().size()) != size){
        testResultsFile << "Map from file: " << "Map y size incorret" << std::endl;
        ++error;
    }

    for(int y = 0; y < testFileMap.height; y++){
        for(int x = 0; x < testFileMap.width; x++){
            if(testFileMap.getMapContent()[y].size() != static_cast<unsigned int>(size)){
                testResultsFile << "Map from file: " << "Map x size incorret" << std::endl;
                ++error;
            }
            if(testFileMap.getMapObject(y,x) != 0){
                testResultsFile << "Map from file: " << "Conntent error. != 0" << std::endl;
                ++error;
            }
            testFileMap.setMapObject(1,y,x);
        }
    }

    for(int y = 0; y < testFileMap.height; y++){
        for(int x = 0; x < testFileMap.width; x++){
            if(testFileMap.getMapObject(y,x) != 1){
                testResultsFile << "Map from file: " << "Conntent error. != 1" << std::endl;
                ++error;
            }
        }
    }

    //Map from corrupt file
    testResultsFile << "Enviroment Simulator test Map from corrupt file" << std::endl;
    //Map corruptMap("testFileMapCorrupt.map");
    testResultsFile << "Map from corrupt file: " << "Lets see" << std::endl;

    //Map not from file
    testResultsFile << "Enviroment Simulator test Map not from file" << std::endl;
    Map testMap("testMap.map", size,size);

    if(static_cast<unsigned int>(testMap.getMapContent().size()) != size){
        testResultsFile << "Map not from file: " << "Map y size incorret" << std::endl;
        ++error;
    }

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            if(static_cast<unsigned int>(testMap.getMapContent()[y].size()) != size){
                testResultsFile << "Map not from file: " << "Map x size incorret" << std::endl;
                ++error;
            }
            if(testMap.getMapObject(y,x) != 0){
                testResultsFile << "Map not from file: " << "Conntent error. != 0" << std::endl;
                ++error;
            }
            testMap.setMapObject(1,y,x);
        }
    }

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            if(testMap.getMapObject(y,x) != 1){
                testResultsFile << "Map not from file: " << "Conntent error. != 1" << std::endl;
                ++error;
            }
        }
    }


    testMap.setMapObject(0,size - 5, size - 2);
    if(testMap.getMapObject(size - 5,size - 2) != 0){
        testResultsFile << "Map not from file: " << "Object error size - 5,size - 2 != 0" << std::endl;
        ++error;
    }

    testMap.setMapObject(1,size - size,size - size);
    if(testMap.getMapObject(size - size,size -size) != 1){
        testResultsFile << "Map not from file: " << "Object error 0,0 != 1" << std::endl;
        ++error;
    }

    testMap.setMapObject(1,size - 1,size - (size - 1));
    if(testMap.getMapObject(size - 1,size - (size - 1)) != 1){
        testResultsFile << "Map not from file: " << "Object error size - 1,size - (size - 1) != 1" << std::endl;
        ++error;
    }

    testMap.setMapObject(0,size - 1,size - 1);
    if(testMap.getMapObject(size - 1,size - 1) != 0){
        testResultsFile << "Map not from file: " << "Object error size - 1,size - (size - 1) != 0" << std::endl;
        ++error;
    }

    testMap.setMapObject(0,size + 1,size + 1);
    if(testMap.getMapObject(size + 1,size + 1) != -1){
        testResultsFile << "Map not from file: " << "Object error size - 1,size - (size - 1) != -1" << std::endl;
        ++error;
    }

    testMap.setMapObject(0,size,size);
    if(testMap.getMapObject(size,size) != -1){
        testResultsFile << "Map not from file: " << "Object error size, size != -1" << std::endl;
        ++error;
    }

    testMap.setMapObject(0,size - 21,size - 21);
    if(testMap.getMapObject(size - 21,size - 21) != -1){
        testResultsFile << "Map not from file: " << "Object error size - 21,size - 21 + 1 != 1" << std::endl;
        ++error;
    }

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            testMap.setMapObject(1,y,x);
        }
    }

    //Save file
    testResultsFile << "Enviroment Simulator test Save file" << std::endl;
    testMap.saveMap();

    std::ifstream mapFile;
    mapFile.open("testMap.map");
    if(!mapFile.is_open()){
        testResultsFile << "File: " << "Map file could not be opend" << std::endl;
        ++error;
    }
    int x = 0,y = 0;
    int content = 0;

    while(y < testMap.height){
        mapFile >> content;

        if(content != testMap.getMapObject(y,x)){
            testResultsFile << "File: " << "Map connect not equal to file content" << std::endl;
            ++error;
            break;
        }

        x++;
        if(x > testMap.width - 1){
            x = 0;
            y++;
        }
    }
    mapFile.close();

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            testMap.setMapObject(0,y,x);
        }
    }

    //Vector
    testResultsFile << "Enviroment Simulator test Vector abuse" << std::endl;
    vector<vector< int > > testVector;

    testVector.resize(1);

    testMap.setMapContent(testVector);
    testResultsFile << "Vector: " << "Set map content with too small vector" << std::endl;

    testVector.resize(size+1);

    testMap.setMapContent(testVector);
    testResultsFile << "Vector: " << "Set map content with too big vector" << std::endl;


    //Simuate test
    testResultsFile << "Enviroment Simulator test Simulate" << std::endl;

    Map *tp = new Map("testSimulateMap.map" , size, size);
    tp->setMapObject(1,1,9);

    SimulateMap testSim(tp);

    testSim.addCheckPoint(6,2);

    testSim.addCheckPoint(21,21);
    testResultsFile << "addCheckPoint 21 21" << std::endl;

    testSim.addCheckPoint(-1,-1);
    testResultsFile << "addCheckPoint -1 -1" << std::endl;

    testSim.simulate();
    testResultsFile << "Simulate: " << "Lest see" << std::endl;

    Map *pt = new Map("temp.map", size, size);

    SimulateMap testSimEmpty(pt);

    testSimEmpty.simulate();
    testResultsFile << "Simulate: " << "Lest see" << std::endl;

    testSimEmpty.getPointCloud();
    testResultsFile << "Simulate: " << "Lest see" << std::endl;



    //PointCloud test
    testResultsFile << "Enviroment Simulator test PointCloud" << std::endl;
    Pointcloud pC = testSim.getPointCloud();
    for(Pointcloud::Point p : pC.getPoints()){
        if(p.X != 3){
            testResultsFile << "PointCloud: " << "Lest see" << std::endl;
            ++error;
        }
        if(p.Y != 1){
            testResultsFile << "PointCloud: " << "Lest see" << std::endl;
            ++error;
        }
    }

    //Done
    testResultsFile << "Enviroment Simulator test done" << std::endl;
    if(error == 0){
        testResultsFile << "Test Succes!" << std::endl;
        std::cout << "Test Succes!" << std::endl;
    }

    testResultsFile << '\n' << '\n';
    testResultsFile.close();
    std::cout << "Enviroment Simulator test done" << std::endl;
    return error;
}
