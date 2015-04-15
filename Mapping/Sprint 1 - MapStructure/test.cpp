//! Entry point application for testing the map, line and point class
#include "point.hpp"
#include "line.hpp"
#include "map.hpp"
#include <iostream>

// Testing performance difference
#include <Windows.h>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto& el : vec)
    {
        os << el << std::endl;
    }
    return os;
}

int main(){
    point pA{ 4, 5 };
    point pB{ 5, 5 };
    point pC{ 4, 5 };
    point pD{ 2, 6 };
    point pE{ 6, 6 };

    line lA{ pA, pB };
    line lB{ pB, pA };
    line lC{ pD, pC };
    line lD{ pA, pE };
    line lE{ pA, pB };

    std::cout << pA << std::endl;
    std::cout << std::boolalpha << pA.equals(pB) << std::endl;
    std::cout << std::boolalpha << pA.equals(pC) << std::endl;
    std::cout << pD << std::endl;
    std::cout << pD.getX() << "," << pD.getY() << std::endl << std::endl;

    std::cout << lA << std::endl;
    std::cout << lB << std::endl;
    std::cout << lC << std::endl;
    std::cout << lD << std::endl;
    std::cout << lE << std::endl << std::endl;

    std::cout << std::boolalpha << lA.equals(lB) << std::endl;
    std::cout << std::boolalpha << lB.equals(lA) << std::endl;
    std::cout << std::boolalpha << lA.equals(lE) << std::endl;
    std::cout << std::boolalpha << lE.equals(lA) << std::endl << std::endl;

    std::cout << lA.getPoint(0) << std::endl;
    std::cout << lA.getPoint(1) << std::endl;
    std::cout << lA.getPoint(2) << std::endl;
    std::cout << lA.getPoint(-1) << std::endl << std::endl;

    map mA{};
    std::cout << "appending A" << std::endl; mA.appendLine(lA);
    std::cout << "Hasline A: " << std::boolalpha << mA.hasLine(lA) << std::endl;
    std::cout << "Removing A: " << std::boolalpha << mA.removeLine(lA) << std::endl;
    std::cout << "Hasline A: " << std::boolalpha << mA.hasLine(lA) << std::endl;
    std::cout << "Removing A: " << std::boolalpha << mA.removeLine(lA) << std::endl;
    std::cout << "Printing map: " << mA;

    std::cout << std::endl << std::endl << "New map: " << std::endl;
    std::vector<line> vB;
    map mB{};
    vB.push_back(lA); vB.push_back(lB); vB.push_back(lC);
    mB.appendLine(lA); mB.appendLine(lB); mB.appendLine(lC);
    std::cout << mB;
    std::cout << "Has vector of lines: " << mB.hasLine(vB) << std::endl;
    std::cout << "Removing vectors: " << mB.removeLine(vB) << std::endl;
    std::cout << "Has vector of lines: " << mB.hasLine(vB) << std::endl;
    std::cout << "Map:" << mB << std::endl;

    std::cout << std::endl << std::endl << "New map: " << std::endl;
    std::vector<line> vC;
    map mC{};
    vC.push_back(lE); vC.push_back(lD);
    mC.appendLine(lD); mC.appendLine(lE); mC.appendLine(lA); mC.appendLine(lD);
    mC.appendLine(std::vector<line>() = {lD, lE, lA});
    std::cout << mC;
    std::cout << "Has vector of lines: " << mC.hasLine(vC) << std::endl;
    std::cout << "Removing vectors: " << mC.removeLine(vC) << std::endl;
    std::cout << "Has vector of lines: " << mC.hasLine(vC) << std::endl;
    std::cout << "Map:" << mC << std::endl;

    std::cout << std::endl << std::endl << "New map: " << std::endl;
    map mD{ std::vector<line>() = { lA, lB, lC } };
    map mE{ std::vector<line>() = { lA, lB, lC } };
    map mF{ std::vector<line>() = { lB, lA, lC } };
    map mG{ std::vector<line>() = { lB, lA, lC, lD } };
    map mH{ std::vector<line>() = { lA, lB} };
    map mI{ std::vector<line>() = { lA, lB, lD } };

    std::cout << mD << std::endl;
    std::cout << mE << std::endl;
    std::cout << mF << std::endl;

    std::cout << mD.equals(mE) << "; = true?" << std::endl;
    std::cout << mE.equals(mD) << "; = true?" << std::endl;
    std::cout << mD.equals(mF) << "; = true?" << std::endl;
    std::cout << mA.equals(mG) << "; = false?" << std::endl;
    std::cout << mG.equals(mH) << "; = false?" << std::endl;
    std::cout << mA.equals(mH) << "; = false?" << std::endl;
    std::cout << mI.equals(mD) << "; = false?" << std::endl;

    line lF{ point{ -10, -10 }, point{ 0, 0 } };
    line lG{ point{ 0, -10 }, point{ -10, 0 } };
    line lH{ point{ -2, -10 }, point{ -10, 0 } };
    line lI{ point{ -2, -8 }, point{ -8, -2 } };	//diagonal line tests

    line lJ{ point{ -6, -4 }, point{ -6, -8 } };
    line lK{ point{ -6, -4 }, point{ -6, -10 } };
    line lL{ point{ -6, 0 }, point{ -6, -8 } };
    line lM{ point{ -6, 0 }, point{ -6, -10 } };	//vertical line tests

    line lN{ point{ 1, 1 }, point{ 3, 3 } };
    line lO{ point{ 1, 1 }, point{ -4, 3 } };
    line lP{ point{ -4, 4 }, point{ -4, -8 } };

    std::cout << std::endl << std::endl << std::endl << "Region tests: " << std::endl;
    map mapRegion{ std::vector<line>() = { lA, lB, lC, lD, lE, lF, lG, lH, lI, lJ, lK, lL, lM, lN, lO, lP } };
    std::cout << mapRegion;
    point pAA{-10, -10};
    point pBB{5, 0};
    point pCC{5, 5};
    point pDD{5, 6};
    std::cout << std::endl << "Region test ints:" << std::endl << mapRegion.getRegion(-10, -10, 10, 10) << std::endl;
    std::cout << std::endl << "Region test point:" << std::endl << mapRegion.getRegion(pAA, 10, 10) << std::endl;

    std::cout << std::endl << std::endl << "mapGetPointLines:" << std::endl;
    line lQ{ point{ 0, 0 }, point{ 10, 0 } };
    line lR{ point{ 10, 0 }, point{ 0, 0 } };
    line lS{ point{ 0, 0 }, point{ 10, 10 } };

    map mapGs{ std::vector<line>() = { lQ, lR, lS } };
    std::cout << "Lines: " << mapGs.getPointLines(pBB) << std::endl;
    std::cout << "Lines: " << mapGs.getPointLines(pCC) << std::endl;
    std::cout << "Lines: " << mapGs.getPointLines(pDD) << std::endl;

    (void)getchar();
    return 0;
}
