#ifndef CLASSIFICATIONJSON
#define CLASSIFICATIONJSON

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/filestream.h"

#include <iostream>
#include <fstream>
#include <cstdio>

class ClassificationJson {


public:
	ClassificationJson();
	std::string TextFileToJsonString(std::string filename);

private:
	std::string returnString;
	std::ifstream myReadFile;
};
#endif // CLASSIFICATIONJSON

