

// compiled with: g++ circles.cpp -o circles `pkg-config --cflags --libs opencv`
#include <iostream>
#include <stdio.h>
#include "time.h"
#include "ctime"
#include <math.h>
#include <fstream>
#include "shapedetector.h"
#include <fstream>

void test(){
	std::ofstream output("../../../../results/ShapeDetection_results.txt");
    ShapeDetector sD;
	const Mat & image = sD.createImage("circles400.txt");
	if (image.size().width < 400 || image.size().height < 400){
		output << "image WIDTH: " << image.size().width << "\t image HEIGHT: " << image.size().height << "\n";
		output << "image creation FAILED\n";
	}
	else{
		output << "image WIDTH: " << image.size().width << "\t image HEIGHT: " << image.size().height << "\n";
		output << "image created SUCCESFULLY\n";
	}
	clock_t Start = clock();
    CvSeq* circles = sD.detectCircles(image);
    vector<Vec4i> lines = sD.searchLines(image);
    clock_t end = clock();
    float time = (float)(end - Start) /CLOCKS_PER_SEC;
    std::cout << (circles->total+ lines.size()) << " Objects detected in " << time << " seconds" << std::endl;
	output << (circles->total + lines.size()) << " Objects detected in " << time << " seconds" << std::endl;
	if (circles->total + lines.size() < 14){
		output << "14 objectes should be detected, only " << circles->total + lines.size() <<" objects detected \t\tFAILDED";
	}
	else{
		output << circles->total + lines.size() << " objects detected \t object detection SUCCES";
	}

    sD.writeCirclesToConsole(circles);
    sD.writeLinesToConsole(lines);
	output.close();
}

int main(int argc, char** argv)
{

    if(argc <=1){
        std::cout << "running Shape Detection test" << std::endl;
        test();
        return 0;
	}
	else{
		std::cout << "mek\n";
		ShapeDetector sD;
		const Mat & orginal_image = sD.createImage(argv[1]);
		Mat customImage = orginal_image.clone();
		CvSeq* circles = sD.detectCircles(customImage);
		vector<Vec4i> lines = sD.searchLines(customImage);
		sD.writeObjectsToConsole(lines,circles);
		sD.showObjects(lines,circles, orginal_image, customImage);

		waitKey();
	}
    return 0;

}
