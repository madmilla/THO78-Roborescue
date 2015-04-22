# ShapeDetection Test

This program will test the Pointcloud functions.
The functions which will be tested:

	*void setPoint(Point point);
	void setPoint(int x, int y);
	std::vector<Point> getPoints();
	void removePoint(Point p);
	void removePoint(int x, int y);
	int getCloudWidth();
	int getCloudHeight();
	void setOrientation(int degrees);
	int getOrientation();
	void setOffset(Point newOffset);
	Point getOffset();
	void savePointsToFile(std::string filename);
	void loadPointsFromFile(std::string filename);*

The **setPoint** functions will be tested by setting a point and comparing the points in the pointcloud to the set point. 

The **getPoints** function will be tested by adding a few points to the pointcloud and check if they will be returned in the vector with getPoints.

the **removepoint** functions will be tested by adding a few points to the pointcloud and removeing them afterwards. If the size of the pointcloud is 0 the function works.

the **getCloudWidth** and **getCloudHeigth** functions will be tested by setting some points with a maxHeight and maxWidth and compare the values of the getters with the maxHeight en maxWidth.

The setters and getters of the orientation and the offset will be tested by setting a value an compare the set value to get value returned by the getter.

The **savePointsToFile** and **loadPointsFromFile** functions will be tested by saving a pointcloud an load it in another pointcloud. Then the program will compare al the points, the offset and the orientation of the pointclouds.
