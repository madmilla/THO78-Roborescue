#include "map.h"

#include <fstream>
#include "mapreadfailure.h"

Map::Map(std::string filename) :
    filename{filename},
    data{nullptr}
{
    std::ifstream file{filename, std::ios::in | std::ios::binary};
    if(!file.is_open()){
        throw MapReadFailure{"Cannot open file: " + filename};
    }

    //load dataNames
    unsigned int dataNamesCount;
    file.read(reinterpret_cast<char *>(&dataNamesCount), UISize);
    char * dataNames = new char[dataNamesCount];
    file.read(dataNames, dataNamesCount);
    int start = 0;
    for(unsigned int i = 0; i < dataNamesCount; i++){
        if(dataNames[i] == '\0'){
            this->dataNames.push_back(std::string(dataNames + start));
            start = i + 1;
        }
    }
    delete dataNames;

    if(!file.good()){
        throw MapReadFailure{"Fail while reading dataNames"};
    }

    file.read(reinterpret_cast<char *>(&rows), UISize);
    file.read(reinterpret_cast<char *>(&colloms), UISize);

    if(!file.good()){
        throw MapReadFailure{"Fail while reading rows or colloms"};
    }

    data = new unsigned int*[rows];
    for(unsigned int r = 0; r < rows; r++){
        data[r] = new unsigned int[colloms];
    }

    for(unsigned int r = 0; r < rows; r++){
        file.read(reinterpret_cast<char *>(data[r]), UISize * colloms);
        if(file.fail()){
            throw MapReadFailure{"Fail while reading data"};
        }else if(file.eof()){
            throw MapReadFailure{"File is to small"};
        }
    }

    if(file.fail()){
        throw MapReadFailure{"Fail while reading data"};
    }

    char eofCheck;
    file.read(&eofCheck, 1);

    if(!file.eof()){
        throw MapReadFailure{"File is to large"};
    }

    file.close();
}

Map::~Map()
{
    for(unsigned int r = 0; r < rows; r++){
        delete[] data[r];
        data[r] = nullptr;
    }
    delete[] data;
    data = nullptr;
}

void Map::save(){
    std::ofstream file{filename, std::ios::out | std::ios::binary};

    //save dataNames
    unsigned int strlen = dataNames.size();
    for(std::string dataName : dataNames){
        strlen += dataName.length();
    }

    file.write(reinterpret_cast<char *>(&strlen), UISize);

    for(std::string dataName : dataNames){
        file.write(dataName.c_str(), dataName.size() + 1);
    }

    file.write(reinterpret_cast<char *>(&rows), UISize);
    file.write(reinterpret_cast<char *>(&colloms), UISize);

    for(unsigned int r = 0; r < rows; r++){
        file.write(reinterpret_cast<char *>(data[r]), UISize * colloms);
    }

    file.close();
}

unsigned int Map::get(unsigned int row, unsigned int collom){
    if(row >= rows)
        throw std::range_error{"There are " + std::to_string(rows) + " rows, but request is: " + std::to_string(row)};
    if(collom >= colloms)
        throw std::range_error{"There are " + std::to_string(colloms) + " colloms, but request is: " + std::to_string(collom)};
    return data[row][collom];
}

void Map::set(unsigned int value, unsigned int row, unsigned int collom){
    if(row >= rows)
        throw std::range_error{"There are " + std::to_string(rows) + " rows, but request is: " + std::to_string(row)};
    if(collom >= colloms)
        throw std::range_error{"There are " + std::to_string(colloms) + " colloms, but request is: " + std::to_string(collom)};
    data[row][collom] = value;
}

void Map::createEmpty(std::string filename, unsigned int rows, unsigned int colloms){
    std::ofstream file{filename, std::ios::out | std::ios::binary};
    std::string block0Name = "Air";
    unsigned int strlen = block0Name.size() + 1;

    file.write(reinterpret_cast<char *>(&strlen), UISize);
    file.write(block0Name.c_str(), block0Name.size() + 1);

    file.write(reinterpret_cast<char *>(&rows), UISize);
    file.write(reinterpret_cast<char *>(&colloms), UISize);

    unsigned int * temp = new unsigned int[colloms];

    for(unsigned int c = 0; c < colloms; c++){
        temp[c] = 0;
    }

    for(unsigned int r = 0; r < rows; r++){
        file.write(reinterpret_cast<char *>(temp), UISize * colloms);
    }

    delete[] temp;

    file.close();
}
