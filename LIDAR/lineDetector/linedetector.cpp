#include "linedetector.h"

lineDetector::lineDetector() {

}

lineDetector::~lineDetector() {

}

/* this function converts a Mat object to a IplImage
 * so the function cvSmooth can be used. */
bool lineDetector::callCvSmooth(const Mat & m_src, const Mat & m_dest, const int smooth_type, const int param1, const int param2) {
    if(m_src.empty()) {
        return false;
    }
    IplImage src = m_src;
    IplImage dst = m_dest;
    cvSmooth( &src, &dst, smooth_type, param1, param2 );
    return true;
}

/*This function creates a .jpg file from a .txt file with pixels according to the output paramter
 * and after creation returns the picture */
Mat lineDetector::createImage(const std::string & source){
    std::ifstream file(source); // open  inputfile
    if (!file.is_open()){
        std::cout << "could not open file with name " << source << std::endl;
        exit(-1);
    }
    std::string line;
    int imageHeight = 0;
    int imageWidth = 0;
    while(getline(file,line)){ //a while loop to get the image width and the image Height
        imageHeight++;
        if(line.length()> imageWidth){
            imageWidth = line.length();
        }
    }
    Mat mat(imageWidth,imageHeight,CV_8UC1); //Create a Mat object which will represent the image with all the pixels
    int x = 0;
    file.clear();
    file.seekg(0,file.beg);
    while(getline(file,line)){ //Walk through the file
        int y = 0;
        for(int i = 0; i< imageWidth; i++){
            char ch = line[i];
            if(isdigit(ch)){ // if the char in the file is a number, the pixel should be 255
                mat.at<uchar>(Point(y,x)) = BLACK_PIXEL; // set the pixel at 255
            }
            else{
                mat.at<uchar>(Point(y,x)) = WHITE_PIXEL;
            }
            y++;
        }
        x++;
    }
    file.close();
    imwrite("output.jpg", mat); // save the image

    return Mat(imread("output.jpg")); //read and return the image
}

/*the function checks for double lines to prevent unneeded data*/
void lineDetector::checkLines(vector<Vec4i> & lines) {

    for( size_t i = 0; i < lines.size(); i++ ) {    //walk through the line container
        Vec4i second = lines[i];
        for (size_t j = 0; j < lines.size(); j++) {
            Vec4i current = lines[j];

            const int current_x1 = (current[0]);
            const int current_y1 = (current[1]);
            const int current_x2 = (current[2]);
            const int current_y2 = (current[3]);

            const int second_x1 = second[0];
            const int second_y1 = second[1];
            const int second_x2 = second[2];
            const int second_y2 = second[3];

            if((second_x1 - RANGE_CHECK)< current_x1&& (second_x2 + RANGE_CHECK) > current_x2) {
                if(((second_y1 < (current_y1 + RANGE_CHECK)) && second_y1 > (current_y1 - RANGE_CHECK)) &&  //compare the current and the second line
                  ((second_y2 < (current_y2 + RANGE_CHECK)) && second_y2 > (current_y2 - RANGE_CHECK))){    // coordinates in a range

                    if(j!=i){
                        lines.erase(lines.begin()+j); // erase the target line
                    }
                }
            }
        }
    }
}

/* the function search for lines in the given image
 * and returns the lines*/
vector<Vec4i> lineDetector::searchLines(const Mat & image, Mat & final_dest) {

    if (image.empty()) { //check if there is a image
        std::cout << "could not read image" << std::endl;
        exit(-1);
    }

    Mat dest;
    if(!callCvSmooth(image, image, CV_GAUSSIAN, SMOOTH, SMOOTH)) {
       std::cout << "the source file is empty!" << std::endl;
       exit(-1);
    }
    Canny(image, dest, CANNY_THRESHHOLD1, CANNY_THRESHHOLD2); //extracts the egdes of an image
    cvtColor(dest, final_dest, CV_GRAY2BGR);

    vector<Vec4i> lines;  // container to save te lines
    HoughLinesP(dest, lines, HOUGHLINES_RHO, HOUGHLINES_THETA, HOUGHLINES_THRESHHOLD,
    HOUGHLINES_MINLINELENGTH, HOUGHLINES_MAXLINEGAP);  //search the lines

    checkLines(lines); //check for double lines

    return lines;  // return the saved lines
}

/* write the lines container to the console*/
void lineDetector::writeLinesToConsole(const vector<Vec4i> & lines) {
    std::stringstream stream;
    stream << "found lines: " << lines.size() << std::endl << std::endl;
    for (size_t i = 0; i < lines.size(); i++ ) {
        Vec4i line = lines[i];
        stream << "line " << i+1 << std::endl;
        stream << "(x1, y1) (" << line[0] << ',' << line[1] << ')' << std::endl;
        stream << "(x2, y2) (" << line[2] << ',' << line[3] << ')' << std::endl << std::endl;
    }
    std::cout << stream.str();
}

/* draw the lines in a given matrix */
void lineDetector::drawLines(const vector<Vec4i> & lines, Mat & final_dest) {
    for( size_t i = 0; i < lines.size(); i++ ) {
        Vec4i l = lines[i];
        line( final_dest, Point(l[0], l[1]), Point(l[2], l[3]), LINECOLOR, THICKNESS, CV_AA);
    }
}

/* shows the gui's */
void lineDetector::showGui(const Mat & source, const Mat & final_dest) {
    imshow("orginal Image", source);
    imshow("detected lines", final_dest);
}



