#include "tester.h"
#include <QMessageBox>

tester::tester()
{}

tester::~tester(){}

// Let the testing commence
void tester::ini(){
    std::cout << "----TESTING----\n";
    std::cout << "Creating mapLogic\n";
    mapLogic * logic = new mapLogic();
    std::cout << (logic != nullptr ? "\tConstructor succeeded\n" : "\tConstructor FAILED;\n");
    std::cout << "Creating 20x20 array\n";

    int ** testMap1 = logic->create2DArray(20, 20);
    std::cout << (testMap1 != nullptr ? "\tCreation succeeded\n" : "\tCreation FAILED;\n");

    std::cout << "Retrieving created map in constructor\n";
    int ** testMap2 = logic->getMap();
    std::cout << (testMap2 != nullptr ? "\tgetMap() succeeded\n" : "\tgetMap() FAILED;\n");

    std::cout << "Simulating right mouseclick at 200, 200\n";
    logic->mouseClicked(QPoint(200, 200), Qt::MouseButton::RightButton);
    std::cout << (logic->getCelltype(logic->getCell(QPoint(200,200))) == 2 ? "\tResult is correct\n" : "\tResult is INCORRECT\n");
    std::cout << "Simulating left mouseclick at 200, 200\n";
    logic->mouseClicked(QPoint(200, 200), Qt::MouseButton::LeftButton);
    std::cout << (logic->getCelltype(logic->getCell(QPoint(200,200))) == 1 ? "\tResult is correct\n" : "\tResult is INCORRECT\n");
    std::cout << "Simulating left mouseclick at 200, 200\n";
    logic->mouseClicked(QPoint(200, 200), Qt::MouseButton::LeftButton);
    std::cout << (logic->getCelltype(logic->getCell(QPoint(200,200))) == 0 ? "\tResult is correct\n" : "\tResult is INCORRECT\n");

    std::cout << "Filling the map with some objects\n";
    logic->mouseClicked(QPoint(252, 200), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(263, 260), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(330, 200), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(150, 240), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(240, 230), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(200, 220), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(270, 210), Qt::MouseButton::LeftButton);
    logic->mouseClicked(QPoint(200, 200), Qt::MouseButton::RightButton);
    std::cout << logic->toString().toUtf8().constData();
    delete logic;
}
