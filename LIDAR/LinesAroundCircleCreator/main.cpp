#include <iostream>
#include "circledetector.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv/cv.h>
#include "time.h"
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
using namespace cv;

struct LinesAroundCircleCreator {

private:
    const CvScalar LINECOLOR = CV_RGB(255,0,0);
    const int THICKNESS = 3;
    const int ANGLE_STEP = 45;

public:
    LinesAroundCircleCreator() {}

    void showLines(const vector<Vec4i> & lines, Mat & final_dest) {
        for( size_t i = 0; i < lines.size(); i++ ) {
            Vec4i l = lines[i];
            line( final_dest, Point(l[0], l[1]), Point(l[2], l[3]), LINECOLOR, THICKNESS, CV_AA);
        }
        imshow("lines around circles", final_dest);
    }
    vector<Vec4i> createLinesAroundCircle(CvSeq* circles) {
        vector<Vec4i> lines;

        for (size_t i = 0; i < circles->total; i++) {
            float* p = (float*)cvGetSeqElem(circles, i);
            Point center(cvRound(p[0]), cvRound(p[1]));
            int radius = cvRound(p[2]);

            for(int angle = 90; angle < 360; angle+= ANGLE_STEP) {

                int x1 = static_cast<int>(center.x + (radius * cos(angle))); //calculate point 1
                int y1 = static_cast<int>(center.y + (radius * sin(angle)));

                int x2 = static_cast<int>(center.x + (radius * cos(angle + ANGLE_STEP))); //calculate point 2
                int y2 = static_cast<int>(center.y + (radius * sin(angle + ANGLE_STEP)));

                lines.push_back(Vec4i{x1, y1, x2, y2}); //store line
            }
        }
        return lines;
    }
    void writeLinesToConsole(const vector<Vec4i> & lines) {
        int circle_counter = 1;
        int line_counter = 1;
        std::stringstream stream;
        for (const auto & line : lines) {
            if(line_counter > 6) {
                circle_counter++;
                line_counter = 1;
            }
            if(line_counter == 1) {
                stream << "circle " << circle_counter << " contains lines: " << std::endl;
            }
            stream << "line " << line_counter << std::endl;
            stream << "(x1, y1) (" << line[0] << ',' << line[1] << ')' << std::endl;
            stream << "(x2, y2) (" << line[2] << ',' << line[3] << ')' << std::endl << std::endl;
            line_counter++;
        }
        std::cout << stream.str();
    }
};

void test() {
    CircleDetector sD;
    CvSeq* circles = sD.detectCircles("circles400.txt");

    LinesAroundCircleCreator LACC{};
    clock_t Start = clock();
    vector<Vec4i> & lines = LACC.createLinesAroundCircle(circles);
    clock_t end = clock();
    float time = (float)(end - Start) /CLOCKS_PER_SEC;
    LACC.writeLinesToConsole(lines);
    std::cout << "the createLinesAroundCircle function is executed in: " << time << " seconds" << std::endl;

    std::ofstream result;
    result.open("results.txt");

    result << "the createLinesAroundCircle function is executed in: " << time << " seconds" << std::endl;

    result.close();
}

int main(int argc, char *argv[]) {

    if(argc >1 && strcmp(argv[1], "test") == 0) {
        std::cout << "running test..." << std::endl;
        test();
    }
    else {
        CircleDetector sD;
        CvSeq* circles = sD.detectCircles(argv[1]);
        sD.showCircles(circles);

        LinesAroundCircleCreator LACC{};
        vector<Vec4i> & lines = LACC.createLinesAroundCircle(circles);
        LACC.writeLinesToConsole(lines);

        Mat image{sD.image, false};

        LACC.showLines(lines, image);

        cv::waitKey(0);
    }
    return 0;
}
