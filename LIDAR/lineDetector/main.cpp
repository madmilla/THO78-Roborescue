#include "linedetector.h"
#include "time.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/opencv.hpp"

void test(){
    lineDetector myLineDetector;

    const Mat & image = myLineDetector.createImage("test.txt");
    clock_t Start = clock();
    Mat final_dest;
    vector<Vec4i> lines = myLineDetector.searchLines(image, final_dest);
    clock_t end = clock();
    float time = (float)(end - Start) /CLOCKS_PER_SEC;
    std::cout << "the searchLines function is executed in: " << time << " seconds" << std::endl;
    myLineDetector.writeLinesToConsole(lines);
}

int main(int argc, char** argv) {

    if(argc >1 && strcmp(argv[1], "test") == 0){
        std::cout << "running test..." << std::endl;
        test();
    }
    else {
        lineDetector myLineDetector;

        const Mat & image = myLineDetector.createImage(argv[1]);
        Mat final_dest;
        vector<Vec4i> lines = myLineDetector.searchLines(image, final_dest);

        myLineDetector.writeLinesToConsole(lines);

        myLineDetector.drawLines(lines, final_dest);

        myLineDetector.showGui(image, final_dest);

        waitKey();
    }
    return 0;
}
