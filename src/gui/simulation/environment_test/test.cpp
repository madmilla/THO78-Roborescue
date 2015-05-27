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
        std::cout << "Result log: " << "Log file could not be opend" << std::endl;
        ++error;
    }

    testResultsFile << "Enviroment Simulator test begin" << std::endl;

    //Map from file
    testResultsFile << "Enviroment Simulator test Map from file" << std::endl;

    Map testFileMap("testFileMap.map");


    if(static_cast<int>(testFileMap.getMapContent().size()) != size){
        testResultsFile << "Map from file: " << "Map y size incorret" << std::endl;
        ++error;
    }

    for(int y = 0; y < testFileMap.height; y++){
        for(int x = 0; x < testFileMap.width; x++){
            if(static_cast<int>(testFileMap.getMapContent()[y].size()) != size){
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

    if(static_cast<int>(testMap.getMapContent().size()) != size){
        testResultsFile << "Map not from file: " << "Map y size incorret" << std::endl;
        ++error;
    }

    for(int y = 0; y < testMap.height; y++){
        for(int x = 0; x < testMap.width; x++){
            if(static_cast<int>(testMap.getMapContent()[y].size()) != size){
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
    std::vector<std::vector< int > > testVector;

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
    tp->setMapObject(1,15,15);

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

    //Objects behind objects test

    Map *tM = new Map("testMap.map", size,size);
    //right side
    tM->setMapObject(1,5,9);
    testResultsFile << "addObject 5 9 right side from checkpoint" << std::endl;
    tM->setMapObject(1,5,10);
    testResultsFile << "addObject 5 10 right side from checkpoint" << std::endl;
    //left side
    tM->setMapObject(1,5,5);
    testResultsFile << "addObject 5 5 left side from checkpoint" << std::endl;
    tM->setMapObject(1,5,4);
    testResultsFile << "addObject 5 4 left side from checkpoint" << std::endl;
    //upper side
    tM->setMapObject(1,3,7);
    testResultsFile << "addObject 3 7 upper side from checkpoint" << std::endl;
    tM->setMapObject(1,2,7);
    testResultsFile << "addObject 2 7 upper side from checkpoint" << std::endl;
    //lower side
    tM->setMapObject(1,7,7);
    testResultsFile << "addObject 7 7 lower side from checkpoint" << std::endl;
    tM->setMapObject(1,8,7);
    testResultsFile << "addObject 8 7 lower side from checkpoint" << std::endl;

    //left up side diagonal
    tM->setMapObject(1,4,6);
    testResultsFile << "addObject 4 6 left up side diagonal checkpoint" << std::endl;
    tM->setMapObject(1,3,5);
    testResultsFile << "addObject 5 3 left up side diagonal checkpoint" << std::endl;

    //left down side diagonal
    tM->setMapObject(1,6,6);
    testResultsFile << "addObject 6 6 left down side diagonal checkpoint" << std::endl;
    tM->setMapObject(1,7,5);
    testResultsFile << "addObject 5 7 left down side diagonal checkpoint" << std::endl;

    //right up side diagonal
    tM->setMapObject(1,4,8);
    testResultsFile << "addObject 8 4 right up side diagonal checkpoint" << std::endl;
    tM->setMapObject(1,3,9);
    testResultsFile << "addObject 9 3 right up side diagonal checkpoint" << std::endl;

    //right down side diagonal
    tM->setMapObject(1,6,8);
    testResultsFile << "addObject 8 6 right down side diagonal checkpoint" << std::endl;
    tM->setMapObject(1,7,9);
    testResultsFile << "addObject 9 7 right down side diagonal checkpoint" << std::endl;

    SimulateMap tS(tM);

    tS.addCheckPoint(7,5);
    testResultsFile << "addCheckPoint 5 7" << std::endl;

    tS.simulate();
    testResultsFile << "Enviroment Simulator object behind object test PointCloud" << std::endl;
    Pointcloud pointc = tS.getPointCloud();

    for(Pointcloud::Point p : *pointc.getPoints()){
        if(p.X == 3 && p.Y == 0){
            testResultsFile << "PointCloud: " << "Right side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X == -3 && p.Y == 0){
            testResultsFile << "PointCloud: " << "Left side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X == 0 && p.Y == 3){
            testResultsFile << "PointCloud: " << "Upper side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X == 0 && p.Y == -3){
            testResultsFile << "PointCloud: " << "Lower side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X ==  -2 && p.Y == -2){
            testResultsFile << "PointCloud: " << "Upper left diagonal side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X == 2 && p.Y == -2){
            testResultsFile << "PointCloud: " << "Lower left diagonal side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X == 2 && p.Y == 2){
            testResultsFile << "PointCloud: " << "Lower right diagonal side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
        else if(p.X == -2 && p.Y == 2){
            testResultsFile << "PointCloud: " << "Upper right diagonal side object behind object scanned. FAILURE!" << std::endl;
            ++error;
        }
    }

    //PointCloud test
    testResultsFile << "Enviroment Simulator test PointCloud" << std::endl;
    Pointcloud pC = testSim.getPointCloud();
    if(pC.getPoints()->size() > 1){
       ++error;
        testResultsFile << "PointCloud: " << "Radius failed" << std::endl;
    }
    for(Pointcloud::Point p : *pC.getPoints()){
        //std::cout << "x: " << p.X << " y: " << p.Y;
        if(p.X != 3){
            testResultsFile << "PointCloud: " << "X wrong" << std::endl;
            ++error;
        }
        if(p.Y != 1){
            testResultsFile << "PointCloud: " << "Y wrong" << std::endl;
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
