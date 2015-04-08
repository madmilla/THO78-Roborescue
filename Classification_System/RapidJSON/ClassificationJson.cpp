#include "ClassificationJson .h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
using namespace rapidjson;
ClassificationJson::ClassificationJson(){
}

std::string ClassificationJson::TextFileToJsonString(std::string filename)
{
	myReadFile.open(filename);
	std::string str;
	if (myReadFile.is_open()) {
		while (std::getline(myReadFile, str)){
			returnString.append(str);
		}
	}
	myReadFile.close();
	printf("%s", returnString.c_str());
	return returnString;
}

