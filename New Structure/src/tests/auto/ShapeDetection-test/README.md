# ShapeDetection Test

This program will test the ShapeDetection functions.
The functions which will be tested:

	Mat createImage(const std::string & source);
	vector<Vec4i> searchLines(const Mat & image);
	CvSeq * detectCircles(const Mat & image);

The createImage function will be tested by creating an image and checking the size values of the image.

The searchLines and detectCircles functions will be tested by checking the amount of found circles and lines.
