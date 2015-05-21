

// compiled with: g++ circles.cpp -o circles `pkg-config --cflags --libs opencv`ss
#include <iostream>
#include <stdio.h>
#include "time.h"
#include "ctime"
#include <math.h>
#include <fstream>
#include "shapedetector.h"
#include <fstream>
#include <vector>
#include "Circle.h"
#include "Line.h"

//Create a pointcloud out of a .txt file
//ONLY NEEDED TO TEST THE POINTCLOUD DETECTION
Pointcloud txtToPointcloud(const std::string & source){
	std::ifstream file(source); // open  inputfile
	if (!file.is_open()){
		std::cout << "could not open file with name " << source << std::endl;
		exit(EXIT_FAILURE);
	}
	std::string line;
	size_t imageHeight = 0;
	size_t imageWidth = 0;
	while (getline(file, line)){ //a while loop to get the image width and the image Height
		imageHeight++;
		if (line.length()> imageWidth){
			imageWidth = line.length();
		}
	}
	Pointcloud pointcloud;
	int x = 0;
	file.clear();
	file.seekg(0, file.beg);
	while (getline(file, line)){ //Walk through the file
		int y = 0;
		for (int i = 0; i< (int)imageWidth; i++){
			char ch = line[i];
			if (isdigit(ch)){ // if the char in the file is a number, the pixel should be 255
				pointcloud.setPoint(x,y); // set the pixel at 255
			}
			y++;
		}
		x++;
	}
	file.close();
	std::cout << "size of pointcloud: " << pointcloud.getPoints().size() << "\n";
	return pointcloud;
}

void test(){
	std::ofstream output("../../../../results/ShapeDetections_results.txt");
    ShapeDetector sD;
	Pointcloud p = txtToPointcloud("circles400.txt");
	const Mat & image = sD.createImage(p);
	if (image.size().width < 400 || image.size().height < 400){
		output << "image WIDTH: " << image.size().width << "\t image HEIGHT: " << image.size().height << "\n";
		output << "image creation FAILED\n";
	}
	else{
		output << "image WIDTH: " << image.size().width << "\t image HEIGHT: " << image.size().height << "\n";
		output << "image created SUCCESFULLY\n";
	}
	clock_t Start = clock();
    std::vector<Circle> circles = sD.detectCircles(image);
    vector<Line> lines = sD.searchLines(image);
    clock_t end = clock();
    float time = (float)(end - Start) /CLOCKS_PER_SEC;
    std::cout << (circles.size()+ lines.size()) << " Objects detected in " << time << " seconds" << std::endl;
	output << (circles.size() + lines.size()) << " Objects detected in " << time << " seconds" << std::endl;
	if (circles.size() + lines.size() < 14){
		output << "14 objectes should be detected, only " << circles.size() + lines.size() <<" objects detected \t\tFAILDED";
	}
	else{
		output << circles.size() + lines.size() << " objects detected \t object detection SUCCES";
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
	std::cout << "running Shape Detection test" << std::endl;
	ShapeDetector sD;
	Pointcloud p = txtToPointcloud(argv[1]);
	Pointcloud p2;
	p2.loadPointsFromFile("cloudje");
	std::cout << " - " << p2.getPoints().size() << " - " << p2.getCloudWidth() << " - " << p2.getCloudHeight();
	const Mat & orginal_image = sD.createImage(p2);
	std::cout << "running Shape Detection test" << std::endl;
	const Mat & orginal_image2 = sD.createImage(p2);
	Mat customImage = orginal_image.clone();
	std::vector<Circle> circles = sD.detectCircles(customImage);
	vector<Line> lines = sD.searchLines(customImage);
	sD.writeObjectsToConsole(lines,circles);
	sD.showObjects(lines,circles, orginal_image, customImage);
	waitKey();
    return 0;

}
