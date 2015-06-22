#include <iostream>
#include <stdexcept>

#include <stdio.h>
#include <iostream>

#include "lines.h"
#include "algorithms.h"

int main(int argc, char *argv[]) {

    // Initialize lines vector with "random" numbers
    std::vector<std::vector<points> > polygons;
    std::vector<points> polygon1;
    std::vector<points> polygon2;

    points p1(42, 36);
    points p2(53, 23);
    points p3(456, 34);
    points p4(1, 243);
    points p5(25, 35);
    points p6(65, 678);

    polygon1.push_back(p1);
    polygon1.push_back(p2);
    polygon1.push_back(p3);
    polygon1.push_back(p4);
    polygon1.push_back(p5);
    polygon1.push_back(p6);

    points p7(34, 34);
    points p8(586, 3);
    points p9(786, 456);
    points p10(233, 423);
    points p11(65, 14);
    points p13(345, 456);

    polygon2.push_back(p7);
    polygon2.push_back(p8);
    polygon2.push_back(p9);
    polygon2.push_back(p10);
    polygon2.push_back(p11);
    polygon2.push_back(p13);

    polygons.push_back(polygon1);
    polygons.push_back(polygon2);



//    Lines<int> line1(-533445, 535435, -23424, 312312);
//    Lines<int> line2(343242, 223, 0, -42);
//    Lines<int> line3(211, 25454, 44674, 1665432);
//    Lines<int> line4(-142421, 4256, 98765432, 7653);
//    lines.push_back(line1);
//    lines.push_back(line2);
//    lines.push_back(line3);
//    lines.push_back(line4);
	
	// Normalize lines between -1 and 1 floats
    const std::vector<Lines<float> > normalizedLines = Algorithms::getNormalizedLinesForPolygons(polygons);
    for(std::vector<Lines<float> >::const_iterator it = normalizedLines.begin(); it != normalizedLines.end(); ++it) {
        if (it->x1 > 1 || it->x1 < -1) {
            std::cout << "X1 value was out of bounds";
            return -1;
        } else if (it->x2 > 1 || it->x2 < -1) {
            std::cout << "X2 value was out of bounds";
            return -1;
        } else if (it->y1 > 1 || it->y1 < -1) {
            std::cout << "Y1 value was out of bounds";
            return -1;
        } else if (it->y2 > 1 || it->y2 < -1) {
            std::cout << "Y2 value was out of bounds";
            return -1;
        }
    }

    std::cout << "SUCCESSSSS!!";
    return 0;
}
