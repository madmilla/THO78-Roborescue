#include "map.h"

Map::Map(){

}

void Map::EditMap(int wight, int hight, Color r){
	switch (r) {
	case red: twoDmap[wight][hight] = '0'; break;
	case white: twoDmap[wight][hight] = '1'; break;
	case blue: twoDmap[wight][hight] = '2'; break;
	}
	
}

void Map::StoreMAp(std::string filepath){
	std::ofstream file;
	file.open(filepath, std::ios::trunc);
	std::string lineString;
	if (file.is_open()){
		for (int yIndex = 0; yIndex <= 19; yIndex++){
			for (int xIndex = 0; xIndex <= 19; xIndex++){
				file << twoDmap[yIndex][xIndex] << " ";

				//lineString.append("" + twoDmap[yIndex][xIndex]);
				//lineString.append(" ");
			}
			file << "\n";
			
		}
	}
	file.close();
}

void Map::LoadMap(std::string filePath){
	std::ifstream file(filePath);
	std::string str;
	int xIndex = 0; 
	int yIndex = 0;
	if (file.is_open()){
		while (std::getline(file, str)){
			for (char t : str){
				if (t != ' '){
					twoDmap[yIndex][xIndex] = t;
					xIndex++;
				}
			}
		xIndex = 0;
		yIndex++;
		}
	}
	file.close();
}


Map::~Map(){

}

