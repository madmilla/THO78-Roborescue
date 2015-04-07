#include <iostream>
#include <cstdio>
#include "ClassificationJson .h"
#include "rapidjson\reader.h"
using namespace std;
using namespace rapidjson;

int main()
{
	ClassificationJson StringFromFile;
	Document JsonObj;
	JsonObj.Parse<0>(StringFromFile.TextFileToJsonString("heli.json").c_str());
	assert(JsonObj.IsObject());


	assert(JsonObj.HasMember("Type"));
	assert(JsonObj["Type"].IsString());
	printf("Type = %s\n", JsonObj["Type"].GetString());



	// modify value
	Value& s = JsonObj["Type"];
	s.SetString("newname");


	// add mamber
	JsonObj.AddMember("Membername", s, JsonObj.GetAllocator());

	//output
	StringBuffer buffer;
	Writer<StringBuffer> writer(buffer);
	JsonObj.Accept(writer);
	cout << buffer.GetString();

	getchar();
	return 0;
}

