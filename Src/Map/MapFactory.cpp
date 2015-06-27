#include "MapFactory.h"


mapFactory::mapFactory()
{}


mapFactory::~mapFactory()
{}

Map mapFactory::loadMapFromDatabase(databaseConnector& theDatabase){
	return Map{};
}
void mapFactory::saveMapToDatabase(Map & theMap, databaseConnector &theDatabase){

}

std::vector<line> mapFactory::loadMapFromFile(std::string fileAddress){
	std::vector<line> rtn;					// The vector to return
	std::ifstream readFile(fileAddress);	// The file stream
	std::string fileLine;

	// Read for as long file has lines
	// Every line starts with an object indicator by 1 character
	// q = QR code object; r = Rosbee object; a = ATV object; c = Quadcopter object; l = line object
	// Line objects can be parsed immediatly and stored in the rtn vector
	// Objects have to be parsed to four lines and can be stored then
	while (std::getline(readFile, fileLine)){
		char objectType = fileLine.at(0);
		if (objectType == 'l'){
			// objectType is line
			rtn.push_back(linestringToLine(fileLine.substr(1)));
		}
		else{
			// objectType is object
			// All objects are universal and can be parsed the same way
			std::vector<line> objectLines = objectToLines(fileLine.substr(1));

			// Append the objectsLines to the rtn vector
			rtn.insert(rtn.end(), objectLines.begin(), objectLines.end());
		}
	}

	return rtn;
}

line mapFactory::linestringToLine(std::string linestring){
	// Strip the '(' and ')' of the string
	std::string nums = linestring.substr(1, linestring.length() - 2);
	std::vector<std::string> elems = splitString(nums, ' ');

	// Remove commas at the end of the first three values
	for (unsigned int i = 0; i < elems.size() - 1; i++){
		elems[i] = elems[i].substr(0, elems[i].length() - 1);
	}


	// Elems now contains x, y, x1, y1 as string
	int x = atoi(elems[0].c_str());
	int y = atoi(elems[1].c_str());
	int x1 = atoi(elems[2].c_str());
	int y1 = atoi(elems[3].c_str());

	return line(point(x, y), point(x1, y1));
}

std::vector<line> mapFactory::objectToLines(std::string object){
	// Received string will be in this format: (0, 1, 2, 3)
	// 0 will be the x coördinate as int of the top-left point
	// 1 will be the y coördinate as int of the top-left point
	// 2 will be the width of the object
	// 3 will be the height of the object

	std::vector<line> rtn;

	// Strip the '(' and ')' of the string
	std::string nums = object.substr(1, object.length() - 2);
	std::vector<std::string> elems = splitString(nums, ' ');

	// Remove commas at the end of the first three values
	for (unsigned int i = 0; i < elems.size() - 1; i++){
		elems[i] = elems[i].substr(0, elems[i].length() - 1);
	}

	int x = atoi(elems[0].c_str());
	int y = atoi(elems[1].c_str());
	int width = atoi(elems[2].c_str());
	int height = atoi(elems[3].c_str());

	rtn.push_back(line(point(x, y), point(x + width, y)));
	rtn.push_back(line(point(x + width, y), point(x + width, y + height)));
	rtn.push_back(line(point(x, y + height), point(x + width, y + height)));
	rtn.push_back(line(point(x, y), point(x, y + height)));

	return rtn;
}

std::vector<std::string> mapFactory::splitString(std::string text, char delimiter){
	std::vector<std::string> rtn; // The vector to return

	std::string tmp = "";
	for (unsigned int i = 0; i < text.length(); i++){
		if (text[i] != delimiter){
			tmp += text[i];
		}
		else{
			rtn.push_back(tmp);
			tmp = "";
		}
	}
	rtn.push_back(tmp);

	return rtn;
}