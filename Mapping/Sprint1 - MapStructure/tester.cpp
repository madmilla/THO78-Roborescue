#include "point.hpp"
#include "line.hpp"
#include "map.hpp"
#include <iostream>
#include <vector>

template<typename T>
std::ostream & operator<<(std::ostream& os, const std::vector<T>& vec)
{
    for (auto & el : vec)
    {
        os << el;
    }
    return os;
}

int main(){
    std::cout << "----TESTING----\n";
    std::cout << "--Testing point--\n";
    std::cout << "-Constructor-\n";
    point * pp1 = new point{0,0};
    point * pp2 = new point{-1,-1};
    point * pp3 = new point{-1,1};
    point * pp4 = new point{1,-1};
    point * pp5 = new point{1,1};
    std::cout << (pp1 != nullptr ? "\tConstructor with value 0,0   succeeded\n" : "\tConstructor with value 0,0   FAILED;\n");
    std::cout << (pp2 != nullptr ? "\tConstructor with value -1,-1 succeeded\n" : "\tConstructor with value -1,-1 FAILED;\n");
    std::cout << (pp3 != nullptr ? "\tConstructor with value -1,1  succeeded\n" : "\tConstructor with value -1,1  FAILED;\n");
    std::cout << (pp4 != nullptr ? "\tConstructor with value 1,-1  succeeded\n" : "\tConstructor with value 1,-1  FAILED;\n");
    std::cout << (pp5 != nullptr ? "\tConstructor with value 1,1   succeeded\n" : "\tConstructor with value 1,1   FAILED;\n");

    std::cout << "-Equals-\n";
    point p1{1, 1};
    point p2{-1, -1};
    point p3{1, -1};
    point p4{-1, 1};
    std::cout << std::boolalpha << "\t1,1 equals 1,1    = " << p1.equals(p1) << std::endl;
    std::cout << std::boolalpha << "\t1,1 equals -1,-1  = " << p1.equals(p2) << std::endl;
    std::cout << std::boolalpha << "\t-1,-1 equals 1,-1 = " << p2.equals(p3) << std::endl;
    std::cout << std::boolalpha << "\t-1,-1 equals -1,1 = " << p2.equals(p4) << std::endl;

    std::cout << "-operator<<-\n";
    std::cout << "\tPoint p1(1,1)   = " << p1 << std::endl;
    std::cout << "\tPoint p2(-1,-1) = " << p2 << std::endl;

    std::cout << "-getX-\n";
    std::cout << (p1.getX() == 1 ? "\tgetX succesfull" : "\tgetX FAILED") << " in retrieving X: " << p1.getX() << std::endl;
    std::cout << (p2.getX() == -1 ? "\tgetX succesfull" : "\tgetX FAILED") << " in retrieving X: " << p2.getX() << std::endl;

    std::cout << "-getY-\n";
    std::cout << (p1.getY() == 1 ? "\tgetX succesfull" : "\tgetX FAILED") << " in retrieving Y: " << p1.getY() << std::endl;
    std::cout << (p2.getY() == -1 ? "\tgetX succesfull" : "\tgetX FAILED") << " in retrieving Y: " << p2.getY() << std::endl;

    std::cout << "\n--Testing line--\n";
    std::cout << "-Constructor-\n";
    line * lp1 = new line{p1, p2};
    line * lp2 = new line{p2, p1};
    std::cout << (lp1 != nullptr ? "\tConstructor with value [(1,1),(-1,-1)] succeeded\n" : "\tConstructor with value [(1,1),(-1,-1)] FAILED;\n");
    std::cout << (lp2 != nullptr ? "\tConstructor with value [(-1,-1),(1,1)] succeeded\n" : "\tConstructor with value [(-1,-1),(1,1)] FAILED;\n");

    std::cout << "-Equals-\n";
    line l1{p1, p2};
    line l2{p2, p1};
    line l3{p1, p3};
    line l4{p1, p4};
    std::cout << std::boolalpha << "\t[(1,1),(-1,-1)] equals [(1,1),(-1,-1)] = " << l1.equals(l1) << std::endl;
    std::cout << std::boolalpha << "\t[(1,1),(-1,-1)] equals [(-1,-1),(1,1)] = " << l1.equals(l2) << std::endl;
    std::cout << std::boolalpha << "\t[(-1,-1),(1,1)] equals [(1,1),(1,-1)]  = " << l2.equals(l3) << std::endl;
    std::cout << std::boolalpha << "\t[(-1,-1),(1,1)] equals [(1,1),(-1,1)]  = " << l2.equals(l4) << std::endl;

    std::cout << "-getPoint-\n";
    std::cout << std::boolalpha << "\t(1,1) equals (1,1)" << l1.getPoint(0).equals(p1) << std::endl;
    std::cout << std::boolalpha << "\t(-1,-1) equals (-1,-1)" << l1.getPoint(1).equals(p2) << std::endl;
    std::cout << std::boolalpha << "\t(-1,-1) equals (1,1)" << l2.getPoint(0).equals(p1) << std::endl;

    std::cout << "-operator<<-\n";
    std::cout << "\tLine l1[(1,1),(-1,-1)] = " << l1 << std::endl;
    std::cout << "\tLine l2[(-1,-1),(1,1)] = " << l2 << std::endl;

    std::cout << "-getPoints-\n";
    std::cout << "\tl1 X = " << l1.getPoints().first << "; l1 Y = " << l1.getPoints().second << std::endl;
    std::cout << "\tl2 X = " << l2.getPoints().first << "; l2 Y = " << l2.getPoints().second << std::endl;

    std::cout << "\n--Testing map--\n";
    std::cout << "-Constructor-\n";
    std::vector<line> lvec1 = {l1, l2, l3};
    std::vector<line> lvec2 = {l1, l2, l3, l4};
    map * mp1 = new map{};
    map * mp2 = new map{l1};
    map * mp3 = new map{lvec1};
    std::cout << (mp1 != nullptr ? "\tEmpty constructor succeeded\n" : "\tSingle line constructor FAILED;\n");
    std::cout << (mp2 != nullptr ? "\tSingle line constructor succeeded\n" : "\tSingle line constructor FAILED;\n");
    std::cout << (mp3 != nullptr ? "\tLine vector constructor succeeded\n" : "\tLine vector constructor FAILED;\n");

    std::cout << "-hasLine-\n";
    map m1{lvec1};
    std::cout << "\tHasline single should be true  = " << std::boolalpha << m1.hasLine(l1) << std::endl;
    std::cout << "\tHasline single should be true  = " << std::boolalpha << m1.hasLine(l2) << std::endl;
    std::cout << "\tHasline single should be false = " << std::boolalpha << m1.hasLine(l4) << std::endl;
    std::cout << "\tHasline vector should be true  = " << std::boolalpha << m1.hasLine(lvec1) << std::endl;
    std::cout << "\tHasline vector should be false = " << std::boolalpha << m1.hasLine(lvec2) << std::endl;

    std::cout << "-getPointLines-\n";
    point pmap1{0, 0};
    point pmap2{10, 10};
    point pmap3{5, 5};
    point pmap4{0, 10};
    point pmap5{10, 0};
    line lmap1{pmap1, pmap2}; //diagonally
    line lmap2{pmap1, pmap4}; //vertically
    line lmap3{pmap1, pmap5}; //horizontally
    line lmap4{pmap2, pmap1}; //diagonally
    std::vector<line> lvec3 = {lmap1, lmap2, lmap3, lmap4};
    map m2{lvec3};
    std::vector<line> result = {lmap1, lmap2};
    std::cout << "\t" << m2.getPointLines(pmap3) << " == " << result << std::endl;

    std::cout << "-appendLine-\n";
    m1.appendLine(l4);
    std::cout << (m1.hasLine(l4) ? "\tAppending was succesfull\n" : "\tAppending was FAILED\n");

    std::cout << "-removeLine-\n";
    m1.removeLine(l4);
    std::cout << (!m1.hasLine(l4) ? "\tRemoving was succesfull\n" : "\tRemoving has FAILED\n");

    std::cout << "-equals-\n";
    map m3{lvec3}; map m4{lvec3};
    std::cout << (m3.equals(m4) ? "\tMap comparison was sucessfull\n" : "\tMap comparison has FAILED\n");

    std::cout << "-getRegion-\n";
    point pZero{0,0};
    std::cout << (m3.getRegion(0, 0, 10, 10).equals(m3) ? "\tgetRegion was sucessfull\n" : "\tgetRegion has FAILED\n");
    std::cout << (m3.getRegion(pZero, 10, 10).equals(m3) ? "\tgetRegion was sucessfull\n" : "\tgetRegion has FAILED\n");
    std::cout << (!m3.getRegion(pmap3, 5, 5).equals(m3) ? "\tgetRegion was sucessfull\n" : "\tgetRegion has FAILED\n");

    delete pp1; delete pp2; delete pp3; delete pp4; delete pp5; delete lp1; delete lp2; delete mp1; delete mp2; delete mp3;
    return 0;
}

/*
cd "Mapping/Sprint1 - MapStructure"
g++ std=c++11 tester.cpp -o testLineMapStructure map.hpp map.cpp line.hpp line.cpp point.hpp point.cpp
./testLineMapStructure
*/
