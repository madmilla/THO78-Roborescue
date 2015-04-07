#include "Map.h"



int main(int argc, char *argv[]){
	std::string url = "testmap.txt";
	Map mapper;
	mapper.LoadMap(url);
	std::cout << mapper.twoDmap[19][19]<< "\n";
	mapper.EditMap(19,19,blue);
	std::cout << mapper.twoDmap[19][19]<< "\n";
	mapper.StoreMAp(url);


	getchar();
}