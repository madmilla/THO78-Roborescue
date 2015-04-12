#include "testperformance.h"
#include "glwidget.h"
#include <iostream>
#include <ctime>
#include <unistd.h>

void TestPerformance::test(){
    std::vector<Line<int> > lines;
    //voorbeeld lijnen
    Line<int> line1(0, 0, 0, 1);
    Line<int> line2(0, 1, 1, 1);
    Line<int> line3(1, 1, 1, 0);
    Line<int> line4(1, 0, 0, 0);
    lines.push_back(line1);
    lines.push_back(line2);
    lines.push_back(line3);
    lines.push_back(line4);

    GLWidget glWidget(NULL);

    std::clock_t start;
    double duration;

    //3D
    start = std::clock();
    for(int i = 0; i < 1000000; i++){
         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
         glWidget.setLines(lines);
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "3D: " << duration << " sec\n";

    //ISO
    start = std::clock();
    for(int i = 0; i < 1000000; i++){
         glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
         glWidget.setLinesIso(lines);
    }

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
    std::cout << "ISO: " << duration << " sec\n";
}
